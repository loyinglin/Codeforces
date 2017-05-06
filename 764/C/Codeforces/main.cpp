//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/764/problem/C
 题目大意：
 一棵树有n个点，每个点有一个颜色值color[i];
 现在要求选择一个点，以这个点作为新的root根节点，要求其root根节点下，每颗子树内的颜色相同，子树与子树之间颜色可以不同；
 
 题目解析：
 先遍历找到一条边(u, v)且u、v两个点的颜色不同，分别进行一次dfs即可。
 
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
