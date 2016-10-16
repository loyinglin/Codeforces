//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/715/problem/B
 题目大意：给出n个点，m条边，边的长度为0到10^9；长度为0的边表示可修改边。
 可修改边都需要赋值，边长必须是正整数。
 要求赋值完成后，点s到点t的最短路刚好为L。
 s n, m, L, s, t (2 ≤ n ≤ 1000,  1 ≤ m ≤ 10 000,  1 ≤ L ≤ 109,  0 ≤ s, t ≤ n - 1,  s ≠ t) 
 
 Examples
 input
 5 5 13 0 4
 0 1 5
 2 1 2
 3 2 3
 1 4 0
 4 3 4
 output
 YES
 0 1 5
 2 1 2
 3 2 3
 1 4 8
 4 3 4
 input
 2 1 123456789 0 1
 0 1 0
 output
 YES
 0 1 123456789
 input
 2 1 999999999 1 0
 0 1 1000000000
 output
 NO

 
 题目解析：
 先不考虑可修改边。
 求出s到t的最短路。
 枚举每一条可修改边，先按照长度为1的大小加入；如果加入后的最短路小于L，则找到解，剩下的所有可修改边重置为inf。
 在最短路中的找到刚刚添加的最后一条可修改边，把变成重置为L-dis+1，得到一个解。
 
 
 
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
const lld N = 1020;
const lld M = 20002;
const lld inf = 1e9 + 3;
struct Edge
{
    lld s, t, c;
    lld next;
}e[M], ee[M];
lld cnt, eeCNT, n, m, L, dest, src;
lld pre[N], dist[N], eat[N];
lld inq[N], vt[N];

void init()
{
    cnt = 0;
    eeCNT = 0;
    memset(pre, -1, sizeof(pre));
}

void addedge(lld s, lld t, lld c)
{
    e[cnt].s = s, e[cnt].t = t, e[cnt].c = c, e[cnt].next = pre[s];
    pre[s] = cnt++;
}

void addZeroEdge(lld s, lld t, lld c)
{
    ee[eeCNT].s = s, ee[eeCNT].t = t, ee[eeCNT].c = c;
    eeCNT++;
}


lld SPFA(lld s, lld t, lld n)
{
    queue <lld> q;
    memset(inq, 0, sizeof(inq));
    memset(eat, -1, sizeof(eat));
    memset(vt, 0 ,sizeof(vt));
    for(lld i = 0; i <= n; i ++) dist[i] = inf;
    inq[s] = 1;
    vt[s]++;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        lld u = q.front();
        q.pop();
        inq[u] = 0;
        if(vt[u] > n) break;
        for(lld i = pre[u]; i != -1; i = e[i].next){
            lld v = e[i].t;
            if(dist[v] > dist[u] + e[i].c){
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
    if(dist[t] == inf || !q.empty()) return inf;
    return dist[t];
}

lld check(lld mid) {
    e[cnt - 1].c = mid;
    e[cnt - 2].c = mid;
    return SPFA(src, dest, n);
}

int main()
{
    cin >> n >> m >> L >> src >> dest;
    init();
    for (lld i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w) {
            addedge(u, v, w);
            addedge(v, u, w);
        }
        addZeroEdge(u, v, w);
    }
    
    
    lld dis = SPFA(src, dest, n), pos = -1;
    
    if (dis < L) {
        cout << "NO" << endl;
        return 0;
    }
    bool find = dis == L;
    
    for (int i = 0; i < eeCNT; ++i) {
        if (ee[i].c == 0) {
            if (find) {
                ee[i].c = inf;
            }
            else {
                addedge(ee[i].s, ee[i].t, 1);
                addedge(ee[i].t, ee[i].s, 1);
                ee[i].c = 1;
                lld cur = SPFA(src, dest, n);
                if (cur <= dis) {
                    dis = cur;
                    pos = i;
                }
                if (cur <= L) {
                    find = 1;
                }
            }
        }
    }
    if (find) {
        cout << "YES" << endl;
        if (pos != -1) {
            if (dis != L) {
                ee[pos].c = L - dis + 1;
            }
        }
        for (int i = 0; i < eeCNT; ++i) {
            cout << ee[i].s << " " <<ee[i].t << " " << ee[i].c << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

