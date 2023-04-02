//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1788/problem/A)
 **题目大意：**
 在二维坐标系中，每次有两个走法：
 1、从(𝑥,𝑦) 到 (𝑥+1, 𝑦+1)；
 2、从(𝑥,𝑦) 到 (𝑥-1, 𝑦)；

 现在有初始点坐标(a, b)，想要到达坐标(c, d)，想知道最少的步数。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例1行，第一行整数𝑎, 𝑏, 𝑐, 𝑑  (−1e8≤𝑎,𝑏,𝑐,𝑑≤1e8 )
 
  
 **输出：**
 每个样例一行，输出最小的步数；如果不存在则输出-1；
 
 **Examples**
 **input**
 6
 -1 0 -1 2
 0 0 4 5
 -2 -1 1 1
 -3 2 -3 2
 2 -1 -1 -1
 1 1 0 2

 **output**
 4
 6
 -1
 0
 3
 3

 
 **题目解析：**
 由条件知道，y只能+1或者保持不动，那么先计算y坐标的变化，得到y移动的位置；
 剩下的位置只能走x-1的步数，如果x过小则误解，否则x坐标的差距就是剩余步数。
 
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int ok = 0, ans = 0;
            do {
                if (b > d) break;
                ans += d - b;
                a += d - b;
                if (a < c) break;
                ans += a - c;
                ok = 1;
            } while (0);
            cout << (ok ? ans : -1) << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
