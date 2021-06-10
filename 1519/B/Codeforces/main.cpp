//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1519/problem/B)
 **题目大意：**
 
 **输入：**
 第一行是整数n，表示数组长度 (1≤𝑛≤5000)
 第二行是n个整数a[1]、a[2]、a[3]... a[n]; (1<=a[i] <= 1e7）；
 第二行是n个整数b[1]、b[2]、b[3]... b[n];(1<=b[i] <= 1e7）；
 
 **输出：**
 调转一次区间之后，数组a和数组b的最大乘积和。
 
 **Examples**
 **input**
 5
 2 3 2 1 3
 1 3 2 4 2
 
 **output**
 29

 样例解释：
 调转区间[4,5]，a=[2,3,2,3,1]，那么数组a和b的成绩和= 2⋅1+3⋅3+2⋅2+3⋅4+1⋅2=29
 
 **题目解析：**
 对于一个4x4的格子，我们有随便选择一种走法
 1 0 0 0
 2 0 0 0
 3 4 5 6
 0 0 0 7
 这种走法的步伐是：
 (1,1) - (2,1) - (3,1) - (3,2) - (3,3) - (3,4) - (4,4)
 
 再随机选择一种走法
 1 2 3 4
 0 0 0 5
 0 0 0 6
 0 0 0 7
 这种走法的步伐是：
 (1,1) - (1,2) - (1,3) - (1,4) - (2,4) - (3,4) - (4,4)
 
 容易知道，第一种的代价是1+1+3+3+3+4，都是步伐组合中数字的一半；
 第二种的代价是1+1+1+4+4+4，都是步伐组合中数字的一半；
  
 我们知道步伐的组合，本质就是6次选择，每次选择x=x+1或者y=y+1，一共有C(6,3)种可能；（从6个元素中选择3个元素的可能）
 计算几次，发现价格是一样的。
 
 怎么证明呢？
 我们用dp[i][j]表示，走到i、j的代价，容易知道dp[i][j+1]=dp[i][j]+i 以及 dp[i+1][j]=dp[i][j]+j，并且是唯一解；
 那么dp[i+1][j+1]=dp[i][i+1]+j=dp[i][j]+i+j。
 我们由dp[1][1]开始，可以递推出来dp[1~100][1~100]的价格。
 
 
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

class Solution {
    static const int N = 105;
public:
    int n, m, k, t;
    int dp[N][N];
public:
    void solve() {
        cin >> t;
        dp[1][1] = 0;
        for (int i = 2; i < N; ++i) {
            dp[1][i] = dp[1][i - 1] + 1;
            dp[i][1] = dp[i-1][1] + 1;
        }
        for (int i = 2; i < N; ++i) {
            for (int j = 2; j < N; ++j) {
                dp[i][j] = dp[i-1][j] + j;
            }
        }
        while (t--) {
            cin >> n >> m >> k;
            cout << (dp[n][m] == k ? "YES" : "NO") << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 Input
 5
 2 3 2 1 3
 1 3 2 4 2
 
 2 9 8 2 6
 
 Output
 29
 Input
 2
 13 37
 2 4
 Output
 174
 Input
 6
 1 8 7 6 3 6
 5 9 6 8 8 6
 Output
 235

 
 */
