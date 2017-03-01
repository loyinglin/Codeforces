//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/first-missing-positive/
 题目大意：
 给出一个数组，找到数组中没有的最小正整数。
 example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 要求，O(N)的时间和O(1)的空间复杂度；
 
 题目解析：
 先不考虑题目要求的时间、空间复杂度；
 暴力的做法有两个：
 1、时间最快，空间不限：数组a[N]，然后出现数字k就a[k]=1标志出现；
 2、时间、空间都不限：排序，遍历一遍数组；
 
 回到题目的要求，时间复杂度要求是O(N)，可以肯定是会用到方法1；
 现在要求O(1)的空间复杂度，那么就必须利用上给出的数组。
 遍历数组，如果数字k小于n且非负，那么a[k-1]=k-1;
 然后遍历一遍，a[i] != i的就行是解。
 
 复杂度解析：
 O(N)的时间和O(1)的空间复杂度；
 
 
 
 其他解法：
 基数排序。
 
 从低位开始，
 当前第i位，统计0出现x次，1出现y次，(x+y == n)
 再次扫描数组，可以直接确定每个数字该排在哪里。
 if bit = 0 then
 idx = total_y + (total_x-left_x)
 ..
 
 http://blog.csdn.net/zzwab99/article/details/8181927
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
    int firstMissingPositive(vector<int>& nums) {
        int ret = (int)nums.size() + 1, n = (int)nums.size();
        for(int i = 0; i < n; ++ i) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++ i) {
            if(nums[i] != i + 1) {
                ret = i + 1;
                break;
            }
        }
        return ret;
    }
}lc;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {100, -1};
    vector<int> nums2 = {2};
    cout << lc.firstMissingPositive(nums1) << endl;
    
    return 0;
}
