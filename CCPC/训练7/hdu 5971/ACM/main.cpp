//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 n个人，m个1对1的比赛，每次比赛都是goodPlayer vs badPlayer；
 给出x个goodPlayer 和 y个badPlayer；
 询问：
 是否每个人在比赛中或者在给出的x、y内；
 是，输出Yes；
 否，输出No；
 
 N (1 ≤ N≤ 1000)、M(1 ≤M ≤ 10000)、X,Y(X+Y≤N )
 
 Sample Input
 5 4 0 0
 1 3
 1 4
 3 5
 4 5
 5 4 1 0
 1 3
 1 4
 3 5
 4 5
 2
 Sample Output
 NO
 YES
 
 
 
 题目解析：
 题目意思不清楚，根据样例猜测：
 首先希望每个人在比赛中合法，同时与给定的good、bad不冲突，最后每个人都在比赛中 或者 在制定的good、bad中；
 
 于是可以这么做：
 用vis[i] 来表示第i个人的状态：
 vis[i] = 0 表示未知数；
 vis[i] = 1 表示good；
 vis[i] = -1 表示bad；
 
 按照题目给出的x、y个人标志1和-1；然后按照这些人的比赛进行dfs；
 然后再遍历n个人，如果这个人在比赛中，并且目前还未标志，给他随意标记为good，然后dfs；
 
 最后看n个人是否全部vis[i] != 0即可；
 
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
const lld N = 1111;
vector<int> g[N];
int vis[N];
int beyong[N];
int ok;

void dfs(int u) {
    //    cout << "dfs " << u << " vis " << vis[u] << endl;
    if (!ok) return ;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (vis[v] == 0)
        {
            vis[v] = -vis[u];
            dfs(v);
        }
        else
        {
            if (vis[v] != -vis[u])
            {
                ok = 0;
                return ;
            }
        }
    }
    
}

int main()
{
    int n, m, x, y;
    while(cin >> n >> m >> x >> y)
    {
        ok = 1;
        memset(vis, 0, sizeof(vis));
        memset(beyong, 0, sizeof(beyong));
        for (int i = 0; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
            beyong[u] = beyong[v] = 1;
        }
        for (int i = 0; i < x; ++i) {
            int k;
            scanf("%d", &k);
            vis[k] = 1;
        }
        for (int i = 0; i < y; ++i) {
            int k;
            scanf("%d", &k);
            vis[k] = -1;
        }
        for (int i = 1; i <= n; ++i)
            if (vis[i] != 0) dfs(i);
        
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && beyong[i])
            {
                vis[i] = 1;
                dfs(i);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i]) ok = 0;
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
