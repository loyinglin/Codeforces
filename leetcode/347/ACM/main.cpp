//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/top-k-frequent-elements/?tab=Description
 题目大意：
 给出一个数组，返回k个最出现频率最高的数字。
 example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2].
 
 1 <= k <= n, n是数组大小；
 
 
 题目解析：
 题目分为两个步骤：
 1、统计每个数字的出现次数；
 2、从中选择k个次数最多的数字；
 
 一个简单的做法：
 用哈希表统计每个数字的出现次数；
 把每个数字的出现次数和数字组成一个pair，放入优先队列；
 
 这样从优先队列中取出k个即可。
 
 复杂度解析：
 时间复杂度是O(NlogN)，主要在最后的优先队列。
 
 其他解法：
 有一个O(NlogK)的优化；
 首先把队列变成最小有限队列，
 每次pair放入优先对时，如果当前的size大于k，那么弹出top；
 这样每次的操作从O(logN)变成O(logK)。
  
 
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsHash;
        for (int i = 0; i < nums.size(); ++i) {
            ++numsHash[nums[i]];
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            if(numsHash[nums[i]]) {
                q.push(make_pair(numsHash[nums[i]], nums[i]));
                numsHash[nums[i]] = 0;
            }
        }
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 1,1,2,2,3};
    vector<int> nums2 = {2};
    leetcode.topKFrequent(nums1, 2);
    
    return 0;
}
