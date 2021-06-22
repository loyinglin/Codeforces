//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/C)
 **题目大意：**
 给出一个数字n，构造n*n的矩阵，要求：
 相邻的数字，绝对值只差要大于1；
 每个数字可以和上下左右，四个方向的数字相邻；
 矩阵中的数字是1~n*n，没有重复；
 
 **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤100).
 每个样例第一行是整数𝑛 (1≤𝑛≤100).
 **输出：**
 如果有解，则输出n行，每行n个整数；
 如果无解则输出-1；
 
 **Examples**
 **input**
 3
 1
 2
 3

 
 **output**
 1
 -1
 2 9 7
 4 6 3
 1 8 5
 
 **题目解析：**
 1只有一个解，2无解；
 从3开始，可以采用间隔的方式先填充数字；
 1 0 2
 0 3 0
 4 0 5
 如上，先从上到下，从左到右填充；
 最后补齐
 1 5 2
 6 3 7
 4 8 5
 因为我们都是间隔着填充，相邻的数字只差，肯定大于1，满足要求。
 
 
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
    int a[101][101];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            if (n == 1) {
                cout << 1 << endl;
            }
            else if (n == 2) {
                cout << -1 << endl;
            }
            else {
                int cnt = 1, x = 0, y = 0;
                while (cnt <= n*n) {
                    a[x][y] = cnt;
                    ++cnt;
                    y += 2;
                    if (y >= n) {
                        x += 1;
                        y -= n;
                    }
                    if (x >= n) {
                        x = 0;
                        y = 1;
                    }
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
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
