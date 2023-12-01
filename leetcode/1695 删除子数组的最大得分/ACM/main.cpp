//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/maximum-erasure-value/)
 **题目大意：**
 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

 返回 只删除一个 子数组可获得的 最大得分 。

 如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。

  

 示例 1：

 输入：nums = [4,2,4,5,6]
 输出：17
 解释：最优子数组是 [2,4,5,6]
 示例 2：

 输入：nums = [5,2,1,2,5,2,1,2,5]
 输出：8
 解释：最优子数组是 [5,2,1] 或 [1,2,5]
  

 提示：

 1 <= nums.length <= 105
 1 <= nums[i] <= 104

 **题目解析：**
 从数组中找到一个连续的区间，区间不能包括相同的数字，要求区间的数字和尽可能大。
 从左到右遍历数组，维护一个区间[left, right]，区间没有相同元素，我们用map<int, int> 来记录数组中出现的数字，sum记录数组的和；
 假设遍历到数字a[i]，如果map中没有数字a[i]，则直接添加到map中，右区间右移right=right+1，sum=sum+a[i]；
 假设遍历到数字a[i]，如果map中存在数字a[i]，则左区间右移sum=sum-a[left]，left=left+1，直到发现数字a[i]，这样得到包括数字a[i]的区间[left, right]和区间和sum；
 
 遍历过程中的最大和所在区间，就是答案。复杂度O(N)。
 
 
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
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, left = 0, right = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp[nums[i]]) {
                while (mp[nums[i]]) {
                    sum -= nums[left];
                    mp[nums[left]]--;
                    ++left;
                }
            }
            right += 1;
            sum += nums[i];
            ++mp[nums[i]];
            ans = max(ans, sum);
        }
        return ans;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {4,2,4,5,6};
    vector<int> nums2 = {2};
    leetcode.maximumUniqueSubarray(nums1);
    
    return 0;
}
