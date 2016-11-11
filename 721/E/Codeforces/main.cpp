//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/721/problem/E
 题目大意：
 在一条数轴上，Bob要学校（点0）走到家（点L），其中有n个路灯，路灯照耀的范围是(l[i], r[i])（路灯的范围不会重叠）；
 Bob会在灯亮的的范围内唱歌，每次唱的距离为p；（必须唱完，中间必须全部是在路灯照耀范围内）
 当Bob唱完一次的时候，下一次唱的地点必须满足以下其中一点：
 1、开始唱的地点和上一次唱结束的地点重合；
 2、开始唱的地点和上一次唱结束的地点距离>=t;
 
 问最多，能唱几次。
 (1 ≤ L ≤ 1e9, 0 ≤ n ≤ 100 000, 1 ≤ p ≤ 1e9, 1 ≤ t ≤ 1e9)
 
 
 题目解析：
 
 
 
 
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
const int N = 110000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int l[N], r[N];
int dp[N];
int g[N];


/**
 
 dp[i] 表示到r[i]距离的最多唱次数； count(L)表示距离L能唱的次数；
 g[i] 表示dp[i]取到最优解的时候，最左的距离；
 容易维护这样一个队列：
 对于i < j, 有  dp[i] > dp[j] 且 g[i] > g[j]；
 
 证：
 对于i < j, 必然有 g[i] <= g[j]；
 那么对于dp[j] < dp[i]，我们不放入队列即可；
 
 
 对于k < i, 如果 l[i] - g[k] >= t；
 dp[i] = max(dp[i], dp[k] + count(r[i] - l[i]));
 g[i] = l[i] + count(r[i] - l[i]) * p;
 
 如果l[i] - g[k] < t，有：
 如果r[i] - g[k] < t ，continue；//不合法
 如果r[i] - g[k] >= t,
 dp[i] = max(dp[i], dp[k] + count(r[i] - g[k] - t));
 g[i] = g[k] + count * p + t;
 
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, L, p, t;
    cin >> L >> n >> p >> t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    deque<int> q; // dp值从小到大，g[i]值从大到小；
    q.push_back(0);
    g[0] = -t;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = -1;
        while (!q.empty() && g[q.front()] + t <= r[i]) { //每次检测是否进入下一个值的有效区间
            int nl = max(l[i], g[q.front()] + t), nr = r[i];
            if (dp[q.front()] + (nr - nl) / p > dp[i]) {
                dp[i] = dp[q.front()] + (nr - nl) / p;
                g[i] = nl + (nr - nl) / p * p;
            }
            else if (dp[q.front()] + (nr - nl) / p == dp[i]) {
                g[i] = min(g[i], nl + (nr - nl) / p * p); // 同样的dp值，只保留最小的g[i]值
            }
            k = q.front();
            q.pop_front();
        }
        if (k != -1) {
            q.push_front(k);
        }
        if (dp[i] > ans) {
            ans = dp[i];
            q.push_back(i);
        }
        
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    
    return 0;
}

/*
 10 3 2 2
 1 3
 4 8
 9 10
 
 
 
 20 3 3 3
 0 6
 7 8
 9 12
 
 
 
 1000 10 1 3
 0 1
 2 3
 4 5
 6 7
 8 9
 10 11
 12 13
 14 15
 16 17
 18 19
 
 
 
 */
