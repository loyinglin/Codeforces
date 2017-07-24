//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/822/problem/C
 题目大意：
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second, cost;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

int dp[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &node[i].first, &node[i].second, &node[i].cost);
    }
    sort(node, node + n);
    
    
    for (int i = 0; i < n; ++i) {
        <#statements#>
    }
    
    return 0;
}
