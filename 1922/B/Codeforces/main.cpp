//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1922/problem/B)
 **题目大意：**
 有n个棍子，长度分别为2^𝑎𝑖；
 从这些棍子里面挑出3个，组成一个三角形；
 想知道，一共有多少种选择。
（三个棍子，顺序不同算一个组合，比如说1、2、3 和 3、2、1）
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行 整数𝑛，表示n个棍子(1≤𝑛≤20)
 第二行 n个整数，𝑎1,𝑎2,…,𝑎𝑛  (0≤𝑎𝑖≤𝑛 ).
  
 **输出：**
 每个样例第一行，输出能够组合成三角形的数量。
 
 **Examples**
 **input**
 4
 7
 1 1 1 1 1 1 1
 4
 3 2 1 3
 3
 1 2 3
 1
 1



 **output**
 35
 2
 0
 0


 **题目解析：**
 先分析题目的数据特点。
 由题目知道，三个不同的数字是无法组合成三角；
 那么，有且仅有两种可能：
 1、三个数字相同；（这种情况就是组合数，C(x, 3) 从x个相同数组中选择3个）
 2、两个数字相同，剩下一个更小的数字；
 
 将整数排序，从小到大。情况2的数量，就可以选定当前数字的2个棍子，再乘以前面的所有数字的数量。
 
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
    static const int N = 301010;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            map<int, int> h;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                h[a[i]]++;
            }
            lld ans = 0, sub = 0;
            for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
                int cnt = it->second;
                if (cnt >= 3) {
                    ans += 1LL * cnt * (cnt - 1) * (cnt - 2) / 6;
                }
                if (cnt >= 2) {
                    ans += 1LL * cnt * (cnt - 1) / 2 * sub;
                }
                sub += cnt;
            }
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
