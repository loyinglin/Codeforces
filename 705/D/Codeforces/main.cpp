//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/705/problem/D
 题目大意：n个点，每个点有权值x[i]，a[i], b[i], c[i], d[i]。
 每个点都存在一条边到其他点，代价为：
  |xi - xj| + ci + bj seconds if j < i.
 |xi - xj| + di + aj seconds otherwise (j > i).
 求从点s，到点t，遍历所有点的最短路径。（每个点只走一次）
 
 题目解析：
 每个点都遍历一遍，那么最终路径是一条s到t的直线。
 归纳法：
 n = 2的时候，直接s到t的路径得到最优解；
 n = 3的时候，枚举能插入的位置，可以得到最优解；
 ...
 n = k的时候，在n=k-1形成的s到t链上，枚举能插入的位置，得到最优解。
 
 假设插入的位置是i，那么n=k-1的链会分解成几段：s到i，NEXT[i]到t，i到k，k到NEXT[i]，其中 s到i 、 NEXT[i]到t 的距离不变。
 那么当 cost(i, k) + cost(k, NEXT[i]) - cost(i, NEXT[i]) 最小时，i就是插入的最优解。
 
 证明的关键点：当n=k插入的时候，点k不会对s到i、NEXT[i]到t 的路径造成影响。
 
 目前还未完善证明。
 
 
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
const lld N = 5002;
const lld M = N * N;
const lld inf = 0x3ffffffffffffffll;
lld cnt;
lld sumFlow;
lld NEXT[N], dist[N], eat[N];
lld inq[N], vt[N], a[N], b[N], c[N], d[N], x[N];
void init()
{
    cnt = 0;
    memset(NEXT, -1, sizeof(NEXT));
}

lld cost(lld i, lld j) {
    if (i < j) {
        return x[j] - x[i] + d[i] + a[j];
    }
    else if (i > j) {
        return x[i] - x[j] + c[i] + b[j];
    }
    return 0;
}

int main()
{
    
    
    lld n, dest, src;
    cin >> n >> src >> dest;
    init();
    for(lld i = 1; i <= n; i ++){
        cin >> x[i];
    }
    for(lld i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(lld i = 1; i <= n; i ++){
        cin >> b[i];
    }
    for(lld i = 1; i <= n; i ++){
        cin >> c[i];
    }
    for(lld i = 1; i <= n; i ++){
        cin >> d[i];
    }
    
    lld ans = cost(src, dest);
    
    NEXT[src] = dest;
    for (lld i = 1; i <= n; ++i) {
        if (i == src || i == dest) {
            continue;
        }
        lld MAX = inf, key = 0;
        for (lld j = src; j != dest; j = NEXT[j]) {
            if (cost(j, i) + cost(i, NEXT[j]) - cost(j, NEXT[j]) < MAX) {
                MAX = cost(j, i) + cost(i, NEXT[j]) - cost(j, NEXT[j]);
                key = j;
            }
        }
        ans = ans + MAX;
        NEXT[i] = NEXT[key];
        NEXT[key] = i;
    }
    
    
    cout << ans << endl;
    
    return 0;
}

