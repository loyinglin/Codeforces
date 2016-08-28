//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/697/problem/A
 题目大意：
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
lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    string ret = "I hate ";
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            ret += "that I love ";
        }
        else {
            ret += "that I hate ";
        }
    }
    ret += "it";
    cout << ret << endl;
    
    return 0;
}
