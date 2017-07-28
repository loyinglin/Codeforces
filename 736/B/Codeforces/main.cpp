//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/736/problem/B
 题目大意：
 给出一个整数n（n<=2e9）；
 现在把n分成k个数的和，假设是a[i]；（要求a[i]>=2, k>=1)
 分出数字a[i]的cost为a[i]的最大因子；
 分成k个数的代价为每个数字的cost和；
 
 给出n，求分成若干个数字的最小cost。
 
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
 分出数字a[i]的cost为a[i]的最大因子，那么分出素数的cost为1；
 
 由[哥德巴赫猜想](https://zh.wikipedia.org/wiki/%E5%93%A5%E5%BE%B7%E5%B7%B4%E8%B5%AB%E7%8C%9C%E6%83%B3 )
 可以知道，**任一大于2的偶数，都可表示成两个素数之和，任一大于5的整数都可写成三个质数之和。**
 
 那么可以知道：
 素数是1；
 偶数是2；
 如果是奇数， 那么最大为3；
 还有一种情况是奇数=2+素数，因为2也算素数，如果能拆出这种答案为2；
 
 
 >可怕的队友提供的想法。
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
