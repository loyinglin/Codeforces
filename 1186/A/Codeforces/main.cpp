//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1186/problem/A)
 **题目大意：**
 在一维坐标轴上有三个点a、b、c，现在需要移动这三个点的位置，使得三个点之间两两间隔大于d；
 每次只能移动一个点，每秒只能移动距离1；
 问最少需要多少秒，才能满足题目条件。
 
 
 输入：
 第一行，四个数字 𝑎, 𝑏, 𝑐, 𝑑 (1≤𝑎,𝑏,𝑐,𝑑≤10e9)
 
 输出：
 最少的秒数。
 
 
 **Examples**
 **input**
 **output**

 Examples
 input
 5 2 6 3
 output
 2
 input
 3 1 5 6
 output
 8
 
 
 **题目解析：**

 
 
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
    
    int a[3], d, ans = 0;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    int x = a[1] - a[0], y = a[2] - a[1];
    if (x >= d) {
        ans = max(0, d - y);
    }
    else if (y >= d) {
        ans = max(0, d - x);
    }
    else {
        ans = (d - x) + (d - y);
    }
    cout << ans << endl;
    
    return 0;
}
