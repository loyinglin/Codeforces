//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/767/problem/C
 题目大意：
 小明有一群羊，羊之间用绳子连接起来，最前面的羊由小明牵着，每只羊有一个价值a[i]；
 小明还有两个朋友，他希望和他们平分这群羊，并且三个人至少有一只羊，三个人分到的羊的总价值相同；
 
 小明只能剪断两条绳子，问是否存在合适解？
 如果不存在输出-1；
 如果存在，则输出两只羊的序号，表示应该剪断牵着这两只羊的绳子；
 
 输入数据
 第一行 数字n (3 ≤ n ≤ 1e6)
 接下来n行，每行两个数字x和y；第i行的x表示第i只被第x只羊用绳子牵着（x=0表示被小明牵着），第i行的y表示第i只羊的价值；(-100<=y<=100)
 
 
 Examples
 input
 6
 2 4
 0 5
 4 2
 2 1
 1 1
 4 2
 output
 1 4
 
 
 
 题目解析：
 抽象一下，就是把一棵树分成3部分，并且每部分的节点之和相等。
 
 注意到题目一个很重要的条件，**三个人的价值相同**。
 而且注意到只能减两次，那么必然有一个是子树；
 于是遍历整个树，当遇到一个子树的节点和满足条件时，把这个子树从树中剔除；
 再遍历整棵树，找到另外一颗子树，节点和满足条件即可。
 
 
 优化方案：
 两次dfs合并成一次，当找到被剔除的节点时，return的sum=0即可。
 
 
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
const int N = 1010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;

    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

int a[N], vis[N], partTotal, root;
vector<int> g[N];
int ans1, ans2;

int dfs(int u) {
    vis[u] = 1;
    int sum = a[u];
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            sum += dfs(v);
        }
    }
    
    if (ans1 == 0 && u != root) {
        if (sum == partTotal) {
            ans1 = u;
        }
    }
    return sum;
}


int dfs2(int u) {
    vis[u] = 1;
    int sum = a[u];
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v] && v != ans1) {
            sum += dfs2(v);
        }
    }
    
    if (ans2 == 0 && u != root) {
        if (sum == partTotal) {
            ans2 = u;
        }
    }
    return sum;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 1, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int fat;
        scanf("%d%d", &fat, &a[i]);
        if (fat == 0) {
            root = i;
        }
        else {
            g[fat].push_back(i);
            g[i].push_back(fat);
        }
        sum += a[i];
    }
    if (sum % 3) {
        cout << -1 << endl;
    }
    else {
        partTotal = sum / 3;
        dfs(root);
        memset(vis, 0, sizeof(vis));
        dfs2(root);
        
        if (ans1 && ans2) {
            cout << ans1 << " " << ans2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    
    
    
    
    return 0;
}
