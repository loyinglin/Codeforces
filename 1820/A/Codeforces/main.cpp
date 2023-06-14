//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1820/problem/A)
 **题目大意：**
 给出一个由 "_" 和 "^" 两种字符组成的字符串，现在小明可以往字符串任意位置插入这两种字符，要求：
 1、任何位置的字符，都可以和相邻连续字符组成"^_^"  或者 "^^" 这样的字符串；
 2、尽可能少的插入字符；
 
 比如说字符串"^^__^_^^__^"，在第3,4,9,10,11个字符，就无法和相邻连续字符组成满足要求的字符串。
 
 问最少需要插入多少个字符。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例1行，字符串𝑠 (1≤|𝑠|≤100)
 
  
 **输出：**
 每个样例一行，输出最少插入数量；
 
 **Examples**
 **input**
 7
 ^______^
 ___^_^^^_^___^
 ^_
 ^
 ^_^^^^^_^_^^
 ___^^
 _


 **output**
 5
 5
 1
 1
 0
 3
 2


 
 **题目解析：**
 字符串只包含两种字符，由于可以插入^字符，^字符可以和_组成^_^ ，也可以和^组成^_^，那么必然题目有解；
 对于题目来说，单个^，以及_左右不是^都是不合法的，需要插入^；
 那么就可以有简单的解决方案：
 从左到右遍历字符串，对于第i个字符串s[i]，假如：
 1、s[i]是^字符，只要i>0，^必然合法，因为s[i-1]是'^'，已经合法；如果s[i-1]是'_'，那么在处理s[i-1]的时候已经做了合法处理；
 2、s[i]是_字符，如果i==0，需要在前面插入^，否则只需要考虑后面是_的情况，需要插入一个^；
 
 
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
            int n = strlen(s);
        
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '_') {
                    if (i == 0) {
                        ++ans;
                    }
                    if (i + 1 == n || s[i + 1] == '_') {
                        ++ans;
                    }
                }
                else {
                    if (n == 1) {
                        ++ans;
                    }
                }
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
 
