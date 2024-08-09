//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1925/problem/B)
 **题目大意：**
 有一个正整数x，现在需要把x分成n个正整数，这些正整数之和是x；
 现在要求，n个正整数的最大公约数，尽可能的大；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行，整数𝑥和 𝑛  (1≤𝑥≤1e8) and  (1≤𝑛≤𝑥).
  
 **输出：**
 每个样例一行，输出最大的公约数。
 
 **Examples**
 **input**
 3
 10 3
 5 5
 420 69

 **output**
 2
 1
 6


 **题目解析：**
 按照题目的要求，全部拆分成数字1，必然可以拆出满足要求：
 k-1个整数1，剩下的整数是x-n-1，这些整数的最大公约数是1；
 
 同理，假如最大公约数是2，可以这么拆：
 k-1个整数2，剩下的整数是x-2n-2，最大的公约数是2；
 
 也就是说，假设最大公约数是k，也可以这么安排：n-1个整数k，剩下是x-kn-k；
 
 由于题目的范围不大，那么枚举最大公约数的数字就好。
  
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
            int x, n;
            cin >> x >> n;
            int k = sqrt(x) + 1;
            int ans = 1;
            for (int i = 1; i <= k; ++i) {
                if (x % i == 0) {
                    if (i >= n) ans = max(ans, x / i);
                    if (x / i >= n) ans = max(ans, i);
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
 
