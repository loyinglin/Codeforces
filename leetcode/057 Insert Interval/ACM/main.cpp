//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/insert-interval/
 题目大意：
 给出n个不重叠的区间[x, y]，并且按照起始坐标x进行从小到大的排序；
 现在新增一个区间[a, b]，为了保持区间不重叠，对区间进行merge，问剩下的区间有哪些；
 
 Example:
 Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 Output: [[1,2],[3,10],[12,16]]
 Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
 题目解析：
 最直接的做法是对所有区间进行处理，分情况讨论：
 1、区间[x, y]与[a, b] 无重叠，则不变换；
 2、区间[x, y]与[a, b] 有部分重叠，则拿出来特殊处理；
 最后从情况2的所有区间和[a, b]中找到一个区间的起始最小值、结束最大值，作为新的区间。
 
 但是这样的代码复杂度比较高，更简洁的做法可以是：
 1、把区间[a, b]放入n个区间中，按起始和结束位置从小到大排序；
 2、如果区间i的起始位置<=区间i-1的结束位置，则认为是一个区间；
 
 复杂度解析：
 方法1
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 方法2
 时间复杂度是O(NLogN)
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
