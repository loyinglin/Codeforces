//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1519/problem/A)
 **题目大意：**
 n个黑球，m个红球，将这些球分成若干堆，要求：
 1、每一堆都有至少一个黑球；
 2、每一堆都有至少一个红球；
 3、每一堆的黑球和红球数量差不超过d；
 
 **输入：**
 第一行是整数 𝑡，表示t个样例 (1≤𝑡≤1000)
 每个样例一行，整数 𝑟, 𝑏, and 𝑑 (1≤𝑟,𝑏≤1e9; 0≤𝑑≤1e9)
 
 **输出：**
 如果可以按照要求拆分，则输出YES；如果无法拆分，则输出NO；
 
 **Examples**
 **input**
 4
 1 1 0
 2 7 3
 6 1 4
 5 4 0
 
 **output**
 YES
 YES
 NO
 NO
 
 
 **题目解析：**
 用贪心的思想，在满足1和2的情况下，球堆的数量越多，那么3更容易满足；
 那么就可以直接分出min(n, m)堆，然后剩下的球再平分到这些球堆中，最后再计算是否满足条件3。
 为了方便计算，我们可以假设n<m；（如果n>m则进行调换，红黑色并不影响）
 那么会有m堆，每堆最多有球(n+m-1)/m个，这样就可以快速计算是否满足条件3。
 
 
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
    static const int N = 105;
public:
    int n, m, k, t;
public:
    void solve() {
        cin >> t;
        while (t--) {
            cin >> n >> m >> k;
            if (n < m) {
                swap(n, m);
            }
            cout << (((n + m - 1) / m - 1) <= k ? "YES" : "NO") << endl;
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
 Input
 5
 2 3 2 1 3
 1 3 2 4 2
 
 2 9 8 2 6
 
 Output
 29
 Input
 2
 13 37
 2 4
 Output
 174
 Input
 6
 1 8 7 6 3 6
 5 9 6 8 8 6
 Output
 235

 
 */
