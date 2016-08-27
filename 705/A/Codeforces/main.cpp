//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/705/problem/A
    题目大意：输入n，输出一个字符串。
    题目解析：
 n = 1：I hate it
 n = 2：I hate that I love it
 n = 3：I hate that I love that I hate it
  ...
 
把字符串分割成三部分"I hate  " + ... + "it"，再根据n构建中间的字符串。

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
