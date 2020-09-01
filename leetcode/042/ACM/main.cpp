//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/trapping-rain-water)
 **题目大意：**
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

 示例:

 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 输出: 6


 **题目解析：**
 先找出一个递增的子序列，直到遇到一个数组的最大值；
 如何快速计算两个数字之间能乘的雨水？排除法。
 矩形，去掉中间数字的和。
 
 最后反着计算，考虑高度相同的情况即可。


 
 
 
 ```
 
 ```
 
 **思考：**
 
 
 
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
    int trap(vector<int>& height) {
        int curHeight = -1, sum = 0, pos = -1, ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > curHeight) {
                ans += curHeight * (i - pos - 1) - sum;
                curHeight = height[i];
                sum = 0;
                pos = i;
            }
            else {
                sum += height[i];
            }
        }
        int highPos = pos;
        curHeight = -1, sum = 0,
        pos = height.size();
        for (int i = height.size() - 1; i >= highPos && i >= 0; --i) {
            if (height[i] >= curHeight) {
                ans += curHeight * (pos - i - 1) - sum;
                curHeight = height[i];
                sum = 0;
                pos = i;
            }
            else {
                sum += height[i];
            }
        }
        return ans;
    }
}lc;


int main(int argc, const char * argv[]) {
//    vector<int> nums1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> nums1 = {};
    cout << lc.trap(nums1) << endl;
    
    
    return 0;
}
