//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/B)
 **题目大意：**
 给出一个数字n，求出[1,n]的区间中，有多少整数是可以满足，所有数字都是相同的。
 
 
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
 如果直接遍历数字1到n，可以算出来有多少个整数满足要求。
 因为n比较比较大，这种做法会超时。
 注意到满足要求的数字应该不多，我们可以直接满足要求的数字：
 先看一位数的有多少个数字；
 再看二位数的有多少个数字；
 ...
 直到枚举出来的数字，比n还要大。
 
 
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
    static const int N = 100010;
public:
    int n, m;
    string str;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            int ans = 0;
            int current = 1, cnt = 1;
            while (current * cnt <= n) {
                ++ans;
                ++cnt;
                if (cnt > 9) {
                    current = current * 10 + 1;
                    cnt = 1;
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
