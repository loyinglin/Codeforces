//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1646/problem/D)
 **题目大意：**
 给出一个有n个节点的树，现在可以把1、2、3·····n的整数赋值到每一个节点上；
 一个节点可以被称为good节点，如果它满足：相邻点的数字之和等于自己节点的数字；
 现在需要给每个节点赋值，要求整棵树有尽可能多的good节点，如果有多种方案则输出数字和最小的方案；
 
  **输入：**
 第一行𝑛 (2≤𝑛≤2e5)
 接下来有n-1行，每行两个整数 𝑢 and 𝑣 表示相邻的节点(1≤𝑢,𝑣≤𝑛)
 
 **输出：**
 先输出最多的good节点数和总的数字和；
 接下来n个数字， 𝑤1,𝑤2,…,𝑤𝑛分别表示n个节点的数字 (1≤𝑤𝑖≤109)

 
 **Examples**
 input
 2
 1 2
 output
 2 2
 1 1
 input
 9
 3 4
 7 6
 2 1
 8 3
 5 6
 1 8
 8 6
 9 6
 output
 6 11
 1 1 1 1 1 1 1 3 1

 
 **题目解析：**
 由题目的要求，首先要求是尽可能多的good节点，那么叶子节点肯定都会标位1；
 其次叶子的相邻节点也一定是1（为了满足good节点的要求），如果有节点和两个叶子相邻节点连接，那么这个节点也有机会成为good节点，如下：
 五个连乘一条直线节点：1-1-2-1-1
 
 由此我们知道，每个节点有两种状态isGood=1和0，信息有maxNode子树最大节点数，minWeight子树最小数字和；
 而且我们按照题目可以得到两个状态转移的条件，对于节点u：
 1、假如u是good节点，那么和u相邻的节点一定不是good节点；
 2、假如u不是good节点，那么和u相邻的节点可以是good节点，也可以不是good节点；
 
 由于上面的条件2，我们知道这个题目无法使用贪心的思想，因为贪心需要决策路径是唯一的，但是由于非good节点节点是可以相邻的，导致出现了分支；
 针对这个情况，我们可以用动态规划来解决。
 首先设定好状态，pair<int, int> dp[n][2]：n个节点，每个节点有2个状态，每个节点需要关注两个信息；
 dp[i][0]表示第i个节点不为good的子树最优解，dp[i][1]为第i个节点为good的子树最优解，first是good数，second是子树和；
 再由上面的状态转移条件，可以得到转移方程。
 
 接着从节点1开始dfs，对于每一个节点u和字节点v，计算得到dp[u][0]和dp[u][1]；
 同时需要记录动态规划的决策过程，因为最终答案还要回溯决策，从而得到结果。
 
 **思考🤔：**
 这个题目的输出略微麻烦，但是记录清楚决策分支，再用dfs回溯还是可以解决的。
 
 
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
    vector<int> g[N];
    int vis[N];
    vector<int> last[N];
    int ans[N];
    pair<int, int> dp[N][2]; // dp[i][0]表示第i个节点不为good的子树最优解，dp[i][1]为第i个节点为good的子树最优解，first是good数，second是子树和
    void add_pair(pair<int, int> &x, pair<int, int> &y) {
        x.first += y.first;
        x.second += y.second;
    }
    
    bool cmp_pair(pair<int, int> &x, pair<int, int> &y) {
        return x.first > y.first || (x.first == y.first && x.second < y.second);
    }
    
    void dfs(int u) {
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                dfs(v);
            }
        }
        
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (cmp_pair(dp[v][0], dp[v][1])) {
                add_pair(dp[u][0], dp[v][0]);
                last[u].push_back(0);
            }
            else {
                add_pair(dp[u][0], dp[v][1]);
                last[u].push_back(1);
            }
            add_pair(dp[u][1], dp[v][0]);
        }
        dp[u][1].first += 1; // 自己作为good节点
        dp[u][1].second += g[u].size(); // good节点代价，自重
        
        dp[u][0].second += 1; // 自重
//        cout << u << " " << dp[u][0].first << " " << dp[u][0].second  << " " << dp[u][1].first << " " << dp[u][1].second << endl;
    }
    
    
    void dfs_ans(int u, bool isGood) {
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                dfs_ans(v, isGood ? 0 : last[u][i]);
            }
        }
        
        if (isGood) {
            ans[u] = g[u].size();
        }
        else {
            ans[u] = 1;
        }
    }
    
    


public:
    void solve() {
        int n;
        cin >> n;
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (n == 2) {
            cout << "2 2\n1 1" << endl;
        }
        else {
            dfs(1);
            memset(vis, 0, sizeof(vis));
            if (cmp_pair(dp[1][0], dp[1][1])) {
                cout << dp[1][0].first << " " << dp[1][0].second << endl;
                dfs_ans(1, 0);
            }
            else {
                cout << dp[1][1].first << " " << dp[1][1].second << endl;
                dfs_ans(1, 1);
            }
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
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
 
 */
