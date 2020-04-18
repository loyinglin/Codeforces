//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1199/problem/B)
 **题目大意：**
 有一朵睡莲漂浮在水面上，睡莲超过水面距离为H；
 随着河水的流动，睡莲刚好触碰水面，此时睡莲的移动距离为L；
 已知睡莲的根部为A点。
 问，水的深度是多少；
 
 输入：
 两个整数 𝐻  and 𝐿 (1≤𝐻<𝐿≤1e6)
 
 输出：
 水的深度，误差不超过10^-6。
 
 Examples
 input
 1 2
 output
 1.5000000000000

 **题目解析：**
 设 x 为湖的深度。
 (x + h)^2 = (x^2 + L^2)
 x^2 + 2xh + h^2 = x^2 + L^2
 2xh + h^2 = L^2
 x = (L^2 - h^2) / 2h;
 
 输出的参数可以为%.7f，保证误差不超过10^-6。
 
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

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    float h, l;
    cin >> h >> l;
    printf("%.7f", (l*l - h*h) / 2.0 / h);
    
    return 0;
}
