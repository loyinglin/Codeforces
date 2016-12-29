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
 问题在于，每个卡片必须选x和x+1张，这个在dp过程中无法控制；
 我们只考虑最少的选x张，容易只知道，如果x张可行，那么x-1张可行，具有单调性；
 于是，可以用二分来确定x的大小，现在的问题是给出最小长度x，是否能快速求出x的是否有解；
 容易知道，每个数字只有x/x+1的状态，可以用0/1来表示，1~8的数字状态压缩后，有255种状态；
 dp[i][j] 表示 前i个，状态为j（0101，为1表示对应位数的数字已经选择过）中选择x+1的最大数量；
 状态转移：
 dp[p[k][t]+1][j|(1<<k)]=max(dp[p[k][t]+1][j|(1<<k)],dp[i][j]);  跳转到新的长度，选择x个
 dp[p[k][t]+1][j|(1<<k)]=max(dp[p[k][t]+1][j|(1<<k)],dp[i][j]+1); 选择x+1个
 p[k][t] 存的是数字k的第t个的下标；
 当len=0特殊处理（出现过的颜色的数量）。
 
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
const int N = 1010, inf = 1e9;
int a[N], dp[N][1<<8], num[8];
vector<int> p[8];

int look(int len, int n) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (1 << 8); ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << 8); ++j) {
            if (dp[i][j] != -inf) {
                for (int k = 0; k < 8; ++k) {
                    if ((j & ( 1 << k)) == 0) {
                        int t = num[k] + len - 1;
                        if (t < p[k].size()) {
                            dp[p[k][t] + 1][j | (1 << k)] = max(dp[p[k][t] + 1][j | (1 << k)], dp[i][j]);
                        }
                        ++t;
                        if (t < p[k].size()) {
                            dp[p[k][t] + 1][j | ( 1 << k)] = max(dp[p[k][t] + 1][j | (1 << k)], dp[i][j] + 1);
                        }
                    }
                }
            }
        }
        ++num[a[i]];
    }
    int ans = -inf;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[i][(1<<8) - 1]);
    }
    if (ans == -inf) {
        return -1;
    }
    else {
        return ans * (len + 1) + (8 - ans) * len;
    }
    
    return 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[--a[i]].push_back(i);
    }
    int l = 1, r = n / 8;
    while (r > l) {
        int mid = (l + r + 1) / 2;
        if (look(mid, n) != -1) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    int ans = look(l, n);
    if (ans == -1) {
        ans = 0;
        for (int i = 0; i < 8; ++i) {
            if (p[i].size()) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
