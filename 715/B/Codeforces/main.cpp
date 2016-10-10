//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/715/problem/B
 题目大意：
 
 
 题目解析：
 
 
 
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
const int N = 3010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    lld i = 1, j = 2, k = 1;
    while (k <= n) {
        cout << (k + 1) * (k + 1) * i - j << endl;
        j = i;
        i = k = k + 1;
    }
    
    
    
    return 0;
}
