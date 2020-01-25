//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1185/problem/A)
 **题目大意：**
 在一维坐标轴上有三个点，坐标是a、b、c；
 现在需要移动这三个点的位置，使得三个点之间两两间隔大于d；
 每次只能移动一个点，每秒只能移动距离1；
 问最少需要多少秒，才能满足要求。
 
 
 输入：
 一行，四个数字 𝑎, 𝑏, 𝑐, 𝑑 (1≤𝑎,𝑏,𝑐,𝑑≤10^9)
 
 输出：
 最少的秒数。
 
 Examples
 input
 5 2 6 3
 output
 2
 
  
 
 **题目解析：**
 a、b、c之间没有关系，可以先排序，使得a<b<c。
 使得x=b-a, y=c-b，那么有：
 x>=d的时候，ans=max(0, d-y);
 y>=d的时候，ans=max(0, d-x);
 都不满足的时候，ans=(d-x)+(d-y);
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[3], d, ans = 0;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    int x = a[1] - a[0], y = a[2] - a[1];
    if (x >= d) {
        ans = max(0, d - y);
    }
    else if (y >= d) {
        ans = max(0, d - x);
    }
    else {
        ans = (d - x) + (d - y);
    }
    cout << ans << endl;
    
    return 0;
}
