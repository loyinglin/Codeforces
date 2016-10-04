//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/712/problem/A
 题目大意：给出n个数字。（a1, a2, ..., an）
 ai和bi的关系如下。
 a[i] = b[i] - b[i+1] + b[i+2] - b[i+3]....
 
 求n个数字bi。
  n (2 ≤ n ≤ 100 000)
  ai ( - 109 ≤ ai ≤ 109)
 
 
 题目解析：
 容易知道b[n] = a[n]。
 然后倒着求b[i], b[i] = a[i] + a[i+1]。
 
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
const int N = 110010, inf = 0x7fffffff;
const lld MOD = 1000000007LL;
lld a[N], ans[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = a[i] + a[i + 1];
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
