//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/B)
 **题目大意：**
 有n个整数的数组a，现在可以对数组进行操作：
 将数组区间[l, r]内的数值乘以-1；
 比如说[1,2,3,4,5]，对区间[2, 3]进行操作，则得到[1, -2, -3, 4, 5]；
 现在可以进行任意次（包括0次），问最少多少次，才能将数组所有元素的和最大；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例2行，第一行整数𝑛 (1≤𝑛≤2e5)
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛(-1e9≤𝑎𝑖≤1e9)
 
 
 **输出：**
 每个样例一行，输出2个整数，第一个整数表示最大的元素和，第二个整数表示最小的操作次数；
 
 **Examples**
 **input**
 5
 6
 -1 7 -4 -2 5 -8
 8
 -1 0 0 -2 1 0 -3 0
 5
 2 -1 0 -3 -7
 5
 0 -17 0 1 0
 4
 -1 0 -2 -1

 **output**
 27 3
 7 2
 13 1
 18 1
 4 1



 **题目解析：**
 要让结果最大，所有数字都应该变成非负数，最大和就是所有数字的绝对值之和；
 关键在于如何让次数尽可能少，我们对题目进行简化，在考虑正负数时，数值大小没有意义，可以将所有数字简化成：-1、0、1；
 由于操作的时候，可以选择一个区间进行操作，那么[-1、-1]和 [1, 1]这样的区间，可以简化成[-1]和[1]；（0也是同样道理）
 那么数组就变成了由[-1, 0, 1]组成的；
 同样简化思路，由于[-1, 0, -1]也同样看成一个[-1]，于是数组就变成了-1和1交错的情况；
 假设简化后的数组长度为m，结果就是m/2;（-1都是单独的，直接消除）
 
 
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
    static const lld N = 201010;
    int a[N];
public:
    void solve() {
        lld t;
        cin >> t;
        while (t--) {
            lld n, ans = 0;
            cin >> n;
            for (lld i = 0; i < n; ++i) {
                cin >> a[i];
                ans += abs(a[i]);
            }
            lld sum = 0;
            lld cur = 0, last = 0;
            while (cur < n && a[cur] >= 0) {
                ++cur;
            }
            if (cur < n) {
                ++sum;
                last = a[cur];
            }
            ++cur;
            while (cur < n) {
                if (a[cur] != 0) {
                    if (a[cur] * last < 0) {
                        last = a[cur];
                        ++sum;
                    }
                }
                ++cur;
            }
            cout << ans << " " << (sum + 1) / 2 << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
