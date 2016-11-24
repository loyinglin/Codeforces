//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5934
 题目大意：
 有n个炸弹，给出炸弹的坐标(x[i], y[i]), 爆炸的范围r[i], 引爆的代价c[i];
 （如果爆炸的范围内有炸弹，也会被引爆）
 求n个炸弹引爆的最小代价；
 n=1000
 
 Sample Input
 1
 5
 0 0 1 5
 1 1 1 6
 0 1 1 7
 3 0 2 10
 5 0 1 4
 
 
 Sample Output
 Case #1: 15

 样例数据解释：
 1          样例数量
 5          n个炸弹
 0 0 1 5    x[i], y[i], r[i], c[i]
 
 
 题目解析：
 记录前i个引爆的最小代价，ans[k] = 1，表示第k个炸弹是主动引爆；
 对于第i个炸弹，有两种可能：主动引爆和被动引爆；
 先看主动引爆的最小代价：对于前面i-1个炸弹中ans[k]=1,且在i的爆炸范围内的炸弹，可以不引爆，算出i个炸弹的引爆最小代价sum1;
 再看被动引爆的最小代价：从前面i-1个炸弹中，选择能引爆i，且代价最小的一个点，作为引爆i的点；然后把i能引爆的点优化掉，算出sum2；
  
 比较sum1和sum2，得出当前最优解。
 **但是**，
 中间WA了几次，发现这种策略无法保证正确性，于是换一种思路：
 对于炸弹，我们分成几类：
 * 1、两两能相互引爆；
 * 2、A能引爆B，B不能引爆A；
 * 3、A和B是独立的；
 
 
 容易知道，对于类型1，只需选择一个最小的引爆；类型2要选择引爆链的最前端（A->B->C）；对于类型3，两个都要引爆；
 最终做法：
 按照炸弹的引爆范围建图，如果A能引爆B，那么连A到B的边；
 遍历有向图，把强连通分量缩点；
 最后把所有入度为0的点的cost相加即可得到答案；

 
 
 
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
const int N = 1100, M = 500000, inf = 100100100; //注意修改点的范围

int x[N], y[N], r[N], c[N];
int f[N];
int ans[N];
int cro[N][N];

stack<int> S;
vector<int> g[N];
int sv[N], dfn[N], low[N];
int in[N], out[N], num[N];
int id; //连通分支个数
int cost[N];
int vis[N];

void dfs(int u, int dep){
    low[u] = dfn[u] = dep;
    S.push(u);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(dfn[v] == -1) dfs(v, dep + 1);
        if(sv[v] == -1) low[u] = min(low[u], low[v]);  // 判断不可少
    }
    if(low[u] == dfn[u]){
        ++id;
        cost[id] = c[u];
        while(S.top() != u){
            sv[S.top()] = id;
            cost[id] = min(cost[id], c[S.top()]);
            S.pop();
        }
        sv[S.top()] = id;
        S.pop();
    }
}

int tarjan(int n){
    id = 0;
    while(!S.empty()) S.pop();
    memset(dfn, -1, sizeof(dfn));
    memset(sv, -1, sizeof(sv));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) if (dfn[i] == -1) dfs(i, 0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int v = g[i][j], u = i;
            if (sv[u] != sv[v]) {
                ++vis[sv[v]];
            }
        }
    }
    
    int ret = 0;
    for (int i = 1; i <= id; ++i) {
        if (!vis[i]) {
            ret += cost[i];
        }
    }
    
    return ret;
}



bool cross(int i, int j) {
    double dis = sqrt((double)(x[i] - x[j]) * (double)(x[i] - x[j]) + (double)(y[i] - y[j]) * (double)(y[i] - y[j]));
    return dis <= r[i];
}


int main(){
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x[i], &y[i], &r[i], &c[i]);
            f[i] = i;
            g[i].clear();
        }
        memset(ans, 0, sizeof(ans));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j && cross(i, j)) {
                    g[i].push_back(j);
                }
            }
        }
        
        int total = tarjan(n);
        
        printf("Case #%d: %d\n", ++ca, total);
    }
    return 0;
}

/*
 
 4
 5
 0 0 1 5
 100000000 100000000 1 6
 0 1 1 7
 3 0 2 10
 5 0 1 4
 
 
 5
 0 0 1 5
 1 1 1 6
 0 1 1 7
 3 0 2 10
 5 0 2 4
 
 
 5
 0 0 3 5
 1 1 1 6
 0 1 1 7
 3 0 3 10
 5 0 2 4
 
 
 5
 0 0 1 5
 100000000 100000000 1 6
 0 1 1 7
 3 0 2 10
 5 0 1 4
 
 
 
 
 Case #1: 21
 Case #2: 9
 Case #3: 4
 Case #4: 21

 */

