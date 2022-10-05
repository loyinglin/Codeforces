//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1516/problem/A)
 **题目大意：**
 n个数字的数组a，可以执行最多k次操作，每次操作是找两个数字，其中一个+1，另外一个-1；
 想知道经过最多k次操作之后，数组最小的字典序是什么；
 
 **输入：**
 第一行是样例数𝑡 (1≤𝑡≤20)
 每个样例两行，第一行是整数𝑛 and 𝑘 (2≤𝑛≤100, 1≤𝑘≤10000)
 第二行是n个整数 𝑎1 , 𝑎2, …, 𝑎𝑛 (0≤𝑎𝑖≤100)
 **输出：**
 每个样例一行，要求所有数字非负，且 字典序最小；
  
 **Examples**
 **input**
 2
 3 1
 3 1 4
 2 10
 1 0
 
 **output**
 2 1 5
 0 1
 
 **题目解析：**
 容易知道，要让字典序最小，那么就是让前面的数字尽可能小；
 所以从左到右开始选择数字，让前面的数字优先-1，收益最大；
 同理，当我们需要+1的时候，为了字典序最小，全部加到最末尾的整数即可；
  
 
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
    int n, m;
    int a[N], b[N], c[N], ans[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> m;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            for (int i = 0; i < n - 1; ++i) {
                if (m >= a[i]) {
                    a[n - 1] += a[i];
                    m -= a[i];
                    a[i] = 0;
                }
                else {
                    a[n - 1] += m;
                    a[i] -= m;
                    m = 0;
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
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
