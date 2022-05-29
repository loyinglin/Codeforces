//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1679/problem/A)
 **题目大意：**
 有两种车分别有4个轮子和6个轮子，现在只知道若干个车的轮子总数，想知道最少和最多有几辆车；
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤1000)
 每个样例一行 整数 𝑛，表示 𝑛个轮子 (1≤𝑛≤10e18)
  
 **输出：**
 每个样例一行，分别输出最少和最多有几辆车，如果没有则输出-1；
 
 
 **Examples**
 **input**
 4
 4
 7
 24
 998244353998244352
 **output**
 1 1
 -1
 4 6
 166374058999707392 249561088499561088
 
 
 **题目解析：**
 容易知道，如果n为奇数，则题目无解；
 n为偶数，如果n=2则无解，其他必然有解；
 最少的情况，全部用6轮，剩下的有2个轮子和4个轮子的情况；如果剩2个轮子，则总数+1（将1个6改成4就好）；如果剩4个轮子，则总数+1；
 最多的情况，全部用4轮，如果剩2个轮子，则总数不变（将1个4改成6就好）；
  
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
            lld n;
            cin >> n;
            if (n < 4 || n % 2) {
                cout << -1 << endl;
            }
            else {
                lld ansMin = (n / 6) + (n % 6 != 0);
                lld ansMax = (n / 4);
                cout << ansMin << " " << ansMax << endl;
            }
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
