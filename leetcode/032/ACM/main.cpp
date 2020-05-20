//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/longest-valid-parentheses/
 题目大意：
 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

 示例 1:

 输入: "(()"
 输出: 2
 解释: 最长有效括号子串为 "()"
 示例 2:

 输入: ")()())"
 输出: 4
 解释: 最长有效括号子串为 "()()"

 
 题目解析：
 先用栈，找到所有的匹配的括号，标记好01的位置，0是默认值，1表示该位置有匹配的括号；
 然后遍历数组，统计连续1的长度；
 
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 特殊样例：
 (((((())
 ()()()(()
 ( ( ( ) ( ) ) )
 
 
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
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> stk;
        vector<int> vis = vector<int>(s.length());
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == '(') {
                stk.push(i);
            }
            else {
                if (stk.size() > 0) {
                    vis[stk.top()] = 1;
                    vis[i] = 1;
                    stk.pop();
                }
            }
        }
        
        int tmp = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (vis[i]) {
                ++tmp;
                ret = max(ret, tmp);
            }
            else {
                tmp = 0;
            }
        }
        
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    cout << leetcode.longestValidParentheses("()(()") << endl;
    
    return 0;
}
