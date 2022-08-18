//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1704/problem/A)
 **题目大意：**
给出长度为n的由0和1组成的字符串a，现在可以对字符串a执行下面的操作：
 1、将a2=min(a1, a2)，然后移除a1；
 2、将a2=max(a1, a2)，然后移除a1；
现在有长度为m的字符串b，想问字符串a是否能通过任意次操作1或者操作2，得到字符串b；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤2000)
 每个样例第一行 整数   𝑛, 𝑚 (1≤𝑛,𝑚≤50, 𝑚≤𝑛)
 第二行长度为n的字符串a
 第三行长度为m的字符串b
 
  
 **输出：**
 每个样例一行，如果可以则输出YES；否则输出NO；
 
 
 **Examples**
 **input**
 10
 6 2
 001001
 11
 6 2
 110111
 01
 6 2
 000001
 11
 6 2
 111111
 01
 8 5
 10000101
 11010
 7 4
 1010001
 1001
 8 6
 01010010
 010010
 8 4
 01010101
 1001
 8 4
 10101010
 0110
 7 5
 1011100
 11100
 
 **output**
 YES
 YES
 NO
 NO
 NO
 YES
 YES
 NO
 NO
 YES
 
 
 **题目解析：**
 不管是操作1、操作2，都无法影响后续字符串；
 那么给出的字符串b，其实只有第一个字符的组成，a是有办法去选择；
 也就是说对于字符串a来说，后面的m-1个字符，必须和b一样；然后前面的字符必须出现过1次b的第一个字符；
 
 
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
            int n, m;
            cin >> n >> m;
            string a, b;
            cin >> a >> b;
            if (n == 1) {
                cout << (a[0] == b[0] ? "YES" : "NO") << endl;
                continue;;
            }
            if (m == 1) {
                int find = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i] == b[0]) find = 1;
                }
                if (find) cout << "YES" << endl;
                else cout << "NO" << endl;
                continue;
            }
            int ok = 1;
            for (int i = 1; i < m; ++i) {
                if (b[i] != a[n - m + i]) ok = 0;
            }
            int find = 0;
            for (int i = 0; i <= n - m; ++i) {
                if (a[i] == b[0]) find = 1;
            }
            if (find && ok) cout << "YES" << endl;
            else cout << "NO" << endl;
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
