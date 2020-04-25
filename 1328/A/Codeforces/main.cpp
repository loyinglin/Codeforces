//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1328/problem/A)
 **题目大意：**
 输入两个整数a和b，每次操作可以使得a=a+1；
 问最少要几次操作，可以使得a可以整除b；
 
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
 为了便于描述，下面用x和y来代替a和b；
 如果x<=y，那么操作数就是y-x；
 如果x>y，那么可以直接判断x%y==0，不满足则++x；
 但是如果这样直接算，这个过程比较慢。在x%y!=0，不断x=x+1的时候，可以确定x/y的结果就是(x+y)/y取整；
 那么最小操作次数就是`(x + y) / y * y - x` 。
 
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
        int x, y;
        cin >> x >> y;
        if (x <= y) {
            cout << y - x << endl;
        }
        else {
            if (x % y == 0) {
                cout << 0 << endl;
            }
            else {
                cout << (x + y) / y * y - x << endl;
            }
        }
    }
    
    return 0;
}
