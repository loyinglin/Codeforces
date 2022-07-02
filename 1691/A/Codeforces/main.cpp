//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1691/problem/A)
 **题目大意：**
 给出n个整数，求移除掉最少的整数，要求：
 剩下的整数中，任意两个相邻整数之和都是偶数；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例俩行，第一行 整数  𝑛 (3≤𝑛≤1e5)
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e9)
  
 **输出：**
 每个样例一行，输出最少的移除整数。
 
 
 **Examples**
 **input**
 2
 5
 2 4 3 6 8
 6
 3 5 9 7 1 3
 **output**
 1
 0
 
 
 **题目解析：**
 奇+奇=偶；
 偶+偶=偶；
 奇偶和偶奇都是奇数；
 所以剩下的整数中，要么全部是整数，要么全部是奇数；
 
 枚举下这两种情况即可。
 
 
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
            int x = 0, y = 0;
            while (n--) {
                int k;
                cin >> k;
                x += k % 2;
                y += (k + 1) % 2;
            }
            cout << min(x, y) << endl;
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
