//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/palindrome-number/submissions/)
 **题目大意：**
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

 示例 1:
 输入: 121
 输出: true
 
 示例 2:
 输入: -121
 输出: false
 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 
 示例 3:
 输入: 10
 输出: false
 解释: 从右向左读, 为 01 。因此它不是一个回文数。

 **题目解析：**
 将数字转成字符串，然后开始从左右两边开始遍历，如果遇到不一样的字符串则输出false；
 如果没有发现不一样的字符，则左右边界递进，则最后输出true；


 ```
 
 ```
 
 **思考：**
 如果是要在字符串中找出最长的回文串呢？
 
 
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
    bool isPalindrome(int x) {
        char s[20];
        sprintf(s, "%d", x);
        int end = strlen(s) - 1, st = 0;
        while (st < end) {
            if (s[st] != s[end]) {
                return false;;
            }
            ++st;
            --end;
        }
        return true;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
