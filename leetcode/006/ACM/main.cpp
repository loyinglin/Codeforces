//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/zigzag-conversion/description/
 题目大意：
 
 
 题目解析：
 方法1：
 找规律，模拟；
 
 方法2:
 vector暂存；
 去掉x坐标的影响，直接计算y的变化。
 
 trick，nums=1的时候！
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
