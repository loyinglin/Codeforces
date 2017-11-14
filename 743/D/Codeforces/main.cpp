//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/743/problem/D
 题目大意：
 n个节点的树，1为根；
 每个节点有权值a[i]；
 现在要求从树中选择两个节点u、v，切断u、v与父亲的边，形成两颗子树，满足条件：
 1、两个子树不重叠；
 2、两个子树节点的权值和最大；
 
 (1<=n<=2e5, -1e9 ≤ a[i] ≤ 1e9)
 如果存在，输出权值和；不存在输出-1；
 
 Examples
 input
 8
 0 5 -1 4 3 2 6 5
 1 2
 2 4
 2 5
 1 3
 3 6
 6 7
 6 8
 output
 25
 input
 4
 1 -5 1 1
 1 2
 1 4
 2 3
 output
 2
 input
 1
 -1
 output
 Impossible
 
 
 题目解析：
 容易知道，只要有一个节点存在两个子树，那么有解；
 在有解的情况下，必然存在这样一个点P：两个最优子树T1和T2，都是点P的子树。
 
 那么维护一个最优子树的值：dp[i] 表示i节点为根的子树，子树的权值和；
 同时在进行状态转移的时候，维护一个新的数组：top[i] 表示i节点为根的树，其所有子树中，子树权值和的最大值；
 那么对于节点u和子节点v，有top[u] = max(dp[u], top[v])；（dp[u]表示以节点u为根的子树权值和，top[v]是u的子树的最大权值和）；
 
 并且对于节点u，如果有多个子节点v，那么只需保留最大的两个top[v]即可。
 
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
const int N = 201010;
lld tops[N], a[N], dp[N];
vector<int> g[N];
lld ans = -1e15;

void dfs(int u, int fat) {
    dp[u] = a[u];
    multiset<lld> childs;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != fat) {
            dfs(v, u);
            dp[u] += dp[v];
            tops[u] = max(tops[u], tops[v]);
            childs.insert(tops[v]);
            if (childs.size() == 3) {
                childs.erase(childs.begin());
            }
            if (childs.size() == 2) {
                ans = max(ans, *childs.begin() + *(++childs.begin()));
            }
        }
    }
    tops[u] = max(tops[u], dp[u]);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tops[i] = -1e15;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    if (ans != -1e15) {
        cout << ans << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    
    
    return 0;
}
