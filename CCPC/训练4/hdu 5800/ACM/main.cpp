//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 　给定一个由n个元素组成的序列,和s (n<=1000,s<=1000)
 
 f (i，j，k，l，m) 指必定选第i，j号元素，必定不选k，l号元素，选的元素总和为m的子集个数。
 
 
 
 题目解析：
 令dp[i][j][s1][s2]表示前i个物品填了j的体积，有s1个物品选为为必选，s2个物品选为必不选的方案数(0<=s1,s2<=2)，则有转移方程dp[i][j][s1][s2] = dp[i - 1][j][s1][s2] + dp[i - 1][j - a[i]][s1 - 1][s2] + dp[i - 1][j][s1][s2 - 1]，边界条件为dp[0][0][0][0] = 1，时间复杂度O(NS*3^2)。
 
 看的的题解，最后*4是因为必选AB可以调换位置变成BA，同理非必选，所以答案*4。
 
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

const int mod = 1000000007, N = 1010;
int dp[N][N][3][3]; //dp[i][j][x][y] 前i个，重量为j，x个必选，y个必不选的可能数
int a[N];

int main(int argc, const char * argv[]) {
    int t = 1000;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        dp[0][0][0][0] = 1;
        for (int i = 1; i <= n; ++i) { // 每个物体有4个选择：选、不选、必选、必不选；
            for (int j = 0; j <= s; ++j) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        dp[i][j][x][y] = dp[i - 1][j][x][y]; // 不选
                        if (j >= a[i]) { // 选
                            dp[i][j][x][y] = (dp[i][j][x][y] + dp[i - 1][j - a[i]][x][y]) % mod;
                        }
                        if (x > 0 && j >= a[i]) { // 必选
                            dp[i][j][x][y] = (dp[i][j][x][y] + dp[i - 1][j - a[i]][x - 1][y]) % mod;
                        }
                        if (y > 0) {
                            dp[i][j][x][y] = (dp[i][j][x][y] + dp[i - 1][j][x][y - 1]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= s; ++j) {
            ans = (ans + dp[n][j][2][2]) % mod;
        }
        
        cout << (ans * 4LL) % mod << endl;
    }
}
