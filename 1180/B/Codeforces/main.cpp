//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1180/problem/B)
 **题目大意：**
 有一个数组𝑎=[𝑎1,𝑎2,…,𝑎𝑛] ，可以对任意数进行下面的操作：
  𝑎𝑖:=−𝑎𝑖−1；
 每个数可以操作任意次；
 
 要求 最后的乘积（𝑎1⋅𝑎2⋅…𝑎𝑛）最大。
 
 输入：
 第一行， 𝑛 (1≤𝑛≤10^5)
 第二行，n个整数； 𝑎1,𝑎2,…,𝑎𝑛 (−10^6≤𝑎𝑖≤10^6)
 
 输出：
 一行，使得乘积最大的n个整数（𝑎1,𝑎2,…,𝑎𝑛）
 
 
 **题目解析：**
 题目的要求是乘积最大，但是数字有很多，最终的乘积肯定会很大。
 再来看看题目的操作，其实就是x= -x-1;
 如果操作两次呢？x = -(-x-1) -1 = x + 1 - 1 = x;
 操作两次是变回x，那么可以知道对于每个数字只有1个选择：要么不操作，要么操作一次。
 
 回头来看看乘积最大的要求，先不考虑正负的问题，要使得乘积最大，自然是每个数字越大越好。
 容易知道，乘积对于负数有一个负负得正的作用，那么要使得乘积最大要满足两个条件：
 1、所有的数字里不会出现单数的负数，否则结果一定是负数；
 2、每个数字要尽可能的大；
 
 分析这个操作x=-x-1，容易知道对于正数，当x操作一次之后，绝对值是+1；对于负数，当x操作一次之后，绝对值是-1；
 
 综上，我们可以先将所有的数字全部变为负数，这样可以使得绝对值最大。
 但是因为可能会出现单数的负数，此时我们需要选择一个负数变为整数，通过推导，我们会选择负数中绝对值最大的那个变为负数。
 
 推导：
 先假设有两个正整数x和y，并且x<y。
 (x-1)*y=x*y-y
 x*(y-1)=x*y-x
 因为x<y,所以有(x-1)*y < x*(y-1)
 
 **思考🤔：**
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0) {
            a[i] = -a[i] - 1;
        }
        if (index == -1) {
            index = i;
        }
        else if (a[i] < a[index]) {
            index = i;
        }
    }
    if (n % 2) {
        a[index] = -a[index] - 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
