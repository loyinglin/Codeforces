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
const int N = 502;
const int M = 110002;
const int inf = 100100100;
struct Edge
{
    int s, t, f, c;
    int next;
};
char str[N][N];
vector<pair<int, int> > mV, hV;
struct MCMF { // minCostMaxFlow
    int cnt, sumFlow;
    int pre[N], dist[N], eat[N];
    int inq[N], vt[N];
    struct Edge e[M];
    void reset()
    {
        cnt = 0;
        memset(pre, -1, sizeof(pre));
    }
    void addedge(int s, int t, int f, int c)
    {
        e[cnt].s = s, e[cnt].t = t, e[cnt].f = f, e[cnt].c = c, e[cnt].next = pre[s];
        pre[s] = cnt++;
        e[cnt].s = t, e[cnt].t = s, e[cnt].f = 0, e[cnt].c = -c, e[cnt].next = pre[t];
        pre[t] = cnt++;
    }
    bool SPFA(int s, int t, int n)
    {
        queue <int> q;
        memset(inq, 0, sizeof(inq));
        memset(eat, -1, sizeof(eat));
        memset(vt, 0 ,sizeof(vt));
        for(int i = 0; i <= n; i ++) dist[i] = inf;
        inq[s] = 1;
        vt[s]++;
        dist[s] = 0;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inq[u] = 0;
            if(vt[u] > n) break;
            for(int i = pre[u]; i != -1; i = e[i].next){
                int v = e[i].t;
                if(e[i].f && dist[v] > dist[u] + e[i].c){
                    dist[v] = dist[u] + e[i].c;
                    eat[v] = i;
                    if(!inq[v]){
                        q.push(v);
                        vt[v]++;
                        inq[v] = 1;
                    }
                }
            }
        }
        if(dist[t] == inf || !q.empty()) return false;
        return true;
    }
    int look(int s, int t, int n)
    {
        int flow = 0; // 总流量
        int i, minflow, mincost;
        mincost = 0;
        while(SPFA(s, t, n)){
            minflow = inf + 1;
            for(i = eat[t]; i != -1; i = eat[e[i].s])
                if(e[i].f < minflow) minflow = e[i].f;
            flow += minflow;
            for(i = eat[t]; i != -1; i = eat[e[i].s]){
                e[i].f -= minflow;
                e[i^1].f += minflow;
            }
            mincost += dist[t] * minflow; //单位流量的最小代价dist[t]
        }
        sumFlow = flow; // 题目需要流量，用于判断
        return mincost;
    }
}acm;


int main()
{
    int n, m;
    while(cin >> n >> m){
        if (n + m == 0) {
            break;
        }
        int src = 0, dest = 222;
        for (int i = 1; i <= n; ++i) {
            cin >> (str[i] + 1);
        }
        acm.reset();
        mV.clear();
        hV.clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str[i][j] == 'm') {
                    mV.push_back(make_pair(i, j));
                    acm.addedge(src, mV.size(), 1, 0);
                    
                }
                if (str[i][j] == 'H') {
                    hV.push_back(make_pair(i, j));
                    acm.addedge(hV.size() + 111, dest, 1, 0);
                }
            }
        }
        
        for (int i = 0; i < mV.size(); ++i) {
            for (int j = 0; j < hV.size(); ++j) {
                acm.addedge(i + 1, 111 + j + 1, inf, abs(mV[i].first - hV[j].first) + abs(mV[i].second - hV[j].second));
            }
        }
        int ans = acm.look(src, dest, dest);
        printf("%d\n", ans);
    }
    return 0;
}
