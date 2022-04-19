//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/A)
 **题目大意：**
 小明有a个1元硬币，b个2元硬币；
 小明想要购买一个商品，并且不想找零；
 现在小明想知道自己无法给到最低价格是多少；

 比如说1个1元硬币，1个2元硬币，最低价格就是4元；
 比如说0个1元硬币，1个2元硬币，最低价格就是1元；（不能找零）
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例一行，整数 𝑎𝑖 and 𝑏𝑖 (0≤𝑎𝑖,𝑏𝑖≤1e8)
 
 **输出：**
 每个样例一行，输出最低价格；
 
 
 **Examples**
 **input**
 5
 1 1
 4 0
 0 2
 0 0
 2314 2374
 
 **output**
 4
 5
 1
 1
 7063

 **题目解析：**
 如果有1元硬币，那么必然可以给到a+2*b价格内的所有整数；
 如果没有1元硬币，那么1元就无法给到；
 
 
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

class Solution {
    static const int N = 201010;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int x, y;
            cin >> x >> y;
            cout << (x > 0 ? x+1+2*y : 1) << endl;
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
