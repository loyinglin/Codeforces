//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/703/problem/C
    题目大意：n个点形成的多边形，整体以v的速度向x轴负方向移动；点P从（0，0）向（0，w）以最大u的速度前进。问，不撞到多边形的最短到达时间。（相交不算碰撞）
    题目解析：
 为了达到最短时间，并且点与多边形碰撞，可以知道会有如下结果：
 1、点直接到（0，w）；
 2、点在行进过程中等待若干时间，到达（0，w）；
 
核心：变换参考系，假设多边形不动，把v的速度叠加到点P上，那么变成点P以-v的速度在x轴运动。
求出每个点相对点P的速度斜率曲线在X轴上的距离，得到最大和最小的两个值minT和maxT。
 如果minT>=0或者MaxT<=0，点P可以直接到达点w；（多边形太远和太近两种情况）
 其他情况，点P要在x轴移动maxT的距离，再直线到达点w。（在x轴移动maxT的距离相当于等待maxT/v的时间）

************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N], flag[N], c[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    long long sum = 0, ans = 0, n, w, v, u;
    cin >> n >> w >> v >> u;
    double k = u * 1.0 / v, ret = 0, l = w * 1.0 / u, minT = 10E9, maxT = -10E9;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        double t = y - k * x;

        minT = min(minT, -t / k);
        maxT = max(maxT, -t / k);
    }
    if (minT >= 0) {
        ret = l;
    }
    else if (maxT <= 0) {
        ret = l;
    }
    else {
        ret = l + maxT / v;
    }
    printf("%.6lf", ret);
    
    
    return 0;
}
