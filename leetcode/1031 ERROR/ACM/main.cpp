//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/)
 **题目大意：**
 给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）

 从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 并满足下列条件之一：

 0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
  

 示例 1：
 输入：A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
 输出：20
 解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
 示例 2：
 输入：A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
 输出：29
 解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
  示例 3：
 输入：A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
 输出：31
 解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
  
 提示：
 L >= 1
 M >= 1
 L + M <= A.length <= 1000
 0 <= A[i] <= 1000

 **题目解析：**
 题目要求是找到两个子数组并且要求和最大，我们可以先简化题目要求；
 假如只考虑找到一个最大子数组的情况，此时可以从左到右遍历数组，就可以得到每个位置的最大子数组和；
 dpLeftFisrt[i]表示前i个数字，取长度区间为First且一定包括第i个数字，可以得到的最大子数组和，那么可以得到递推方程：
 dpLeftFisrt[i] = max(dpLeftFisrt[i-1], sum[i]);  // sum[i]表示以i结尾，长度区间不超过first的最大值
 
 
 
 假如是要寻找长度L和M的子数组，那么问题可以继续拆分为：
 1、假设有位置k，那么[1, k]中会产生L数组，[k+1, n]会产生M数组；此时可以枚举k的位置；
 2、LR的位置是反过来的，按照1的做法把L和R交换一下；
 时间和空间复杂度都是O(N)；

 
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
    int search(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size(), sum = 0;
        vector<int> preMax, lastMax(n);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= firstLen) {
                sum -= nums[i - firstLen];
            }
            if (i + 1 >= firstLen) {
                if (preMax.size()) preMax.push_back(max(*preMax.end(), sum));
                else preMax.push_back(sum);
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += nums[i];
            if (n - 1 - i >= secondLen) {
                sum -= nums[i + secondLen];
            }
        }
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(search(nums, firstLen, secondLen), search(nums, secondLen, firstLen));
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
