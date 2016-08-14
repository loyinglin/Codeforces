//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/697/problem/D
 题目大意：
 题目解析：
 
 对于点u有的若干个子节点，有：
 如果v是u的子节点，那么starting_time[v] = 所有其他子树的和/2 + starting_time[u] + 1;
 如果u只有一个子树，那么starting_time[v] = starting_time[u] + 1;
 如果u有多个子树，如果先遍历其他子树，再遍历v所在子树，starting_time会加上其他子树的节点和；
 由题目可知，遍历是随机的，那么相对子树v，先遍历某个子树的概率为1/2；
 （如果难以理解，可以枚举abc、abcd的全排列，b在a前面的概率为1/2。
 
 
 
 
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
const int N = 101000, M = 3010100, inf = 10110110;
int sv[N], dfn[N], low[N], cut[N], childs[N];
double ans[N];
int cnt, son, root;
vector<int> g[N];

int dfs(int u, int dep){
    dfn[u] = dep;  //访问时间
    int sum = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(dfn[v] == 0){
            sum += dfs(v, dep + 1);
        }
    }
    return childs[u] = sum;
}

void look(int u){
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (dfn[v] > dfn[u]) {
            ans[v] = ans[u] + 1 + (childs[u] - childs[v] - 1) / 2.0;
            look(v);
        }
    }
    return ;
}




int main(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int k;
        cin >> k;
        g[k].push_back(i);
        g[i].push_back(k);
    }
    dfs(1, 1);
    
//    for (int i = 1; i <= n; ++i) {
//        cout << i << " " << childs[i] << endl;
//    }
    
    ans[1] = 1;
    look(1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}


