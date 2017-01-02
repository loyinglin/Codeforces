//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/745/problem/C
 题目大意：
 给出一个图，n个点，m条边，其中k个点为关键点；
 现在在图上加边，要求：
 1、关键点之间不能存在路径；
 2、不能存在自环、多重边；
 问，最多能加多少边。
 
 Examples
 input
 4 1 2
 1 3
 1 2
 output
 2
 input
 3 3 1
 2
 1 2
 1 3
 2 3
 output
 0
 n, m and k (1 ≤ n ≤ 1 000, 0 ≤ m ≤ 100 000, 1 ≤ k ≤ n)
 
 
 题目解析：
 添加的边不能产生关键点之间的路径，那么可以换一种思路：
 对于和关键点已经相连的点，缩成一点；
 那么总共会有k个关键点，还有若干个（假设是x）独立点；
 sum[i]表示关键点i的点的数量（缩点），假设y=max(sum[i]);
 此时能加多的边：
 关键点构建成完全图；
 独立点构建成完全图；
 独立点集和最大的关键点两两相连；
 
 记得计算的过程中减去所有已有的边。
 
 
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
const int N = 10100;

int f[N], sum[N], flag[N], edge[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        sum[i] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        int t;
        cin >> t;
        flag[t] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) {
            if (flag[f[v]]) {
                swap(u, v);
            }
            sum[f[u]] += sum[f[v]];
            if (sum[f[u]] > n) {
                cout << "why " << u << " " << v << " " << i << endl;
            }
            f[f[v]] = f[u];
        }
    }
    int ans = -m, maxSum = 0, total = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == find(i)) {
//                        cout << i << " sum " << sum[i] << " flag " << flag[i] << " edge " << edge[f[i]] << endl;
            if (flag[i]) { // 关键点
                int x = sum[f[i]];
                ans += x * (x - 1) / 2; // 完全图减去已有的图
                maxSum = max(maxSum, x);
            }
            else { // 独立点
                total += sum[i];
            }
        }
    }
//        cout << "total " << total << " maxSum " << maxSum << endl;
    ans += (total + maxSum) * (total + maxSum - 1) / 2 - maxSum * (maxSum - 1) / 2 ;
    
    if (ans < 0) {
        cout << ans << " " << total << " " << maxSum << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}

/**
 
 5 4 1
 4
 1 2
 2 3
 3 1
 2 4

 
 
 
 **/
