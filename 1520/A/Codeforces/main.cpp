//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/A)
 **题目大意：**
 
 给出一个字符串，要求相同的字母都连在一起。
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 
 
 **思考🤔：**
 
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
    static const int N = 100010;
public:
    int n, m;
    string str;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            cin >> str;
            int a[256] = {0}, ok = 1;
            a[str[0]] = 1;
            for (int i = 1; i < n; ++i) {
                if (str[i] == str[i-1]) {
                    continue;;
                }
                else {
                    if (a[str[i]]) {
                        ok = 0;
                    }
                    else {
                        a[str[i]] = 1;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
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

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
