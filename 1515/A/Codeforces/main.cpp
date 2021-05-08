//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1515/problem/A)
 **题目大意：**
 
 给出n个整数和整数x，问能否找到一个顺序：
 按照这个顺序累加数字，中间不会出现数字和等于x；
 已知n个整数互不相同。
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 只要最终的和与结果不同，那么就可以构造出来一个合理的顺序。
 
 比如说[1, i]的和等于x，由于a[i]!=a[i+1]，那么将i和i+1的数字进行调换即可。
 
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
            cin >> n >> x;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            int ok = 1, sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += a[i];
                if (sum == x) {
                    if (i == n - 1) {
                        ok = 0;
                    }
                    else {
                        swap(a[i], a[i + 1]);
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;
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
