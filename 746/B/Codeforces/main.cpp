//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/746/problem/B
 题目大意：
 定义一个“median letter”的概念：
 1、如果字符串长度为奇数，那么为中间的字符；
 2、如果字符串长度为偶数，那么为中间偏左的字符；
 
 现在对一个字符串，选择median letter，并且将这个字符拿出来，重复这个操作；
 每次取出来的字符串依次排好，得到一个新字符串。
 例如：volga 分别取出来的字符是l,o,g,v,a，组成一个新的字符串 logva 。
 
 现在给出字符串的长度n，还有一个字符串str；
 求一个字符串strNew，要求strNew按照上面的规则，组成是新字符串是str。
 
 
 Examples
 input
 5
 logva
 output
 volga
 input
 2
 no
 output
 no
 input
 4
 abba
 output
 baba
 
 
 题目解析：
 先来看这个提取的过程：每次都是选出中间的字符。
 那么在恢复原来字符串的时候，只要按照原来的顺序，假设有n个字符串。
 那么第一个字符串是n/2, 然后再假设一个left 和 right 指针，然后轮流往两边延伸即可。 
 
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

char a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    string str;
    cin >> n >> str;
    int l, r, flag = n % 2;
    if (flag) {
        a[n / 2] = str[0];
        l = n / 2 - 1;
        r = n / 2 + 1;
    }
    else {
        l = n / 2 - 1;
        r = n / 2;
    }
    for (int i = 0; i + flag < n; ++i) {
        if (i % 2 == 0) {
            a[l--] = str[i + flag];
        }
        else {
            a[r++] = str[i + flag];
        }
    }
    
    a[n] = '\0';
    cout << a << endl;
    
    
    return 0;
}
