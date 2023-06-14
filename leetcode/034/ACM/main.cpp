//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 题目大意：
 给出一个递增的整数数组nums，求某个整数target在数组的区域，如下：
 
 Example 1:
 Input: nums = [5,7,7,8,8,10], target = 8
 Output: [3,4]
 
 Example 2:
 Input: nums = [5,7,7,8,8,10], target = 6
 Output: [-1,-1]
 
 题目解析：
 二分法，给出整数target，可以比较快速找出分别找出左边界，同理找到右边界即可。
 时间复杂度：O（ log N）
 
 
 
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        
        int left = 0, right = (int)nums.size() - 1;
        int index = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                index = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        ret.push_back(index);
        
        if (index == -1) {
            ret.push_back(-1);
            return ret;
        }
        
        
        left = 0, right = (int)nums.size() - 1;
        index = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                index = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        ret.push_back(index);
        
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {5,7,7,8,8,10};
    
    leetcode.searchRange(nums1, 6);
    
    return 0;
}
