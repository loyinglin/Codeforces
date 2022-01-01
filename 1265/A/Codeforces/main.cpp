//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1265/problem/A)
 **题目大意：**
 一个字符串，如果没有连续两个字符是相同的，则称为美丽的字符串；
 
 给出一个字符串s，包括a/b/c/?，四种字符；
 现在需要把每个?字符，分别填入a/b/c字符中的一个；
 
 
 
 输入：
 第一行 𝑡，表示样例数 (1≤𝑡≤1000)
 每个样例一行，字符串𝑠 包括 'a', 'b', 'c' 和 '?'四种字符，字符串长度不超过10e5。
 
 输出：
 如果有解，则输出填充过后的字符串；
 如果无解，则输出-1；
 
 input
 3
 a???cb
 a??bbc
 a?b?c
 
 output
 ababcb
 -1
 acbac
 
 **题目解析：**
 首先是可以通过动态规划来解决，dp[i][j]=0/1表示第i个字符为a、b、c（j=0/1/2）是否有解；
 当s[i]=='?'时，则可以生成d[i][0]、d[i][1]、d[i][2]三种状态，状态转移方程比较直接。
 
 但是，题目还有另外一种解法：
 对于字符串中的?字符，假如某个位置只有一个?连续，则只需考虑相邻的字符，填入一个不冲突的字符填入即可；
 如果有多个?连续，因为连续?的相邻字符最多只有两种，但是?可以填入三种字符，则?必然可以填入一个字符，使得三个字符不连续相同；
 
 那么，什么情况下会出现-1的情况？
 幸好题目给出了样例：原来的字符就有相同字符的情况。 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

char a[N];



int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", a);
        int n = (int)strlen(a);
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == '?') {
                bool vis[3] = {0};
                if (i - 1 >= 0) {
                    vis[a[i-1] - 'a'] = 1;
                }
                if (i + 1 < n && a[i + 1] != '?') {
                    vis[a[i+1] - 'a'] = 1;
                }
                for (int j = 0; j < 3; ++j) {
                    if (!vis[j]) {
                        a[i] = 'a' + j;
                    }
                }
            }
        }
        
        bool ok = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ok = 0;
            }
        }
        if (ok) {
            printf("%s\n", a);
        }
        else {
            puts("-1");
        }
    }
           
    
    return 0;
}


/**
 
 */
