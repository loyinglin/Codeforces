//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/723/problem/E
 题目大意：
 n个点（n=200），m条无向边，没有重边和指向自己的边；
 现在把无向边改成有向边，要求入度等于出度的点最多。
 输入：
 t，表示样例个数。
 每个样例先输入n，m，再输入m条边；
 
 输出：
 先满足要求的点数，再输出所有边(u，v）u=>v。
 
 Example
 input
 2
 5 5
 2 1
 4 5
 2 3
 1 3
 3 5
 7 2
 3 7
 4 2
 output
 3
 1 3
 3 5
 5 4
 3 2
 2 1
 3
 2 4
 3 7
 
 样例解释：
 样例1：3个点，分别是1、2、5。
 样例2：3个点，分别是1、5、6。
 
 
 题目解析：
 这个题目需要一点脑洞。
  如果一个联通图里，所有点的度数都是偶数，那么存在一条回路，使得所有点的点的入度=出度。
 这也是无向图存在欧拉回路的充要条件：
 一个无向图存在欧拉回路，当且仅当该图所有顶点度数都为偶数,且该图是连通图。
 
 接下来就是要开脑洞的时候：某个点如果是奇数，那么和一个虚拟的点0连接。
 那么会得到一个无向图，并且所有点的度数都是偶数的无向图。（因为度数为奇数的点的数量必然是偶数）
 
 对每个点遍历一次（dfs），标出有向边即可。
 满足要求的点数，就是度数为偶数的点数。
 
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
const int N = 222;

int g[N][N];
int vis[N][N];
int n, m;
int dg[N];

void dfs(int u) {
    for (int v = 0; v <= n; ++v) {
        if (g[u][v] && !vis[u][v]) {
            vis[u][v] = 1;
            vis[v][u] = -1;
            dg[u]--;
            dg[v]--;
            dfs(v);
        }
    }
}

void look(int u) {
    dfs(u);
}

int main(int argc, const char * argv[]) {
    int ca;
    cin >> ca;
    while (ca--) {
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        memset(dg, 0, sizeof(dg));
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u][v] = g[v][u] = 1;
            dg[u]++;
            dg[v]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dg[i] % 2 == 0) {
                ++ans;
            }
            else {
                g[0][i] = g[i][0] = 1;
                ++dg[0];
                ++dg[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            dfs(i);
        }
        cout << ans << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (vis[i][j] == 1) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    
    return 0;
}

/**
 4333
 
 5 6
 1 2
 2 3
 3 1
 1 4
 4 5
 5 2
 
 
 9 12
 1 2
 1 8
 2 3
 2 9
 3 4
 4 9
 4 5
 5 6
 6 9
 6 7
 7 8
 8 9
 
 
 */
