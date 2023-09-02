//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/C)
 **题目大意：**
 有[如图](https://espresso.codeforces.com/3fe851b2505ce276dabd4a63ad7472346f98f9a8.png)的二叉树；
 数字从1到n有且只有一条路径，求这个路径上的整数和。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行整数𝑛 (1≤𝑛≤1e16)
 
 
 
 **输出：**
 每个样例一行，输出路径上的累加和。
 
 **Examples**
 **input**
 6
 3
 10
 37
 1
 10000000000000000
 15


 **output**
 4
 18
 71
 1
 19999999999999980
 26





 **题目解析：**
 二进制分析思路：
 完全二叉树，每次有两个选择，左或者右；
 对应到二进制，左边是0，右边是1；
 5是101，对应到二进制树就是左+右；
 
 搜索分析思路：
 1到12为例，1到12的路径有且仅有1-3-6-12；
 将这些数字的二进制写出来：
 1
 11
 110
 1101
 容易发现二进制的前缀是相同的；
 
 这样不断能去掉n最为后一位二进制数，可得上一位数字，累加即可。
 
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
            lld n;
            cin >> n;
            lld ans = 0;
            while (n) {
                ans += n;
                n /= 2;
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
 
