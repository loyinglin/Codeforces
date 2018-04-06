//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 ####1.Numbers Exchange
 [题目链接](http://codeforces.com/contest/749/problem/B)
 **题目大意：**
 给出平行四边形的三个点(x[i], y[i])，求出可能的第四个点的坐标。
 先输出可能数m，接下来m行，每行两个数，表示点的x和y坐标。
 
 
 **输入数据：**
 xi and yi ( - 1000 ≤ xi, yi ≤ 1000)
 
 >**Examples**
 **input**
 0 0
 1 0
 0 1
 **output**
 3
 1 -1
 -1 1
 1 1
 
 **题目解析：**
 给出平行四边形的三个点，那么三个点必然可以连成一个三角形。
 过三角形的每条边，都可以做一个平行四边形，所以可能的点固定为3个。
 
 ```
 cout << 3 << endl;
 cout << a[0] + (c[0] - b[0]) << " " << a[1] + (c[1] - b[1]) << endl;
 cout << b[0] + (a[0] - c[0]) << " " << b[1] + (a[1] - c[1]) << endl;
 cout << c[0] + (b[0] - a[0]) << " " << c[1] + (b[1] - a[1]) << endl;
 ```
 
 **思考🤔：**
 
 
 
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[2], b[2], c[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    cout << 3 << endl;
    cout << a[0] + (c[0] - b[0]) << " " << a[1] + (c[1] - b[1]) << endl;
    cout << b[0] + (a[0] - c[0]) << " " << b[1] + (a[1] - c[1]) << endl;
    cout << c[0] + (b[0] - a[0]) << " " << c[1] + (b[1] - a[1]) << endl;
    
    return 0;
}
