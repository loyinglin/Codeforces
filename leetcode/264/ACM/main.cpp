//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/ugly-number-ii/)
 **题目大意：**
 

 **题目解析：**


 
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
