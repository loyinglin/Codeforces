//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1905/problem/B)
 **题目大意：**
给出一个n个节点的树，现在每次可以选择两个节点，将两个节点之间的最短路径上，所有节点都合并成一个节点，类似下图的操作：
 ![如图](https://espresso.codeforces.com/17652d819e3f2befc596f790b49c7268c923236b.png)
 和原来节点相连的边，改为和新合并成的点相连。
 
 问，最少要进行多少次操作，剩下的节点只有1个。

 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例第一行，整数 𝑛   (2≤𝑛≤100000)
 接下来n-1行，整数 𝑢𝑖 and 𝑣𝑖 ，表示两个点之间存在一条边  (1≤𝑢𝑖,𝑣𝑖≤𝑛,𝑢𝑖≠𝑣𝑖 )
 
 **输出：**
 每个样例一行，输出满足要求的最小操作次数。
 
 
 **Examples**
 **input**
 4
 4
 1 2
 1 3
 3 4
 9
 3 1
 3 5
 3 2
 5 6
 6 7
 7 8
 7 9
 6 4
 7
 1 2
 1 3
 2 4
 4 5
 3 6
 2 7
 6
 1 2
 1 3
 1 4
 4 5
 2 6

 **output**
 1
 3
 2
 2


 **题目解析：**
 题目给出来的图，就比较好分析。
 每次操作都会减少若干个节点，最终是从n个节点变成1个节点，这是一个节点数量单调递减的过程。
 那么可以知道，每次应该尽可能多的去选择节点，比如说从根节点到叶子节点作为一条路径，我们每次选择两条最长的路径，组成一条当前树上的最长路径，进行合并。
 但是这种做法，如何证明就是最优解？有没有可能局部最优会破坏全局最优。
 在思索和这个过程的时候发现，沿着上面的思路，每次选择两条到叶子节点的路径，融合之后就会减少一个叶子节点。当不存在叶子节点的时候，就只剩下一个节点。
 这个过程的最优性也比较容易保证，对于有m个叶子节点的树，每次操作只能减少2个叶子节点。最优解就是m/2。
 
 剩下的问题，就是如何确定根节点？
 答案就是不需要根节点，从任意点出发，只有一个点相连就是叶子节点，计算叶子节点数量即可。
 
 

 
 
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
    static const int N = 201010;
    vector<int> g[N];
    int dfs(int u, int fat) {
        int ret = g[u].size() == 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v == fat) continue;;
            ret += dfs(v, u);
        }
        return ret;
    }
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i <= n; ++i) g[i].clear();
            for (int i = 1; i < n; ++i) {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            cout << (dfs(1, 0) + 1) / 2 << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
