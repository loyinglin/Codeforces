//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/two-sum/submissions/)
 **题目大意：**
 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

  

 示例:

 给定 nums = [2, 7, 11, 15], target = 9

 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]


 **题目解析：**
 先不考虑复杂度，直接两个for循环，对于每个数字nums[i]，寻找target-nums[i]是否也在数组；
 这样的时间复杂度为O(N^2)，可以牺牲一些空间来换取更快的速度：比如说把已经出现过的数字用hash表直接存下来，这样下次用hash表直接循环该数字是否存在。
 题目的要求还要输出数组下标，那么可以用hash表的值来存数组下标。
 

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
    unordered_map<int, int> mp;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        mp.clear();
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (mp[target - nums[i]]) {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]] - 1);
                break;
            }
            mp[nums[i]] = i + 1;
        }
        return  ans;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
