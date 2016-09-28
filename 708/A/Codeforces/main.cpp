//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/708/problem/A
 题目大意：输入一个长度为s的字符串，可以选择一个子串，把子串里每个字母的字典序-1（'a'变成'z'），求操作后的最小字典序字符串。
 s (1 ≤ s ≤ 100 000)
 >Examples
 input
 codeforces
 output
 bncdenqbdr
 
 >input
 abacaba
 output
 aaacaba
 
 题目解析：
 因为操作不会减短字典序，即操作之后的字符串应该是等长的；
 容易知道，'a'是不需要操作的，那么找到第一个不为'a'的字符串，开始变小，直到遇到下一个'a'即可；
 
 
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
char str[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> str;
    int n = strlen(str);
    int flag = 0, changing = 0;
    int i = 0;
    while (i < n && str[i] == 'a') {
        ++i;
    }
    if (i == n) {
        str[n - 1] = 'z';
    }
    else {
        while (i < n && str[i] != 'a') {
            str[i] -= 1;
            ++i;
        }
    }
    cout << str << endl;
    return 0;
}
