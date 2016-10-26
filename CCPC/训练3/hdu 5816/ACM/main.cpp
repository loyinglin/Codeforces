//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 H题。
 有n张卡片A，m张卡片B。卡片A的效果是再摸2张牌，卡片B的效果是造成a[i]点伤害；
 现在将n+m张牌混合随机打乱。
 抽一张牌，当出完抽的所有牌的时候，能造成>=P点伤害的概率。
 P (P<=1000), N and M (N+M<=20)
 样例
 3 1 2
 1 2
 
 1/3
 解释：三张牌，分别是"抽2张牌"、"造成1点伤害"、"造成2点伤害";
 只有第一张为卡片A的时候，才能造成3点伤害；其他两种可能因为无法抽后续卡牌，无法造成3点伤害；
 
 
 
 题目解析：
 d[j] 表示状态为j的合法数量；(j化为01010，1表示当前牌已经选了）
 d[j]，枚举i个伤害牌，放入j中，得到新状态jj
 d[jj] = d[jj] + d[j];
 
 状态j是否合法，取决于当前已选卡片A的数量与卡片B的数量，当A+1>=B的时候，有意义的；(A>=B 表示还能抽一张）
 
 
 
 
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
const lld N = 21, M = 3010100, mod = 1000000007ll;


lld dp[1<<N], f[N * 2]; // 20 * 100w，方便表示规定前n个为卡片A，后m个为卡片B。
int a[N], x[1<<N], y[1<<N], dam[1<<N]; //

void check(int j, int n, int m) {
    x[j] = y[j] = dam[j] = 0;
    for (int i = 0; i < n; ++i) {
        if (j & (1 << i)) {
            ++x[j];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        if (j & (1 << (n + i))) {
            ++y[j];
            dam[j] += a[i+1];
        }
    }
}

inline bool checkMore(int j, int n, int m) {
    return x[j] >= y[j];
}


inline bool checkDamage(int j, int n, int m, int p) {
    return dam[j] >= p;
}

int main(int argc, const char * argv[]) {
    int caseN, ca = 0;
    f[0] = 1;
    for (int i = 1; i <= N; ++i) {
        f[i] = f[i-1] * i;
    }
    cin >> caseN;
    while (caseN--) {
        ++ca;
        int p, n, m;
        scanf("%d%d%d", &p, &n, &m);
        for (int i = 1; i <= m ; ++i) {
            scanf("%d", &a[i]);
        }
        int t = n + m;
        for (int j = 0; j < (1<<t); ++j) {
            dp[j] = 0;
            x[j] = y[j] = dam[j] = 0;
        }
        dp[0] = 1; // 初始合法序列
        for (int j = 0; j < (1<<t); ++j) { // 先枚举卡片A
            if (!dp[j]) {
                continue;
            }
            check(j, n, m);
            if (!(x[j] >= y[j]) || (dam[j] >= p)) {
                continue;
            }
            for (int i = 1; i <= t; ++i) {
                int k = 1 << (i - 1);
                if ((j & k) == 0) { // 不包括第i个卡片
                    int jj = j  + k;
                    dp[jj] += dp[j];
                }
            }
        }
        lld ans = 0;
        for (int j = 1; j < (1<<t); ++j) {
            if (dp[j] && (dam[j] >= p)) {
                ans += dp[j] * f[t - x[j] - y[j]];
            }
        }
        lld fenmu = 1;
        for (int i = 1; i <= t; ++i) {
            fenmu *= i;
        }
        for (int i = t; i > 1; --i) {
            if (ans && ans % i == 0) {
                ans /= i;
                fenmu /= i;
            }
        }
        if (!ans) {
            fenmu = 1;
        }
        cout << ans << "/" << fenmu << endl;
        
    }
    
}
