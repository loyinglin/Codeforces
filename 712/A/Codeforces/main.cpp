//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/712/problem/A
 题目大意：给出n个数字。（a[1], a[2], ..., a[n]）
 a[i]和b[i]的关系如下。
 a[i] = b[i] - b[i+1] + b[i+2] - b[i+3]....
 
 给出数组a[i]，求数组b[i]。
  n (2 ≤ n ≤ 100 000)
  a[i] ( - 1e9 ≤ a[i] ≤ 1e9)
 
 Examples
 input
 5
 6 -4 8 -2 3
 output
 2 4 6 1 3
 input
 5
 3 -2 -1 5 6
 output
 1 -3 4 11 6
 
 
 题目解析：
 根据通项公式，知道b[n] = a[n]；（因为不能存在b[n+1])
 然后倒着求b[i], b[i] = a[i] + a[i+1]；
 
 
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
