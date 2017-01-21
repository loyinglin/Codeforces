//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/jump-game-ii/
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
    int step, pos;
    Node() {
        step = pos = 0;
    }
    Node(int s, int p) {
        step = s;
        pos = p;
    }
    
    bool operator<(const Node &tmp) const
    {
        if (step != tmp.step) {
            return step > tmp.step;
        }
        else {
            return pos < tmp.pos;
        }
    };
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        vector<int> step(nums.size(), 0);
        queue<Node> q;
        q.push(Node(0, nums[0]));
        int maxRight = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            while (q.front().pos < i) {
                q.pop();
            }
            ret = q.front().step + 1;
            if (i + nums[i] > maxRight) {
                maxRight = i + nums[i];
                q.push(Node(ret, i + nums[i]));
            }
        }
        return ret;
    }
}lc;

/*
struct Node {
    int step, pos;
    Node() {
        step = pos = 0;
    }
    Node(int s, int p) {
        step = s;
        pos = p;
    }
    
    bool operator<(const Node &tmp) const
    {
        if (step != tmp.step) {
            return step > tmp.step;
        }
        else {
            return pos > tmp.pos;
        }
    };
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        vector<int> step(nums.size(), 0);
        priority_queue<Node> q;
        q.push(Node(0, nums[0]));
        for (int i = 1; i < nums.size(); ++i) {
            while (q.top().pos < i) {
                q.pop();
            }
            ret = q.top().step + 1;
            q.push(Node(ret, i + nums[i]));
        }
        return ret;
    }
}lc;
*/

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,1,2,3,3};
    vector<int> nums2 = {2};
    lc.jump(nums1);
    
    return 0;
}
