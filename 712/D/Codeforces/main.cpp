//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/712/problem/D
 题目大意：
 A 和 B玩一个游戏，初始时，A和B的分数为a和b。
 每轮游戏，A和B都可以从[-k, k]的区间里面选择一个整数加到自己的分数。
 问最后有多少种可能，A的分数大于B的分数。
 （只要某一轮A或者B的分数不同，即视为不同的可能）
  
 a, b, k, and t (1 ≤ a, b ≤ 100, 1 ≤ k ≤ 1000, 1 ≤ t ≤ 100)
 
 结果要mod 1 000 000 007 (109 + 7)。
 
 input
 1 2 2 1
 output
 6
 
 Note
 In the first sample test, Memory starts with 1 and Lexa starts with 2. If Lexa picks  - 2, Memory can pick 0, 1, or 2 to win. If Lexa picks  - 1, Memory can pick 1 or 2 to win. If Lexa picks 0, Memory can pick 2 to win. If Lexa picks 1 or 2, Memory cannot win. Thus, there are 3 + 2 + 1 = 6 possible games in which Memory wins.
 

 
 
 题目解析：
 容易知道，每次的选择都是[-k, k]，那么总共就有(2k + 1)个选择；
 t轮之后就是(2k+1)^t个选择。
 接下来考虑去重，存在一轮分数不同，即是在第i轮的时候，选择不同的数字。
 那么，我们用dp[i][j]来表示 前i轮，分数等于j的选择个数。
 这样就可以统计出t轮之后，分数为j的不同选择个数。
 
 先是对A  dp出t次后的结果，再对B dp出t次后的结果。这两个都是O(NK^2)。
 
 最后再对dpB[n][j] 统计下所有∑dpA[n][c]，c > j，然后相乘，得到B为j的时候，A赢的选择数。
 最后累加j = [-k * k / 2, k * k / 2]的和即可。
 
 
 小技巧：
 1、为了方便计算，把所有的状态都加上一个offset，这样-k*k/2 就变成正数，避免dp过程中访问到下标是负的情况；
 2、为了状态转移更快，dpA[i][j] 可以存分数为1到j的和，这样分数为j的值可以通过dpA[i][j] - dpA[i][j - 1]求出。
 
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
const int M = 510010, N = 3, inf = 0x7fffffff;
const lld MOD = 1000000007LL;

lld dpA[N][M];
lld dpB[N][M];

int F(int x) {
    if (x < 0) {
        x = 0;
    }
    else if (x >= M) {
        x = M - 1;
    }
    return x;
}

lld ABS(lld x) {
    return x < 0 ? x + MOD : x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    int offset = M / 2;
    dpA[0][a + offset] = dpB[0][b + offset] = 1;
    for (int i = 1; i < M; ++i) {
        dpA[0][i] += dpA[0][i - 1];
        dpB[0][i] += dpB[0][i - 1];
    }

    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < M; ++j) {
            dpA[i % 2][j] = (dpA[(i - 1) % 2][F(j + k)] - dpA[(i - 1) % 2][F(j - k - 1)]) % MOD;
            dpB[i % 2][j] = (dpB[(i - 1) % 2][F(j + k)] - dpB[(i - 1) % 2][F(j - k - 1)]) % MOD;
            if (j > 0) {
                dpA[i % 2][j] = (dpA[i % 2][j] + dpA[i % 2][j - 1]) % MOD;
                dpB[i % 2][j] = (dpB[i % 2][j] + dpB[i % 2][j - 1]) % MOD;
            }
        }
    }
    
    lld ans = 0;
    for (int j = 0; j < M; ++j) {
        if (dpB[t % 2][j]) {
            lld bTmp = dpB[t % 2][j];
            if (j) {
                bTmp = ABS(dpB[t % 2][j] - dpB[t % 2][j - 1]);
            }
            ans = (ans + (bTmp * ABS(dpA[t % 2][M - 1] - dpA[t % 2][j])) % MOD) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
