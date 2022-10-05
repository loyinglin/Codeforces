//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/regular-expression-matching)
 **题目大意：**
 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

 '.' 匹配任意单个字符
 '*' 匹配零个或多个前面的那一个元素
 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 说明:
 s 可能为空，且只包含从 a-z 的小写字母。
 p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 示例 1:

 输入:
 s = "aa"
 p = "a"
 输出: false
 解释: "a" 无法匹配 "aa" 整个字符串。
 示例 2:

 输入:
 s = "aa"
 p = "a*"
 输出: true
 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 示例 3:

 输入:
 s = "ab"
 p = ".*"
 输出: true
 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 示例 4:

 输入:
 s = "aab"
 p = "c*a*b"
 输出: true
 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

 **题目解析：**
 用搜索是一种解法，但是搜索写起来比较麻烦，并且时间复杂度也有较大劣势；
 这里使用动态规划会更加合适。
 动态规划要优先考虑子问题和无后效性，我们用dp[i][j]表示字符串s前i个字符和字符串p前j个字符是否匹配，容易知道dp[i][j]的状态可以由dp[i-1][j-1]等前面的状态递推过来，并且dp[i][j]不会影响前面的结果。
 接下来推导状态转移方程：
 首先看字符p[j]，如果p[j]不是'*'字符，那么dp[i][j]就取决于s[i]是否等于p[j]，s[i]==p[j]或者p[j]=='.' 则有dp[i][j]=dp[i-1][j-1]；否则有dp[i][j]=false;
 如果p[j]是'*'字符，那么要分情况讨论，如果取的是0个，那么dp[i][j]就可以由dp[i][j-2]递推过来；如果是取1个以上，那么在满足s[i]和p[j-1]相同的情况，可以由dp[i-1][j]递推过来；
 
 
 **注意：**
 子状态的设计比较直接，状态转移也没有太多考虑点，但是在实现过程还是需要考虑越界等边界情况。
 
 
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
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


struct Node {
    int first, second;
    Node(){}
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator < (const Node tmp) const {
        if (first != tmp.first) {
            return first > tmp.first;
        }
        else {
            return second > tmp.second;
        }
    }
};

typedef long long lld;

const int N = 10;

class Solution {
    vector<vector<bool> > dp;
    bool checkCharMatch(char c, char p) {
        return (c == p) || (p == '.');
    }
public:
    bool isMatch(string s, string p) {
        dp.clear();
        for (int i = 0; i <= s.length(); ++i) {
            vector<bool> vec(p.length() + 1, 0);
            dp.push_back(vec);
        }
        dp[0][0] = 1;
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                if (p[j-1] == '*') {
                    if (j <= 1) { // 避免出现单个*开头的字符串
                        return false;
                    }
                    // x* *号表示0个，或者1到若干个)
                    dp[i][j] = dp[i][j-2]; // 表示*取0个，需要特殊考虑
                    if (i>0 && checkCharMatch(s[i - 1], p[j - 2])) { // 如果某个s[i-1]和p[j-2]匹配，则当s[i-1]没有出现过，直接看前面dp[i-1][j]是否匹配即可；
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                else if (i>0 && checkCharMatch(s[i - 1], p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        bool ret = dp[s.length()][p.length()];
        return ret;
    }
}ac;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    string s = "aa";
    string p = "a*ac*";
    cout << ac.isMatch(s, p) << endl;
    
    return 0;
}
