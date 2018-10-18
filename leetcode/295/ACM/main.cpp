//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/find-median-from-data-stream/?tab=Description
 题目大意：
 实现一个数据结构，其中有两个函数：
 1、addNum 添加一个数字；
 2、findMedian 找到已有数字的中位数；
 
 example:
 addNum(1)
 addNum(2)
 findMedian() -> 1.5
 addNum(3)
 findMedian() -> 2
 
 题目解析：
 插入，可以用链表；
 找中位数，可以用朴素的遍历；
 这样，每次的时间复杂度O(N)。
 
 另外一种简单的实现是：把链表分成两部分，维护一个最大堆，一个最小堆。
 这样只要每次看看数字的大小，分别放到左右两个堆就行；
 为了方便寻找中位数，要保证最大堆和最小堆的size大小差别不超过1；
 
 每次操作的复杂度都是O(logN)；
 
 
 
 
 
 其他解法：
 老老实实用链表+遍历。
 
 
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


class MedianFinder {
    
public:
    priority_queue<int> little;
    priority_queue<int, vector<int>, greater<int> > big;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        little.push(num);
        big.push(little.top());
        little.pop();
        if (little.size() < big.size()) {
            little.push(big.top());
            big.pop();
        }
        cout << findMedian() << endl;
    }
    
    double findMedian() {
        double ret = 0.0;
        if (little.size() == big.size()) {
            ret = (little.top() + big.top()) / 2.0;
        }
        else {
            ret = little.top();
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    leetcode.addNum(1);
    leetcode.addNum(2);
    leetcode.addNum(3);
    
    
    return 0;
}
