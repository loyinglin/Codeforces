//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/generate-parentheses/description/
 题目大意：
 给出一个整数n，求n对括号组成的，所有可能的合法字符串；
 
 例如，n=3，则有：
 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 
 
 
 题目解析：
 合法的字符串指的是左右括号数量相同，并且每一个左括号，都能在其右边找到一个右括号；
 类似")("这样就是不合法的字符串。
 理解定义之后，考虑长度为2*n的字符串中第i个字符应该怎么填：
 假设此刻已经具有的左括号有left个，右括号有right个；
 如果left>right，比如说"(()"，则可以放左括号=>"(()("，也可以放右括号=>"(())"
 如果left==right，比如说"(())"，那么只能放左括号=>"(())"
 如果left<right，此时为不合法序列，我们不应该出现这种情况；
 
 在此过程中，需要注意保证左右括号的数量不要超过n个；
 
 
 优化思路：
 
 
 复杂度解析：
 时间复杂度
 
 空间复杂度
 
 代码量
 
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
#include <list>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

class Solution {
public:
    
    void dfs(vector<string> &ret, string &str, int left, int right) {
        if (left > 0) {
            str.push_back('(');
            dfs(ret, str, left - 1, right);
            str.pop_back();
        }
        if (left < right && right > 0) { // 必须保证right > left，这样的字符串才是合法的
            str.push_back(')');
            dfs(ret, str, left, right - 1);
            str.pop_back();
        }
        if (left == 0 && right == 0)
            ret.push_back(str);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string tmp;
        dfs(ret, tmp, n, n);
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    
   
    return 0;
}
