//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/743/problem/E
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
const int N = 201010;
lld tops[N], a[N], dp[N];
vector<int> g[N];
lld ans = -1e15;

void dfs(int u, int fat) {
    dp[u] = a[u];
    multiset<lld> childs;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != fat) {
            dfs(v, u);
            dp[u] += dp[v];
            tops[u] = max(tops[u], tops[v]);
            childs.insert(tops[v]);
            if (childs.size() == 3) {
                childs.erase(childs.begin());
            }
            if (childs.size() == 2) {
                ans = max(ans, *childs.begin() + *(++childs.begin()));
            }
        }
    }
    tops[u] = max(tops[u], dp[u]);
//    cout << u << " dp " << dp[u] << "  tops " << tops[u] << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tops[i] = -1e15;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    if (ans != -1e15) {
        cout << ans << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    
    
    return 0;
}
