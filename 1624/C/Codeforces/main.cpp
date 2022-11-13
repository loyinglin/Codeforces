//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1624/problem/C)
 **题目大意：**
 给出n个正整数的数组a，现在每次可以对数组的一个元素操作：a[i]=a[i]除以2，向下取整；
 问经过若干次操作之后，能否将数组变成1到n的排列，即数组是由整数1到n组成。
 
  **输入：**
 第一行样例数𝑡 (1≤𝑡≤1e4)
 每个样例两行，第一行整数𝑛 (1≤𝑛≤50)
 第二行n个整数 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9)
 
 **输出：**
 如果有解，输出YES；如果无解，输出NO；
 
 **Examples**
 **input**
 6
 4
 1 8 25 2
 2
 1 1
 9
 9 8 3 4 2 7 1 5 6
 3
 8 2 1
 4
 24 7 16 7
 5
 22 6 22 4 22
 **output**
 YES
 NO
 YES
 NO
 NO
 YES
 
 **题目解析：**
 由贪心的思想可以知道，如果给出的整数a中存在1到n的整数，应该优先使用这些整数；
 接着从剩下的整数中，不断挑选整数进行除2操作，如果遇到没有出现过的整数，则停止除2操作；
 
 因为即使存在另外整数除以2会得到相同值的整数，在得到相同值的时候，他们已经是等价的整数了。
  
 
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
    static const int N = 10010;
    string str;
    int a[N];
    int cnt[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                cnt[i + 1] = 0;
            }
            int ok = 1;
            for (int i = 0; i < n; ++i) {
                while (a[i]) {
                    if (a[i] <= n && cnt[a[i]] == 0) {
                        cnt[a[i]] = 1;
                        break;;
                    }
                    a[i] /= 2;
                }
                if (!a[i]) {
                    ok = 0;
                }
            }
            cout << (ok ? "YES" : "NO") << endl;
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
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
