//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/3sum-closest)
 **题目大意：**
 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 示例：
 输入：nums = [-1,2,1,-4], target = 1
 输出：2
 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
  

 提示：
 3 <= nums.length <= 10^3
 -10^3 <= nums[i] <= 10^3
 -10^4 <= target <= 10^4

 
 **题目解析：**
 假如不考虑复杂度，可以枚举3个数，复杂度是O(N^3）；
 加一个优化，先对数组排序，随机选择2个数之后，接下来可以用二分来查找剩下的数字，复杂度是O(N^2 · LogN)；
 
 如果还想优化呢？
 在排序完之后，我们仍然使用枚举固定第一个元素a，并且要求剩下两个元素b和c在元素a的右边；（因为顺序并不重要）
 问题变成了在区间中寻找两个数字，其和尽可能接近target-a，就是普通的双指针问题，比如说：
 在一个从小到大的数组中有n个元素，找到两个元素b和c，使得和尽可能接近x；
 
 令b=x[1], c=x[n]，假如b+c>x，那么x[2]、x[3]和x[n]的和 只会更大，所以可以直接跳过，令c=x[n-1]；
 同理，如果b+c<x，那么b+x[n-1] <= b + x[n]，所以可以直接跳过，令 b=x[2];
 
 这样总的复杂度就是O(NLogN)的排序，加上O(N^2)的枚举；
 
 这里考虑到实现成本，使用的是简单法。

 
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

//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        int n = nums.size();
//        int dif = 0x7fffffff, ret = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                for (int k = j + 1; k < n; ++k) {
//                    int tmp = nums[i] + nums[j] + nums[k];
//                    if (abs(tmp - target) < dif) {
//                        dif = abs(tmp - target);
//                        ret = tmp;
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//}leetcode;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int dif = 0x7fffffff, ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int tmp = nums[i] + nums[j] + nums[k];
                    if (abs(tmp - target) < dif) {
                        dif = abs(tmp - target);
                        ret = tmp;
                    }
                }
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
