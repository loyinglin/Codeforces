//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1847/problem/B)
 **题目大意：**
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例两行
 第一行整数𝑛,𝑘 (1≤𝑘≤𝑛≤100 ).
 第二行整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤500)
 
 **输出：**
 每个样例，输出最小的区间和。
 
 **Examples**
 **input**
 3
 4 2
 1 3 5 2
 6 3
 1 9 12 4 7 2
 12 8
 1 9 8 2 3 3 1 8 7 7 9 2

 **output**
 4
 11
 2



 **题目解析：**
 n=1时，最小值就是a[1];
 n=2时，最小值就是a[1]&a[2];
 n=k时，最小值就是a[1]~a[k]的与，因为and操作只会使得结果更小；
 
 假设最小值结果为m；
 m不为0时，集合数量只能为1，因为拆分两个集合结果就变成2m，值会更大；
 m为0时，集合数量可以拆分为多个&值为0的区间，那么从左到右遍历，累计出现&结果为0就算一个区间。
 
 
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
    static const int inf = 0x7fffffff;
    int a[N];
    int b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            int m = a[0];
            for (int i = 1; i < n; ++i) m = m&a[i];
            if (!m) {
                int cur = inf, ans = 0;
                for (int i = 0; i < n; ++i) {
                    cur = cur & a[i];
                    if (cur == m) {
                        ++ans;
                        cur = inf;
                    }
                }
                cout << ans << endl;
            }
            else {
                cout << 1 << endl;
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
 
