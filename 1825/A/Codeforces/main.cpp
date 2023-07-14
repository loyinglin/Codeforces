//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1823/problem/A)
 **题目大意：**
 给出一个字符串s，现在想要从字符串s中找到最长的子序列，并且该子序列不是回文串；
 问，最长的子序列长度为多少；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行，字符串s （1≤|𝑠|≤50)
 
  
 **输出：**
 如果不存在子序列，输出-1；
 如果存在符合要求子序列，输出最大长度；
 
 **Examples**
 **input**
 4
 abacaba
 aaa
 codeforcesecrofedoc
 lol


 **output**
 6
 -1
 18
 2

 
 **题目解析：**
 如果字符串s全部是相同的字符，那么必然无解，因为无论怎么选择都是回文串；
 如果字符串存在不同的字符，那么必然可以构造一个非回文串（去掉任何一个偶数数量的字符即可）；
  
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
    char s[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int all = 1, n = strlen(s);
            for (int i = 1; i < n; ++i) all = all && (s[i] == s[0]);
            if (all) cout << -1 << endl;
            else {
                bool pl = 1;
                int x = 0, y = n - 1;
                while (x < y) {
                    if (s[x] != s[y]) pl = 0;
                    ++x;
                    --y;
                }
                cout << (pl ? n - 1 : n) << endl;
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
 
