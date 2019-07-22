//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1180/problem/A)
 **题目大意：**
 给出一个整数n，下面给出当n=1、2、3的图：
 
 计算第n个图，需要多少个方格组成。
 
 
 输入：
 一个整数𝑛 (1≤𝑛≤100)
 
 输出：
 需要的方格数量。
 
 
 **题目解析：**
 等差数列，1、3、5、、、2n-1；
 两个等差数列，减去一个多余的2n-1,于是有：
 一个等差数列和sum: (1+(2n-1)) x n/2
 最终得到 ans = 2 x sum - (2n-1) = 2n^2 - 2n + 1。
 
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


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    cout << 2 * n * n - 2 * n + 1 << endl;
    
    return 0;
}
