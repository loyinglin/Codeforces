//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/734/problem/E
 题目大意：
 n个点的树，树的节点有两种黑色（黑、白），有两个操作：
 1、path（u, v)：表示u到v的最短路径，包括u、v；
 2、paint(v)：u是树上任意点，假如path(u, v)上所有节点的颜色相同，那么u的颜色会change（黑白互换）；
 
 现在给出一棵树和节点颜色，求最少需要几次paint操作，使得树上所有的节点颜色相同。
 n (1 ≤ n ≤ 200 000)
 
 Examples
 input
 11
 0 0 0 1 1 0 1 0 0 1 1
 1 2
 1 3
 2 4
 2 5
 5 6
 5 7
 3 8
 3 9
 3 10
 9 11
 output
 2
 
 题目解析：
 相同的颜色缩点，得到一个黑白交替的树。
 要使得整棵树的节点颜色变成相同，可以找到最长的链，然后对着链的中间节点k，不断进行paint(k)操作即可。
 答案为最长链的长度/2。
 
 要点：并查集缩点+dfs找最长链。
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
const int N = 222222;

int f[N], color[N];
pair<int, int>  p[N];
vector<int> g[N];
int ans;

int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}


/**
 @param u 当前节点
 @param f 父亲节点
 @param len 从父亲节点过来，最多有多少长度
 @return 当前节点往下，最多的长度
 */
int dfs(int u, int f, int len) {
    int ret = 0, maxLen = len;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != f) {
            int chLength = dfs(v, u, maxLen);
            ans = max(ans, maxLen + chLength + 1);
            ret = max(ret, chLength);
            maxLen = max(maxLen, ret);
        }
    }
    
    return ret + 1;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        f[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        p[i].first = u;
        p[i].second = v;
        if (color[u] == color[v]) {
            if (u < v) {
                swap(u, v);
            }
            f[find(u)] = find(v);
        }
    }
    for (int i = 1; i < n; ++i) {
        int u = find(p[i].first), v = find(p[i].second);
        if (u != v) {
//            cout << u << " " << v << endl;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(find(1), 0, 0);
    cout << ans / 2 << endl;
    
    
    return 0;
}
