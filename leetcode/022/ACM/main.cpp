//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/generate-parentheses/description/
 题目大意：
 
 题目解析：
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
        
        if (left == 0 && right == 0) {
            ret.push_back(str);
        }
        
        d
}leetcode;


int main(int argc, const char * argv[]) {
    
   
    return 0;
}
