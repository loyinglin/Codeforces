//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 
 
 
 题目解析：
 dp[i][j] 表示从root到点i的路径cost为j的最大收益；
 那么遍历i所有的孩子k，dp[i][j] += dp[k][t]; t为j到maxCost的值中，最优解；
 最后在加上i自己的节点上的cost。
 
 
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
vector<int> g[N], edgeID[N];
vector<lld> vis[N];
lld cost[N];
int n, m;
lld dp[N][N];
lld ans[N];

void dfs(int u, int f) {
    for (int i = 1; i <= m; ++i) { // 枚举费用
        lld curCost = cost[i];
        lld sum = 0;
        for (int j = 0; j < vis[u].size(); ++j) { // 统计当前费用下，u点的收益
            if (curCost <= vis[u][j]) {
                sum += curCost;
            }
        }
        dp[u][i] = sum;
    }
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != f) {
            dfs(v, u);
        }
    }
    lld maxChild[N] = {0};
    for (int i = m; i >= 0; --i) { // 枚举当前点的cost，求出最大值
        lld sum = 0;
        for (int j = 0; j < g[u].size(); ++j) {
            int v = g[u][j];
            if (v != f) {
                maxChild[j] = max(maxChild[j], dp[v][i]);
                sum += maxChild[j];
            }
        }
        dp[u][i] += sum;
    }
    return ;
}

void ansDFS(int u, int f, int c) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != f) {
            lld maxCost = dp[v][c];
            int index = c;
            for (int k = c; k <= m; ++k) {
                if (dp[v][k] > maxCost) {
                    maxCost = dp[v][k];
                    index = k;
                }
            }
            ans[edgeID[u][i]] =cost[index] - cost[c];
            ansDFS(v, u, index);
        }
    }
}

int main(int argc, const char * argv[]) {
//         数据
    
//    freopen("input.txt", "w", stdout);
//    int t = 10;
//    cout << t << endl;
//    while (t--) {
//        int n = 100;
//        cout << n  << " " << n-1 << endl;
//        int t = 2;
//        for (int i = 1; i <= n/3; ++i) {
//            cout << i << " " << t++ << endl;
//            cout << i << " " << t++ << endl;
//            cout << i << " " << t++ << endl;
//        }
//        
//        for (int i = 2; i <= n; ++i) {
//            cout << i <<  " " << arc4random_uniform(10000) << endl;
//        }
//    }
//    return 0;

    
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    
    int caseN;
    cin >> caseN;
    while (caseN--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            vis[i].clear();
            edgeID[i].clear();
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
            edgeID[v].push_back(i);
            edgeID[u].push_back(i);
        }
        for (int i = 1; i <= m; ++i) {
            int v;
            scanf("%d%lld", &v, &cost[i]);
            vis[v].push_back(cost[i]);
        }
        sort(cost + 1, cost + 1 + m);
        dfs(1, 0);
        cout << dp[1][0] << endl;
        ansDFS(1, 0, 0);
        for (int i = 1; i < n; ++i) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
