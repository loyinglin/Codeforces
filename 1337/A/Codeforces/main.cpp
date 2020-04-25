//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1337/problem/A)
 **题目大意：**
 输入4个整数𝑎 , 𝑏, 𝑐, 𝑑, 并且 𝑎≤𝑏≤𝑐≤𝑑；
 现在需要找三个整数𝑥, 𝑦, 𝑧，满足：
 𝑎≤𝑥≤𝑏.
 𝑏≤𝑦≤𝑐.
 𝑐≤𝑧≤𝑑.
 并且𝑥, 𝑦, 𝑧能构成一个三角形。
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，四个整数𝑎 , 𝑏, 𝑐, 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤10^9）
 
 **输出：**
 每个样例一行，三个s整数𝑥, 𝑦, 𝑧；
 
 **Examples**
 **input**
 4
 1 3 5 7
 1 5 5 7
 100000 200000 300000 400000
 1 1 977539810 977539810
 **output**
 3 4 5
 5 5 5
 182690 214748 300999
 1 977539810 977539810
 
 
 **题目解析：**
 三角形要满足两边之和大于第三边，由题目意思我们知道x≤y≤z；
 所以只要满足，x+y≥z即可；
 所以令y=z，那么x随便取值即可。
 
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
        int a[4];
        for (int i = 0; i < 4; ++i) {
            cin >> a[i];
        }
        cout << a[1] << " " << a[2] << " " << a[2] << endl;
    }   
    
    return 0;
}
