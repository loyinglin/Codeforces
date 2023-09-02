//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1845/problem/D)
 **题目大意：**
 小明在参加比赛，一共做了n道题目；
 初始状态0分，每道题目有得分a[i]，如果是正数则加分，如果是负数则扣分；
 现在可以选定一个整数k，在计算得分的过程中，如果小明分数大于等于k，则后续分数不会再小于k分（如果遇到负数，扣分之后最小分为k）；
 问整数k为多少，才能使得小明最后分数最大。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例2行
 第一行整数n ，表示数组长度（1 ≤ n ≤ 3e5)
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛 (−1e9≤𝑎𝑖≤1e9 ; 𝑎𝑖≠0 )
 
 
 **输出：**
 每个样例一行，输出使得小明分数最大整数k（区间范围内[−1e18, 1e18]），)如果有多个可以输出任意一个；
 
 **Examples**
 **input**
 4
 4
 3 -2 1 2
 3
 -1 -2 -1
 2
 4 2
 7
 5 1 -3 2 -1 -2 2


 **output**
 3
 0
 25
 6



 **题目解析：**
 如果题目没有负数，则任意选择整数即可；
 如果题目只有1个负数，那么选择这个负数前面的元素之和作为k，这样就可以抵消该负数的扣分；
 如果题目有2个负数，假如两个负数连起来能产生更大的负数，那么就用第一个负数前面的元素之和；如果两个负数中间存在正数，并且该正数大于任何一个负数，那么两个负数必然无法产生更大负数，那么选择较大负数前面的元素之和作为整数k；
 如果题目有更多负数，其实也可以简化为前面的情况，也就是找到一个区间，区间内元素之和是最大的负数，那么这个区间前面的元素之和就是k；
 
 每个位置记录一下sum[i]表示包括第i个元素的区间最小和，对于i+1元素，要么与前面区间和sum[i]合并，得到sum[i]+a[i]；要么就是单独成为一个区间a[i]；
 遍历一遍就可以得到最大负数的连续区间。
 
 
 
 
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
    static const int N = 301010;
    lld a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            lld minSum = 0, pos = -1, curSum = 0;
            for (int i = 0; i < n; ++i) {
                curSum = min(0ll, curSum) + a[i];
                if (curSum < minSum) {
                    minSum = curSum;
                    pos = i;
                }
            }
            if (minSum < 0) {
                lld tmp = 0;
                do {
                    tmp += a[pos];
                    --pos;
                } while (tmp != minSum);
                lld ans = 0;
                for (int i = 0; i <= pos; ++i) ans += a[i];
                cout << ans << endl;
            }
            else {
                cout << 0 << endl;
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
 
