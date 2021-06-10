//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1519/problem/A)
 **题目大意：**
 n个黑球，m个红球，将这些球分成若干堆，要求：
 1、每一堆都有至少一个黑球；
 2、每一堆都有至少一个红球；
 3、每一堆的黑球和红球数量差不超过d；
 
 **输入：**
 第一行是整数n，表示数组长度 (1≤𝑛≤5000)
  第二行是n个整数b[1]、b[2]、b[3]... b[n];(1<=b[i] <= 1e7）；
 
 **输出：**
 
 
 **Examples**
 **input**
 5
 2 3 2 1 3
 1 3 2 4 2
 
 **output**
 29

 样例解释：
 调转区间[4,5]，a=[2,3,2,3,1]，那么数组a和b的成绩和= 2⋅1+3⋅3+2⋅2+3⋅4+1⋅2=29
 
 **题目解析：**
 
 从题目的要求来看，堆是越多越好；红黑色并不影响，我们可以假设n<m；（如果n>m则进行调换）
 那么会有m堆，每堆最多有球(n+m-1)/m个
 
 
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
