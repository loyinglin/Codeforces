//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/string-to-integer-atoi/)
 **题目大意：**
 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
 在任何情况下，若函数不能进行有效的转换时，请返回 0 。

 提示：
 本题中的空白字符只包括空格字符 ' ' 。
 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
  
 示例 1:
 输入: "42"
 输出: 42
 
 示例 2:
 输入: "   -42"
 输出: -42
 解释: 第一个非空白字符为 '-', 它是一个负号。
      我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
 
 示例 3:
 输入: "4193 with words"
 输出: 4193
 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
 
 示例 4:
 输入: "words and 987"
 输出: 0
 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
      因此无法执行有效的转换。
 
 示例 5:
 输入: "-91283472332"
 输出: -2147483648
 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
      因此返回 INT_MIN (−231) 。

 
 **题目解析：**
 按照题目的要求实现，拆分出来具体的过程。
 1、还未进行数字转换的状态，hasConvert=false，此时可以允许空格跳过；
 2、遇到+、-、数字之后，hasConvert=true，不允许空格跳过，遇到非数字符号结束转化；
 3、符号和数字分开处理，超过int大小分别出来，可以用long long来暂存；
 
 整体代码不复杂。


 ```
 
 ```
 
 **注意：**
 题目很坑，+1 这种数据也没有说明；
 +03这种，会认为是数字3，题目的严谨程度较差；
 
 
 
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
    int myAtoi(string str) {
        long long ret = 0;
        int flag = 0; // 前置符号， 0表示还没放过， 1 是正数，-1是负数
        bool hasConvert = false;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '-' || str[i] == '+') {
                if (flag) {
                    return flag * ret;
                }
                flag = str[i] == '-' ? -1 : 1;
                hasConvert = true;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                if (!flag) flag = 1;
                hasConvert = true;
                ret = ret * 10 + str[i] - '0';
                if (flag * ret < -(1LL << 31)) {
                    return -(1LL << 31);
                }
                if (flag * ret > (1LL << 31) - 1) {
                    return (1LL << 31) - 1;
                }
            }
            else if (!hasConvert && str[i] == ' ') {
                continue;
            }
            else {
                return flag * ret;
            }
        }
        return flag * ret;
    }
}lc;


int main(int argc, const char * argv[]) {
    while (1) {
        char s[111];
        gets(s);
        string str(s);
        cout << lc.myAtoi(str) << endl;
    }
    
    
    return 0;
}
