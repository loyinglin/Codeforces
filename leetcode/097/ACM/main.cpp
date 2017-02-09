//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 题目大意：
 
 
 题目解析：
 
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 
 
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
