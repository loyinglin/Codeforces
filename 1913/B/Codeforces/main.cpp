//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1913/problem/B)
 **题目大意：**
 给出一个01字符组成的字符串𝑠，现在可以对字符串进行任意次下面操作：
 1、删除字符串中的某个一个字符，代价为1；
 2、调用两个位置上的字符，代价为0；
 

 现在要求，若干次操作后的字符串t，t上面每一个字符都与原来字符串s的字符相反，比如说：
 s=011
 那么t=10，最小操作代价是1，移除一个字符1，然后交换一次0、1的位置；
 
 s=111100
 那么t=00，最小操作代价是4，移除所有字符1；
 
 问生成满足要求的字符串t，最小的代价是多少。（注意移除所有字符也满足要求）
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，字符串𝑠 (1≤ |𝑠| ≤2⋅1e5）
  
 **输出：**
 每个样例一行，输出满足题目要求的最小代价；
 
 **Examples**
 **input**
 4
 0
 011
 0101110001
 111100

 **output**
 1
 1
 0
 4


 **题目解析：**
 按照题目的要求，直接看最终字符串t的样式，比如说s=111100，那么t=001111；
 那么只需要累计原来0、1的数字数量，然后从左到右枚举t的位置，直到剩下的字符无法填充，那么就得到t的最大长度；
 得到t的最大长度k，那么需要移除的字符串长度就是n--k。
 
 
 
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
            string str;
            cin >> str;
            int n = str.length(), x = 0, y = 0;
            for (int i = 0; i < n; ++i)
                if (str[i] == '0') ++x;
                else ++y;
            int k = 0, cntX = x, cntY = y;
            while (k < n) {
                if (str[k] == '0') {
                    if (y > 0) --y;
                    else break;
                }
                else {
                    if (x > 0) --x;
                    else break;
                }
                ++k;
            }
            if (x + y == 0) {
                cout << 0 << endl;
            }
            else {
                cout << n - k << endl;
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
 
