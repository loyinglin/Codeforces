//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1916/problem/A)
 **题目大意：**
 有一个整数数组a，数组每个元素的乘积是2023；
 数组移除了k个整数，剩下长度为n的数组b；
 
 现在已知数组长度n和数组b，问能否找到原来的数组a。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例2行
 第一行，整数𝑛和k (1≤𝑛,𝑘≤5)
 第二行，n个整数𝑏1,𝑏2,…,𝑏𝑛(1≤𝑏𝑖≤2023)
  
 **输出：**
 每个样例第一行，无解输出NO，有解输出YES；
 如果有解，则第二行再输出被移除的k个整数；
 
 **Examples**
 **input**
 7
 2 2
 5 2
 3 1
 7 17 7
 4 2
 1 289 1 1
 3 1
 7 17 17
 1 1
 289
 1 1
 2023
 1 3
 1


 **output**
 1
 1 0
 0
 0
 1
 3 0

 **题目解析：**
 题目的要求比较明确，当我们给出整数数组b时，假设最终的数组b乘积为m；
 m能够被2023整数时，剩余的k个数组就可以是[2023/m, 1， 1， 1】这样的数组来组成。
 如果m不能被整数，那么就无解了。

 
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
            int n, k;
            cin >> n >> k;
            int ans = 2023, ok = 1;
            for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                if (ans % x == 0) ans /= x;
                else ok = 0;
            }
            if (ok) {
                cout << "YES\n" << ans;
                while (k > 1) {
                    k--;
                    cout << " " << 1;
                }
                cout << endl;
            }
            else {
                cout << "NO" << endl;
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
 
