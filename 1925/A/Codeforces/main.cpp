//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1925/problem/A)
 **题目大意：**
 有两个整数n和k，n表示字符串长度，k表示字符串由前k个小写字符；
 现在需要构造一个字符串s，要求任何长度为n的字符串，都是字符串s的子序列；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤676)
 每个样例一行，整数n和k  (1≤𝑛≤26 ) and  (1≤𝑘≤26 ).
  
 **输出：**
 每个样例一行，输出字符串s，如果有多个则输出最短长度的字符串；
 
 **Examples**
 **input**
 4
 1 2
 2 1
 2 2
 2 3

 **output**
 ab
 aa
 baab
 abcbac


 **题目解析：**
 题目的要求，所有常读为n的字符串，在拼接的时候就可以看成是n个选择，每次从k个字符中选择一个；
 那么在构造的时候，可以采用这样的策略：
 我们重复abc/abc/abc这样的字符串，每一组都相当有k个不同字符的桶。
 这样构造出来的结果就能满足要求。
  
 
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
            int n, k;
            cin >> n >> k;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j) putchar('a' + j);
            }
            cout << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
