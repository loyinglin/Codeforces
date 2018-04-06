//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/760/problem/C
 题目大意：
 n个烤炉排成一行，每个炉子上面都有一串烤肉；
 每一秒之后，第i个烤炉上的烤肉会移动到第p[i]个炉子，同时如果b[i]==1，则烤肉会翻面；
 现在希望，在2*n秒后，每串烤肉的每个面都能经过n个炉子；
 但是给出的p数组和b数组可能无法满足，我们可以修改p数组和b数组，每修改一个数字算一次操作；
 求最少的操作次数以满足条件。
 
 输入数据：
 n (1 ≤ n ≤ 2·1e5)
 p[i]；
 a[i];
 
 Examples
 input
 4
 4 3 2 1
 0 1 1 1
 output
 2
 input
 3
 2 3 1
 0 0 0
 output
 1
 样例解释：第一组样例只需把序列p变成4，3，1，2，操作次数为2；
 第二组样例可以把数组b变成1,0,0，操作次数为1；
 
 
 题目解析：
 对于数组p[i]，可以理解为i->p[i]的一条边；
 这样可以把这个序列，转换一个简单图，每个点有一个边出去；
 那么每串烤肉要经过n个炉子，那么就需要n个炉子都相连，故而是一个环；
 要让每个面都经过n个炉子，只要满足回到原点的时候，面是反的，这样再走一圈即可；
 因为每个点只有一条边，只要对每个点dfs一次，就能统计出来环的数量，环的数量就是要修改的次数；（脑补下两个环合并需要修改的边数）
 要保证回到原点之后，面是反的，就要求n个点的b[i]加起来的sum%2==1；
 综上 只要满足修改之后，只剩下一个环 + sum%2==1，就满足要求。
 
 
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

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != second) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int vis[N];
vector<int> g[N];

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        sum += t;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++ans;
        }
    }
    if (ans == 1) {
        --ans;
    }
    cout << ans + (sum + 1) % 2 << endl;
    
    return 0;
}
