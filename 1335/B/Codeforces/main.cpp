//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1335/problem/B)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，四个整数𝑎 , 𝑏, 𝑐, 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤10^9）
 
 **输出：**
 每个样例一行，三个s整数𝑥, 𝑦, 𝑧；
 
 **Examples**
 input
 4
 7 5 3
 6 1 1
 6 6 1
 5 2 2
 output
 tleelte
 qwerty
 vvvvvv
 abcde
 
 
 **题目解析：**
 a个字符的子串中，有b个不同的字符；
 那么将b个字符串不断重复，即可满足题目要求；
 比如说题目样例 7 5 3
 abcabca
 样例 5 2 2
 ababa

 实现较为简单：
 
 
 **思考🤔：**
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool cmp(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            putchar('a' + k);
            k = (k + 1) % b;
        }
        puts("");
    }   
    
    return 0;
}
