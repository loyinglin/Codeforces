//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/736/problem/A
 题目大意：
 给出一个整数n，n<=2e9；
 现在把n分成k个数的和，假设是a[i]；（要求a[i]>=2, k>=1)
 分出数字a[i]的cost为a[i]的最大因子；分成k个数的代价为每个数字的cost和；
 
 给出n，求最小的cost。
 Examples
 input
 4
 output
 2
 input
 27
 output 
 3
 
 题目解析：
 哥德巴赫猜想，答案只能是1、2、3;
 素数是1；
 偶数是2；
 奇数看是否能拆成偶数+素数；（偶数就是2，那么素数就是n-2）；
 
 可怕的队友提供的想法。
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
const int N = 101001;


int isprime (int n) {
    for (int i = 2; i * i <= n; ++ i)if (n%i==0) return false;
    return true;
}

int main (){
    int n; cin >> n;
    int ans = 0;
    if (isprime(n)) ans = 1;
    else if(n%2==0) ans = 2;
    else {
        if(isprime(n-2)) ans = 2;
        else ans = 3;
    }
    cout<<ans<<endl;
    return 0;
}
