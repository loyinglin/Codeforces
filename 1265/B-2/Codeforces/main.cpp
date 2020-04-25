//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1265/problem/A)
 **题目大意：**
 给出1~n的n个整数组成的数组，每个数字都只有一个；
 我们把数字i称为beautiful，如果能够在数组中找到一段连续的数字，这个区间内的数字是1到i；
 比如说对于数组[4,5,1,3,2,6]，我们能找到：
 [1], [1,3,2], [4,5,1,3,2],[4,5,1,3,2,6] 这四个区间，所以数字1、3、5、6是beautiful，数字2、4不是beautiful；
 
 现在给出一个1~n组成的数组，问数组中有哪些数字是beautiful；
  
 输入：
 第一行 𝑡  (1≤𝑡≤1000) 表示接下来有t个样例
 每个样例的第一行是𝑛  (1≤𝑛≤2⋅10^5），表示数组的长度；
 接下来一行是n个整数；
 
 
 输出：
 每一个样例输出一行长度为n的字符串，每个字符都是01组成，第i个字符为1表示第i个数字是beautiful；
 
 input
 3
 6
 4 5 1 3 2 6
 5
 5 3 1 2 4
 4
 1 4 3 2
 
 output
 101011
 11111
 1001
 
 
 **题目解析：**
 
 
 排序，染色。
 
 
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
const int N = 1010010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;
int n,p[20],pos[20];
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",p+i),pos[p[i]]=i;
        int mx=0,mi=n+1;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,pos[i]);
            mi=min(mi,pos[i]);
            printf("%d",mx-mi+1==i);
        }
        puts("");
    }
    return 0;
}
