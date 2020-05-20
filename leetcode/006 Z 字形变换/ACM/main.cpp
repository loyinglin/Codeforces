//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/zigzag-conversion/)
 **题目大意：**
 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

 L   C   I   R
 E T O E S I I G
 E   D   H   N
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

 请你实现这个将字符串进行指定行数变换的函数：

 string convert(string s, int numRows);
 示例 1:

 输入: s = "LEETCODEISHIRING", numRows = 3
 输出: "LCIRETOESIIGEDHN"
 示例 2:

 输入: s = "LEETCODEISHIRING", numRows = 4
 输出: "LDREOEIIECIHNTSG"
 解释:

 L     D     R
 E   O E   I I
 E C   I H   N
 T     S     G

 
 **题目解析：**
 方法1：
 找规律，模拟；
 
 方法2:
 vector暂存；
 去掉x坐标的影响，直接计算y的变化。
 trick就是nums=1的特殊判断。
 
 这里使用方法2，代码较为直接：
 ```
 ```
 
 
 
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

typedef long long lld;
const int N = 50000;

class Solution {
public:
    string ans[N];
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        string ret;
        for (int i = 0; i < numRows; ++i) {
            ans[i].clear();
        }
        int y = 0, gap = 1;
        for (int i = 0; i < s.length(); ++i) {
            ans[y].push_back(s[i]);
            y += gap;
            if (y < 0) {
                y = 1;
                gap = 1;
            }
            else if (y >= numRows) {
                y = numRows - 2;
                gap = -1;
            }
        }
        
        for (int i = 0; i < numRows; ++i) {
            ret += ans[i];
        }
        return ret;
    }
    
}leetcode;


int main(int argc, const char * argv[]) {
    string s = "PAYPALISHIRING";
    leetcode.convert(s, 1);
    
    
    return 0;
}
