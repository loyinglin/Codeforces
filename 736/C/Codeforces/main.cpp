//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/736/problem/A
 题目大意：
 给出一个n个节点的树，现在把树上部分点染成黑色，要求：每个点在k的路径范围内，一定有黑色节点；
 问，有多少种染色方案。（结果mod=1e9+7)
 n=100, k<=min(20, n-1);
 
 
 Examples
 input （输入是n、k，接下来是n-1条边，保证是树）
 2 0
 1 2
 output
 1
 input
 2 1
 1 2
 output
 3
 input
 4 1
 1 2
 2 3
 3 4
 output
 9
 
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
