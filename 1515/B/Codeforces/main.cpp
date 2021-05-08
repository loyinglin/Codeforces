//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1515/problem/A)
 **题目大意：**
 给出n个等边直角三角形，问 能不能拼出来正方形。
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 一个三角形面积是0.5，n个三角形的面积是n/2，假设最终能拼成三角形，则边长是 √(n/2)。
 只要最终的边长 是三角形的边是1和√2的整数倍，则题目有解。
 简化计算，我们已知
 √(n/2) = 1*x
 或者 √(n/2) =  √2 * y
 两边平方，有n/2=x*x 或者 n/2=2*y*y
 所以只要求一下√(n/2)，看看最终能否找到x或者y即可。
 
 
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
    int n, x;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            if (n % 2) {
                cout << "NO" << endl;
            }
            else {
                n /= 2;
                int t = sqrt(n), k = sqrt(n / 2);
                if (t * t == n || k * k * 2 == n) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
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
