//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/C)
 **题目大意：**
 字符串s可以成为偶字符串，如果字符串满足：
 1、字符串的长度为偶数；
 2、所有奇数位的字符𝑎[𝑖]，满足𝑎[𝑖]=𝑎[𝑖+1]；
 
 比如说“aa”、“aabb”、“aabbcc”就是偶字符串，但是“aaa”、“aaab”、“abba”就不是偶字符串；
 现在想知道，最少移除掉字符串s中多少个字符，可以使得字符串s变成偶字符串；
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例一行，字符串 𝑠 (1≤|𝑠|≤2⋅105),
 
 **输出：**
 每个样例一行，输出最少移除的字符串；
 
 
 **Examples**
 **input**
 4
 aabbcc
 aaab
 aaa
 abba
 
 **output**
 0
 2
 1
 2

 **题目解析：**
 
 dp[i] 表示前i个字符，能找到的最长even字符串；
 那么对于第i个字符，我们有两个选择：
 取第i个字符，那么找到最近一个和第i个字符相近的位置k，我们有dp[i]=max(dp[i], dp[k-1] + 2)；
 不取第i个字符，那么有dp[i]=max(dp[i], dp[i - 1])；
 
 
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
    static const int N = 201010;
    char str[N];
    int dp[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> (str + 1);
            int n = strlen(str + 1);
            int pos[26] = {0};
            for (int i = 1; i <= n; ++i) {
                dp[i] = dp[i - 1];
                int index = str[i] - 'a';
                if (pos[index]) { //
                    dp[i] = max(dp[i], dp[pos[index] - 1] + 2);
                }
                pos[index] = i;
            }
            cout << n - dp[n] << endl;
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
