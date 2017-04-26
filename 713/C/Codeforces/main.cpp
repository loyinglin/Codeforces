//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/713/problem/C
 题目大意：n个数字，每次可以把一个数字+1或者-1，代价为1；
 问把n个数字改为严格递增序列的最小代价。
  n (1 ≤ n ≤ 3000)
 ai (1 ≤ ai ≤ 1e9).
 
 
 input
 5
 5 4 3 2 1
 output
 12
 
 
 解释：
 1 2 3 4 5
  |5 - 1| + |4 - 2| + |3 - 3| + |2 - 4| + |1 - 5| = 12
 
 
 题目解析：
 如果是非严格递增（即是a[i]=a[i+1]是可行的），可以用dp来解决。
 令b[i]=第i大的数字， dp[i][j] 表示第前i个数字转移到第j大的数字的代价；
 那么有dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - b[i]));  1<= k <= j；
 在求dp[i][j] 的过程中，维护一个dp[i-1][1~j]的最小值即可。
 
 
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
const int N = 3010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int a[N], b[N];
lld dp[N][N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = b[i] = a[i] - i;
    }
    
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
        lld maxInf = llinf;
        for (int j = 1; j <= n; ++j) {
            maxInf = min(maxInf, dp[i - 1][j]);
            dp[i][j] = maxInf + abs(a[i] - b[j]);
        }
    }
    
    lld ans = llinf;
    for (int i = 1; i <= n; ++i) {
        ans = min(dp[n][i], ans);
    }
   
    cout << ans << endl;
    
    
    return 0;
}
