//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1526/problem/C1)
 **题目大意：**
 
 
 
 
 **输入：**
 第一行是整数t，表示有t个样例(1≤𝑡≤1e4).
 每个样例一行，第一行是整数n(1≤𝑛≤1e9).
 **输出：**
 每个样例一行，输出1到n的整数中，有多少个由相同数字组成的数。

 
 **Examples**
 **input**
 6
 1
 2
 3
 4
 5
 100

 **output**
 1
 2
 3
 4
 5
 18

 
 
 **题目解析：**
 一种简单的策略：
 遇到正的就吃，遇到负的就看当前能否吃下，能够吃则直接吃；
 如果不能吃，则考虑是否将吃过的负数吐出来，如果存在某个负数的绝对值 比这个数字的绝对值要大，则可以把原来的负数吐出来，把这个数字吃进去；
 
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

class Solution {
    static const int N = 200010;
public:
    int a[N];
    priority_queue<int, vector<int>, greater<int> > q;
public:
    void solve() {
        int t = 1;
        while (t--) {
            int n;
            cin >> n;
            while (!q.empty()) {
                q.pop();
            }
            lld sum = 0, ans = 0;
            for (int i = 0; i < n; ++i) {
                int tmp;
                scanf("%d", &tmp);
                if (sum + tmp >= 0) {
                    ++ans;
                    sum += tmp;
                    if (tmp < 0) {
                        q.push(tmp);
                    }
                }
                else {
                    int top = 0;
                    if (!q.empty()) {
                        top = q.top();
                    }
                    if (top < tmp) {
                        q.pop();
                        q.push(tmp);
                        sum = sum - top + tmp;
                    }
                }
            }
            cout << ans << endl;
            
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 
 8
 4 -4 -3 -2 -1 -1 -1 -1
 
 */
