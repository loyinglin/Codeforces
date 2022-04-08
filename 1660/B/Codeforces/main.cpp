//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/B)
 **题目大意：**
 小明有n种糖果，每种糖果分别有a[i]颗；
 现在小明开始吃糖果，并且每次只吃剩下糖果数量最多的那种，如果有多种则可以任意选择一种数量最多的糖果；
 
 小明想知道最终，能不能吃完所有糖果，并且满足没有连续2天吃到一样的糖果；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例两行，第一行整数 𝑛 (1≤𝑛≤2⋅1e5)
 第二行是n个整数𝑎𝑖 (1≤𝑎𝑖≤1e9)
 
 **输出：**
 每个样例一行，如果可以输出YES，如果不行则输出NO；
 
 
 **Examples**
 **input**
 4
 aabbcc
 aaab
 aaa
 abba
 
 **output**
 0
 2
 1
 2

 **题目解析：**
 因为题目限定了每次只吃数量最多的糖果，那么可以将数组排序，这样方便后续抉择；
 我们唯一能选的，就是当出现两种糖果一样多情况，我们要如何吃；
 容易知道，假如有两个糖果一样多，只要交替吃就行了；
 那么问题就变成，最多和次最多的两个糖果，能不能顺利达到数量一致的情况；
 容易知道相差超过1就无法达到，因为需要连续两天吃一样的最多数量的糖果。
 
 
 
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
    static const int N = 201010;
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
            sort(a, a + n);
            bool ans = 0;
            if (n == 1) {
                ans = a[0] <= 1;
            }
            else {
                ans = (a[n - 1] - a[n - 2]) <= 1;
            }
            cout << (ans ? "YES" : "NO") << endl;
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
 */
