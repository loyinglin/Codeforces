//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/743/problem/C
 题目大意：
 给出一个数字n，求出三个不同的正整数，要求：
 2/n = 1/x + 1/y + 1/z。
 
 如果不存在，输出-1.
 1<=n<=1e4
 x, y and z (1 ≤ x, y, z ≤ 1e9, x ≠ y, x ≠ z, y ≠ z)
 
 Examples
 input
 3
 output
 2 7 42
 input
 7
 output
 7 8 56
 
 
 
 题目解析：
 第二个样例给了思路。
 
 2/n = 1/n + 1/(n+1) + 1/n(n+1) 
 
 n = 1的时候，存在无解的情况。
 
 
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
const int N = 201010;

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
    }
    else {
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    }
    
    return 0;
}
