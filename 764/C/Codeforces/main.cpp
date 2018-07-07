//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/764/problem/C
 题目大意：
 一棵树有n个点，序号是1~n，每个点有一个颜色值color[i];
 现在要求选择一个点，以这个点作为新的root根节点，要求其root根节点下，每颗子树内的颜色相同（子树与子树之间颜色可以不同）；
 如果可以则输出YES，然后再输出点序号；
 如果不可以则单独输出NO。
 
 输入：
 n (2 ≤ n ≤ 1e5)
 颜色值 c1, c2, ..., cn (1 ≤ ci ≤ 1e5)
 
 **Examples**
 **input**
 4
 1 2
 2 3
 3 4
 1 2 1 1
 **output**
 YES
 2
 
 题目解析：
 题目要求子树内颜色相同，那么对于边(u, v)，如果u和v的颜色不同，那么有三种可能：
 1、以u为根；
 2、以v为根；
 3、无解；
 
 接下来的问题是，如何判断以u为根的情况是否满足题意？
 以u为根，对每个子树进行一次dfs，判断是否子树的颜色相同，即可。
 
 
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<int> g[N];
int a[N];
int vis[N];

bool dfs(int u, int color) {
    vis[u] = 1;
    if (a[u] != color) {
        return false;
    }
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            if (!dfs(v, color)) return false;
        }
    }
    return true;
}

bool check(int x) {
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int t = g[x][i];
        if (!dfs(t, a[t])) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int x = -1, y = -1;
    for (int i = 0; i < n && x == -1; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (a[i] != a[g[i][j]]) {
                x = i;
                y = g[i][j];
                break;
            }
        }
    }
    if (x == -1) {
        cout << "YES" << endl << 1 << endl;
    }
    else {
        if (check(x)) {
            cout << "YES" << endl << x << endl;
        }
        else if (check(y)) {
            cout << "YES" << endl << y << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
