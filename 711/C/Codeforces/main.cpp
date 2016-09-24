//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/711/problem/C
 题目大意：n棵树，现在有m种颜料（数字1~m），输入n个数字，表示n棵树当前的颜色（0为uncolor，其他为当前的颜色）；
 输入n*m个数字，表示第i颗树染色成第j种颜色的代价cost[i][j];
 连续的相同颜色值算1次，问出现k次 的最小代价是多少？（无解输出-1）
 
 序列 2, 1, 1, 1, 3, 2, 2, 3, 1, 3 的次数为7，如下：
  {2}, {1, 1, 1}, {3}, {2, 2}, {3}, {1}, {3}
 
 
 input
 3 2 2
 0 0 0
 1 2
 3 4
 5 6
 output
 10
 
 
 input
 3 2 2
 2 1 2
 1 3
 2 4
 3 5
 output
 -1
 
 
 题目解析：
 
 dp[i][j[k] 表示前i个，color为j，最后一个为颜色k的最小代价；
 对于状态dp[i][j][k]，枚举前面状态的转移即可。
 考虑1，
 
 
 
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
const int N = 110;
const lld llinf = 0x7fffffff7fffffffll;
lld a[N];
lld cost[N][N];
lld dp[N][N][N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int z = 0; z <= m; ++z) {
                dp[i][j][z] = llinf;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int z = 0; z <= m; ++z) {
        dp[0][0][z] = 0;
    }
    dp[0][1][a[1]] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int z = 1; z <= m; ++z) {
                if (a[i] == z) { // 颜色相同，可以选择不染色或者选择染色
                    dp[i][j][z] = dp[i - 1][j][z]; // 不染色，和前面的一样
                    if (a[i] == 0) {
                        for (int t = 0; t <= m; ++t) { // 染成和前面不同的颜色
                            if (t != z) {
                                dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][t] + cost[i][z]);
                            }
                        }
                    }
                    else {
                        for (int t = 0; t <= m; ++t) {
                            if (t != z) {
                                dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][t]);
                            }
                        }
                    }
                }
                else { // 颜色不相同，必须染色
                    if (a[i] == 0) {
                        dp[i][j][z] = dp[i - 1][j][z] + cost[i][z]; // 染成和前面一样的颜色
                        for (int t = 0; t <= m; ++t) { // 染成和前面不同颜色
                            if (t != z) {
                                dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j - 1][t] + cost[i][z]);
                            }
                        }
                    }
                    else {
                        // 无能为力
                    }
                }
            }
        }
    }
    
    lld ans = llinf;
    for (int z = 1; z <= m; ++z) {
        ans = min(ans, dp[n][k][z]);
    }
    if (ans == llinf) {
        ans = -1;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
