//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1828/problem/C)
 **题目大意：**
 给出两个整数数组a和b，数组a的元素两两不相同；
 现在可以对数组a的元素任意排序，要求：
 对于数组a每一个元素a[i]，都满足a[i]>b[i]；
 问最多有多少种选择？
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行，第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 第二行 n个整数， 𝑎1 , 𝑎2, …, 𝑎𝑛 (1≤𝑎𝑖≤1e9)
 第三行 n个整数，𝑏1 , 𝑏2 , … , 𝑏𝑛 (1≤𝑏𝑖≤1e9 )
 
   
 **输出：**
 对于每个样例，输出最后的可能数，结果对1e9+7 取余；
 
 **Examples**
 **input**
 5
 6
 9 6 8 4 5 2
 4 1 5 6 3 1
 3
 4 3 2
 3 4 9
 1
 2
 1
 3
 2 3 4
 1 3 3
 12
 2 3 7 10 23 28 29 50 69 135 420 1000
 1 1 2 3 5 8 13 21 34 55 89 144

 
 **output**
 32
 0
 1
 0
 13824

 
 
 **题目解析：**
 
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
    int a[N], b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) cin >> b[i];
            sort(a, a + n, greater<int>());
            sort(b, b + n, greater<int>());
            lld sum = 1;
            int pos = 1;
            for (int i = 0; i < n; ++i) {
                if (a[i] <= b[i]) {
                    sum = 0;
                    break;
                }
                while (pos < n && a[pos] > b[i]) ++pos;
//                cout << i << " " << pos << " " << sum << endl;
                sum = (sum * (pos - i)) % 1000000007;
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
 
