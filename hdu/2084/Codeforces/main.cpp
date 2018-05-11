//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Numbers Exchange
 [题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=2084)
 **题目大意：**
 
 **输入数据：**
 
 >**Examples**
 **input**
 **output**
 
 **题目解析：**
 
 **思考🤔：**
 
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
const int N = 1010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N][N], dp[N][N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int testCase = 0;
    cin >> testCase;
    while (testCase--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                cin >> a[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        
        dp[1][1] = a[1][1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                if (j > 1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[n][i]);
        }
        
        cout << ans << endl;
    }
    
    
    
    
    return 0;
}
