//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/interleaving-string
 题目大意：
 给出三个字符串s1,s2,s3；
 判断字符串s3能否由字符串s1和s2组成，要求s1的字符串内字符的相对顺序不变，s2同理。（假如s1=abc，那么在s3中，就不能变成bac，相对顺序必须是abc）
 
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 
 
 题目解析：
 动态规划。
 dp[i][j] 表示s1的前i个字符，s2的前j个字符，组成的字符串是否为s3的前i+j个字符。
 dp[0][0]=true，表示初始状态。
 假设dp[i][j]=true，那么表示s1的前i个字符，s2的前j个字符，与s3的前i+j个字符是匹配的。
 那么只要s1[i+1]==s3[i+j+1]，那么dp[i+1][j]=true;
 同理，有dp[i][j]=true && s2[j+1] == s3[i+j+1] => dp[i][j+1]=true

 最后看dp[n][m]是否为true即可。
 
 复杂度解析：
 时间和空间复杂度是O(NM) N是s1长度，M是s2长度；
 
 
 
 其他解法：
 
 
 
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

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int n = (int)s1.length(), m = (int)s2.length();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] & (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] & (s1[i - 1] == s3[i - 1]);
                } else {
                    if (s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                    if (s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] |= dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
