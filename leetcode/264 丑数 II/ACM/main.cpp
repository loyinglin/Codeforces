//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/ugly-number-ii/)
 **题目大意：**
 给你一个整数 n ，请你找出并返回第 n 个 丑数 。

 丑数 就是只包含质因数 2、3 or 5 的正整数。

 **题目解析：**
 如果不考虑复杂，可以从1、2、3开始枚举，不断判断数字是否满足要求；（判断方式就是用2、3、5去除，最终结果是1）
 但是这样复杂度会比较高，中间会经历较多无用的数字。
 
 考虑刚刚的判断方式，是用2、3、5去判断是否整除，那么直接用2、3、5相乘，来得到整数即可保证得到的整数都满足要求，从而过滤掉很多无用的整数。
 那怎么保证是从小到大呢？
 
 这里可以用优先队列，每次吐出队列中的最小数字；
 初始状态则只需要放入2、3、5，每次拿到最小数字，则继续乘以2、3、5再放回队列中。

 
 **思考：**
 注意int越界的问题。
 
 
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

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        priority_queue<lld, vector<lld>, greater<lld> > q;
        unordered_map<lld, lld> h;
        lld cnt = 1, cur = 1;
        q.push(1);
        while (cnt <= n) {
            cur = q.top();
            q.pop();
            ++cnt;
            if (!h[cur * 2]) {
                h[cur * 2] = 1;
                q.push(cur * 2);
            }
            
            if (!h[cur * 3]) {
                h[cur * 3] = 1;
                q.push(cur * 3);
            }
            
            if (!h[cur * 5]) {
                h[cur * 5] = 1;
                q.push(cur * 5);
            }
            
        }
        
        return cur;
    }
}lc;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    cout << lc.nthUglyNumber(1690) << endl;
    
    return 0;
}
