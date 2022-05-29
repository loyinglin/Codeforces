//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1673/problem/C)
 **题目大意：**
 给出一个数字n，将数字n可以拆分成若干个整数之和；
 现在想知道，有多少种拆分方法，要求拆分出来的整数都是回文数；
 （拆分出来的数字至少有一个不同，才算不同组合）
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例一行，整数 𝑛 (1≤𝑛≤4⋅1e4)
  
 **输出：**
 每个样例一行，输出不同的组合数字；结果可以对1e9+7取模；
 
 **Examples**
 **input**
 2
 5
 12
 **output**
 7
 74

 
 **题目解析：**
 首先，把1到40000的回文数全部列出来，得到若干个回文数；
 题目的要求是计算数字n拆分有多少种组合，我们只看数字1和2，就是将数字n拆成1和2的和；
 这个和动态规划的经典题目类似：上n个台阶，每次有1步或者2步，最后有多少走法；
 
 但是这个题目有点不同，就是对不同走法的判断，这里只有新增不同数字的情况，才认为是不同的；（1+2和2+1是一样的）
 那么我们将回文数数字从小到大排列，然后判断每次回文数是否可以替换已有数字即可。
 比如说：
 考虑数字1，有dp[1]=1，dp[2]=1, dp[3]=1, dp[4]=1;（dp[i]表示数字i有多少总走法）
 考虑数字2，有dp[1]=1，dp[2]=2, dp[3]=2, dp[4]=3；对于dp[2]，引入2的时候多了2=2的选择，同时还有原来的2=1+1；对于dp[4]，可以在dp[2]的基础上+2（新增2种选择4=2+2, 4=1+1+2），也可以不使用2，保留原来的4=1+1+1+1；
 
 按照这种思路分析，可以得到状态转移方程还是dp[i]=dp[i]+dp[i-k]；（k是回文数）
 
 
 
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
    static const int N = 40100;
    static const int MOD = 1e9 + 7;
    int dp[N];
    
    bool check(int k) {
        vector<int> vec;
        while (k) {
            vec.push_back(k % 10);
            k /= 10;
        }
        for (int i = 0; i < vec.size() / 2; ++i) {
            if (vec[i] != vec[vec.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    void solve() {
        vector<int> vec;
        for (int i = 1; i < N; ++i) {
            if (check(i)) {
                vec.push_back(i);
            }
        }
        dp[0] = 1;
        
        for (int j = 0; j < vec.size(); ++j) {
            for (int i = vec[j]; i < N; ++i) {
                dp[i] = ((lld)dp[i] + dp[i - vec[j]]) % MOD;
            }
        }
         
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cout << dp[n] << endl;
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
 */
