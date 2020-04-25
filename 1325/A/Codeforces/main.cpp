//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1325/problem/A)
 **题目大意：**
 给出整数x，求两个整数a和b，满足：
 𝐺𝐶𝐷(𝑎,𝑏)+𝐿𝐶𝑀(𝑎,𝑏)=𝑥 .
 GCD是最大公约数；
 LCM是最小公约数；
 
 题目保证a和b存在；
 
 **输入：**
 第一行整数t，表示样例个数；  (1≤𝑡≤100)
 接下来t个样例，每个样例一行，整数x；(2≤𝑥≤10^9)
 
 **输出：**
 整数a和b； (要求范围，1≤𝑎,𝑏≤10^9)
 
 **Examples**
 input
 2
 2
 14
 output
 1 1
 6 4
 
 **题目解析：**
 构造题，这里提供一种思路：1+(x-1)。
 
 
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
        int n;
        cin >> n;
        cout << 1 << " " << n - 1 << endl;
    }
    
    return 0;
}
