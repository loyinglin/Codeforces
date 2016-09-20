//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/710/problem/E
 题目大意：n, x and y (1 ≤ n ≤ 107, 1 ≤ x, y ≤ 109).
 构造n个'a'字符，x为insert/delete 'a'一次的代价，y为复制粘贴一次的代价。
 
 题目解析：
 动态规划。
 dp[i] 表示构造i个字符的最优解。
 对应三种可能，三个状态转移。
 dp[i] = min(dp[i], dp[i + 1] + x);     删除
 dp[i + 1] = min(dp[i + 1], dp[i] + x); 增加
 dp[i * 2] = min(dp[i * 2], dp[i] + y); 双倍
 
 1 2 4 8 16 13 26 52 删除3次，double 6次
 1 2 4 6 12 13 25 52 增加3次，double 6次
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
const int N = 20001000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
};
lld dp[N];

int main(int argc, const char * argv[]) {
    // insert code here...

    lld n, x, y;
    cin >> n >> x >> y;
    
    for (int i = 0; i <= 2 * n; ++i) {
        dp[i] = llinf;
    }
    dp[1] = x;
    for (int i = 1; i < 2 * n; ++i) {
        dp[i] = min(dp[i], dp[i + 1] + x);
        if (i + 1 <= 2 * n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + x);
        }
        if (i * 2 <= 2 * n) {
            dp[i * 2] = min(dp[i * 2], dp[i] + y);
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}
