//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2118/problem/A)
A. 相等子序列
每个测试用例的时间限制：1 秒
每个测试用例的内存限制：256 兆字节
我们称一个双字符串（由 0 和 1 组成的字符串）是 “完美的”，如果它所包含的 “101” 和 “010” 子序列数量相同。构造一个长度为 n 的完美双字符串，且其中恰好包含 k 个字符 1。
可以证明这样的构造总是可行的。如果有多个解，输出任意一个即可。
双字符串：仅由字符 0 和 1 组成的字符串。
子序列：若序列 a 可以通过删除字符串 b 中的若干（可能为 0 个或全部）字符得到，则称 a 是 b 的子序列。
输入
每个测试用例包含多个测试案例。第一行包含测试案例的数量 t（1 ≤ t ≤ 500）。接下来是各测试案例的描述。
每个测试案例的第一行包含两个整数 n 和 k（1 ≤ n ≤ 100，0 ≤ k ≤ n）—— 双字符串的长度以及其中字符 1 的数量。
输出
对于每个测试案例，输出构造好的双字符串。如果有多个解，输出任意一个即可。
示例
输入
5
4 2
5 3
5 5
6 2
1 1
输出
0101
10110
11111
100010
1
说明
在第一个测试案例中，“101” 和 “010” 子序列的数量相同，均为 1，且该序列恰好包含 2 个字符 1。
在第二个测试案例中，“101” 和 “010” 子序列的数量相同，均为 2，且该序列恰好包含 3 个字符 1。
在第三个测试案例中，“101” 和 “010” 子序列的数量相同，均为 0，且该序列恰好包含 5 个字符 1。


 
**题目解析：**
这是一道典型的构造题，题目没有要求符合的子序列数量，我们可以构造101、010都不包含的字符串，只要保证1的数量是k个即可。
比如说00000111111，这样的字符串，因为0和1都是挨着的，那么肯定无法出现101（两个1夹带0）或者010（两个0夹带1）。 
 
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
            int n, q;
            cin >> n >> q;
            for (int i = 0; i < q; ++i) putchar('1');
            for (int i = q; i < n; ++i) putchar('0');
            puts("");
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
