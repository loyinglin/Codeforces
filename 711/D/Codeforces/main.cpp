//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/711/problem/D
 题目大意：n个点，每个点有一条从其出发的有向边，现在可以选择一个边的集合，对集合的每条边进行一个翻转的操作，要求让n个点没有形成环。问有多少种集合可能。
 
 n (2 ≤ n ≤ 2·10e5)
 MOD = 10e9 + 7.
 
 input
 3
 2 3 1
 output
 6
 
 
 题目解析：
 每个点初始状态只有一条有向边，那么每个环都是简单的环（没有重叠的环）。
 那么把所有的点分成两种，环上的点，环外的点。
 不在环上的点有k个，那么有2^k个选择。
 第i个环的数量为num[i]，有2^num[i] - 2个选择。（全选和全不选）
 结果之乘积就是答案。
 
 
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
const int N = 201000;
const lld MOD = 1e9+7LL;


lld a[N];
lld dfn[N];
lld dep, last;
lld num;
lld ans;
lld POWER[N];
//
//lld POWER(lld x) {
//    if (x <= 0) {
//        return 1;
//    }
//    else if (x == 1) {
//        return 2;
//    }
//    else {
//        lld ret = (POWER(x / 2) * POWER(x / 2)) % MOD;
//        if (x % 2) {
//            ret = (ret * 2) % MOD;
//        }
//        return ret;
//    }
//}

lld ABS(lld x) {
    return (x + MOD) % MOD;
}

void dfs(lld u) {
    dfn[u] = ++dep;
    if (!dfn[a[u]]) {
        dfs(a[u]);
    }
    else {
        if (dfn[a[u]] > last) {
            lld k = dfn[u] - dfn[a[u]] + 1;
            num += k; // 环上的数量
            ans = (ans * ABS(POWER[k] - 2)) % MOD;
        }
    }
}


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    POWER[0] = 1;
    for (int i = 1; i <= n; ++i) {
        POWER[i] = (POWER[i - 1] * 2) % MOD;
    }
    
    ans = 1;
   
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            last = dep;
            dfs(i);
        }
    }
    
    ans = (ans * POWER[n - num]) % MOD;
    
    cout << ans << endl;
    
    return 0;
}
