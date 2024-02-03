//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1917/problem/A)
 **题目大意：**
 有n个整数的数组𝑎1,𝑎2,…,𝑎𝑛
 现在可以对数组进行多次下述操作：
 选择数组中的某个整数𝑎𝑖，如果𝑎𝑖<0 则可以把𝑎𝑖替换为[𝑎𝑖,0]区间中的整数；如果𝑎𝑖>0，则可以把𝑎𝑖替换为 [0,𝑎𝑖] 区间中的整数.
 
 现在想知道最少需要多少次操作，才能使得最终数组所有数字的乘积尽可能的小；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤500)
 每个样例2行
 第一行，整数𝑛(1≤𝑛≤100)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛(−1e9≤𝑎𝑖≤1e9).
  
 **输出：**
 每个样例第一行，输出需要的操作次数x；
 接下来每个操作一行，输出参数i和x，表示将a[i]设置为x；
 
 **Examples**
 **input**
 4
 1
 155
 4
 2 8 -1 3
 4
 -1 0 -2 -5
 4
 -15 -75 -25 -30


 **output**
 1
 1 0
 0
 0
 1
 3 0

 **题目解析：**
 题目的要求的是乘积尽可能小，如果数组当前乘积结果是正数，那么将任意一个数字变为0，结果就是最小值0；
 如果当前乘积是数字0，那么不管如何修改，最终结果都是0；
 如果当前乘积是数字负数，那么修改任何数字，都可能会让结果更大，而不是更小。
 
 
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
            int zero = 0, cnt = 0;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) ++zero;
                else if (a[i] < 0) ++cnt;
            }
            if (cnt % 2 || zero) cout << 0 << endl;
            else cout << "1\n 1 0" << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
