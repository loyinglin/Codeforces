//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/706/problem/A
    题目大意：点A在（a，b），n个点以速度v[i]，向A靠近，求最短时间。
 输入：
 点A的a，b；
 还有n个x,y,v 表示点的坐标(x, y)和速度v。
 
    题目解析：
 计算每个点与A的距离，除以对应的速度v，取最小时间即可。
 
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
const int N = 10100, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    cin >> a >> b;
    
    int n;
    cin >> n;
    
    double minTime = 0x1.fffffep+127f;
    while (n--) {
        int x, y, v;
        cin >> x >> y >> v;
        minTime = min(minTime, sqrt((x- a) * (x - a) + (y - b) * (y - b)) / v);
    }
    printf("%.7f", minTime);
    
    return 0;
}
