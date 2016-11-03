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
 令dp[i][j][s1][s2]表示前i个物品填了j的体积，有s1个物品选为为必选，s2个物品选为必不选的方案数(0<=s1,s2<=2)，则有转移方程dp[i][j][s1][s2] = dp[i - 1][j][s1][s2] + dp[i - 1][j - a[i]][s1 - 1][s2] + dp[i - 1][j][s1][s2 - 1]，边界条件为dp[0][0][0][0] = 1，时间复杂度O(NS*3^2)。
 
 看的的题解，最后*4是因为必选AB可以调换位置变成BA，同理非必选，所以答案*4。
 
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
const int N = 310, M = 500000, inf = 100100100; //注意修改点的范围
struct Edge{
    int s, t, f, id;
    int next;
}e[M];
int pre[N], tpre[N], dis[N], ans[M], cnt;
int a[N][N];
void addedge(int s, int t, int f, int id){ //有上下界的最大流模板
    e[cnt].s = s, e[cnt].t = t, e[cnt].f = f, e[cnt].id = id, e[cnt].next = pre[s];
    pre[s] = cnt++;
    e[cnt].s = t, e[cnt].t = s, e[cnt].f = 0, e[cnt].id = 0, e[cnt].next = pre[t];
    pre[t] = cnt++;
}
int bfs(int s, int t){
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i = pre[id]; i != -1; i = e[i].next)
            if(dis[e[i].t] == 0 && e[i].f > 0){
                dis[e[i].t] = dis[id] + 1;
                q.push(e[i].t);
            }
    }
    return dis[t] != 0;
}
int dfs(int s, int t, int cur_flow){
    int lev = cur_flow;
    if(s == t) return cur_flow;
    for(int &i = tpre[s]; i != -1; i = e[i].next)
        if(dis[e[i].t] == dis[s] + 1 && e[i].f > 0 && lev > 0){
            int temp = dfs(e[i].t, t, min(lev, e[i].f));
            e[i].f -= temp;
            e[i^1].f += temp;
            lev -= temp;
        }
    return cur_flow - lev;
}
int dinic_flow(int s, int t){    //注意是从s到t，故而s最小，t最大
    int sum = 0;
    while(bfs(s, t)){
        int flow;
        for(int i = s; i <= t; i++) tpre[i] = pre[i];
        while((flow = dfs(s, t, inf))) sum += flow;
    }
    return sum;
}

void flow_init(){
    memset(pre, -1, sizeof(pre));
    memset(ans, 0, sizeof(ans));
    cnt = 0;
}

int limit_min_flow(int n, int m, int mid, int k, int &flow){
    int src = 0, dest = n + 2 * m + 1;
    for (int i = 1; i <= n; ++i) {
        addedge(src, i, 1, 0);
    }
    if (mid == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j]) {
                    addedge(i, n + j, 1, 0);
                }
                else {
                    addedge(i, n + m + j, 1, 0);
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        addedge(n + i, dest, 1, 0);
        if (mid == 1) {
            addedge(n + m + i, n + i, k, 0);
        }
        
    }
    flow += dinic_flow(src, dest);
    return flow >= mid * n;
}


int main(){
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        int n, m, L, k;
        cin >> n >> m >> L >> k;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < L; ++i) {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        int ans = 0, flow = 0;
        flow_init();
        
        while (true) {
            if (limit_min_flow(n, m, ans + 1, k, flow)) {
                ++ans;
            }
            else {
                break;
            }
        }
        printf("Case %d: %d\n", ++ca, ans);
    }
    return 0;
}

