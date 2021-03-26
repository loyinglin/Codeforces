//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1478/problem/B)
 **题目大意：**
 给出的数字能否拆成若干个数字之和，每个数字都包含特定数字。
 
 **输入：**
 
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
以7为例，如果数字大于77，那么必然有解。
 那么小于100的数字可以枚举，更大的数字必然有解；
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

lld calc(lld a) {
    lld x = 0, y = 9;
    while (a) {
        x = max(x, a%10);
        y = min(y, a%10);
        a /= 10;
    }
    return x*y;
}

int a[100][10]; // a[i][j]表示数字为i，幸运数字是j，是否有解

int main(int argc, const char * argv[]) {
    // insert code here...

    for (int i = 1; i < 100; ++i) {
        for (int lucky = 1; lucky <= 9; ++lucky) {
            bool ok = 0;
            int tmp = i;
            while (tmp) {
                if (tmp % 10 == lucky) {
                    ok = 1;
                    break;
                }
                tmp /= 10;
            }
            a[i][lucky] = ok;
            for (int k = 1; k <= i; ++k) {
                if (a[k][lucky] && k + lucky < 100) {
                    a[k+lucky][lucky] = 1;
                }
            }
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        int q, d;
        cin >> q >> d;
        while (q--) {
            int k;
            cin >> k;
            if (k >= 100) {
                cout << "YES" << endl;
            }
            else {
                cout << (a[k][d] ? "YES" : "NO") << endl;
            }
        }
    }   
    
    return 0;
}
