//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/largest-rectangle-in-histogram/
 题目大意：
 给出一个数组，数组a[i]表示第i栋楼的高度；
 求出最大矩形的面积。
 
 For example,
 Given heights = [2,1,5,6,2,3],
 return 10.
 
 
 题目解析：
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
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        stack<int> s;
        for (int col = 0; col < heights.size(); ++col) {
            while (!s.empty() && heights[col] < heights[s.top()]) {
                int top = s.top();
                s.pop();
                int area = heights[top] * (s.empty() ? col : (col - s.top() - 1));
                ret = max(ret, area);
            }
            s.push(col);
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
    
    
    return 0;
}
