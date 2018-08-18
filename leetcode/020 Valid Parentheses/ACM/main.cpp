//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/valid-parentheses/description/
 题目大意：
 给出一个字符串，只包含'(', ')', '{', '}', '[' and ']' 六类字符；
 问给出的字符串是否满足：
 1、所有括号都是匹配的；（左右括号数量一致）
 2、匹配的括号是合法的；（没有交错）
 
 Example 1:
 Input: "()"
 Output: true
 
 Example 2:
 Input: "()[]{}"
 Output: true
 
 Example 3:
 Input: "(]"
 Output: false
 
 Example 4:
 Input: "([)]"
 Output: false
 
 Example 5:
 Input: "{[]}"
 Output: true
 
 
 题目解析：
 根据题目的要求，可以用栈来实现，从左到右遍历字符串：
 1、遇到一个字符，先看栈是否为空，如果为空则直接入栈；如果栈不为空，则看当前字符是左括号还是右括号；
 2、如果是左括号，直接入栈；
 3、如果是右括号，则看栈顶元素是否为左括号，并且匹配；
 4、最后看栈是否为空。
 
 
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
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i];
            if (stk.size() == 0) {
                stk.push(c);
            }
            else {
                if (c == '[' || c == '{' || c == '(') {
                    stk.push(c);
                }
                else {
                    char top = stk.top();
                    stk.pop();
                    if ((c == ']' && top != '[') || (c == '}' && top != '{') || (c == ')' && top != '(')) {
                        return false;
                    }
                }
            }
        }
        return stk.size() == 0;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string str = "()";
    cout << leetcode.isValid(str) << endl;
   
    return 0;
}
