//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/701/problem/B
    题目大意：NxN的棋盘，每个格子可以放一个车，有M个车，问：每个车放完后，棋盘还剩多少格子是所有车攻击范围外？
    题目解析：
 棋盘放下去一个车有横竖的影响，分开考虑。
 对于横行，如果之前已经放过，没有影响；如果之前没有放过，那么看有多少列已经添加，得出影响到的cell为n - colNum;
 对于纵列，如果之前已经放过，没有影响；如果之前没有放过，那么看有多少行已经添加，得出影响到的cell为n - rowNum;
 如果行和列都没添加过，那么会有个重叠的计算，需要去除：sum = sum + 1;
************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];

int row[N], col[N];


int main(int argc, const char * argv[]) {
    // insert code here...
   
    long long n, m, sum;
    cin >> n >> m;
    sum = n * n;
    long long rowNum, colNum;
    rowNum = colNum = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (!row[x]) {
            sum -= n - colNum;
        }
        if (!col[y]) {
            sum -= n - rowNum;
        }
        if (!row[x] && !col[y]) {
            ++sum;
        }
        if (!row[x]) {
            ++rowNum;
            row[x] = 1;
        }
        if (!col[y]) {
            ++colNum;
            col[y] = 1;
        }
        
        cout << sum << " ";
    }
    
    
    return 0;
}
