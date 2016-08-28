//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/706/problem/B
    题目大意：n个数，q个询问，对于每个询问k，输出n个数中小于等于k的数量；
    题目解析：
 方法多种多样：
 1、排序，二分查找；
 2、动态规划；
 3、树状数组；
 
 这里用方法2.
dp[i] 表示小于等于i的数量；
dp[i] = dp[i-1]+a[i]; a[i]是大小为i的数量。
 
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
const int N = 101000, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
lld a[N], dp[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ++a[k];
    }
    
    for (int i = 1; i < N; ++i) {
        dp[i] = a[i] + dp[i - 1];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        k = min(k, N - 1);
        cout << dp[k] << endl;
    }
    
    
    
    
    return 0;
}
