//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1873/problem/A)
 **题目大意：**
 有3个字符a/b/c，排成一行；
 现在可以选择两个字符，交换对应的位置；
 上述操作最多只能执行一次，问能否得到abc的顺序。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤6)
 每个样例一行，字符串abc的随机排列；
  
 **输出：**
 每个样例一行，如果有解则输出YES，无解则输出NO；
 
 **Examples**
 **input**
 6
 abc
 acb
 bac
 bca
 cab
 cba

 **output**
 YES
 YES
 YES
 NO
 NO
 YES



 **题目解析：**
 将字符串与abc进行匹配，计算得到一共有x个位置的字符匹配；
 如果x=3，则全部字符都匹配了，不需要操作；
 如果x=1，则表示有2个字符不匹配，那么交换这两个字符；
 其他情况则直接输出NO；
   
 
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
            char s[10];
            cin >> s;
            int cnt = 0;
            for (int i = 0; i < 3; ++i) if (s[i] == 'a' + i) ++cnt;
            cout << ((cnt == 1 || cnt == 3) ? "YES":"NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
