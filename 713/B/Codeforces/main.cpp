//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/713/problem/B
 题目大意：
 
 
 题目解析：
 dp[i][j] 表示第前i个数字转移到第j大的数字的代价；
 
 
 
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

int trans(lld x) {
    int ret = 0, t = 1;
    while (x) {
        ret += (x % 10) % 2 * t;
        x /= 10;
        t *= 2;
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    while (n--) {
        char op[11];
        lld k;
        scanf("%s%lld", op, &k);
        if (op[0] == '+') {
            a[trans(k)]++;
        }
        else if (op[0] == '-') {
            a[trans(k)]--;
        }
        else {
            cout << a[trans(k)] << endl;
        }
    }
    
    
    return 0;
}
