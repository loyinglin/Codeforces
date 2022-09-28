//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1715/problem/B)
 **题目大意：**
 给出包括n个非负整数的数组a，我们可以计算这个数组的beauty值：
 将数组每个元素除以k，向下取整得到这个元素的beauty值，数组的beauty值等于所有元素的beauty值总和；
 现在给出n、k、数组beauty值b和数组元素累加和s，求是否能够构造数组a；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤1000)
 每个样例第一行 整数  𝑛, 𝑘, 𝑏, 𝑠 (1≤𝑛≤1e5, 1≤𝑘≤1e9, 0≤𝑏≤1e9, 0≤𝑠≤1e18).
  
 **输出：**
 每个样例一行，如果无解输出-1；如果有解则输出n个整数；𝑎1,𝑎2,…,𝑎𝑛  (0≤𝑎𝑖≤1e18)
 
 
 **Examples**
 **input**
 8
 1 6 3 100
 3 6 3 12
 3 6 3 19
 5 4 7 38
 5 4 7 80
 99978 1000000000 100000000 1000000000000000000
 1 1 0 0
 4 1000000000 1000000000 1000000000000000000
 **output**
 -1
 -1
 0 0 19
 0 3 3 3 29
 -1
 -1
 0
 0 0 0 1000000000000000000
 
 
 **题目解析：**
 为了方便思考，我们先考虑数组只有3个元素的情况，那么有：
 a1 + a2 + a3 = s ;
 a1/k + a2/k + a3/k = b;
 
 那么我们可以令a1=k * b，先保证条件b可以满足；
 因为除以k的原因，接下来a1到a3，都可以增大k-1的大小而且不影响b的值；
 那么s的上限就是k * b + n * (k - 1)，下限就是k * b；
 满足这里的条件就有解。
 
 思考：
 如何证明正确性？假设a1/k + a2/k，a2需要大于k，那么将a2-k，并将a1+k是等价的；
 
 注意：
 超过int32，不过样例已经覆盖了这样的case。
 
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
        lld t;
        cin >> t;
        while (t--) {
            lld n, k, b, s;
            cin >> n >> k >> b >> s;
            lld maxSum = k * b + n * (k - 1);
            if (maxSum < s || b * k > s) {
                cout << -1 << endl;
            }
            else {
                s -= b * k;
                for (lld i = 0; i < n; ++i) {
                    lld tmp = min(k - 1, s);
                    s -= tmp;
                    if (i == 0) tmp += b*k;
                    cout << tmp << " ";
                }
                cout << endl;
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
 */
