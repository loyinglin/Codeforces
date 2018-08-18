//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 题目大意：
 输入一个字符串，仅包含2-9的数字；
 数字代表的是键盘上的输入，如图
 问对于这个输入，可能有哪些字符串。
 
 
 Example:
  Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 
 题目解析：
 
 对于每个数字，代表3或者4个字母；
 于是可以用搜索的思想解决问题，枚举每一种可能。
 
 
 小trick，如果输入的是空串，那么返回的是空值；
 
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


class Solution {
public:
    
    void dfs(string &digits, int i, string &tmp, vector<string> &ret) {
        if (i >= digits.length()) {
            ret.push_back(tmp);
            return;
        }
        else {
            int nums[10] =
            {
                0,
                0, 3, 3,
                3, 3, 3,
                4, 3, 4,
            };
            
            int index = digits[i] - '0';
            int start = 0;
            for (int i = 2; i < index; ++i) {
                start += nums[i];
            }
            int end = start + nums[index];
            for (int j = start; j < end; ++j) {
                tmp.push_back('a' + j);
                dfs(digits, i + 1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string tmp;
        if (digits.length()) {
            dfs(digits, 0, tmp, ret);
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string str = "";
    vector<string> ret =  leetcode.letterCombinations(str);
   
    return 0;
}
