//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/container-with-most-water/
 题目大意：

 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

 说明：你不能倾斜容器，且 n 的值至少为 2。

  



 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

  

 示例：

 输入：[1,8,6,2,5,4,8,3,7]
 输出：49
 
 
 题目解析：
 暴力，O(N^2)；
 递增序列优化，常数优化；
 面对1，2，3，4这种bad case，还是一样；
 
 一种O(N)的解法如下：
 对于数组height[0~n-1]，假设最左边的数是x，最右边的数是y；
 我们容易知道x和y组合形成的池子是width*min(x,y)；
 假如x<y，那么对于节点x而言，选择节点y组成形成池子已经是最优解；（因为width*height的公式中，width已经是数组最大宽度，height已经是x的最大值）
 那么保存完这个计算结果，实际上x已经可以抛弃！这样便减少了n-1运算！
 重复以上过程，可以使得算法时间复杂度为O(N)；
 
 
 
 
 
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

//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        long long ans = 0, size = 0;
//        for (long long i = 0; i < height.size(); ++i)
//            for (long long j = i + 1;j < height.size(); ++j)
//                ans = max(ans, min(height[i], height[j]) * (j - i));
//        return ans;
//    }
//};
//
//
typedef long long lld;
const int N = 50000;

//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int ans = 0;
//        vector<pair<int, int> > vec;
//        vec.push_back(make_pair(height[0], 0));
//
//        for (int i = 1; i < height.size(); ++i) {
//            for (int index = 0; index < vec.size(); ++index) {
//                int width = i - vec[index].second;
//                int tmp = min(height[i], vec[index].first) * width;
//                ans = max(ans, tmp);
//            }
//
//            if (height[i] > vec.back().first) {
//                vec.push_back(make_pair(height[i], i));
//            }
//        }
//
//        return ans;
//    }
//
//}leetcode;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                ++left;
            }
            else {
                --right;
            }
        }
        return ans;
    }
    
}leetcode;

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,8,6,2,5,4,8,3,7};
    vector<int> nums2 = {1,3,2,5,25,24,5};
    vector<int> nums3 = {1,2,3,4,5,6,7,8,9,10};
    leetcode.maxArea(nums3);
    
    return 0;
}
