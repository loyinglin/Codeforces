//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 M个商店，N个工厂，每个商店获利的条件是建设了指定的k个工厂。求总获利不小于L，工厂建设的时间最大值最小是多少。
 

 
 
 题目解析：
 二分时间的答案，看哪些工厂能建造。
 建图按照最大权闭合图。
 
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
const int N = 420, M = 200000, inf = 100100100; //注意修改点的范围 N所有点的范围
struct Edge{
    int s, t, f, id;
    int next;
}e[M];

int pre[N], tpre[N], dis[N], cnt;
int pro[N], Time[N], stTime[N], pay[N], vis[N];
vector<int> g[N];
void addedge(int s, int t, int f, int id){ //有上下界的最大流模板
    //    cout << s << " TO " << t << " FLOW " << f << endl;
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
    cnt = 0;
}

int limit_min_flow(int n, int m, int L, int l, int& flow, int &sum){
    int src = 0, dest = n + m + 1;
    for (int i = 1; i <= n; ++i) {
        if (Time[i] == stTime[l]) {
            addedge(m + i, dest, pay[i], 0); // n 个 plants 到 dest
        }
    }
    
    
    for (int i = 1; i <= m; ++i) {
        int ok = 1;
        for (int j = 0; j < g[i].size(); ++j) { // 判断m个shop中，需要的plants全部在规定时间内
            int t = Time[g[i][j]];
            if (t > stTime[l]) {
                ok = 0;
                break;
            }
        }
        if (ok && !vis[i]) {
            vis[i] = 1;
            addedge(src, i, pro[i], 0);
            sum += pro[i];
            for (int j = 0; j < g[i].size(); ++j) {
                addedge(i, g[i][j] + m, inf, 0);
            }
        }
    }
    
    flow += dinic_flow(src, dest);
    return sum - flow >= L;
}


int main(){
    
    //freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        int n, m, L;
        scanf("%d%d%d", &n, &m, &L);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &pay[i], &Time[i]);
            stTime[i] = Time[i];
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &pro[i]);
            g[i].clear();
            int k;
            scanf("%d", &k);
            while (k--) {
                int tmp;
                scanf("%d", &tmp);
                g[i].push_back(tmp);
            }
        }
        printf("Case #%d: ", ++ca);
        flow_init();
        sort(stTime + 1, stTime + 1 + n);
        memset(vis, 0, sizeof(vis));
        int ok = 0, l = 1, flow = 0, sum = 0;
        while (l <= n) {
            int r = l + 1;
            while (r <= n && stTime[l] == stTime[r]) {
                ++r;
            }
            if (limit_min_flow(n, m, L, l, flow, sum)) {
                cout << stTime[l] << " " << sum - flow << endl;
                ok = 1;
                break;
            }
            else {
                l = r;
            }
        }
        if (!ok) {
            cout << "impossible" << endl;
        }
        
    }
    return 0;
}
