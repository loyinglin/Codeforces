//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/739/problem/B
 题目大意：
 n个点的树，根为1，每个点有权值a[i]，每条边有权值e[i];
 两个点u, v, dist(u, v)是u到v的路径距离；
 如果u,v 满足两个条件：
 1、v是u子树上的点；
 2、dist(u, v) <= a[v]；
 我们认为u控制了v节点；
 求出每个点控制的节点数。(n=20w, a[i]=1e9)
 
 input
 5
 2 5 1 4 6
 1 7
 1 1
 3 5
 3 6
 output
 1 0 1 0 0
 
 
 
 
 题目解析：
 
 先简化问题：
 先看在一个链上的情况，a->b->c->d;
 容易知道，a能控制d 可以推出 b、c能控制d；
 同时容易知道一个性质：dist(u,v) < dist(f[u],v) f[u]是u的父节点；
 并且如果一个点v，在当前u无法控制的时候，在f[u]也无法控制；
 
 于是可以按照a[v]的值排序，保证一个单调的有效区间，并在dfs的过程维持上溯时路径的边长距离。
 
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
const int N = 201001;

int a[N], ans[N];
vector<int> g[N], c[N];
int f[N];
priority_queue<lld> q[N];

void merge(int u, int v) {
    int l = f[u], r = f[v];
    if (q[l].size() < q[r].size()) {
        l = f[v];
        r = f[u];
    }
    while (!q[r].empty()) {
        q[l].push(q[r].top());
        q[r].pop();
    }
    f[u] = l;
    f[v] = r;
}

void dfs(int u, int fat, lld path) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i], cost = c[u][i];
        if (v != fat) {
            dfs(v, u, path + cost);
            while (!q[f[v]].empty()) {
                lld top = q[f[v]].top();
                if (top - path > 0) { //dist(u, v) - a[v]
                    q[f[v]].pop();
                }
                else {
                    break;
                }
            }
            merge(u, v);
        }
    }
    ans[u] = q[f[u]].size();
    q[f[u]].push(path - a[u]);
}

int main(int argc, const char * argv
         []) {
    int n;
    cin >> n;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    cout << q.top() << endl;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        int u, v = i, w;
        cin >> u >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
        
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
