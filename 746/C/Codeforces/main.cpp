//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/746/problem/C
 题目大意：
 在一条直线上，有一辆公共汽车从点0到点s，不断往返，速度为t1秒每米；
 有一个人，要从点x1到点x2，速度为t2秒每米；
 当人和车子的位置重叠时，人可以上车，之后可以随时下车；（上下车时间忽略）
 现在求人到达目的地的最短时间是多少？
 
 输入数据有三行，分别是：
  s, x1 and x2 (2 ≤ s ≤ 1000, 0 ≤ x1, x2 ≤ s, x1 ≠ x2) 
  t1 and t2 (1 ≤ t1, t2 ≤ 1000) 
  p and d (1 ≤ p ≤ s - 1, d is either 1 or -1) p表示当前车子所在的位置，d表示方向 只能为1或者-1
 
 Examples
 input
 4 2 4
 3 4
 1 1
 output
 8
 input
 5 4 0
 1 2
 3 1
 output
 7

 
 
 题目解析：
 题目有一个很重要的限制 0 ≤ x1, x2 ≤ s， 表示车子的行程最终是会覆盖到x1和x2。
 那么，就不会出现人上车后下车再走的情况。
 用贪心的策略可以知道，人要么一直走到终点站；
 要么走一段距离，然后上车，直到终点。
 
 人直接走到终点的时间为 time1 = t2 * |x2 - x1|;
 为了简化计算，第二种情况采用这样的计算方式：
 假设人站在x1不动，等着车子来接。
 计算车子第一次经过终点的时间，同时考虑这个路程有没有经过点x1；
 如果没有再计算车子第二次经过终点的时间，直到有经过点x1，得到时间time2;
 
 ans = min(time1, time2);
 
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

char a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int s, x1, x2;
    int t1, t2;
    int p, d;
    
    cin >> s >> x1 >> x2;
    cin >> t1 >> t2;
    cin >> p >> d;
    
    int ans = abs(x1 - x2) * t2; // 人直接走到终点时间
    int time = 0, ok = 0;
    if (p != x2) { // 先让车子到达终点
        if (p < x2) {
            time = (x2 - p) * t1;
            if (d == -1) {
                time += p * 2 * t1;
                d = -d;
                if (x1 <= x2) {
                    ok = 1;
                }
            }
            else {
                if (x1 <= x2 && p <= x1) {
                    ok = 1;
                }
            }
        }
        else {
            time = (p - x2) * t1;
            if (d == 1) {
                time += (s - p) * 2 * t1;
                if (x1 >= x2) {
                    ok = 1;
                }
                d = -d;
            }
            else {
                if (x1 >= x2 && x1 <= p) {
                    ok = 1;
                }
            }
        }
    }
    if (ok) { // 在第一次到达终点的过程遇到了人
        ans = min(ans, time);
    }
    else {
        if ((x2 - x1) / d > 0) {
            time += s * 2 * t1;
        }
        else {
            if (x2 < x1) {
                time += (s - x2) * 2 * t1;
            }
            else {
                time += x2 * 2 * t1;
            }
        }
        ans = min(ans, time);
    }
    
    cout << ans << endl;
    
    return 0;
}
