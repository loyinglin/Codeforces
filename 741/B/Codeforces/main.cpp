//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/741/problem/A
 题目大意：
 n个物品，每个物品有选中代价cost[i]和价值value[i];
 同时有m个关系，每个关系由u和v组成，表示u和v是同一组内；
 限制：每一组只能选一个，或者全部选；
 现在有一个容量为w的背包，希望选出最大价值的物品组合放入；
 (1  ≤  n  ≤  1000, , 1 ≤ w ≤ 1000)
 
 题目解析：
 如果不考虑限制，就是普通的背包；
 加上限制，就是一个分组背包；
 
 
 
 
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
const int N = 1010;

int dp[N], c[N], v[N], f[N];

int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

int main(int argc, const char * argv
         []) {
    int n, m, w;
    cin >> n>> m >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        f[i] = i;
    }
    for (int i = 1; i <= n;  ++i) {
        cin >> v[i];
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            if (v[f[x]] * c[f[y]] >= v[f[y]] * c[f[x]]) {
                f[f[y]] = f[x];
            }
            else {
                f[f[x]] = f[y];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w; j >= c[i]i; --j) {
            <#statements#>
        }
    }
    
    
    
    
    
    
    return 0;
}
