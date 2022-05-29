//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1684/problem/B)
 **题目大意：**
 给出整数a，b，c，满足a<b<c；
 构造三个整数x，y，z，满足：
 x mod y = a;
 y mod z = b;
 z mod x = c;
  
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤10000)
 每个样例一行，𝑎 , 𝑏, 𝑐 (1≤𝑎<𝑏<𝑐≤1e8).
  
 **输出：**
 每个样例一行，输出满足的𝑥 , 𝑦, 𝑧 (1≤𝑥,𝑦,𝑧≤1e18)
 
 
 **Examples**
 **input**
 4
 1 3 4
 127 234 421
 2 7 8
 59 94 388
 **output**
 12 11 4
 1063 234 1484
 25 23 8
 2221 94 2609
 
 
 **题目解析：**
 题目要求里面并没有包括x、y、z的大小关系，那么如果要满足x%y = a，最简单的做法就是x=a，并且满足x<y；
 同理，可以得到y%z=b，会有y=b，并且满足y<z；
 但是在z%x=c，假如我们令z=c，满足z<x则会出现异常，因为由前面两个已经可以递推得到x<y<z；并且由于a<c，x如果为a是无法得到c的；
 
 由于a<c的约束，我们先考虑满足z%x=c的限制，即是令z=c，并且满足z<x；
 接着是y%z=b，可以令y=b，由于b<c=z，所以这个也能够满足；
 剩下的就是x%y=a，已知y=b，那么有x%b=a，即是x=b*k + a；
 
 此时要满足x=b*k + a，z<x，可以令k=c，那么有x=c*b+a；
 
 
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

class Solution {
    static const int N = 201010;

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            lld a, b, c;
            cin >> a >> b >> c;
            cout << (c * b + a) << " " << b << " " << c << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 */
