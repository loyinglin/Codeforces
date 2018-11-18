//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/next-permutation/description/
 题目大意：
 给出一个整形数组，返回数组的下一个排列(next permutation)，排列是按照字典序排序的；
 如果数组已经是字典序最大值，则返回字典序最小的排列；
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 
 
 题目解析：
 题目的描述很直接--找数组的下一个排列，但是看起来毫无头绪。
 我们先从一个简单例子入手：
 对于数字1，2，4，5这样的数组，先求出其下一个排列1、2、5、4。
 这个我们可以直接看出来，接下来尝试用程序化的语言来描述这个思维过程。
 从右到左遍历数组，对于位置为index的数字nums[index]，我们从index+1开始往右查找一位数字，要求尽可能接近nums[index]；
 如果能寻找到，则用其与nums[index]交换，接着从index+1开始的位置则从小到大排列。
 比如说1，2，4，5；我们找到4，其右边有一个数字5，将4和5交换，得到1，2，5；剩下的部分从小到大排列，这样可以得到下一个排列。
 
 特殊情况：
 比如说数组是从大到小排列，比如说3，2，1。
 此时下一个排列返回从小到大的排列，1，2，3即可。
 
 
 
 
 
 
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
    void nextPermutation(vector<int>& nums) {
        for (int index = (int)nums.size() - 2; index >= 0; --index) {
            int value = nums[index];
            int minDiff = -1, minIndex = -1;
            for (int j = index + 1; j < nums.size(); ++j) {
                if (nums[j] > value) {
                    if (minDiff == -1 || nums[j] - value < minDiff) {
                        minDiff = nums[j] - value;
                        minIndex = j;
                    }
                }
            }
            if (minIndex != -1) {
                int tmp = nums[minIndex];
                nums[minIndex] = nums[index];
                nums[index] = tmp;
                sort(nums.begin() + index + 1, nums.end());
                return ;
            }
        }
        sort(nums.begin(), nums.end());
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {4, 3, 1, 1, 3};
    leetcode.nextPermutation(nums1);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << " " << nums1[i];
    }
    
    return 0;
}
