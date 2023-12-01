//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/longest-arithmetic-subsequence/)
 **题目大意：**
 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。

 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。

 示例 1：
 输入：nums = [3,6,9,12]
 输出：4
 解释：
 整个数组是公差为 3 的等差数列。
 示例 2：
 输入：nums = [9,4,7,2,10]
 输出：3
 解释：
 最长的等差子序列是 [4,7,10]。
 示例 3：
 输入：nums = [20,1,15,3,10,5,8]
 输出：4
 解释：
 最长的等差子序列是 [20,15,10,5]。
  

 提示：
 2 <= nums.length <= 1000
 0 <= nums[i] <= 500
 
 
 **题目解析：**
 差值可能为-500到500，枚举每一个公差；
 假设当前公差为k，然后从左到右遍历数组，枚举每个位置作为等差数列起始点的情况。
 总的复杂度为1000*1000*1000。
 
 由于公差取值范围偏大，枚举公差的复杂度，已经接近直接枚举等差数列的前两个位置，这样也可以在O(N^2)的复杂度确定起始位置和公差。接下来可以用O(N)的复杂度遍历剩下的数组。
 整体的复杂度O(N^3)，时间耗时偏长。
 
 
 
 
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
    // 从第pos个位置算第一个，公差为dir的最长等差序列
    int dfs(int pos, int dir, vector<int>& nums, int dp[1010][1010]) {
        if (dp[pos][dir] == 0) {
            dp[pos][dir] = 1;
            for (int k = pos + 1; k < nums.size(); ++k) {
                int diff = dir - 500, cnt = 0;
                if (nums[pos] + diff == nums[k]) {
                    dp[pos][dir] = max(dp[pos][dir], 1 + dfs(k, dir, nums, dp));
                }
            }
        }
        return dp[pos][dir];
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[1010][1010] = {0}; // dp[i][j]表示第i个数字，公差为是j+500时，该数字往后能产生的序列数。
        int ret = 2;
        for 
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j <= 1000; ++j) {
                ret = max(ret, dfs(i, j, nums, dp));
            }
        }
        return ret;
    }
}ac;

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {83,20,17,43,52,78,68,45};
    vector<int > nums2 = {1,2,3,4};
    cout << ac.longestArithSeqLength(nums1) << endl;
    
    return 0;
}
