//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
 题目大意：
 给出一个整数数组nums，数组里每个数字各不相同；
 数组原来是以递增的顺序排列如[0,1,2,4,5,6,7]，经过变换后，从某个位置开始的元素挪到了数组后半部分，如[4,5,6,7,0,1,2]；
 现在给出变换后的数组nums和某个数字target，问target在数组中的索引，如果不存在则输出-1；
 要求时间复杂度在O(logN)的级别；
 
 Example 1:
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 Example 2:
 
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 
 题目解析：
 在一个有序的数组，查找某个数字的索引，可以通过二分法的方式快速定位；
 题目的难点在于数组经过变换后，失去了完整的有序信息；
 如果把变换后的数组，用二维坐标系的方式表达，会是是如下的结果：
 
 在两段线段内部，可以使用二分查找。
 这里可以用增量查询的方式来定位分段的位置，比如说当前的位置是index；
 如果nums[index]<nums[index+1]，我们可以认为[index, index+1]是在同一段；
 并且如果1满足，则尝试index+1+2，再尝试index+1+2+4，直到不满足之前的条件，则怎么跨段了，此时降级从index+1开始计算；
 
 对于某一段[index, index+k]，我们通过上诉的方法判断得到是同一段，接下来在这一段里面查找target；
 如果target<num[index] 或者 target > num[index+k]，则肯定不在这一段，可以跳过；
 如果是其他条件，则同样降级到index+1；
 
 通过这个方法，可以快速定位到target，并且速度非常快！
 
 
 target < nums[index] 是很重要的剪枝，否则当target在数组中不存在时，很容易降级为O(N)的算法。
 
 
 
 
 
 复杂度解析：
 
 
 
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
    int search(vector<int>& nums, int target) {
        return look(nums, target, 0, 1);
    }
    
    int look(vector<int>& nums, int target, int index, int gap) {
        if (index >= nums.size()) {
            return -1;
        }
        if (nums[index] == target) {
            return index;
        }
        if (index + gap < nums.size() && nums[index + gap] > nums[index] && (nums[index + gap] < target || target < nums[index])) {
            return look(nums, target, index + gap, gap * 2);
        }
        else {
            return look(nums, target, index + 1, 1);
        }
    }
    
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << leetcode.search(nums1, 0);
    
    return 0;
}
