//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1635/problem/A)
 **题目大意：**
 给出n个整数，每次可以选择其中两个整数a[i]和a[j]，令a[i]=x和a[j]=y，但是需要满足a[i] | a[j] = x | y；（|是或操作）
 现在可以进行任意次操作，问n个整数的最小和是多少。
 
  **输入：**
 第一行样例数，𝑡(1≤𝑡≤1000)
 每个样例两行，第一行是𝑛  (2≤𝑛≤100)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛  (0≤𝑎𝑖<2^30)
 
 **输出：**
每个样例一行，输出最小和。
 
 **Examples**
 **input**
 4
 3
 1 3 2
 5
 1 2 4 8 16
 2
 6 6
 3
 3 5 6
 **output**
 3
 31
 6
 7
 
 **题目解析：**
 1和3的或操作会得到3，那么相当于1被清0；
 也就是说，两个整数中间相同的二进制位数可以消除其中一个；
 那么题目转化为，对于(1<<k)，k从0到30，只要出现过一次就可消除其他整数；
 于是题目变成对于(1<<k)，k从0到30，所有出现过的数字的和。
 
 
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
    string str;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            bool vis[31] = {0};
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                for (int j = 0; j < 30; ++j) {
                    if (x & (1 << j) && !vis[j]) {
                        ans += (1 << j);
                        vis[j] = 1;
                    }
                }
            }
            cout << ans << endl;
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
