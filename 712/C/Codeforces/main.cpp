//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/712/problem/C
 题目大意：有两个正三角形，边长分别为x，y。
 现在可以对三角形进行操作，每次操作可以改变三角形的一条边长度，变成另外一个三角形。
 问，让正三角形x 变成 正三角形y 的最小操作次数。
  x and y (3 ≤ y < x ≤ 100 000)
 
 
 input
 6 3
 output
 4
 
 解释：666 -> 663 -> 643 -> 343 -> 333.
 
 
 题目解析：
 三角形的性质:两边之和大于第三边。
 反过来考虑，把三角形y变成三角形x。（操作步数是一致的）
 那么自然可以想到一种贪心：每次把最小的边变得最大。
 每次操作完排序，再对最小的进行变大。
 直到最小的边也等于x。
 
 
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
const int M = 510010, N = 3, inf = 0x7fffffff;
const lld MOD = 1000000007LL;

int main(int argc, const char * argv[]) {
    // insert code here...
    int x, y;
    cin >> x >> y;
    int a[3];
    a[0] = a[1] = a[2] = y;
    int ans = 0;
    while (a[0] != x) {
        ++ans;
        int tmp = a[2] + a[1] - 1;
        if (tmp > x) {
            tmp = x;
        }
        a[0] = tmp;
        sort(a, a + 3);
    }
   
    cout << ans << endl;
    
    return 0;
}
