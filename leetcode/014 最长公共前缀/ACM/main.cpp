//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/longest-common-prefix)
 **题目大意：**
 编写一个函数来查找字符串数组中的最长公共前缀。

 如果不存在公共前缀，返回空字符串 ""。

 示例 1:
 输入: ["flower","flow","flight"]
 输出: "fl"
 
 示例 2:
 输入: ["dog","racecar","car"]
 输出: ""
 
 解释: 输入不存在公共前缀。
 说明: 所有输入只包含小写字母 a-z 。

 
 **题目解析：**
前缀和，直接for循环遍历。

 ```
 
 ```
 
 **注意：**
 vector为空的情况。
 
 
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
const int N = 50000;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        while (true && strs.size()) {
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].size() < ret.length() + 1) {
                    return ret;
                }
                if (i > 0 && strs[i][ret.length()] != strs[0][ret.length()]) {
                    return ret;
                }
            }
            ret.push_back(strs[0][ret.length()]);
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
