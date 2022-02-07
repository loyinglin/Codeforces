//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1335/problem/A)
 **题目大意：**
 有n个糖果，分给两个人A和B，要求：
 两个人都有分配到糖果；
 糖果不能拆分，必须全部分分完；
 A的糖果数量比B的要多；
 
 问，最终有多少种分配方案。
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，整数𝑛  (1≤𝑛≤2⋅1e9)
 
 **输出：**
 每个样例一行，输出存在分配方案，不存在则输出0；
 
 **Examples**
 **input**
 6
 7
 1
 2
 3
 2000000000
 763243547
 **output**
 3
 0
 0
 1
 999999999
 381621773
 
 样例解释：
 样例1：
 7个糖果，有下面3个方案：
 𝑎=6, 𝑏=1;
 𝑎=5, 𝑏=2;
 𝑎=4, 𝑏=3.

 
 **题目解析：**
 分糖条件写的很清楚，两个整数a和b，要求a<b；
 对于数字n来说，如果n是偶数，那么有n/2-1种可能；
 如果n是奇数，那么有n/2种可能；
 利用计算机整除的特性，可以表述为(n-1)/2；
 
 
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

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n - 1) / 2 << endl;
    }   
    
    return 0;
}
