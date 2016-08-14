//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/697/problem/A
    题目大意：输入三个整数t, s, x。问输入的整数x等于 t, t + s, t + s + 1, t + 2s, t + 2s + 1... 中的一个。
    题目解析： 分类讨论
 偏移量：ret = x - t。
 如果 ret < s， 只有 ret = 0；
 如果 ret >= s， 满足 ret % s = 0或者1 即可。
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
   
    lld t, s, x;
    cin >> t >> s >> x;
    lld ret = x - t, ans = 0;
    if (ret < s) {
        if (ret == 0) {
            ans = 1;
        }
    }
    else {
        if (ret % s == 0 || ret % s == 1) {
            ans = 1;
        }
    }
    
    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
