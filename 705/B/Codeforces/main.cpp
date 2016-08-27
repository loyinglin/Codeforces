//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/705/problem/B
    题目大意：一个游戏，每次把一个数字x拆成两个数字i,j并且i + j = x。输入n个数字，输出当前结果。
    题目解析：
 
 先手必胜为0， 先手必败为1.
 那么有
 0 + 1 = 0
 1 + 0 = 0
 0 + 0 = 1
 1 + 1 = 1
 
 异或操作符嘛。
 

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
lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n, t = 1; // 1表示先手必败 0表示先手必胜
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k != 1) {
            t = 1 -( t ^ (k % 2));
        }
        cout << t + 1 << endl;
    }
    
    return 0;
}
