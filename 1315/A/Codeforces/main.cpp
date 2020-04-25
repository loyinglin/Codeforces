//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1315/problem/A)
 **题目大意：**
 屏幕上有a*b个像素点，其中第（x、y）个像素点已经损坏；（x和y从0开始）
 现在想在屏幕上选出一个矩形，这个矩形的边与屏幕的边缘平行，并且不包括损坏的像素点(x，y）；
 问这个矩形的最大面积是多少？
 
 **输入：**
 第一行 整数𝑡 (1≤𝑡≤10^4)
 接下来t行，每行4个整数 𝑎,𝑏,𝑥 and 𝑦 (1≤𝑎,𝑏≤104; 0≤𝑥<𝑎; 0≤𝑦<𝑏)
 
 **输出：**
 每个样例一行，每行一个整数，表示最大的面积数。
 
 **Examples**
 input
 6
 8 8 0 0
 1 10 0 3
 17 31 10 4
 2 1 0 0
 5 10 3 9
 10 10 4 8
 output
 56
 6
 442
 1
 45
 80
 
 **题目解析：**
 
 只有四种可能，损坏点的上下左右。
 进行枚举计算。
 
 
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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int ans = 0;
        ans = max(ans, x * m);
        ans = max(ans, (n-x-1) * m);
        ans = max(ans, n * y);
        ans = max(ans, n * (m-y-1));
        cout  << ans << endl;
    }
    
    return 0;
}


/**
 6
 8 8 0 0
 1 10 0 3
 17 31 10 4
 2 1 0 0
 5 10 3 9
 10 10 4 8
 */
