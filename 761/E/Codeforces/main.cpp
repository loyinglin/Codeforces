//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/761/problem/E
 题目大意：
 有一棵n个点的树，已知n个点之间的相连关系，现在需要把树的节点放到一个二维坐标轴上（保持树的结构）
 要求边和x/y轴平行，边没有重叠；
 
 输入：
 第一行n
 接下来n-1行，分别是ui 和 vi,表示 点ui和vi相连，ui, vi (1 ≤ ui, vi ≤ n)
 
 输出
 如果无解，输出NO；
 如果有解，先输出YES，接下来n行，分别输入n个点的坐标
 并且坐标[xi, yi] 满足 (|xi|, |yi| ≤ 1e18)
 
 n (1 ≤ n ≤ 30)
 xi, yi (|xi|, |yi| ≤ 1e18)
 
 Examples
 input
 7
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 output
 YES
 0 0
 1 0
 0 1
 2 0
 1 -1
 -1 1
 0 2
 input
 6
 1 2
 2 3
 2 4
 2 5
 2 6
 output
 NO
 
 
 
 题目解析：
 
 容易知道，如果某个点的边超过5个，那么必然是无解。
 其他情况下，因为给出的xi,yi的范围很大，肯定是有解的。
 先假定点1为root，其他点为子节点，来观察题目的trick所在：
 1、子节点中的数目不定，不好分配具体的先后顺序；
 2、要避免多个子节点直接相互交错；
 3、避免多子节点与到之前的父节点的边存在交错；
 
 如果从叶子节点到根节点的分配坐标，叶子节点的坐标分配需要知道父节点的坐标；
 那么我们可以先假定父节点的坐标为(fx, fy)，子节点的坐标就在(fx, fy)的基础上进行调整；
 沿着这个思路，我们需要保证子节点的坐标和父节点的坐标保持一定的距离；
 观察到点只有30个，给出的范围比较大，我们可以采用每次给节点分配2^i的距离：
 这样保证多个子节点不会交错，并且不会与父节点交错；（因为2^0 + 2^1 + ... + 2^i < 2^i+1;
 最大的点坐标为2^31 - 1，在合理范围内。
 故而，是一种合理的解法。
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<int> g[N];
int vis[N];
pair<lld, lld>  ans[N];
int dir[][2] ={
    -1, 0,
    1, 0,
    0, -1,
    0, 1,
};

bool dfs(int u, lld cur, int lastDir, lld x, lld y) {
    bool ret = true;
    vis[u] = 1;
    ans[u] = make_pair(x, y);
    int mp[4] = {0};
    if (lastDir != -1) {
        mp[lastDir] = 1;
    }
    for (int i = 0; i < g[u].size() && ret; ++i) {
        int v = g[u][i];
        if (vis[v]) {
            continue;
        }
        int k = -1;
        for (int j = 0; j < 4; ++j) {
            if (!mp[j]) {
                k = j;
                break;
            }
        }
        if (k != -1) {
            mp[k] = 1;
            ret = ret && dfs(v, cur >> 1, k ^ 1, x + cur * dir[k][0], y + cur * dir[k][1]);
        }
        else {
            return false;
        }
    }
    return ret;
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
    
    if (dfs(1, 1LL << 30, -1, 0, 0)) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

/*
 7
 1 2
 2 3
 3 4
 3 5
 3 6
 6 7
 */
