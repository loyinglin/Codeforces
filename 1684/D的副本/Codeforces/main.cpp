//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1684/problem/C)
 **题目大意：**
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤100)
 每个样例第一行是整数𝑛 and 𝑚 (1≤𝑛,𝑚≤2⋅1e5)
 接下来会有n行m列的整数 𝑎[𝑖,𝑗] (1≤𝑎[𝑖,𝑗]≤1e9)；
  
 **输出：**
 每个样例一行，输出满足的交换位置；
 如果无解则输出-1；
 
 
 **Examples**
 **input**
 5
 2 3
 1 2 3
 1 1 1
 2 2
 4 1
 2 3
 2 2
 2 1
 1 1
 2 3
 6 2 1
 5 4 3
 2 1
 1
 2
 
 **output**
 1 1
 -1
 1 2
 1 3
 1 1
 
 **题目解析：**
 
 
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
void solve()
{
    long long int n,k,c=0,i;
    cin>>n>>k;
    int a[n],z[n];
    for(i=0;i<n;i++)
    {cin>>a[i];
     c+=a[i];
     z[i]=n-1-i-a[i];
    }
    sort(z,z+n);
    for(i=0;i<k;i++)
    c+=(z[i]-k+i+1);
    cout<<c<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    solve();
}
