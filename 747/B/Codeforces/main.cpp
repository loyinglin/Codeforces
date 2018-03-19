//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/747/problem/B
 题目大意：
 给出一个长度为n的字符串，分别由'A', 'C', 'G', 'T' and '?' 组成，?的字符可以变成ACGT中的任意一个字符。
 现在需要把字符变成全部由ACGT组成，并且四个字符的数量相等。
 如果有解，输出字符串；
 如果无解，输出====。
 n (4 ≤ n ≤ 255)
 
 input
 4
 AGCT
 output
 AGCT
 input
 6
 ????G?
 output
 ===

 
 题目解析：
 ACGT字符数量相等，那么n%4==0，且最小字符数量等于n/4；
 每次遇到？字符，选择变成数量最少的字符。
 
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
        if (tmp.pos != pos) return pos > tmp.pos;
        else return value > tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

char a[N];
char *st = "ACGT";
int num[4];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (st[j] == a[i]) {
                num[j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '?') {
            int minId = 0;
            for (int j = 1; j < 4; ++j) {
                if (num[j] < num[minId]) {
                    minId = j;
                }
            }
            num[minId]++;
            a[i] = st[minId];
        }
    }
    sort(num, num + 4);
    if (n % 4 == 0 && num[0] == n / 4) {
        cout << a << endl;
    }
    else {
        cout << "===" << endl;
    }
    
    
    return 0;
}
