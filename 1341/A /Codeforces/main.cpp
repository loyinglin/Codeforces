//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1341/problem/A)
 **题目大意：**
 有n个砝码，每个砝码的重量是一样的；
 由于砝码的重量标识已经模糊，只能大概知道的重量区间是在 [a-b, a+b]这个区间内；
 现在想知道，这n个砝码的重量，能否在区间[c-d, c+d]内；
 如果可以，则输出YES；如果不可以，则输出NO；
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，5个整数 n,𝑎,𝑏,𝑐,𝑑 (1≤𝑛≤1000, 0≤𝑏<𝑎≤1000, 0≤𝑑<𝑐≤1000)

 
 **输出：**
 每个样例一行，如果可以，则输出YES；如果不可以，则输出NO；
 
 **Examples**
 **input**
 5
 7 20 3 101 18
 11 11 10 234 2
 8 9 7 250 122
 19 41 21 321 10
 3 10 8 6 1
 
 **output**
 Yes
 No
 Yes
 No
 Yes
 
 **题目解析：**
 因为a和b比较小，枚举下a和b的区间，可以解决问题；
 
 但是假如，a和b很大呢？（0≤𝑏<𝑎≤10^9, 0≤𝑑<𝑐≤10^9）
 我们用[l, r]来表示[c-d, c+d]的区间；
 我们用[gapL, gapR] 来表示[(a-b)*n, (a+b)*n]的区间；
 只要这俩个区间有重叠，则表示存在可能性；
 这样就不用枚举，复杂度从O(N^2)变成O(1)。
 
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
        lld n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        lld l = (c - d), r = (c + d);
        lld ans = -1;
        lld gapL = (a - b) * n, gapR = (a + b) * n;
        bool ok = 0;;
        if (gapL <= l && l <= gapR) {
            ok = 1;
        }
        else if (gapL <= r && r <= gapR) {
            ok = 1;
        }
        else if (l <= gapL && gapL <= r) {
            ok = 1;
        }
        else if (l <= gapR && gapR <= r) {
            ok = 1;
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }   
    
    return 0;
}
