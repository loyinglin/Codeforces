//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1867/problem/B)
 **题目大意：**
 有一个长度为n的01字符串s，现在可以构造另外一个长度为n的字符串L，这个字符串有x个字符为1；
 现在想知道当x为0、1、2、3、、、、n时，字符串s和l每个字符按照位置进行异或操作后，最终生产的字符串是否为回文串；
 比如说s=101011，当x=2时，我们可以构造字符串L为010100，这样生成的字符串为111111，是回文串；
  
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100000)
 每个样例两行
 第一行整数𝑛，表示字符串长度 (1≤𝑛≤1e5)
 第二行字符串s
 
 **输出：**
 每个样例一行，输出长度为n+1的字符串，第i个字符为1表示可以构造有i个字符1的字符串l，使得最终生成字符串是回文串。
 
 **Examples**
 **input**
 5
 6
 101011
 5
 00000
 9
 100100011
 3
 100
 1
 1

 **output**
 0010100
 111111
 0011111100
 0110
 11




 **题目解析：**
 首先对字符串进行回文串匹配，初始cnt=1，假如某个位置无法匹配回文串的要求，我们用cnt++记录；
 这样cnt就可以表示回文串中不匹配的数量，不匹配只有01和10两种情况，此时需要一个字符串1和一个字符0，来进行异或操作；
 
 那么最终x应该要>=cnt，因为需要提供足够多的1来修正不匹配的字符；
 但是x也不能太多，因为需要有cnt数量的0来做匹配，最终x要<=n-cnt；
 那是否满足cnt <= x <= n-cnt就有解呢？
 还要考虑回文串中，是否为奇数。
 如果回文串为偶数，那么最终的x - cnt的数量还需要是奇数；
 如果回文串为奇数，存在最中间的位置可以任意操作，那么x - cnt可以为奇数或者偶数。
 
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
    char str[N];
    int ans[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> str;
            int cnt = 0;
            for (int i = 0; i < n / 2; ++i) {
                if (str[i] != str[n - i - 1]) ++cnt;
            }
            if (!cnt) ans[0] = ans[n] = 1;
            else ans[0] = ans[n] = 0;
            for (int i = 1; i < n; ++i) {
                ans[i] = 0;
                if (i >= cnt && i <= (n - cnt)) {
                    if ((i - cnt) % 2 == 0) { // 剩下为偶数，没有问题
                        ans[i] = 1;
                    }
                    else {
                        if (n % 2) ans[i] = 1; // 中间有留1个位置，可以随意变
                    }
                }
            }
            for (int i = 0; i <= n; ++i) putchar('0' + ans[i]);
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
 
