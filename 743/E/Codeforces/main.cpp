//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/743/problem/E
 题目大意：
 有若干个卡片排成1行，上面有数字1~8，现在要找到最长的子序列，满足：
 1、所有相同数字的卡片数量和c[i]，满足i,j∈[1,8]，|c[i] - c[j]| <= 1;
 2、相同的数字卡片必须是连续的；比如说[1,1,2,2]是合法的, [1,2,2,1]是不合法的；
 
 求出最长的子序列。
 n (1 ≤ n ≤ 1000)
 Examples
 input
 3
 1 1 1
 output
 1
 input
 8
 8 7 6 5 4 3 2 1
 output
 8
 
 题目解析：
 子序列，n又小，状态也少，看起来像动态规划。
 dp[i][j][k] 表示 前i个，状态为j（0101，为1表示对应位数的数字已经选择），当前数字为k的最长子序列。
 总共有1000 * 2^8 * 8 = 1000 * 2048 = 2e6 的复杂度；
 转移为O(1)。
 
 
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
int a[N], dp[N][1 << 8][9], ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < (1 << 8); ++j) {
            int mask = 1 << (a[i] - 1);
            if (j & mask) {
                dp[i][j][a[i]] = dp[i - 1][j][a[i]] + 1;
                ans = max(ans, dp[i][j][a[i]]);
            }
            else {
                dp[i][j|mask][a[i]] = dp[i - 1][j][a[i]] + 1;
                ans = max(ans, dp[i][j|mask][a[i]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
