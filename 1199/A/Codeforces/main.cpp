//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1199/problem/A)
 **题目大意：**
 有n个数字组成的数组𝑎1, 𝑎2, ..., 𝑎𝑛;
 找到一个index最小的数字a[k]，满足：
 1、a[k]比k往左边x个数字小；
 2、a[k]比k往右边y个数字大；
 
 输出k。

 
 
 输入：
 第一行， 𝑛, 𝑥 and 𝑦 (1≤𝑛≤100000, 0≤𝑥,𝑦≤7)
 第二行，n个数字，𝑎1, 𝑎2, ..., 𝑎𝑛 (1≤𝑎𝑖≤1e9),；
 
 
 输出：
 满足要求的，最小的索引k；（题目保证数据存在）
 
 **题目解析：**
 直接遍历判断，注意边界情况处理。
 
 
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

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        bool ok = 1;
        for (int j = i + 1; j <= i + y && j < n; ++j) {
            if (a[j] <= a[i]) {
                ok = 0;
            }
        }
        for (int j = i - 1; j >= i - x && j >= 0; --j) {
            if (a[j] <= a[i]) {
                ok = 0;
            }
        }
        if (ok) {
            cout << i + 1  << endl;
            return 0;
        }
    }
    
    
    return 0;
}
