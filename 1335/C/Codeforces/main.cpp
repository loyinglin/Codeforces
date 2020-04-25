//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1335/problem/C)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，四个整数𝑎 , 𝑏, 𝑐, 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤10^9）
 
 **输出：**
 每个样例一行，三个s整数𝑥, 𝑦, 𝑧；
 
 **Examples**
 input
 4
 7
 4 2 4 1 4 3 4
 5
 2 1 5 4 3
 1
 1
 4
 1 1 1 3
 ⁣output
 ⁣3
 ⁣1
 ⁣0
 ⁣2
 
 
 **题目解析：**
 n个数字，先分出k个不同的数字组；
 先拿出来重复次数最多的数字x，剩下k-1个不同的数字；
 我们有min(count[x], k-1)可能性；
 如果这时候count[x]很大，我们还可以分一个x到不同的数字那边，此时答案是k；
 
 
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
const int N = 200010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];
map<int, int> hmap;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        hmap.clear();
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            ++hmap[k];
            maxCount = max(maxCount, hmap[k]);
        }
        
        if (hmap.size() <= maxCount - 1) {
            cout << hmap.size() << endl;
        }
        else {
            cout << min((int)hmap.size() - 1, maxCount) << endl;
        }
    }   
    
    return 0;
}
