//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1527/problem/B)
 **题目大意：**
 
 
 
 
 **输入：**
 第一行是整数t，表示有t个样例(1≤𝑡≤1e4).
 每个样例一行，第一行是整数n(1≤𝑛≤1e9).
 **输出：**
 每个样例一行，输出1到n的整数中，有多少个由相同数字组成的数。

 
 **Examples**
 **input**
 6
 1
 2
 3
 4
 5
 100

 **output**
 1
 2
 3
 4
 5
 18

 
 
 **题目解析：**
 这里有一个简单策略：对于一个回文串（最中间的数字不为0），那么可以采取A填哪个位置，B就填回文串对应的位置；
 直到剩下2个0的时候，A填任何一个位置，B选择reverse；此时A只能再填一次0，B必胜；
 
 先手者，除非回文串中间是0（当有空格的部分大于1时），否则必输；
 
 **思考🤔：**
 
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
    static const int N = 100010;
public:
    int n, m;
    string str;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            cin >> str;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (str[i] == '0') {
                    ++cnt;
                }
            }
            if (cnt == 0) {
                cout << "DRAW" << endl;
            }
            else if (cnt == 1) {
                cout << "BOB" << endl;
            }
            else if (cnt % 2) {
                cout << (str[(n - 1) / 2] == '0' ? "ALICE" : "BOB") << endl;
            }
            else {
                cout << "BOB" << endl;
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

/**
 
 
 
 
 
 
 
 741
 2
 00
 3
 000
 3
 010
 4
 0000
 5
 00000
 5
 00100
 4
 1001
 5
 10001
 5
 10101
 4
 0110
 5
 01010
 5
 01110
 6
 000000
 7
 0000000
 7
 0001000
 6
 100001
 7
 1000001
 7
 1001001
 6
 010010
 7
 0100010
 7
 0101010
 6
 110011
 7
 1100011
 7
 1101011
 6
 001100
 7
 0010100
 7
 0011100
 6
 101101
 7
 1010101
 7
 1011101
 6
 011110
 7
 0110110
 7
 0111110
 8
 00000000
 9
 000000000
 9
 000010000
 8
 10000001
 9
 100000001
 9
 100010001
 8
 01000010
 9
 010000010
 9
 010010010
 8
 11000011
 9
 110000011
 */
