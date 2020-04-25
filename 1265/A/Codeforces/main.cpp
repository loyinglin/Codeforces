//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1265/problem/A)
 **题目大意：**
 一个字符串，如果没有连续两个字符是相同的，则称为美丽的字符串；
 
 给出一个字符串s，包括a/b/c/?，四种字符；
 现在需要把每个?字符，分别填入a/b/c字符中的一个；
 
 
 
 输入：
 
 输出：

 
 input
 
 output
 
 
 **题目解析：**
 假如只有一个?，则只需考虑相邻的字符；
 如果有多个?，那么可以先不考虑第二个?字符；
 因为可以填入三个字符，而每次相邻字符最多只有两种，则?必然可以填入一个字符，使得三个字符不连续相同；
 
 -1的情况仅仅出现在，原来的字符就有相同字符的情况。
 
 
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
