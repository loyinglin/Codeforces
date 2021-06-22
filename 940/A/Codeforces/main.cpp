//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/940/problem/A)
 **题目大意：**
 给出n个整数，还有一个数字d；
 要求去除最少的数字，使得剩余数字的最大最小值差不大于d；
 
 **输入数据：**
 n and d (1 ≤ n ≤ 100, 0 ≤ d ≤ 100)
 (1 ≤ x[i] ≤ 100)
 
 >**Examples**
 **input**
 3 1
 2 1 4
 **output**
 1
 
 
 
 **题目解析：**
 方法1：
 贪心。假设最后的结果是区间是[left, right]，那么小于left、大于right的数字全部要抛弃。
 先对数组排序，假设数字a[i]是left，那么通过二分查找right=a[i]+d，可以快速算出应该要抛弃的数字。
 
 方法2：
 暴力。先排序，枚举保留的数据区间[left, right]，计算是否满足最大最小值差小于d。
 
 方法3：
 扫描线。先排序，从左到右扫描，保持一个最大最小值差小于d的区间；如果区间不满足，则从区间左边抛弃元素。
 
  **思考🤔：**
 
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
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int right = upper_bound(a, a + n, a[i] + d) - a;
        ans = min(ans, i + n - right);
    }
    cout << ans << endl;
    
    
    return 0;
}
