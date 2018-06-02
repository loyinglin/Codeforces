//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Numbers Exchange
 [题目链接](http://codeforces.com/contest/980/problem/C)
 **题目大意：**

 **输入数据：**

 >**Examples**
 **input**
 **output**

 **题目解析：**
 根据题意，我们知道左上角（1，1）目标点是右下角（4，n），左下角（4，1）目标点是右上角（1，n）；
 在题目给出的要求中，是要最短路径的步数相同；
 那么我们知道这个最短的步数，必然是n+2，为什么？
 因为边界的四周是不允许修建旅店，那么必然存在一条沿着四周的最短路径，且步数一定是n+2;
 并且这n+2步中，必然是(n-1)步是向右，2步向下（or向上）；
 容易知道，如果把向下看成向上，对于左下角（4，1）目标点是右上角（1，n）的路径，我们把图上下颠倒，可以得到结论：
 如果图关于x轴对称（上下对称，那么满足要求）；
 
 问题是，怎么证明关于y轴对称（左右对称），也是满足要求的呢？
 

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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[111][11];


int main(int argc, const char * argv[]) {
    // insert code here...

    int n , k;
    cin >> n >> k;

    if (k == 1) {
        cout << "NO" << endl;
    }
    else {
        int col = 1;
        if (k % 2) {
            --k;
            ++col;
            a[2][1] = 1;
        }
        for (int i = 0; i < k / 2; ++i) {
            a[1][col + i] = a[2][col + i] = 1;
        }

        puts("YES");
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) {
                    putchar('#');
                }
                else {
                    putchar('.');
                }
            }
            puts("");
        }
    }


    return 0;
}
