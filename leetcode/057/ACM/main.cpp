//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/insert-interval/
 题目大意：
 给出n个区间
 
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



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool cmp(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    else {
        return b.end < a.end;
    }
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        if (intervals.empty()) return vector<Interval>{};
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ret.back().end < intervals[i].start) { // 新的段
                ret.push_back(intervals[i]);
            }
            else {
                ret.back().end = max(ret.back().end, intervals[i].end);
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
