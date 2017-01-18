//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/merge-intervals/
 题目大意：
 给出n个数字区间，把有相交的区间合并起来。
 example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 
 
 题目解析：
 区间合并只需考虑最左和最右的边界。
 先排序，把可能合并到区间集合在一起。
 容易知道如果前面区间的right >= 当前区间的left 的时候，是可以合并的。
 那么遍历一遍，判断边界是否相交即可。
 
 
 复杂度解析：
 时间复杂度
 O(NlogN) N是区间个数，时间都在排序上；
 空间复杂度
 O(N)； 有可能返回N个结果。
 代码量
 比较函数有简单写法。
 sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
 
 其他解法：
 没有思考其他解法。
 
 
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
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

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
    vector<Interval> merge(vector<Interval>& intervals) {
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
    vector<Interval> vec;
    vec.push_back(Interval(1, 3));
    vec.push_back(Interval(2, 6));
    vec.push_back(Interval(10, 11));
    vec.push_back(Interval(8, 9));
    leetcode.merge(vec);
    
    return 0;
}
