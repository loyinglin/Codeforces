//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/710/problem/A
 题目大意：一个8*8的棋盘，输入一个点表示国际象棋中的king的位置，求king能行动的格子数量；
 输入两个字符，表示列和行。 列是'a'到'h'，行是1到8。
 题目解析：
 题目较简单，看如何实现比较方便。
 列-'a'得到索引x；
 行-'1'得到索引y；
 特判当king在边界的时候，已经两个边界的时候，即可。
 
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

    int ret = 8;
    string str;
    cin >> str;
    int x = str[0] - 'a';
    int y = str[1] - '1';
    if (x == 0 || x == 7) {
        ret -= 3;
    }
    if (y == 0 || y == 7) {
        ret -= 3;
    }
    if (ret == 2) {
        ++ret;
    }
    
    cout << ret << endl;
    
    
    return 0;
}
