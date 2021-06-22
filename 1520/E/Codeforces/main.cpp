//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/E)
 **题目大意：**
 给出长度为n的字符串，'*'表示绵羊， '.'表示空地；
 每次可以把绵羊移动到相邻的空地，问需要移动多少次，才能将所有的绵羊赶在一起。
 
 **输入：**
 第一行是整数t，表示t个样例(1≤𝑡≤1e4).
 每个样例有2行，第一行是整数n (1≤𝑛≤2⋅1e5)
 第二行是字符串
 
 
 **输出：**
最小的移动次数。


 
 ```
 **Examples**
 **input**
 5
 6
 **.*..
 5
 *****
 3
 .*.
 3
 ...
 10
 *.*...*.**
 
 **output**
 1
 0
 0
 0
 9
 ```
 
 **题目解析：**
 方法1：
 暴力，假设羊最终集中在区间[left, right]上面，枚举left的位置，再用贪心从左到右匹配羊的位置。

 方法2：
 动态规划
 dpLeft[i]表示，前i个位置中的所有羊，都集中在位置i左边；
 dpRight[i]表示，[i, n]的位置中所有羊，都集中在位置i的右边；
 这样只要得到结果之后，只要枚举每一个位置即可。
 
 数据范围较大，没用long long 错了2次。

 
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
    static const int N = 1000010;
public:
    int n, m;
    string str;
    pair<lld, lld> dpLeft[N], dpRight[N]; // first 是最小代价，second的当前绵羊数量
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            cin >> str;
            dpLeft[0] = make_pair(0, 0);
            for (int i = 1; i <= n; ++i) {
                char c = str[i - 1];
                if (c == '*') {
                    dpLeft[i].first = dpLeft[i-1].first;
                    dpLeft[i].second = dpLeft[i-1].second + 1;
                }
                else {
                    dpLeft[i].first = dpLeft[i-1].first + dpLeft[i-1].second;
                    dpLeft[i].second = dpLeft[i-1].second;
                }
            }
            dpRight[n+1] = make_pair(0, 0);
            for (int i = n; i > 0; --i) {
                char c = str[i - 1];
                if (c == '*') {
                    dpRight[i].first = dpRight[i+1].first;
                    dpRight[i].second = dpRight[i+1].second + 1;
                }
                else {
                    dpRight[i].first = dpRight[i+1].first+dpRight[i+1].second;
                    dpRight[i].second = dpRight[i+1].second;
                }
            }
            lld ans = dpRight[1].first;
            for (int i = 0; i <= n; ++i) {
                ans = min(ans, dpLeft[i].first + dpRight[i + 1].first);
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
