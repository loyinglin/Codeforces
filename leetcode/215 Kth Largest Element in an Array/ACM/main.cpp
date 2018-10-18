//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 题目大意：
  一个存放乱序整数的数组，找到数组中第k大的数字；
 ```
 Example 1:
 
 Input: [3,2,1,5,6,4] and k = 2
 Output: 5
 Example 2:
 
 Input: [3,2,3,1,2,4,5,5,6] and k = 4
 Output: 4
 ```
 
 
 题目解析：
 从样例的数据可以看出，第k大就是从小到大排序，第k个的数字；
 那么一种简单的办法就是对数组进行排序，然后输出第k个数字；
 
 还有一种做法是建一个大小为k的最大堆，然后遍历数组，把每个数字放进堆中，如果堆大小超过k，则弹出堆顶的数字；
 这样一轮过后，就有一个大小为k的最大堆，堆顶就是第k大的数字；
 
 最后是一种理论（平均）最优解法，从数组中取第一个数字x，遍历数组，按照<x和>x分成两组left和right；
 如果left==k-1，那么数字x就是第k大数字；
 如果left<k-1，那么从right中继续这个筛选过程；（注意right中筛选不是第k个大，要去掉left+1的数量）
 如果left>k-1，那么从left中继续这个筛选过程；
 
 这里附上最简单的实现，两行代码；
 
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
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 1001000, M = 3010100, inf = 0x7fffffff;

char str[N * 2];
int Right[5];

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    
    return 0;
}
