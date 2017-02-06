//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 题目大意：
 
 
 题目解析：
 
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
