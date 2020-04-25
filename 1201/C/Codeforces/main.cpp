//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1201/problem/C)
 **题目大意：**
 有n个数字，𝑎1,𝑎2,…,𝑎𝑛；
 现在可以进行k次操作，每次可以选择一个数字a[i]，使得a[i]=a[i]+1；
 问，进行k次操作，数组中的中位数最大为多少？
 
 
 输入：
 第一行，𝑛  and 𝑘 (1≤𝑛≤2⋅1e5, 𝑛是奇数, 1≤𝑘≤1e9)
 第二行，𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9).
 
 输出：
 最大的中位数。
 
 Examples
 input
 3 2
 1 3 5
 output
 5
 input
 5 5
 1 2 1 1 1
 output
 3

 
 **题目解析：**
 题目的数据没有先后顺序相关，可以先对数据排个序，方便处理。
 题目要求是中位数最大，假设我们的目标是s，那么从a[(n-1)/2]开始，所有的数字小于s的都要变大；
 因为k值比较大，模拟的做法不可取。
 考虑到在变大的过程中，我们每次都是固定处理后面n/2个数，那么如果s有解，则s-1也一定有解；（因为可以少变一些数字）
 基于此线性特点，可以用二分来解决。
 
 注意这里有个trick，二分的范围。
 
 比如说这样的数据：
 1 1000000000
 1000000000
 
 另外就是二分的时候，要注意用int64来处理。
 
 
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N];

bool check(lld mid, lld n, lld k) {
    for (lld i = (n - 1) / 2; i < n; ++i) {
        if (a[i] < mid && k >= 0) {
            k -= mid - a[i];
        }
    }
    return k >= 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    lld n, k;
    cin >> n >> k;
    for (lld i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    lld left = 1, right = a[n - 1] + k, ans = left;
    while (left <= right) {
        lld mid = (left + right) / 2;
        if (check(mid, n, k)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
