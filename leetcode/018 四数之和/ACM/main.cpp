//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/4sum
 题目大意：
 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

 0 <= a, b, c, d < n
 a、b、c 和 d 互不相同
 nums[a] + nums[b] + nums[c] + nums[d] == target
 你可以按 任意顺序 返回答案 。

 示例 1：
 输入：nums = [1,0,-1,0,-2,2], target = 0
 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 示例 2：
 输入：nums = [2,2,2,2,2], target = 8
 输出：[[2,2,2,2]]
 提示：
 1 <= nums.length <= 200
 -109 <= nums[i] <= 1e9
 -109 <= target <= 1e9
 
 **题目解析：**
 两数之和、三数之和的类似问题，题目要求是要找到所有解。
 由于题目对数组元素顺序没有要求，可以先对数组排序，得到从小到大的数组nums；
 枚举两个元素a和b，作为四元组的两个元素；剩下两个元素在区间[a, b]中选择。
 问题变成了，在区间找到两个数字c和d，并且c+d=target-a-b。
 
 时间复杂度O(N^3）
 
 **思考：**
 
 -2, -1, 0, 0, 1, 2
 
 
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        map<vector<int>, int> h;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 3; j < n; ++j) {
                int m = target - nums[i] - nums[j];
                int left = i + 1, right = j - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == m) {
                        vector<int> tmp = {nums[i], nums[j], nums[left], nums[right]};
                        sort(tmp.begin(), tmp.end());
                        if (!h[tmp]) {
                            ret.push_back(tmp);
                            h[tmp] = 1;
                        }
                        ++left;
                    }
                    else if (nums[left] + nums[right] > m) {
                        --right;
                    }
                    else {
                        ++left;
                    }
                }
            }
        }
        
        return ret;
    }
}ac;


int main(int argc, const char * argv[]) {
    vector<int> nums = {-2, -1, 0, 0, 1, 2};
    
    ac.fourSum(nums, 0);
    
    return 0;
}
