//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1838/problem/A)
 **题目大意：**
 给出n个整数，已知这n个整数是按照下面的规则生成。
 1、初始化的时候，数组中有2个整数，每次从数组中选择任意两个整数，计算得到他们差值的绝对值，重新放回数组；
 2、重复n-2次操作1，得到n个元素的数组。
 
 现在已知n个整数的数组，想知道最开始的两个元素中，会存在哪个数字？
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤200)
 每个样例2行
 第一行，整数𝑛 (1≤𝑛≤100)
 第二行，n个整数𝑎1,𝑎2,…𝑎𝑛 (−1e9≤𝑎𝑖≤1e9 )
 
 
 **输出：**
 每个样例一行，输出初始整数中的一个，题目保证有解；
 
 **Examples**
 **input**
 9
 3
 9 2 7
 3
 15 -4 11
 4
 -9 1 11 -10
 5
 3 0 0 0 3
 7
 8 16 8 0 8 16 8
 4
 0 0 0 0
 10
 27 1 24 28 2 -1 26 25 28 27
 6
 600000000 800000000 0 -200000000 1000000000 800000000
 3
 0 -1000000000 1000000000


 **output**
 9
 11
 -9
 3
 8
 0
 -1
 600000000
 0



 **题目解析：**
 由题目的定义可以知道，|A-B|是无法产生负数，那么如果数字中存在负数，则必然负数是初始数字；
 同理假设x是数组中的最大元素，并且此时数组中并没有负数，那么x必然也是初始元素，因为|A-B|在全为正数的情况下，无法产生更大的数值。
 
 
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
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a, a + n);
            if (a[0] < 0) cout << a[0] << endl;
            else cout << a[n - 1] << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
