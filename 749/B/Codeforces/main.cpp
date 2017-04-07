//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/749/problem/B
 题目大意：
 给出平行四边形的三个点，求出可能的第四个点的坐标。
 
 
 
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
