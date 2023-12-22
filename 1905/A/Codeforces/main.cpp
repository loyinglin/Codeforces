//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1905/problem/A)
 **题目大意：**
 有若干个城市在洪水后被冲毁，现在需要重建；
 我们用n x m的矩阵来表示，每个元素都代表一个城市，元素为0表示城市被摧毁，元素为1表示该城市被重建了；
 城市重建有两种方式，首先是指定若干个城市直接重建；
 另外一种方式，是由其他城市协助重建，可以被协助重建的条件是：
 当且仅当这个城市在横、竖两个方向上，都有相邻的城市已经被重建。
 比如说
 10
 11
 右上角的城市就可以被协助重建。
 
 ![如图](https://espresso.codeforces.com/995260d4ec6a62f7330ebf81c0119033d415a785.png)
 
 现在想知道最少需要指定多少个城市，才能让所有城市都被重建。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行，整数 𝑛  and 𝑚  (2≤𝑛,𝑚≤100 )
 
 **输出：**
 每个样例一行，输出满足要求的最小重建数量。
 
 
 **Examples**
 **input**
 3
 2 2
 5 7
 3 2



 **output**
 2
 7
 3

 **题目解析：**
 首先从小样例情况开始分析，容易知道n=2，m=2的情况是：
 01
 10
 或者
 10
 01
 剩下的城市协助重建即可。
 
 当增加到3x3时候，考虑可以直接从2x2的基础上开始思考，并且为了充分利用协助重建，我们可以假设2x2已经完全重建。
 110
 110
 000
 这样我们很容易想到，只需要在右下角添加 一个1，剩下的1可以自动补齐。

 至此，我们很容易得到一个策略，就是不断在右下角添加数字，得到一个最优解。

 
 
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
    int dir[4][2] = {1,1,  -1,1,  1,-1,   -1,-1};
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            /*
             01010
             10101
             01010
             10101
             */
//            int x = m / 2, y = (m + 1) / 2;
//            cout << (n + 1) / 2 * x + n / 2 * y << endl;
            /*
             01000
             10000
             00100
             00011
             */
            cout << 2 + max(n - 2, m - 2) << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
