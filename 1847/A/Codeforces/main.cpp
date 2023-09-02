//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1847/problem/A)
 **题目大意：**
 有n个整数的数组a，我们定义区间[l, r]的区间和为相邻元素的绝对值之和，用数学定义来表示：
 𝑓(𝑙,𝑟)=|𝑎[𝑙] − 𝑎[𝑙+1]| + |𝑎[𝑙+1] − 𝑎[𝑙+2]| + … + |𝑎[𝑟−1] − 𝑎[𝑟]|.
 如果区间长度为1，则区间和为0。
 
 现在需要将数组分隔成k个连续子数组，保证元素的相对顺序不变；
 现在想知道，分隔完之后所有数组进行区间和，总和最小为多少？
 
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
 两个分析思路。
 1、n的思考角度，从重复子问题来看，dp[i][j]表示前i个数字分隔成j段的最小值，那么dp[i][j]就可以由dp[i-1][j]和dp[1~i-1][j-1]来转移；
 2、k的思考角度，k=1时可以直接计算，k=2时我们会选择一个相邻绝对值最大值去分开，k=3时就是选择前2个相邻绝对值最大值去分开。
 
 两个思路都可以解决问题，但是思路2的实现难度要低很多。
 
 
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
    int b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n - 1; ++i) b[i] = abs(a[i] - a[i+1]);
            sort(b, b + n - 1);
            int sum = 0;
            for (int i = 0; i < n - k; ++i) sum += b[i];
            cout << sum << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
