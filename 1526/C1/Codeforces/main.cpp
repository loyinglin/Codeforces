//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1526/problem/C1)
 **题目大意：**
 给出n个整数的数组，从左到右可以依次选择若干个整数，要求累加和在过程中始终不能为负数。
 已知初始数字和为0，想知道最多能选择多少个数字。
 
 **输入：**
 第一行是整数 𝑛 (1≤𝑛≤2000)
 第二行是n个整数𝑎1 , 𝑎2, ... ,𝑎𝑛 (−1e9≤𝑎𝑖≤1e9)
 **输出：**
 输出能选择的最多整数。
 
 **Examples**
 **input**
 6
 4 -4 1 -3 1 -3
 **output**
 5

 
 **题目解析：**
 一种简单的策略：
 遇到正的就吃，遇到负的就看当前能否吃下，能够吃则直接吃；
 如果不能吃，则考虑是否将吃过的负数吐出来，如果存在某个负数的绝对值 比这个数字的绝对值要大，则可以把原来的负数吐出来，把这个数字吃进去；
 
 可以用优先队列来记录负数，复杂度O（NlogN）；
 
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
