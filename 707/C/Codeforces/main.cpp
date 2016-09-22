//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/707/problem/C
    题目大意：给出一个数字n，求一组勾股数中的另外两个，使得三个构成勾股数。
 n (1 ≤ n ≤ 10^9)
 >Examples
 input
 3
 output
 4 5
 input
 6
 output
 8 10
 input
 1
 output
 -1

    题目解析：
 容易知道，n=1,2无解。（最小的勾股数3、4、5）
 假设在a^2+b^2=c^2 中 令a=n
 那么有n*n=c*c-b*b=(c+b)*(c-b)
 当n为奇数时，令c-b=1, 有n*n=(b+1+b) => b=(n*n-1)/2
 当n为偶数时，令c-b=2, n*n=(b+2+b)*2 => b=(n*n/2-2)/2
 
 令mod=2-n%2，那么有b= (n*n/mod - mod)/2
 
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

int main(int argc, const char * argv[]) {
    // insert code here...
   
    lld k, b;
    cin >> k;
    lld mod = 2 - k % 2;
    b = (k * k / mod - mod) / 2;
    if (b == 0) {
        cout << -1;
    }
    else {
        cout << b << " " << b + mod << endl;
    }
    
    return 0;
}
