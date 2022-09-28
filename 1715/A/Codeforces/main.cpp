//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1715/problem/A)
 **题目大意：**
 在一个n x m的方格矩阵中，小明要从左上角（1，1）到右下角（n，m），小红要从左下角（n，1）到右上角（1，m）；
 每个相邻格子的行动代价是1；
 小红先出发，沿路中每个经过格子都会放下一个传送器，这个不需要代价；
 小明晚出发，小明如果站在某个有传送器的格子，那么可以花费1代价，传送到另外一个有传送器的格子；
 问小红和小明到达目的，总的代价最小为多少；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤1000)
 每个样例第一行 整数   𝑛, 𝑚 ( (1≤𝑛,𝑚≤1e5)
  
 **输出：**
 每个样例一行，输出最小的总代价；
 
 
 **Examples**
 **input**
 7
 7 5
 5 7
 1 1
 100000 100000
 57 228
 1 5
 5 1
 **output**
 15
 15
 0
 299998
 340
 5
 5
 
 
 **题目解析：**
 在没有传送器的情况下，小红和小明的路径总代价都是n+m；
 假设小红不考虑小明，按照最短路径到达，总代价是n+m；然后小明借助小红的路径，理论上能节省的最大路径是max(n, m)-1，总的代价就是n+m+max(n, m)-1；
 此时路径应该就是小红先走到(1, 1)，再走到(1, m）；
 有没有可能小红为了让小明能够尽可能传送，特意绕路？不会，因为小红要走过的路才能让小明传送；所以一旦远离小红的最优路径n+m，所有给小明节省的代价，其实都是不划算的.
 注意：边界情况要考虑，n=1 和 m=1。
 
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
            int n, m;
            cin >> n >> m;
            if (n == 1 || m == 1) {
                if (n == m) cout << 0 << endl;
                else cout << max(n, m) << endl;
            }
            else cout << (n + m - 2) * 2 - max(n, m) + 2 << endl;
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
