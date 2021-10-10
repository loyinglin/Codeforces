//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1559/problem/B)
 **题目大意：**

 
  **输入：**
 
 **输出：**

 
 **Examples**
 **input**


 
 **output**

 
 **题目解析：**
 找到一个0/1的序列，数字末尾补1；
 
 
 WA：
 少考虑一种情况，可以从n+1的节点出发。
 
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
    static const int N = 200010;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            a[n] = 1;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            int pos = -1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 1 && a[i - 1] == 0) {
                    pos = i - 1;
                }
            }
            if (pos < 0) {
                cout << pos << endl;
            }
            else {
                for (int i = 0; i <= pos; ++i) {
                    cout << i + 1 << " ";
                }
                cout << n + 1 << " ";
                for (int i = pos + 1; i < n; ++i) {
                    cout << i + 1 << "";
                }
                cout << endl;
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
