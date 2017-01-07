//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/wildcard-matching/
 题目大意：
 输入一个串s和一个匹配串p，问是否匹配。
 匹配串中包括两种特殊字符：
 1、？  匹配单个字符；
 2、*   通配符；
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 
 
 
 
 题目解析：
 ？的匹配非常简单；
 * 的匹配较为复杂，匹配多个长度的字符串，甚至是长度为0的字符串。
 考虑通过搜索来实现这个匹配方案。
 匹配的状态有两个：s串当前的匹配位置，p串当前的匹配位置；
 遇到？时，直接跳到下一个位置；
 遇到*时，枚举下一个可能的位置，只要有一个返回yes，即可；
 
 收获一枚TLE，原因在于样例有多个*，搜索在遇到*的时候会多项式级别（O(N!))增加耗时。
 
 改用动态规划：
 dp[i][j] 表示s串前i个字符和p串前j个字符是否匹配。
 转移时根据当前字符串，分别遍历前面的结果。
 时间复杂度为O(N^2*M)，N为原串的长度，M为匹配串长度；
 空间复杂度为O(N*M)。
 
 更可以优化的地方：dp[i][j]求解中只用到dp[k][j-1]的结果，那么可以用滚动数组来优化，空间复杂度可以降为O(M);
 
 最elegant的做法：**贪心**。
 虽然时间复杂度同样是O(N*M)，但是空间复杂度降到O(1)。
 当匹配失败的时候，不需要从原来的位置匹配，只需从最近的一个星号开始匹配。
 ```
 boolean comparison(String str, String pattern) {
 int s = 0, p = 0, match = 0, starIdx = -1;
 while (s < str.length()){
 if (p < pattern.length()  && (pattern.charAt(p) == '?' || str.charAt(s) == pattern.charAt(p))){
 s++;
 p++;
 }
 else if (p < pattern.length() && pattern.charAt(p) == '*'){
 starIdx = p;
 match = s;
 p++;
 }
 else if (starIdx != -1){
 p = starIdx + 1;
 match++;
 s = match;
 }
 else return false;
 }
 while (p < pattern.length() && pattern.charAt(p) == '*')
 p++;
 return p == pattern.length();
 }
 ```
 
 
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
#include<unordered_set>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 1500;
class Solution {
public:
    bool dp[N][N];
    bool isMatch(string s, string p) {
        long n = s.length(), m = p.length();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '?') {
                    if (i > 0) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
                else if (p[j - 1] == '*') {
                    for (int k = 0; k <= i; ++k) {
                        dp[i][j] |= dp[k][j - 1];
                    }
                }
                else {
                    if (i > 0) {
                        if (p[j - 1] == s[i - 1]) {
                            dp[i][j] |= dp[i - 1][j - 1];
                        }
                    }
                }
            }
        }
        return dp[n][m];
    }
}leetcode;


int main(int argc, const char * argv[]) {
    
    string s = "";
    string p = "";
    cout << leetcode.isMatch(s, p) << endl;
    

    
    
    
    return 0;
}
