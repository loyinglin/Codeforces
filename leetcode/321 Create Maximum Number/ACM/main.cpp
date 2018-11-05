//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/create-maximum-number/
 题目大意：
 给出两个数组，数组只包括0~9十个数字，长度分别为n、m；
 从两个数组中选出k个数，组成一个长度为k的数字，要求：
 1、从数组n、m选择出来的数字相对位置不变；
 2、最后的数字最大；
 输出最后的数字。
 
 Example 1:
 nums1 = [3, 4, 6, 5]
 nums2 = [9, 1, 2, 5, 8, 3]
 k = 5
 return [9, 8, 6, 5, 3]
 
 Example 2:
 nums1 = [6, 7]
 nums2 = [6, 0, 4]
 k = 5
 return [6, 7, 6, 0, 4]
 
 题目解析：
 要求最后数字最大，那么尽可能把数字大的排在前面；
 在都合法的前提下，99* 肯定比 98*要大；
 那么可以按照这样的贪心策略：
 先枚举t，t表示从数组nums1中选出t个数字，那么数组nums2中应该选出k-t个数字；
 两个数组的所有数字组成最大的数字，因为两个数组间的数字是可以任意顺序，那么只需每次选择较大的放在前面即可。
 
 问题简化成，O(N)每次从数组中选出t个最大的数字；
 这个可以用贪心解决：
 假设数组当前枚举到第i个，且nums[i]=x;
 从左到右遍历已经选择的数，当遇到一个数字t，t<x时，判断插入x后，后续是否存在合法解；如果存在则替换，否则直到最后，插入尾部；
 
 
 
 
 
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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        vector<int> ret(k, 0);
        for (int i = max(0, k - m); i <= k && i <= n; ++i) {
            vector<int> tmp1 = maxArray(nums1, i);
            vector<int> tmp2 = maxArray(nums2, k - i);
            vector<int> tmp = merge(tmp1, tmp2, k);
            if (greater(tmp, 0, ret, 0)) {
                ret = tmp;
            }
        }
        return ret;
    }
    
    vector<int> maxArray(vector<int> &nums, int k) {
        int n = (int)nums.size();
        vector<int> ret(k, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            while (n - i + j > k && j > 0 && ret[j - 1] < nums[i]) {
                --j;
            }
            if (j < k) {
                ret[j++] = nums[i];
            }
        }
        return ret;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret(k, 0);
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            ret[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return ret;
    }
    
    bool greater(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {9, 1, 2, 5, 8, 3};
    vector<int> nums2 = {3, 4, 6, 5};
    
    
    return 0;
}
