//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/maximal-rectangle/
 题目大意：
 给出一个01矩阵，求全为1的最大的矩形的面积；
 
 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 6.

 
 题目解析：
 假设最后的矩形是(i, j)到(x, y)，01矩阵为n*m矩阵；
 从1到n枚举y，那么要求变成矩形贴着底边，然后面积尽可能大。
 把与底部连着的1统计起来，例如当row=3的时候，分别为[3,1,3,2,2]；
 此时，题目与[84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)完全一致；
 维护一个高度不减少的栈，每次可以通过栈，快速得出面积。
 
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


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int ret = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m + 2, 0);
        for (int row = 0; row < n; ++row) {
            stack<int> s;
            for (int col = 0; col <= m; ++col) {
                if (col < m) {
                    if (matrix[row][col] == '1') {
                        ++h[col];
                    }
                    else {
                        h[col] = 0;
                    }
                }
                while (!s.empty() && h[col] < h[s.top()]) {
                    int top = s.top();
                    s.pop();
                    int area = h[top] * (s.empty() ? col : (col - s.top() - 1));
                    ret = max(ret, area);
                }
                s.push(col);
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string str0 = "10100";
    string str1 = "10111";
    string str2 = "00000";
    string str3 = "10011";
    vector<vector<char>> matrix;
    vector<char> vec0(str0.begin(), str0.end());
    vector<char> vec1(str1.begin(), str1.end());
    vector<char> vec2(str2.begin(), str2.end());
    vector<char> vec3(str3.begin(), str3.end());
    matrix.push_back(vec0);
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    leetcode.maximalRectangle(matrix);
    
    return 0;
}
