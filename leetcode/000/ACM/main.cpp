//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.com/problems/add-two-numbers/description/)
 **题目大意：**
 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807

 **题目解析：**
 经典面试题。
 用链表加法，注意进位的考虑，以及边界情况。

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
public:
    int x, y;
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float ret = 0.0;
        int n = nums1.size(), m = nums2.size();
        int mid = (n + m + 1) / 2, k = 0;
        while (k < mid) {
            ret = getNext(nums1, nums2);
            ++k;
        }
        if ((n + m) % 2 == 0) {
            ret = (ret + getNext(nums1, nums2)) / 2.0;
        }
        return ret;
    }
    
    int getNext(vector<int>& nums1, vector<int>& nums2) {
        if (x == nums1.size()) {
            return nums2[y++];
        }
        if (y == nums2.size()) {
            return nums1[x++];
        }
        if (nums1[x] < nums2[y]) {
            return nums1[x++];
        }
        else {
            return nums2[y++];
        }
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
