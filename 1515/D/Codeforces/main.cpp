//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1515/problem/D)
 **题目大意：**
 有n只袜子，每只一个颜色
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 先将左右袜子颜色一样的挑出来；
 
 接着将相同颜色的left/right 组成一对，每对的代价是1；（将多的那一组，分给少的那一组）
 
 假设剩下x只left，y只right，并且x和y没有相同的颜色，则剩下有两个花费：
 1、花费abs(x-y)/2的差额，将left和right数量对齐；
 2、花费（x+y)/2的费用，将一半的颜色和另外一半对齐；
 
 
 
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
public:
    int n, l, r;
    int a[N];
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> l >> r;
            map<int, int> hashLeft, hashRight;
            int ans = 0, cntLeft = 0, cntRight = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (i < l) {
                    ++hashLeft[a[i]];
                    ++cntLeft;
                }
                else {
                    if (hashLeft[a[i]]) {
                        --hashLeft[a[i]];
                        --cntLeft;
                    }
                    else {
                        ++hashRight[a[i]];
                        ++cntRight;
                    }
                }
            }
            if (cntLeft > cntRight + 1) {
                for (map<int, int>::iterator it = hashLeft.begin(); it != hashLeft.end(); ++it) {
                    while (it->second >= 2 && cntLeft > cntRight + 1) {
                        cntLeft -= 2;
                        ++ans;
                        it->second -= 2;
                    }
                }
            }
            else if (cntRight > cntLeft + 1) {
                for (map<int, int>::iterator it = hashRight.begin(); it != hashRight.end(); ++it) {
                    while (it->second >= 2 && cntRight > cntLeft + 1) {
                        cntRight -= 2;
                        ++ans;
                        it->second -= 2;
                    }
                }
            }
            ans += max(cntLeft, cntRight);
            
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
 4
 6 3 3
 1 2 3 2 2 2
 6 2 4
 1 1 2 2 2 2
 6 5 1
 6 5 4 3 2 1
 4 0 4
 4 4 4 3
 
 output
 2
 3
 5
 3
 
 */
