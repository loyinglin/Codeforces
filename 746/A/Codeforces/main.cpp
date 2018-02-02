//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/746/problem/A
 题目大意：
 给出a、b、c三种材料，可以1:2:4组成d，不能拆分成0.5，问最多有多少材料参与制作。
 1个a 2个b 4个c 组成一个d，参与的材料有1+2+4=7。
 a,b,c (1 ≤ a,b,c ≤ 1000)
 Examples
 input
 2
 5
 7
 output
 7
 input
 4
 7
 13
 output
 21
 input
 2
 3
 2
 output
 0
 
 题目解析：
 题意非常清晰，暴力的做法是枚举，每次给a/b/c分别减去1/2/4，直到其中一种材料不足。
 更快的做法是`ans = min(a * 7, min(b / 2 * 7, c / 4 * 7));`
 
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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = a * 7;
//    while (a >= 1 && b >= 2 && c >= 4) {
//        ans += 7;
//        a -= 1, b-=2, c -= 4;
//    }
    ans = min(ans, min(b / 2 * 7, c / 4 * 7));
    
    cout << ans << endl;
    return 0;
}
