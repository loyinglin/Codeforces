//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1831/problem/C)
 **题目大意：**
 有n个节点的树，节点序号为1、2、3、、、n，现在小明开始用下面的方式开始绘制整棵树：
 1、先绘制节点1；
 2、按照边输入的顺序遍历，对于每一条边，如果存在一个节点已经绘制且另外一个节点没绘制，则绘制未存在的节点；
 3、遍历完成后，检查是否所有节点已经绘制完成，否则重新操作2；
 
 现在想知道，需要遍历多少次，才能绘制完所有节点；
 
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 接下来n-1行，每行有整数𝑢𝑖 and 𝑣𝑖 (1≤𝑢𝑖,𝑣𝑖≤𝑛 , 𝑢𝑖≠𝑣𝑖 )
   
 **输出：**
 对于每个样例，输出需要遍历的次数；
 
 **Examples**
 **input**
 2
 6
 4 5
 1 3
 1 2
 3 4
 1 6
 7
 5 6
 2 4
 2 7
 1 3
 1 2
 4 5
 
 **output**
 2
 3
 
 
 **题目解析：**
 先考虑简单的情况，假设4个节点，假如边顺序是：
 1 2
 2 3
 3 4
 那么结果，只要遍历一次即可；
 
 如果边顺序是：
 3 4
 2 3
 1 2
 则结果需要3次，因为每次遍历完都只能绘制1个节点；
 
 如果边顺序是：
 1 2
 3 4
 2 3
 则结果需要2次，第一次遍历可以产生1、2、3节点，第二次遍历则产生节点4；
 
 观察这个过程，就是从节点1开始遍历，当遇到下一个节点就有两个抉择：
 1、下个节点可以直接绘制，因为连接下一个节点的边，比当前节点要更晚；
 2、下个节点需要等下一次遍历，因为连接下一个节点的边，比当前节点要更早；
 
 通过上面这个方式，我们只需要遍历一次，就可以快速知道一条链路上，需要遍历多少次才能绘制完成；
 
 当我们知道一条链路的解法之后，对于一个棵树，其实就是不断重复根节点到叶子节点的dfs过程。
 
 
 
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
    map<pair<int, int>, int> h;
    int dfs(int u, int father) {
        int ret = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v != father) {
                ret = max(ret, dfs(v, u) + (h[make_pair(u, father)] > h[make_pair(u, v)]));
            }
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
            h.clear();
            for (int i = 1; i <= n; ++i) g[i].clear();
            for (int i = 1; i < n; ++i) {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
                h[make_pair(u, v)] = i;
                h[make_pair(v, u)] = i;
            }
            int ans = 0;
            for (int i = 0; i < g[1].size(); ++i) {
                ans = max(ans, dfs(g[1][i], 1));
            }
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
