//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1335/problem/B)
 **题目大意：**
 有三个正整数n，a，b，现在需要构造一个字符串s，长度为n，只包含小写字母，并且满足要求：
 字符串s中，任何长度为a的子串要包含b个不同的字符。
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤2000)
 接下来每个样例一行，四个整数 𝑛, 𝑎 and 𝑏 (1≤𝑎≤𝑛≤2000,1≤𝑏≤min(26,𝑎))
 
 **输出：**
 每个样例一行，输出满足要求的字符串；（题目保证答案一定存在）
 
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
 题目的要求是，长度为a的子串中，有b个不同的字符；
 那么将b个字符构成的字符串不断重复，即可满足题目要求；
 比如说题目样例 7 5 3
 b=3，则用abc不断循环，得到abcabca
 样例 5 2 2
 b=2，则用ab不断循环，得到ababa

 实现较为简单。
 
 
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
