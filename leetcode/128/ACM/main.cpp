//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/longest-consecutive-sequence/description/
 题目大意：
 
 
 题目解析：
 把数字x看成一个点，题意变成有若干个点，点x和点x-1、点x+1能够联通，问点数最多的联通子集有几个点。
 两个点集的合并，可以采用并查集的思想，每个点有个指针指向自己的父节点，初始状态是每个点指向自己；
 当点x,y合并的时候，只需要把f[x]=y，相当于把x的父节点指向y。
 从左到右遍历，做一遍并查集，就可以得到点数最多的集合。
 
 接下来是如何计算集合的点数，特别是题目数据存在重复的情况。
 
 
 
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
    int find(unordered_map<int, int> &f, int x) {
        if (f[x] == x)
            return x;
        return f[x] = find(f, f[x]);
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> f;
        unordered_map<int, int> vis;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            f[nums[i]] = nums[i];
            vis[nums[i]] = 1;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[nums[i] - 1] && find(f, nums[i] - 1) != find(f, nums[i])) { //nums[i] - 1有出现这个数字，并且两个集合的顶点不相同
                f[f[nums[i] - 1]] = f[nums[i]];
            }
            if (vis[nums[i] + 1] && find(f, nums[i] + 1) != find(f, nums[i])) {
                f[f[nums[i] + 1]] = f[nums[i]];
            }
        }
        
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[nums[i]] && find(f, nums[i]) != nums[i]) {
                vis[nums[i]] = 0;
                count[f[nums[i]]]++;
            }
            ans = max(ans, count[f[nums[i]]] + 1);
        }
        return ans;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 2, 0, 1};
    vector<int> nums2 = {100,4,200,1,3,2};
    vector<int> nums3 = {0,3,7,2,5,8,4,6,0,1};
    leetcode.longestConsecutive(nums3);
    
    return 0;
}
