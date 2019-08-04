//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1195/problem/C)
 **题目大意：**
 篮球教练有2 * n个学生，排成两行，每行有n个人；
 每个学生都有一个高度h；(1≤h≤10e9)
 现在教练需要选择若干个学生去参加篮球比赛，他决定从左到右选择学生，并且：
 1、每列只选择一个学生；
 2、不连续选择两个同一行的学生，如果这次选择了第一行的学生，则下次必然选择第二行的学生；

 问选择出来的学生高度和最大值是多少；
 
 
 输入：
 第一行，𝑛  (1≤𝑛≤10e5)
 第二行，n个整数h，表示第一行学生高度 (1≤ℎ≤10e9)
 第三行，n个整数h，表示第二行学生高度 (1≤ℎ≤10e9)
 
 输出：
 选择出来的学生高度总和最大值；
 
 Examples
 input
 5
 9 3 5 7 3
 5 8 1 4 5
 output
 29
 input
 3
 1 2 9
 10 1 1
 output
 19
 
 **题目解析：**
 两个数组，从左到右遍历选择数字，每个index只能选择一个数字，并且两个数组要交替选择。
 
 对于每个数字，只有两种选择：选中或者不选中；
 对于每个index，则有三种状态：选择数组a的元素（状态1）、选择数组b的元素（状态2）、都不选择（状态0）；
 那么有dp[N][i]：
 dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
 dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + a[i];
 dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + b[i];
 
 然后选择dp[N][i]中的最大值即可。
 
 
 
 
 
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N], b[N];
lld dp[N][3];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    lld ans = max(a[0], b[0]);
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[0][2] = b[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + a[i];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + b[i];
        for (int j = 0; j < 3; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
