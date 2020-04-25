//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1328/problem/B)
 **题目大意：**
 
 
 **输入：**
 第一行整数t，表示样例个数；  (1≤𝑡≤10000)
 接下来t个样例，每个样例一行，有两个整数a、b；(1≤a，b≤10^9)
 
 **输出：**
 最少操作次数；
 
 **Examples**
 input
 5
 10 4
 13 9
 100 13
 123 456
 92 46
 
 output
 2
 5
 4
 333
 0
 
 **题目解析：**
 1+2+3+...

 
 **思考🤔：**
 
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

bool cmp(int a, int b) {
    return a > b;
}

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            if (k > i) {
                k -= i;
            }
            else {
                int x = n - i - 1, y = n - k;
                for (int j = 0; j < n; ++j) {
                    if (j == x || j == y) {
                        putchar('b');
                    }
                    else {
                        putchar('a');
                    }
                }
                puts("");
                
                break;
            }
        }
    }
    
    return 0;
}


/**
 
 aaabb
 aabab
 baaba
 bbaaa
 abb
 bab
 aaaaabaaaaabaaaaaaaa

 
 */
