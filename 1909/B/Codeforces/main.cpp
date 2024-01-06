//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1909/problem/B)
 **题目大意：**
 有n个整数的数组a，数组中每个元素互不相同；
 现在可以选择一个数字k，将数组中每一个元素进行对k取余的操作，然后将余数替代原来的元素；
 要求选择一个整数k，使得数组在操作后所有元素有且仅有2个不同的值。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤500)
 每个样例
 第一行，整数 𝑛 (1≤𝑛≤100)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤1e17)
 
  
 **输出：**
 每个样例一行，输出满足要求的 𝑘 (1≤𝑘≤1e18 )，题目保证有解；
 
 **Examples**
 **input**
 5
 4
 8 15 22 30
 5
 60 90 98 120 308
 6
 328 769 541 986 215 734
 5
 1000 2000 7000 11000 16000
 2
 2 1


 **output**
 7
 30
 3
 5000
 1000000000000000000


 **题目解析：**
 由于题目要求最后的余数有且仅有两个数字，而取余之后有2个余数的情况，自然就能想到k=2。
 我们对题目整数的值进行分类讨论：
 1、元素如果有奇数和偶数，%2就有0和1；
 2、如果全是偶数，也就是都是2 * x，那么可以再考虑k=4、8、16以此类推；
 3、如果全是奇数，假如1、3、5、7，%2全部是1，那么%4呢？首先排除0和2，因为都是奇数，不会产生偶数；那么结果只有2种情况，要么是1，要么3；
 那么假如全部是3呢？比如说3，7，11呢？那么必然全部可以抽象成4 x k + 3。可以继续用8来取余。转化为k为奇数或者偶数。
 

 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<lld> a;
            for (int i = 0; i < n; ++i) {
                lld x;
                cin >> x;
                a.push_back(x);
            }
            lld ans = 2;
            do {
                map<lld, int> h;
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (!h[a[i] % ans]) {
                        h[a[i] % ans] = 1;
                        ++cnt;
                    }
                }
                if (cnt > 1) break;
            } while (ans *= 2);
            
            cout<< ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
