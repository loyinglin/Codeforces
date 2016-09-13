//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/708/problem/C
 题目大意：输入一棵树。replace操作是去掉树上的一条边，然后添加一条边重新形成一棵树。
 问：对树上每一个节点，是否能通过不超过1次replace操作，让树在去掉这个节点后，剩下所有的子树的大小都不超过n/2。
 
 input
 3
 1 2
 2 3
 output
 1 1 1 
 
 3是n，点数；
 接下来有n-1条边；
 边是u到v；
 
 输出是0和1，0表示不能，1表示可以。
 
 
 
 题目解析：
 容易知道，去掉一个点之后，产生的子树集合从1到n-1都有可能。
 要让所有的子树都不大于n/2，即是要产生2个或以上的集合，并且最大的集合数量小于n/2。
 接下来对replace操作进行抽象。
 贪心可知，replace操作一定发生在最大的子树上。并且是把子树上点最接近n/2的子树，转移成新的子树。
 故而，只要统计每个点上，子树上最接近n/2的子树大小。
 然后在点选中最大一个子树，在这个子树点上判断去掉最近接n/2的节点后，最大的子树是否满足n/2。（需要注意的是，可能从父节点传过来）
 
 父节点的数量为n-num[k].
 
 
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
const int N = 401000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Edge {
    int u, v;
    int next;
}e[N * 2];
int cnt, n;
int pre[N];
int dfn[N];
int child[N]; //以i为根的子树，子树最接近n/2的大小。
int num[N];
int ans[N];
int fat[N];

void addEdge(int u, int v) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].next = pre[u];
    pre[u] = cnt++;
    e[cnt].u = v;
    e[cnt].v = u;
    e[cnt].next = pre[v];
    pre[v] = cnt++;
}

int dfs(int u) {
    dfn[u] = 1;
    int sum = 1;
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (!dfn[v]) {
            sum += dfs(v);
            child[u] = max(child[u], child[v]);
        }
    }
    if (sum <= n / 2) {
        child[u] = max(child[u], sum);
    }
//    cout << u << " num : " << child[u] << endl;
    return num[u] = sum;
}

void look(int u, int father) {
    if (n - num[u] - fat[u] > n / 2) {
        ans[u] = 0;
    }
    pair<int , int> pr[3];
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (v != father) {
            if (num[v] - child[v] > n / 2) {
                ans[u] = 0;
            }
            pr[2] = make_pair(child[v], v);
            sort(pr, pr + 3);
            reverse(pr, pr + 3);
        }
    }
    
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (v != father) {
            fat[v] = max(fat[u], pr[pr[0].second == v ? 1 : 0].first);
            if (n - num[v] <= n / 2) {
                fat[v] = n - num[v];
            }
            look(v, u);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> n;
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    dfs(1);
    
    for (int i = 1; i <= n; ++i) {
        ans[i] = 1;
    }
    
    look(1, -1);
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
