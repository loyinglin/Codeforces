//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1758/problem/A)
 **题目大意：**
 给出在一个字符串s，现在可以将字符串s复制一遍，然后重新排序字符顺序；
 希望能得到一个回文串。
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例1行，字符串 𝑠 (1≤|𝑠|≤100)
   
 **输出：**
 每个样例一行，输出满足最终的回文串。
 
 
 **Examples**
 **input**
 4
 a
 sururu
 errorgorn
 anutforajaroftuna
 **output**
 aa
 suurruurruus
 rgnororerrerorongr
 aannuuttffoorraajjaarrooffttuunnaa

 
 **题目解析：**
 一个回文串的要求是从左到右，从右到左 两次遍历的字符串是一样的。
 那么对于给出的字符串s，我们只需要反着生产一遍即可，比如说：
 abc，我们得到abc + cba= abccba
 
 除了此办法，由于题目允许随意排序，那么遍历字符串，记住a-z的数量，然后左右两边再一起填字符也是可以的。
 
 
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
#include<cstring>
#include<iostream>

using namespace std;
 
typedef long long lld;
 
class Solution {
    static const int N = 201010;
    char str[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> str;
            int n = strlen(str);
            cout << str;
            for (int i = n - 1; i >= 0; --i) putchar(str[i]);
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
 
