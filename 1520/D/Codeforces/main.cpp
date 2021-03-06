//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/D)
 **题目大意：**
 给出n个数字的数组，问数组中存在多少个(i, j)的组合，满足i<j 且 a[j]-a[i]=j-i；
 
 
 **输入：**
 第一行是整数t，表示t个样例(1≤𝑡≤1e4).
 每个样例有2行，第一行是整数n (1≤𝑛≤2⋅1e5)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛)
 
 
 **输出：**
输出满足要求的组合数量。
 
 **Examples**
 **input**
 4
 6
 3 5 1 4 6 6
 3
 1 2 3
 4
 1 3 3 4
 6
 1 6 3 4 5 6
 
 **output**
 1
 3
 3
 10

 
 **题目解析：**
 将题目要求的 a[j]-a[i]=j-i 换一下位置，得到 (a[j] - j)= (a[i] - i)；
 那么将所有的数字，减去当前的位置，然后排序，即可知道每一组数字的数量；
 每一组数字假设有k个，那么就有k*(k-1)/2的可能。
 
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

struct Node {
    int val, pos;
};

class Solution {
    static const int N = 200010;
public:
    int n, m;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                a[i] -= i;
            }
            a[n] = 0;
            sort(a, a + n);
            lld ans = 0, cnt = 1;
            for (int i = 1; i<= n; ++i) {
                if (a[i] != a[i - 1]) {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 1;
                }
                else {
                    ++cnt;
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
