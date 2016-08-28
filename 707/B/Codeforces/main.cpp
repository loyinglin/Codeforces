//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/707/problem/B
 题目大意：n个点，m条边，k个关键点。在关键点外的集合n-k，中找到一点T，使得T与关键点中任意点连接，并且边长最小。
 题目解析：
 难度都在读题，容易知道，关键点只要存在一条边与非关键点相连，那就有解。
 存下边，把点标记为关键点(f[i]=1)和非关键点(f[i]=0)
 遍历查找边由f[i]=1到f[i]=0的最小边即可，无解输出-1.
 
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
const lld N = 101000, M = 3010100, inf = 10110110;
lld f[N], dfn[N], low[N], cut[N];
lld cnt, son, ans, root;
vector<pair<lld, lld> > g[N];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i <= n; ++i) g[i].clear();
    
    for (int i = 0; i < m; ++i) {
        lld u, v, l;
        cin >> u >> v >> l;
        g[u].push_back(make_pair(v, l));
        g[v].push_back(make_pair(u, l));
    }
    
    for (int i = 0; i < k; ++i) {
        int tmp;
        scanf("%d", &tmp);
        f[tmp] = 1;
    }
    
    lld ret = -1;
    for (int i = 1; i <= n; ++i) {
        if (f[i]) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (f[g[i][j].first] == 0) {
                    if (ret == -1) {
                        ret = g[i][j].second;
                    }
                    else {
                        ret = min(ret, g[i][j].second);
                    }
                }
            }
        }
    }
    cout << ret;
    
}

