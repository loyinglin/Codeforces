//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1529/problem/C)
 **题目大意：**
 一棵树有n个节点，每一条边有一个价值，等于两边节点的差的绝对值；
 每个节点有两个值l[i]和r[i]，节点的值x[i]需要满足l[i] <= x[i] <= r[i];
 现在问，按照要求分配各个节点的值，这棵树所有边的最大的价值是多少。
 
 **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤250).
 每个样例第一行是整数 𝑛 (2≤𝑛≤1e5)；
 接下来n行，每行两个整数𝑙𝑖  and 𝑟𝑖 (1≤𝑙𝑖≤𝑟𝑖≤1e9).
 接下来n-1行，每行两个整数𝑢  and 𝑣，表示u到v有一条边 (1≤𝑢,𝑣≤𝑛, 𝑢≠𝑣)
 **输出：**
 每一个样例一行，输出最大的价值数。
 
 **Examples**
 **input**
 3
 2
 1 6
 3 8
 1 2
 3
 1 3
 4 6
 7 9
 1 2
 2 3
 6
 3 14
 12 20
 12 19
 2 12
 10 17
 3 17
 3 2
 6 5
 1 5
 2 6
 4 6
 **output**
 7
 8
 62

 
 **题目解析：**
 只考虑一条边的情况，假设两边的节点取值范围是[L1, R1]和[L2, R2]
 可以知道，这条边的价值只有两种情况：(L1 - R2) 或者(R1 - L1）。
 
 对于每一个点，我们存两个值：ans[i][0]表示取节点i的value取最小值的子树价值，ans[i][1]表示取最大值的子树价值。我们从根节点开始遍历这棵树，对于每一个节点u，其ans[u][0]是由多个子树的ans[v][0]+value(u, v)或者ans[v][1]+value(u, v) 组成。
 
 这样只需从根节点1开始dfs整颗树，那么根节点的ans[1][0]或者ans[1][1]就是最大价值。
  
 
 **思考🤔：**
 
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

class Solution {
    static const int N = 200010;
public:
    vector<int> g[N];
    bool vis[N];
    lld val[N][2];
    lld ans[N][2];
    
    void dfs(int u) {
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                dfs(v);
                ans[u][0] += max(ans[v][0] + abs(val[v][0] - val[u][0]), ans[v][1] + abs(val[v][1] - val[u][0]));
                ans[u][1] += max(ans[v][0] + abs(val[v][0] - val[u][1]), ans[v][1] + abs(val[v][1] - val[u][1]));
            }
        }
    }
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 1; i <= n; ++i) {
                g[i].clear();
                vis[i] = 0;
                ans[i][0] = ans[i][1] = 0;
            }
            for (int i = 1; i <= n; ++i) {
//                cin >> val[i][0] >> val[i][1];
                scanf("%d%d", &val[i][0], &val[i][1]);
            }
            for (int i = 0; i < n - 1; ++i) {
                int u, v;
//                cin >> u >> v;
                scanf("%d%d", &u, &v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
            dfs(1);
            cout << max(ans[1][0], ans[1][1]) << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
