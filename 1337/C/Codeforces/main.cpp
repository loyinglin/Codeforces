//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1337/problem/C)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，整数𝑥 , 𝑛, 𝑚 (1≤𝑥≤10^5, 0≤𝑛,𝑚≤30)
 
 **输出：**
 每个样例一行，如果小明可以打败恶龙，输出YES；如果无法打败，则输出NO；
 
 **Examples**
 input
 7
 100 3 4
 189 3 4
 64 2 3
 63 2 3
 30 27 7
 10 9 1
 69117 21 2
 output
 YES
 NO
 NO
 YES
 YES
 YES
 YES
 
 
 **题目解析：**
 dfs遍历，记录每个点的深度和子节点的数量；
 按照深度，从大到小排序，再按子节点的大小，从小到大排序；
 然后，从深度最大的开始，填充节点；相同深度，优先填充子节点少的；
 最后再遍历一遍，得到结果。
 
 复杂度NlogN。
 
 喜提一个wa。。
 
 
 正确的做法是评估，每一个点的价值和代价，上面只考虑了价值，忽略了代价的问题。
 
 
 **思考🤔：**
 贪心！
 
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
