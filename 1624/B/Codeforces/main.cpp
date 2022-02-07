//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1624/problem/B)
 **题目大意：**
 给出三个正整数a、b、c，现在可以对三个整数中的一个乘以正整数m；
 这个操作只能执行一次，要求是最后三个成为等差数列。
 比如说原来三个整数是10、5、30，那么可以将第二个乘以4，那么三个整数变为10、20、30，可以形成等差数列。
 
 
  **输入：**
 
 **输出：**

 
 **Examples**
 **input**


 
 **output**

 
 **题目解析：**
 最终想要形成的是等差数列，即是a-b=b-c；
 由此可以推出来：
 new_a=2b-c;
 new_b=(a+c)/2;
 new_c=2b-a;
 那么就只要看最终new_a、new_b、new_c是不是原来的a、b、c的整数倍即可。
 
 trick：
 需要注意，由于m是正整数，所以new_a必须大于等于a才行。
 
 
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
    string str;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int a, b, c;
            cin >> a >> b >> c;
            int ok = 0;
            int new_a = 2 * b  - c, new_b = (a + c) / 2, new_c = 2 * b - a;
            if (new_a >= a && new_a % a == 0) {
                ok = 1;
            }
            if (new_b >= b && new_b * 2 == (a + c) && (new_b % b == 0)) {
                ok = 1;
            }
            if (new_c >= c && new_c % c == 0) {
                ok = 1;
            }
            cout << (ok ? "YES" : "NO") << endl;
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
