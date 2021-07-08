//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1538/problem/C)
 **题目大意：**
从n个整数的数组中，找到(i, j)  要求 l ≤ a[i]+a[j] ≤ r，问有多少(i, j)；
 
  **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤10000 ).
 每个样例第一行是整数𝑛,𝑙,𝑟 (1≤𝑛≤2⋅1e5, 1≤𝑙≤𝑟≤1e9)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).
 
 **输出：**
 (𝑖,𝑗)的数量，要求是 (𝑖<𝑗) 并且 𝑙≤𝑎𝑖+𝑎𝑗≤𝑟.
 
 **Examples**
 **input**
 4
 3 4 7
 5 1 2
 5 5 8
 5 1 2 4 3
 4 100 1000
 1 1 1 1
 5 9 13
 2 5 5 1 1

 **output**
 yes
 2
 7
 0
 1

 
 **题目解析：**
 
 
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
    static const int N = 200010;
public:
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, l, r;
            cin >> n >> l >> r;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n);
            lld sum = 0;
            for (int i = 0; i < n; ++i) {
                <#statements#>
            }
            
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
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
