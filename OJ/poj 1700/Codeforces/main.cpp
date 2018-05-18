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

int a[N], dp[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int testCase = 0;
    cin >> testCase;
    while (testCase--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        memset(dp, 0, sizeof(dp));
        dp[1] = a[1];
        dp[2] = a[2];
        dp[3] = a[1] + a[2] + a[3];
        for (int i = 4; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + a[i] + a[1], dp[i - 2] + a[2] + a[1] + a[i] + a[2]);
        }
        
        cout << dp[n] << endl;
    }
    
    
    
    
    return 0;
}
