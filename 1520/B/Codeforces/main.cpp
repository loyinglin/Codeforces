//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/A)
 **题目大意：**
 给出一个数字n，求出[1,n]的区间中，有多少整数是可以满足，所有数字都是相同的。
 
 
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 因为题目数字较少，可以直接枚举，注意下枚举的效率。
 
 
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
            int ans = 0;
            int current = 1, cnt = 1;
            while (current * cnt <= n) {
                ++ans;
                ++cnt;
                if (cnt > 9) {
                    current = current * 10 + 1;
                    cnt = 1;
                }
            }
            cout << ans << endl;
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
