//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/707/problem/A
    题目大意：输入n * m个字符，字符中存在C M Y为混色，否则为黑白，输出对应的描述。
 
 Examples
 input
 2 2
 C M
 Y Y
 output
 #Color
 
 input
 3 2
 W W
 W W
 B B
 output
 #Black&White
 
 
    题目解析：
 难度在读题，黑白不仅仅是W B，还有G。
 
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
const int N = 101000, M = 3010100, inf = 10110110;

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
   
    int n, m, ret = 1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char str[10];
            scanf("%s", str);
            if (str[0] == 'C' || str[0] == 'M' || str[0] == 'Y') {
                ret = 0;
            }
        }
    }
    if (!ret) {
        cout << "#Color";
    }
    else {
        cout << "#Black&White";
    }
    

    
    return 0;
}
