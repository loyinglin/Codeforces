//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1185/problem/B)
 **题目大意：**
 小明用键盘的打字，但是键盘出现故障，每次敲击可能会出现多次结果，比如说按一次h，可能会出现"h"、"hh"、"hhh"等；
 现在给出小明打字的原始字符串和目标字符串，问目标字符串是否可能出现？
 比如说原始串是"hello"，那么目标串可以为"hello", "hhhhello", "hheeeellllooo"，但不能为"hell", "helo", "hhllllooo"。
 
 输入：
 第一行，数字n，表示n组字符；
 每组两行输入，第一行是原始字符串，第二行是目标字符串；
 
 输出：
 可能出现则输出YES，不可能则输出NO。
 
 Examples
 input
 5
 aa
 bb
 codeforces
 codeforce
 polycarp
 poolycarpp
 aaaa
 aaaab
 abcdefghijklmnopqrstuvwxyz
 zabcdefghijklmnopqrstuvwxyz
 output
 NO
 NO
 YES
 NO
 NO
 
 **题目解析：**
 我们用sourceStr和targetStr来表示原始字符串和目标字符串，根据题目的要求：
 1、sourceStr是targetStr的子序列；
 2、sourceStr中间某些单词会重复，并且targetStr与sourceStr不同的部分，均由这个重复的单词组成。

 基于此，可以从左到右遍历sourceStr和targetStr，当字符相同时可以加一，不同时
 if (a[x] == b[y]) {
 ++x;
 ++y;
 }
 else {
 if (x > 0 && b[y] == a[x - 1]) {
 ++y;
 }
 else {
 break;
 }
 }
 
 最后注意把y补齐，判断是否能否填充完毕。
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        int x = 0, y = 0;
        while (x < a.length() && y < b.length()) {
            if (a[x] == b[y]) {
                ++x;
                ++y;
            }
            else {
                if (x > 0 && b[y] == a[x - 1]) {
                    ++y;
                }
                else {
                    break;
                }
            }
        }
        while (y < b.length()) {
            if (a.back() == b[y]) {
                ++y;
            }
            else {
                break;
            }
        }
        if (x == a.length() && y == b.length()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
