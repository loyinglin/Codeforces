//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1679/problem/B)
 **题目大意：**
 给出n个整数的数组a，现在有两个操作：
 1、将第i个数字替换为x；
 2、将整个数组替换为x；
 现在想知道经历q次操作，每次操作完数组的和；
 
  **输入：**
 第一行，整数 𝑛 and 𝑞 (1≤𝑛,𝑞≤2⋅1e5)
 第二行n个整数 𝑎1,…,𝑎𝑛 (1≤𝑎𝑖≤1e9)
 接下来q行，每行第一个数字是t，表示操作1或者操作2；
 如果t=1，则接下来输入数字i和x (1≤𝑖≤𝑛, 1≤𝑥≤1e9)
 如果t=2，则接下来输入数字x  (1≤𝑥≤1e9)
  
 **输出：**
 每个操作一行，输出操作后的数字和；
 
 
 **Examples**
 **input**
 5 5
 1 2 3 4 5
 1 1 5
 2 10
 1 5 11
 1 4 1
 2 1

 **output**
 19
 50
 51
 42
 5
 
 **题目解析：**
 朴素的做法，对于数组a，操作1则修改a[i]，时间复杂度O（1）；
 操作2则全量修改数组a，时间复杂度O（N）；
 计算数字和的复杂度，也是O（N），总的复杂度是（NQ）；
 
 对于操作2，全量修改没必要，用变量记住当前整个数组已经修改即可，数字和也不需要累计，直接x和n的乘积即可；
 但是这个变量要如何兼容操作1？
 不用兼容，单独用一个map来记录操作1，当遇到操作2的时候再把map清空；正常往map里面添加一个值的时候，我们就可以实时算出来这个值带来的总和diff，O（1）就可以维护这个数组和；
 将这个思路流程化，那么就是记录一个当前和sum；
 然后生成一个map，记录每个位置对应的值；
 当遇到操作1，则访问当前map，拿到当前值（如果map没有就是操作2的值），生成新的值记录到map，并更新diff到sum；
 遇到操作2，则清空map并更新sum；
 总的复杂度是O(NlogN)；
 
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
    static const int N = 201010;
    lld a[N];

public:
    void solve() {
        lld n, q;
        cin >> n >> q;
        map<lld, lld> h;
        lld cur = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            lld x;
            cin >> x;
            h[i] = x;
            sum += x;
        }
        while (q--) {
            int k;
            cin >> k;
            if (k == 1) {
                int i, x;
                cin >> i >> x;
                if (h[i]) {
                    sum += x - h[i];
                    h[i] = x;
                }
                else {
                    sum += x - cur;
                    h[i] = x;
                }
            }
            else {
                int x;
                cin >> x;
                cur = x;
                sum = cur * n;
                h.clear();
            }
            cout << sum << endl;
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
 */
