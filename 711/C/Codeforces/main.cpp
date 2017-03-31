//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/711/problem/C
 题目大意：有n棵树排成一行，m种颜料（数字1~m）；
 输入n个数字，表示n棵树当前的颜色（0为uncolor，其他为当前的颜色）；
 树的排列顺序有一个魅力值， 连续的相同颜色值算1点魅力值，例如：
 树的颜色排列为 [2, 1, 1, 1, 3, 2, 2, 3, 1, 3]，其魅力值为7，分别如下：
 {2}, {1, 1, 1}, {3}, {2, 2}, {3}, {1}, {3}
 
 如果树的颜色是uncolor，代表可以染色；
 输入n*m个数字，表示第i颗树染色成第j种颜色的代价cost[i][j];
 

 问，如果要把树的魅力值变为k，需要的最小代价是多少？（如果无解，输出-1）
  
 n, m and k (1 ≤ k ≤ n ≤ 100, 1 ≤ m ≤ 100)
 
 >###Example
 ####input
 3 2 2
 0 0 0
 1 2
 3 4
 5 6
 ####output
 10
 ####input
 3 2 2
 2 1 2
 1 3
 2 4
 3 5
 ####output
 -1
 
 
 题目解析：
 
 从给出的数据范围来看，容许时间复杂度比较大的做法。
 从给出的选择来看，每次的抉择只有uncolor的树，假设要染色的树是i，大概的类别有：
 1、color[i-1] != color[i+1]，这时color[i]可以等于color[i-1]或者color[i+1]，或者都不相同；
 2、color[i-1] == color[i+1]，这时color[i]可以等于color[i-1]和color[i+1]，或者都不相同；
 因为题目要求的是特定的魅力值，故而不能用贪心的做法。
 考虑用动态规划来做，
 dp[i][j[k] 表示前i个，color为j，最后一个为颜色k的最小代价；
 对于第i颗树，color为j的状态，考虑以下的状态：
 1、color[i] != 0，不能染色，那么j=color[i]的状态，可以通过dp[i-1]的状态中获得最小代价；
 1、color[i] != 0，不能染色，那么j!=color[i]的状态，不合法，忽略；
 1、color[i] == 0，能染色，那么枚举j的状态，从dp[i-1]转移即可。
 具体的转移方程较多，可以见代码。
 
 
 思考🤔：
 如果把k去掉，改成最大值，是一道不错的面试题。
 
 
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
