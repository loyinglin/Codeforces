//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/766/problem/C
 题目大意：
 一个长度为n的字符串s，s由26个小写字母组成；
 我们可以把字符串s，切分成多个子串，但是有个限制：
 第i个字母所在的所有子串的长度，不能超过a[i]；
 
 现在想知道：
 1、有多少种切分的方法（结果mod 1e9 + 7）
 2、在所有的切分方法中，最长的子串的长度；
 3、在所有的切分方法中，最少的子串数量；
 
 
 n (1 ≤ n ≤ 1000)
 a1, a2, ..., a26 (1 ≤ a[i] ≤ 1000)
 
 Examples
 input
 3
 aab
 2 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 output
 3
 2
 2
 样例解释：
 总共有三种切分方式：
 a|a|b
 aa|b
 a|ab
 需要注意，aab不是有效的切分方式，因为a所在的子串长度是3，而a[1]=2。
 
 
 
 
 题目解析：
 题目给出的限制是 第i个字母所在的所有子串的长度，不能超过a[i]；
 所以两个合法的子串，拼接起来的也是合法的串，满足动态规划的特性。
 
 对于第一个问题：区间[i, j]的有效切法 dp[i][j]=sum(dp[i][k], dp[k+1][j]), i<=k<=j
 同理，第二、三个问题可以用相同的求解过程。
 但是，每次转移的复杂度是O(N)，状态数是O(N^2)，总的复杂度是O(N^3);
 
 优化：
 dp[i][j]
 
 
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0, last = 2;
    for (int i = 0; i + 2 < n; ++i) {
        int sum = a[i] + a[i + 1];
        if (sum > a[i + 2]) {
            ans = 1;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
