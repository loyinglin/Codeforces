//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/762/problem/C
 题目大意：
 给出两个字符串a和b，现在从b中删去一个连续的子串，得到字符串b'，
 要求b'是a的子序列；
 现在希望删除尽可能短的字符串，并 输出b';
 （如果b'为空，输出'-'）
 
 a和b的长度均小于1e5；
 
 Examples
 input
 hi
 bob
 output
 -
 样例解释：删除所有的字符，得到空串，输出-；
 input
 abca
 accepted
 output
 ac
 样例解释：删除子串cepted，得到b'=ac，是a的子序列；
 
 
 
 
 
 题目解析：
 删除必然是某个区间[l, r]，先看最暴力的做法：
 枚举[l, r]的可能性，得到新的字符串bNew，对a和bNew做一次匹配；
 匹配的规则是对于bNew的每一个字符，都在原来基础上找最近的匹配，最后看bNew是否能在a中找到所有的字符匹配位置；
 枚举区间是O(N^2)，匹配是O(N)，总的复杂度是O(N^3);
 接下来看优化思路，
 性质1：区间[l, r]如果满足题意，那么[l-1, r]或者[l, r+1]也会满足题意；
 如果用动态规划，状态数有N^2，已经超过限制；（虽然动态规划的转移是整体O(N)）
 
 由性质1，这里可以引入一个二分：二分区间长度。
 然后再枚举区间的起点，得到bNew，再进行一次匹配；
 整体的复杂度是O(logN)的二分，O(N)的枚举区间起点，O(N)的单次匹配复杂度；
 
 这里单次匹配可以优化：
 dp[i]表示字符串b，前i个字符匹配字符串a，的最短长度；
 dpR[i]表示reverse_b（字符串b的转置），前i个字符串匹配字符串reverse_a，的最短长度；
 那么bNew=b减去区间[l, r]=[1,l-1] + [r+1, len]
 只要dp[i]+dpR[j]<=lenA，那么就有解；
 这样单次匹配的复杂度降到了O(1);
 
 总体的复杂度是O(logN * N), 题目能接受的复杂度。
 
 
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
const int N = 101000, M = 3010100, inf = 0xfffffff;
const lld llinf = 0x7fffffff7fffffffll;
char a[N], b[N];
char reverse_a[N], reverse_b[N];
int dp[N], dpR[N];
pair<int, int> ans;

bool find(int mid, int n, int m) {
    int t = mid;
    for (int i = 0; i + mid <= m; ++i) {
        int sum = 0;
        if (i > 0) {
            sum += dp[i];
        }
        if (m - i - mid > 0) {
            sum += dpR[m - i - mid];
        }
        if (sum <= n) {
            ans = make_pair(i, i + mid - 1);
            return true;
        }
    
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> a >> b;
    n = (int)strlen(a), m = (int)strlen(b);
    for (int i = 0; i < n; ++i) {
        reverse_a[i] = a[n - i - 1];
    }
    for (int j = 0; j < m; ++j) {
        reverse_b[j] = b[m - j - 1];
    }
    for (int i = 1; i <= m; ++i) {
        int p = dp[i - 1] + 1; // 从上一个开始索引
        while (p <= n && a[p - 1] != b[i - 1]) {
            ++p;
        }
        if (p <= n) {
            dp[i] = p;
        }
        else {
            dp[i] = inf;
        }
        
        int r = dpR[i - 1] + 1;
        while (r <= n && reverse_a[r - 1] != reverse_b[i - 1]) {
            ++r;
        }
        if (r <= n) {
            dpR[i] = r;
        }
        else {
            dpR[i] = inf;
        }
    }
    
    
    
    int l = 0, r = m + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (find(mid, n, m)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    if (ans.first == 0 && ans.second == m - 1) {
        cout << "-" << endl;
    }
    else {
        for (int i = 0; i < m; ++i) {
            if (i < ans.first || i > ans.second) {
                putchar(b[i]);
            }
        }
        puts("");
    }
    
    return 0;
}

/*
 abccdd
 dfcc
 
 */
