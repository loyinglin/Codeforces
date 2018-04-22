//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/752/problem/C
 题目大意：
 有一个机器人，在一个网格的网格线上行走，每次有L/R/U/D四个方向；
 当机器人从点p1走到点p2时，它会走最短的路径。
 如果有3个点p1、p2、p3，机器人会按照最短的路径走向p1点，到达后再走向p2点，再到p3点；
 现在假设机器人在原点，已知机器人走的序列（长度为n），求最少有几个点，可以满足机器人走的序列。
 
 n (1 ≤ n ≤ 2·105)
 Example
 input
 6
 RRULDD
 output
 2
 input
 26
 RRRULURURUULULLLDLDDRDRDLD
 output
 7
 
 题目解析：
 看似很难，仔细分析一下，只要找到两点之间路径的规律即可。
 当出现过R之后，本次路径，就不允许再出现L，同理L、U、D;
 这样，R、L之间算一条路径，U、D之间算一条路径，加起来就是需要的最小点数。
 
 
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
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != second) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
char a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, ans = 1;
    cin >> n;
    cin >> a;
    int way[4] = {0};
    for (int i = 0; i < n; ++i) {
        int id = 0;
        switch (a[i]) {
            case 'L':
                id = 0;
                break;
            case 'U':
                id = 1;
                break;
            case 'D':
                id = 2;
                break;
            case 'R':
                id = 3;
                break;
        }
        if (way[3 - id]) { // 对立的方向已经出现
            ++ans;
            memset(way, 0, sizeof(way));
            way[id] = 1;
        }
        else {
            way[id] = 1;
        }
    }
    
    
    cout << ans << endl;
    
    return 0;
}
