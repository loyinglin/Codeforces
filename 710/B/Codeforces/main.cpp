//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/710/problem/B
 题目大意：输入n个x轴上的点，输出和n个点距离最近的点，如果有多个点，输出最左边的那个。
 题目解析：
 对点排序，易知最后的点在最中间。
 
 对于在[A, B]中的点x，易知x到A和B的距离是固定；
 那么对于[A, B, C]的最优解，必然是在B；
 同上，在[A,B,C,D]中，点x到A和D的距离是固定的，同时与x到[B, C]的最优解的重叠。
 ...
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
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
lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int mid = 1;
    if (n > 1) {
        mid = (n + 1) / 2;
    }
    cout << a[mid - 1] << endl;
   
    
    
    return 0;
}
