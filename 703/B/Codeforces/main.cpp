//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/703/problem/B
    题目大意：n个城市，第i和i+1之间有一条边，第n个和第1个有边。n个城市中有k个特殊城市，与n个城市之间都存在边。每个城市有一个权重c[i]，边(i, j)的值为c[i] * c[j]。 求所有边的值的和。
    题目解析：
 首先n个城市形成一个环，其次每一个特殊城市都会新增若干条边。任意两个城市之间最多只有一条边。
 
 第1个特殊城市a[1]，新增n条边，其中2条边和环重叠;
 第i个特殊城市a[i]，新增n条边，其中2条边和环重叠，i-1条边和之前特殊城市形成的边重叠；
 
 为了便于计算，先不考虑环。
 第1个特殊城市a[1]，新增n条边；
 第i个特殊城市a[i]，新增n条边，i-1条边和之前特殊城市形成的边重叠；
 先计算出所有特殊城市产生的边；
 对于环上的边，如果两点都不是特殊城市，那么是还没计算过的边；
 可以求出总和。
 
 


************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N], flag[N], c[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    long long sum = 0, ans = 0, n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 1; i <= m; ++i) {
        long long k;
        cin >> k;
        flag[k] = 1;
        sum -= c[k];
        ans += c[k] * sum;
    }
    for (int i = 1; i <= n; ++i) {
        int next;
        if (i == n) {
            next = 1;
        }
        else {
            next = i + 1;
        }
        if (!flag[next] && !flag[i]) {
            ans += c[i] * c[next];
        }
    }
    
    cout << ans;
    
    return 0;
}
