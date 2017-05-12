//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/722/problem/D
 题目大意：给出一个set，是setY，由n个不同的正整数y[i]组成；
 setX由n个不同的正整数x[i]组成，现在可以对任意x[i]进行多个以下操作：
 1、x[i] = 2 * x[i];
 2、x[i] = 2 * x[i] + 1;
 
 如果经过操作后的setX和setY是相同的，认为setX能生成setY。（按照从大到小的排序后，一一对应）
 
 现在给出n个数字y[i]，求出set X，要求setX的最大数字最小；（如果有多个答案，输出任意一个）
 
 (1 ≤ y[i] ≤ 1e9)
 (n = 5w)
 
 
 题目解析：
 题目给出的操作意思是：如果x的二进制表示，是y的前缀（y的二进制表示的左边部分），那么x可以转换成y。
 现在给出y[i]，在题目的要求中，必然存在一个解，就是x[i]=y[i]；
 容易看出，最大的数字最小这个限制满足二分。
 现在的问题是，如何迅速判断，在最大的数字不超过mid的情况下，是否存在合适的解？ 
 这里需要用到一个贪心的性质，如果a>b，那么优先匹配a，并且要在a<=mid的情况下，a匹配的数字尽可能大；
 于是可以把数组y[i]排序，从最大的开始匹配，如果y[i]>mid，则y[i] >>= 1，直到出现一个合法的解，添加标记；
 如果一个数字y[i]变到0，则无解，因为题目要求是正整数；
 每次求解的过程为O(NlogM)，总得的复杂度是O(N*logM*logM);
 
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
