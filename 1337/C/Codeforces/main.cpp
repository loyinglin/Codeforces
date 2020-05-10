//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1337/problem/C)
 **题目大意：**
 有n个城市，用n-1条道路相连，并且保证任意两个城市之间都可以通过道路相连；
 作为女王，小明需要选出k个城市作为工业城市，剩下的n-k个城市作为旅游城市。
 城市1是首都，现在要召开工业会议，每个工业城市都会派出一个使者到城市1参加会议，使者会沿着道路按照最短的路径直接到达城市1，使者的快乐值等于沿途经过的旅游城市的数量。

 小明想知道，如何选择工业城市，使得所有使者的快乐值总和最大？
 （城市1可以是工业城市，也可以旅游城市）
 **输入：**
 第一行，整数 𝑛 and 𝑘 (2≤𝑛≤2⋅105, 1≤𝑘<𝑛)
 接下来n-1行，每行两个整数 𝑢 and 𝑣 ，表示城市u和城市v之间有一条道路 (1≤𝑢,𝑣≤𝑛)
 
 **输出：**
 一个整数，表示所有使者的快乐值总和的最大值；
 
 **Examples**
 input
 7 4
 1 2
 1 3
 1 4
 3 5
 3 6
 4 7
 output
 7
 input
 4 1
 1 2
 1 3
 2 4
 output
 2
 
 
 **题目解析：**
 一开始是用贪心的思路：先dfs遍历，记录每个点的深度和子节点的数量；
 按照深度，从大到小排序，再按子节点的大小，从小到大排序；
 然后，从深度最大的开始，填充节点；相同深度，优先填充子节点少的；
 最后再遍历一遍，得到结果。 复杂度NlogN。

 提交之后，喜提一个Wrong Answer。
 
 重新思考：正确的做法是评估，每一个点的价值和代价，上面只考虑了价值，忽略了代价的问题。
 
 
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
const int N = 200010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second, val, cost;
    
    bool operator<(const Node &tmp) const
    {
        if (cost != tmp.cost) return cost > tmp.cost;
        else return second > tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool cmp(int a, int b) {
    return a > b;
}

vector<int> g[N];
int vis[N];

void dfsCount(int u, int dep) {
    node[u].first = dep;
    node[u].val = u;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            dfsCount(v, dep + 1);
            node[u].second += node[v].second + 1;
        }
    }
    node[u].cost = dep - node[u].second;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsCount(1, 0);
    sort(node + 1, node + n + 1);
    
    lld sum = 0;
    for (int i = 1; i <= k; ++i) {
        sum = sum + node[i].cost;
    }
    cout << sum << endl;
    
    return 0;
}

/**
 
 9 4
 1 2
 1 3
 1 4
 3 5
 3 6
 4 7
 6 8
 7 9
 
 1 2 3 4 5 6 7
 1 8
 
 8 4
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 1 8
 
 */
