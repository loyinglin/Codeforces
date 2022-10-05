//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 2022年03月27日.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 链接：https://leetcode.cn/problems/maximum-subarray
 题目大意：
 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 子数组 是数组中的一个连续部分。

  

 示例 1：

 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 输出：6
 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 示例 2：

 输入：nums = [1]
 输出：1
 示例 3：

 输入：nums = [5,4,-1,7,8]
 输出：23

  
 
 题目解析：
 暴力的做法，枚举每个子区间[i, j]，算出每个区间的和，总的复杂度是O(N ^ 2)；
 
 动态规划的做法：
 1、子问题拆解，dp[i]表示前i个数字中，区间以第i个数字结尾的最大和；
 2、状态转移，两个选择，要么取a[i-1]的区间，要么不取前i-1个字数字，得状态转移方程：dp[i] = max(dp[i - 1] + a[i], a[i])；
 复杂度为O(N)；

 
 
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



typedef long long lld;
const int N = 50000;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    else {
        return b.end < a.end;
    }
}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    leetcode.maxSubArray(vec);
    
    return 0;
}
