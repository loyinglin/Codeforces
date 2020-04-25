//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1277/problem/A)
 **题目大意：**
 
 
 输入：
 
 输出：

 
 input
 
 output
 
 
 **题目解析：**
 暴力枚举，从1、2、3开始算，
 
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
        cin >> a;
        int n = strlen(a);
        
        int ans = (n - 1) * 9 + (a[0] - '0');
        int ok = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[0]) {
                ok = 0;
                break;
            }
            else if (a[i] > a[0]) {
                ok = 1;
                break;
            }
        }
        if (!ok) {
            --ans;
        }
        
        cout << ans << endl;
    }
           
    
    return 0;
}


/**
 
 */
