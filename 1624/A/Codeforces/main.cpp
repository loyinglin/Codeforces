//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1624/problem/A)
 **题目大意：**
 给出一个数组长度为n，每次可以选择若干个数字，将其数字+1；
 问最少需要操作几次，才能让整个数组内的元素值相等。
 
  **输入：**
 第一行，样例数𝑡 (1≤𝑡≤1e4)
 每个样例两行，第一行整数𝑛  (1≤𝑛≤50)
 第二行𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9)
 
 **输出：**
每个样例一行，输出最小的操作次数。
 
 **Examples**
 **input**
 3
 6
 3 4 2 4 1 2
 3
 1000 1002 998
 2
 12 11
 
 **output**
 3
 4
 1
 
 **题目解析：**
 由贪心的思想，由最大值减去最小值就能得到最多需要操作次数k；
 因为其他数字和最大值的差距，不会比这个值更大，肯定可以在k次操作内完成。
 
 
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
    string str;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            int valMin = a[0], valMax = a[0];
            for (int i = 1; i < n; ++i) {
                valMin = min(valMin, a[i]);
                valMax = max(valMax, a[i]);
            }
            printf("%d\n", valMax - valMin);
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
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
