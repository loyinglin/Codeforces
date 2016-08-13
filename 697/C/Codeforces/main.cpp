//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/697/problem/C
    题目大意：在自然数中，i到2i存在一条边，i到2i+1存在一条边。输入有两类型：
 1、在u到v的最短路径上每条边的费用都加w；
 2、求u到v的最短距离；
 
    题目解析：
 对于每个自然数i，会和比自己小的自然数构成一条边，比自己大的自然数构成两边条，那么可以把边的费用存在中较大数。
 对于u到v的最短路径，必然是最大的k，路径为(u, k) + (k, v)。
 每次对u、v中的较大值/2，即可。 
 
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
const int N = 10100, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
map<lld, lld> h;

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n;
    cin >> n;
    
    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            lld u, v, cost;
            cin >> v >> u >> cost;
            if (v > u) {
                lld tmp = u;
                u = v;
                v = tmp;
            }
            while (u != v) {
//                cout << "cost " << u << " to " << (u >> 1) << endl;
                h[u] += cost;
                u = u >> 1;
                if (v > u) {
                    lld tmp = u;
                    u = v;
                    v = tmp;
                }
            }
        }
        else {
            lld u, v;
            cin >> u >> v;
            if (v > u) {
                lld tmp = u;
                u = v;
                v = tmp;
            }
            lld ans = 0;
            
            
            while (u != v) {
//                cout << "cost " << u << " to " << (u >> 1) << endl;
                ans += h[u];
                u = u >> 1;
                if (v > u) {
                    lld tmp = u;
                    u = v;
                    v = tmp;
                }
            }
            
            cout << ans << endl;
        }
    }
    
    
    return 0;
}
