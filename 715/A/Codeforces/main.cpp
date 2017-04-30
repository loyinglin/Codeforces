//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/715/problem/A
 题目大意：
 有一个特殊的计算器，只能执行加号和求平方根的操作，计算器有一个等级，用数字k表示；初始值为x。
 执行完加号操作后，x=x+k;
 执行完求根操作后，x=sqrt(x);（这个操作只有当x是perfect square的时候才能执行，且要求执行完的x必须是等级的倍数）
 执行完求根操作后，等级会上升，k=k+1;（注意，执行完求根操作后，等级+1后再进行倍数的判断）
 初始等级是1，初始值是2，问要到达等级n+1，在每次求根操作前需要执行几次加号操作？
 如果有多个解，输出任意解都可以。
 
 Examples
 input
 3
 output
 14
 16
 46
 
 样例解释：表示在等级1、2、3的时候分别按14、16、46次加号；
 
 
 题目解析：
 思路，列出等级和初始值
 LEVEL  Init
 1      2, 2+1, 2+1+1
 2      2, 2+2, 2+2+2, ..., 2*(3*3*2)
 3      3*2, 3*2+3, 3*2+3+3, ..., 3*(4*4*3)
 ...
 i      i*j, i*j+i, i*j+i+i, ..., i*((k+1)*(k+1)*i)
 
 找到规律即可。
 
 
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
const int N = 3010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    lld i = 1, j = 2, k = 1;
    while (k <= n) {
        cout << (k + 1) * (k + 1) * i - j << endl;
        j = i;
        i = k = k + 1;
    }
    
    
    
    return 0;
}
