//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/736/problem/A
 题目大意：
 n个人参加若干个比赛，比赛是1v1，输的人不能再参加比赛；
 假设一个人赢了k次，他只会与赢次数不小于k-1次的人比赛；
 问赢得最多的那个人，能赢多少次；
 (n<=1e18)
 
 Example
 input
 4
 output
 2
 input
 10
 output
 4
 
 题目解析：
 直接想法：n个人，直接两两匹配；再，两两匹配；这样会浪费一部分人，因为k是可以和k-1比赛的；
 必须保证每场比赛都是k和k-1，以及0和0的即可满足最优解；
 
 那么k=1的时候，sum1=2;
 k=2, sum2=2+1=3;
 k=3, sum3=sum2+sum1=5;
 k=4, sum4=sum3+sum2=8;
 k=5, sum5=sum4+sum3=13;
 ...
 以此类推直到sum>n，可以得到最大的k值。
 
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

lld dp[N];


int main(int argc, const char * argv
         []) {
    lld n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    int k = 2;
    while (1) {
        dp[k] = dp[k - 1] + dp[k - 2];
        if (dp[k] > n) {
            cout << k - 1 << endl;
            break;
        }
        ++k;
    }
    
    
    return 0;
}
