//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/777/problem/C
 题目大意：
 给出n行数据，每行有m列，用a[i][j]来表示第i行，第j个数字；
 我们说某一列（比如说第j列）是有序的，如果满足：对于所有的i，a[i][j] ≤ a[i+1][j]；
 现在有k个询问，每个询问给出区间[l, r]，在第l行到第r行是否存在有序的列，有则输出Yes，无则输出No。
  
 n and m (1 ≤ n·m ≤ 100 000)
 a[i][j] (1 ≤ a[i][j] ≤ 1e9)
 k (1 ≤ k ≤ 100 000)
l[i] and r[i] (1 ≤ l[i] ≤ r[i] ≤ n).
 
 Example
 input
 5 4
 1 2 3 5
 3 1 3 2
 4 5 2 3
 5 5 3 2
 4 4 3 4
 6
 1 1
 2 5
 4 5
 3 5
 1 3
 1 5
 output
 Yes
 No
 Yes
 Yes
 Yes
 No
 
 题目解析：
 我们把每一列分成多个区间，每个区间内部都是有序的；（比如说样例的第一列1，3，4，5，4就可以分成两个区间[1, 4], [5, 5])
 对于询问[l, r]即是，是否存在一个有序的区间，覆盖给定的区间[l, r]；
 这题目没有要求统计[l, r]内的有序区间数量，只是询问是否存在，那么可以采用一种特殊的优化方式：
 对于两个区间[l, r]，我们直接用best[r]来表示r最多能达到r-l的距离；
 每一个点保留能到达最远的距离，这样在询问的时候，就可以通过best[r]和(r-l)的大小，O(1)判断是否存在；
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int best[N], dp[N];
vector<int> a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    
    for (int j = 0; j < m; ++j) {
        dp[j] = 1;
    }
    best[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] >= a[i - 1][j]) {
                dp[j]++;
            }
            else {
                dp[j] = 1;
            }
            best[i] = max(best[i], dp[j]);
        }
    }
    
    
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        --r, --l;
        if (best[r] >= r - l + 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
