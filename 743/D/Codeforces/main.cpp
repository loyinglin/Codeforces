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
 现在从树中选择两个节点u、v，要求：
 切断u、v与父亲的边，形成两颗子树；
 两个子树不重叠；
 两个子树节点的权值和最大；
 
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
 只要有一个节点存在两个子树，那么有解；
 
 而且可以确定，必然存在这样一个点P：两个最优子树存在与P的两个子树中。
 
 那么维护一个最优子树的值：
 dp[i] 表示i节点为根的树的权值；
 
 
 在进行状态转移的时候，维护一个新的数组：
 top[i] 表示i节点为根的树中，子树权值的最大值；
 top[u] = max(dp[u], top[v])
 
 
 
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
//    cout << u << " dp " << dp[u] << "  tops " << tops[u] << endl;
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
