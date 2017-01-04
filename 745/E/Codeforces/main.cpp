//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/745/problem/E
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
const int N = 1010, inf = 1e9;
int a[N], dp[N][1<<8], num[8];
vector<int> p[8];

int look(int len, int n) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (1 << 8); ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << 8); ++j) {
            if (dp[i][j] != -inf) {
                for (int k = 0; k < 8; ++k) {
                    if ((j & ( 1 << k)) == 0) {
                        int t = num[k] + len - 1;
                        if (t < p[k].size()) {
                            dp[p[k][t] + 1][j | (1 << k)] = max(dp[p[k][t] + 1][j | (1 << k)], dp[i][j]);
                        }
                        ++t;
                        if (t < p[k].size()) {
                            dp[p[k][t] + 1][j | ( 1 << k)] = max(dp[p[k][t] + 1][j | (1 << k)], dp[i][j] + 1);
                        }
                    }
                }
            }
        }
        ++num[a[i]];
    }
    int ans = -inf;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[i][(1<<8) - 1]);
    }
    if (ans == -inf) {
        return -1;
    }
    else {
        return ans * (len + 1) + (8 - ans) * len;
    }
    
    return 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[--a[i]].push_back(i);
    }
    int l = 1, r = n / 8;
    while (r > l) {
        int mid = (l + r + 1) / 2;
        if (look(mid, n) != -1) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    int ans = look(l, n);
    if (ans == -1) {
        ans = 0;
        for (int i = 0; i < 8; ++i) {
            if (p[i].size()) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
