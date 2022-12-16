//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1771/problem/A)
 **题目大意：**
 给出n个整数的数组，从数组中选择两个数字a[i]和a[j]，要求满足：
 i和j不相同；
 |a[i]-a[j]|的值，等于数组中最大值与最小值的差；
 问，最多能选出多少个组合。
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例2行，第一行整数 𝑛 (2≤𝑛≤1e5)
 第二行整数 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e5)
  
 **输出：**
 每个样例一行，输出满足要求的组合数。
 
 
 **Examples**
 **input**
 2
 5
 6 2 3 8 1
 6
 7 2 8 3 2 10
 **output**
 2
 4
 
 样例解释：
 样例1，满足要求的有[1, 8]和[8, 1]；
 样例1，满足要求的有[2, 10]和[10, 2]，其中2可以为第2个数字、第5个数字；
 
 **题目解析：**
 因为选出来的数字要满足差的绝对值最大，那么必然是最大值和最小值的组合。
 假设最小值x，最大值y，首先看x和y是否相同。
 如果x==y，则看x的总数，答案就是A(n, 2)，即是从n个整数中选择2个数字的组合排列数；
 如果x!=y，那么结果就是x的数量与y的数量的乘积。
 
 trick：
 两个情况都可能超int32。
 
 
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
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n);
            if (a[0] == a[n - 1]) cout << n * 1LL * (n - 1) << endl;
            else {
                int x = 0, y = 0;
                while (a[x] == a[0]) {
                    ++x;
                }
                while (a[n - 1 - y] == a[n - 1]) {
                    ++y;
                }
                cout << x * 1LL * y * 2 << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
