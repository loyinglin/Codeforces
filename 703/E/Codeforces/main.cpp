//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/703/problem/E
 题目大意：n个数字，从中选取m个数字，使得乘积S被k整除。如果有多个组合，m最小；还有多个，S最小。(1 ≤ n ≤ 1 000, 1 ≤ k ≤ 10e12).
 题目解析：
 求出k的所有非1因子集合T，那么对于数字a[i]，不为T的因子没有用。
 那么题目变成：
 一堆物品，每个物品都有相应的cost（数量，大小），要把背包背满（可以超过），使得总数量最小，并且总数字和最小。
 题目非常明显的是DP。
 
 
 d[i][j][k] 表示前i个数字，第j个因子有k个的最小总数和最小数字和。
 最后在所有 d[n][j][k] 中第j个因子中，k大于题目要求中，寻找最小值即可。
 
 d[i][j][k] 根据第i个数的因子，有：
 d[i][j][k] = min(d[i - 1][j][k], d[i-1][j-s][k-t]) s、t取决于k的第j个因子的个数。
 
 状态复杂度n*k的因子数K，10^12的因字数不会超过45个，按50个算。那么状态数最大为 50000个。
 转移复杂度为O（1）。
 那么总得复杂度O(N * K).
 
 
 这种做法的难点在于，对于一个数字，转移的时候无法通过一个式子来表达。（一个数字有多个参数）
 
 换一种dp的表示方式。
 求出K的所有约数，15=1,2,3,5,15。
 于是，一个数的状态可以表示成从左到右的移动。
 dp[i][j]表示前i个数字，能前进到第j个的最优解。
 dp[i][j] = min(dp[i-1][j], dp[i-1][j/gcd(k, x)] + 1);
 题目可解。复杂度O(N*K). K为因子个数
 
 卡在某个地方很久：
    b[i] = gcd(a[i], k);
 可以优化，减少gcd的复杂度。
 
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;

#define N 1005
#define K 10000
#define inf 0x7fffffff

pair<int, long long>  dp[N][K]; // 注意判断边界
map<long long, int> Hash;
vector<long long> vec;
long long b[N];
long long a[N];

inline long long gcd(long long x, long long y) {
    long long r;
    while(y > 0)
    {
        r=x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    long long k;
    cin >> n >> k;
    long long t = sqrt(k);
    
    for (long long i = 1; i <= t; ++i) {
        if (k % i == 0) {
            vec.push_back(k / i);
            vec.push_back(i);
        }
    }
    int vecSize = vec.size();
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vecSize; ++i) {
        Hash[vec[i]] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = gcd(a[i], k);
    }
    if (k == 1)
    {
        cout << 1 << endl;
        cout << min_element(a + 1, a + 1 + n) - a << endl;
        return 0;
    }
    
    for (int j = 1; j < vecSize; ++j) {
        dp[0][j] = make_pair(n + 1, 0);
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < vecSize; ++j) {
            long long gcdnum = gcd(b[i], vec[j]);
            int pre = Hash[vec[j] / gcdnum];
            
            dp[i][j] = min(dp[i - 1][j], make_pair(dp[i - 1][pre].first + 1, dp[i - 1][pre].second + a[i]));
        }
    }
    
    
    if (dp[n][vecSize - 1].first > n) {
        cout << -1 << endl;
        return 0;
    }
    else {
        cout << dp[n][vecSize - 1].first << endl;
        int pre = vecSize - 1;
        for (int i = n; i > 0; --i) {
            if (dp[i][pre] == dp[i - 1][pre]) {
                continue;
            }
            printf("%d ", i);
            pre = Hash[vec[pre] / gcd(vec[pre], b[i])];
        }
    }
    
    
    
    return 0;
}
