//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/703/problem/D
    题目大意：给出有n个数字的数组a, 有m个询问。 (1 ≤ n ≤ 1 000 000)（1 ≤ a[i] ≤ 10e9) (1 ≤ m ≤ 1 000 000)
 询问给出两个数字l, r。(1 ≤ l ≤ r ≤ n) 
 在区间[l, r]中，把出现偶次的数字统计出来。对这些数字求异或，得到询问的值。
 
    题目解析：
 区间求值，数据量极大，可以猜测是从区间相减来求子区间的值，从这里出发。
 [l, r]区间的偶数次的数字的异或和为sumA；
 [l, r]区间的奇数次的数字的异或和为sumB；
 sumA ^ sumB的值为什么？
 [l, r]区间段所有数字的异或和！
 
 其中sumB直接对[l, r]所有的区间求异或和即可；（偶次的会为0）
 重点就是[l, r]的不重复的异或和。
 用map<int, int> 来维护a[i]上一次出现的位置，如果a[i]已经出现，那么在原来的位置进行异或即可。
 于是变成区间[l, r]求和。
 这个是树状数组最擅长的事情了。
 


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
const int N = 1010000;


map<int, int> h;
int tree[N];
int ans[N];
int a[N], f[N];
int n, m;
vector<pair<int, int> > g[N];

int low_bit(int x) {
    return x & (-x);
}

void tree_add(int x, int v) {
    while (x <= n) {
        tree[x] ^= v;
        x += low_bit(x);
    }
}

int tree_sum(int x) {
    int sum = 0;
    while (x) {
        sum ^= tree[x];
        x -= low_bit(x);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = f[i - 1] ^ a[i];
    }
    
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        g[r].push_back(make_pair(l, i));
    }
    
    for (int i = 1; i <= n; ++i) {
        if (h[a[i]]) {
            tree_add(h[a[i]], a[i]);
        }
        h[a[i]] = i;
        tree_add(h[a[i]], a[i]);
        
        for (int j = 0; j < g[i].size(); ++j) {
            int v = g[i][j].first;
            int index = g[i][j].second;
            ans[index] = f[i] ^ f[v - 1] ^ tree_sum(i) ^ tree_sum(v - 1);
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    
    
    return 0;
}

