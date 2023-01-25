//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1731/problem/A)
 **题目大意：**
 给出n个整数的数组，现在可以对数组进行以下操作：
 选择数组中任意两个不同的整数a[i]和a[j]，令a[i]=x，a[j]=y，其中满足x*y = a[i] * a[j];
 
 可以进行任意次操作，最后令数组的元素之和尽可能大。
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤4000).
 每个样例2行，第一行整数 𝑛 (2≤𝑛≤50)
 第二行整数𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e6)
  
 **输出：**
 每个样例一行，输出数组的整数和 乘以 2022。
 
 
 
 **Examples**
 **input**
 3
 3
 2 3 2
 2
 1 3
 3
 1000000 1000000 1
 **output**
 28308
 8088
 2022000000004044
 
 样例解释：
 样例1，第一次操作可以选择2和3，变成6和1，数组为[6, 1, 2]；第二次操作选择6和2，得到数组[12, 1, 1]；最终结果为(12+1+1) * 2022 = 28308；
 
 **题目解析：**
 题目的要求是尽可能让数组的元素和尽可能大，我们知道，对于正整数x和y，我们有[x * y, 1] 要大于[x, y]，那么只要把所有数字集中到一个数组即可。
 
 
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
            lld sum = n - 1, tmp = 1;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                tmp *= a[i];
            }
            sum += tmp;
            cout << sum * 2022 << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
