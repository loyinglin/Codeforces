//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1061/problem/A)
 **题目大意：**
 假设有面值为1、2、3、、、n元的硬币，每种硬币都有无限个，要凑出S元，最少需要多少个硬币？
 
 输入：
 一行，两个整数𝑛 and 𝑆 (1≤𝑛≤100000, 1≤𝑆≤1e9)
 
 输出：
 最少的硬币数量。
 
 Examples
 input
 5 11
 output
 3
 input
 6 16
 output
 3
 
 **题目解析：**
 因为每种硬币无限多，那么可以直接先取面值最大的硬币，剩下的额度再用对应的硬币即可。
 
 **思考🤔：**
 如果硬币面值是1、5、7呢？
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, s;
    cin >> n >> s;
    int ans = s / n;
    if (s % n) {
        ++ans;
    }
    cout << ans;
    
    return 0;
}
