//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1519/problem/B)
 **题目大意：**
 在一个n x m的网格中，小明现在站在[1, 1]的位置，想要走到[n, m]；
 当小明在位置[x, y]时，每次可以选择：
 走到[x, y+1]，花费x的代价；
 走到[x+1,y]，花费y的代价；
 问，小明能否走到位置[n, m]并花费的代价和刚好是k；
 
 **输入：**
 第一行是整数𝑡，表示样例数 (1≤𝑡≤100)
 每个样例一行，整数 𝑛, 𝑚, and 𝑘 (1≤𝑛,𝑚≤100; 0≤𝑘≤10000)
 
 **输出：**
 每个样例一行，可以则输出YES；不可以则输出NO；
 
 **Examples**
 **input**
 6
 1 1 0
 2 2 2
 2 2 3
 2 2 4
 1 4 3
 100 100 10000

 **output**
 YES
 NO
 YES
 NO
 YES
 NO

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
 我们用dp[i][j]表示，走到i、j的代价，容易知道dp[i][j+1]=dp[i][j]+i 以及 dp[i+1][j]=dp[i][j]+j，并且在边界情况是唯一解；
 那么dp[i+1][j+1]=dp[i][i+1]+j=dp[i][j]+i+j。
 我们由dp[1][1]开始，可以递推出来dp[1~100][1~100]的价格。
 
 
 **思考🤔：**
 这里也可以用数学方式去解，但用dp会更直观一些。
 
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
