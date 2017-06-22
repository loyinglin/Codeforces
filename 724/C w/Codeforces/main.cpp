//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/724/problem/C
 题目大意：
 n*m的范围内，有k个感应器，位置为(x[i], y[i]);
 有一道光线从(0, 0)出发，方向是(1, 1), 速度是 sqrt(2);
 光线触碰到n*m的边界会反弹，入射角=反射角；如果碰到四个顶点则会直接停止；
 
 输入n、m、k表示n*m范围和k个感应器；
 再输入k个感应器的位置；
 
 输出每个感应器经过的时间，如果不经过则为-1；
 Examples
 input
 3 3 4
 1 1
 1 2
 2 1
 2 2
 output
 1
 -1
 -1
 2
 
 
 
 题目解析：
 
 
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
const int N = 101001;

lld  f[N];
lld  a[N];
lld  p[N];
lld  ans[N];
lld  sum[N];


int main(int argc, const char * argv
         []) {
    
    int n;
    
    
    return 0;
}
