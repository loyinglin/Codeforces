//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1228/problem/A)
 **题目大意：**
 给出两个整数l和r，已知l <= r；
 现在希望找到一个整数x，要求是 l<=x<=r，并且x中没有相同的数字；
 如果能找到则输出这个数字；
 如果不能找到则输出-1；
 
 
 输入：
 两个整数l和r； (1≤𝑙≤𝑟≤1e5)
 
 输出：
 输出整数x；如果不存在则输出-1；
 
 **题目解析：**
 直接遍历整数区间的数字，判断每个数字是否合法。
 
 
 （假如题目的数据范围非常大，甚至没有限制呢？在无法枚举的情况下，求出一个最小的解。）
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    int x, y;
    cin >> x >> y;
    while (x <= y) {
        int ok = 1;
        int a[10] = {0};
        int tmp = x;
        while (tmp) {
            if (a[tmp % 10]) ok = 0;
            a[tmp%10] = 1;
            tmp /= 10;
        }
        if (ok) {
            cout << x << endl;
            return 0;
        }
        ++x;
    }
    cout << -1 << endl;
    
    return 0;
}


/**
 9877
 10234
 
 
 
 */
