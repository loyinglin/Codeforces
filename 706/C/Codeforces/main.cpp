//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/706/problem/C
    题目大意：n个字符串，可以对每个字符串进行reverse的操作，代价为cost[i]，求让n个字符串按照字符顺序排列的最小代价，如果不能输出-1；
 字符串的总长度不会超过10w， n (2 ≤ n ≤ 100 000)。
    题目解析：
 容易想到每个字符串只有原样+reverse两种状态。
 dp[i][0]表示第i个字符串为原串的最小代价；
 dp[i][1]表示第i个字符串为reverse串的最小代价；
 
 string currentRe = reStr[i];
 string lastRe = reStr[i - 1];
 if (str[i] >= str[i - 1]) {
 dp[i][0] = min(dp[i][0], dp[i - 1][0]);
 }
 if (str[i] >= lastRe) {
 dp[i][0] = min(dp[i][0], dp[i - 1][1]);
 }
 if (currentRe >= str[i - 1]) {
 dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
 }
 if (currentRe >= lastRe) {
 dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
 }
 
 sum = min(dp[n][0], dp[n][1]);
 
 如果sum不为inf就存在解。
 
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
const int N = 101000, M = 3010100;
lld inf = 0x7fffffffffffffLL;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
lld a[N], sum;
lld dp[N][2];
string str[N];
string reStr[N];

int main(int argc, const char * argv[]) {
    // insert code here...

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> str[i];
        reStr[i] = string(str[i].rbegin(), str[i].rend());
    }
    
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i][1] = inf;
        string currentRe = reStr[i];
        string lastRe = reStr[i - 1];
        if (str[i] >= str[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (str[i] >= lastRe) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (currentRe >= str[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        }
        if (currentRe >= lastRe) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        }
    }
    
    sum = min(dp[n][0], dp[n][1]);
    if (sum == inf) {
        sum = -1;
    }
    
    cout << sum << endl;
    
    
    return 0;
}
