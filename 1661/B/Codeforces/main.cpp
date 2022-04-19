//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1661/problem/B)
 **题目大意：**
 给出一个整数v，现在可以执行任意次操作：
 𝑣 = (𝑣+1) mod 32768
 或  𝑣 = (2⋅𝑣) mod 32768.

 现在想知道，最少执行多少次操作，才能让整数变成0；
 
 
  **输入：**
 第一行整数𝑛 ，表示n个整数(1≤𝑛≤32768)
 第二行n个整数𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖<32768)
 
 **输出：**
 输出n个整数，分别表示n个整数的最少操作次数。
 
 
 **Examples**
 **input**
 4
 19 32764 10240 49
 **output**
 14 4 4 15
 
 **题目解析：**
 32768是一个比较大的整数，由于操作里面有一个乘以2操作，我们将32768进行除以2操作，发现32768=2^15；
 那么如果将整数v当成一个二进制数，就是寻求如何快速将这个二进制数的后面15位变为0；
 
 那么+1就是在整数末尾+1，如果是乘以2就是将整个整数左移；
 最极端的情况，将整个整数左移15次，一定会有解；
 另外，容易知道如果执行过一次x2操作，就不会再执行+1操作，因为x2操作是末尾补0，但是+1会导致末尾变成1；
 那么问题就变成在x2之前，需要执行多少次+1操作；
 
 这里有很多种做法：枚举x2操作的次数，然后计算剩下所有加法次数；
 枚举+1的次数，再计算枚举x2的次数；
 
  
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
    int a[N], b[N];
    
    void check(int n) {
        char s[20];
        int pos = 0;
        while (n) {
            s[pos++] = '0' + n % 2;
            n /= 2;
        }
        reverse(s, s + pos);
        s[pos] = 0;
        cout << s << endl;
    }

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            if (n == 0) {
                cout << 0 << endl;
                continue;;
            }
            int ans = 15; // 1 << 15
//            check(n);
            for (int i = 0; i < 15; ++i) {
                int mod = 1 << (15 - i);
                int left = n % mod;
                ans = min(ans, i + (mod - left) % mod);
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

/**
 */
