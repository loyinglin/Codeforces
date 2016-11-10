//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/722/problem/C
 题目大意：给出一个set Y，由n个不同的数字y[i]组成；
 set X由n个不同的数字x[i]组成，现在可以对任意x[i]进行多个以下操作：
 1、x[i] = 2 * x[i];
 2、x[i] = 2 * x[i] + 1;
 
 如果经过操作后的setX和setY是相同的，认为setX能生成setY。（按照从大到小的排序后，一一对应）
 
 现在给出n个数字y[i]，求出set X，要求setX的最大数字最小；（如果有多个答案，输出任意一个）
 
 (1 ≤ y[i] ≤ 1e9)
 (n = 5w)
 
 题目解析：
 如果x的二进制表示，是y的前缀，那么x可以转换成y。
 那么把y从小到大排序，对于每个数字，从前缀开始寻找未出现的数字即可；
 （是否可能出现这个数字被占用的可能？是否是最优的？）
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 101001;

int a[N];
map<int, int> Hash;
int ans[N];
int out[N];

int look(int mid, int n) {
    Hash.clear();
    for (int i = n; i > 0; --i) {
        int x = a[i];
        while (x > mid || Hash[x] == 1) {
            x >>= 1;
        }
        if (x == 0) {
            return 0;
        }
        else {
            Hash[x] = 1;
            ans[i] = x;
        }
        
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        out[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    
    int l = 1, r = a[n];
    while (l < r) {
        int mid = (l + r) / 2;
        if (look(mid, n)) {
            for (int i = 1; i <= n; ++i) {
                out[i] = ans[i];
            }
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << out[i] << " ";
    }
    
    
    cout << endl;
    
    
    return 0;
}
