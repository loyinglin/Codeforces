//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1826/problem/B)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行：
 第一行整数n(2≤𝑛≤2⋅1e5)
 第二行整数数组a
 第二行整数数组b
 注意：数组a和数组b至少有一个位置的元素不相同。
  
 **输出：**
 每个样例一行，输出区间[l, r]，表示可以选择进行操作的最长区间，如果由多个答案，输出任意一个；（题目保证有解）
 
 **Examples**
 **input**
 3
 7
 6 7 3 4 4 6 5
 6 3 4 4 7 6 5
 3
 1 2 1
 1 1 2
 3
 2 2 1
 2 1 2

 **output**
 2 5
 1 3
 2 3


 
 **题目解析：**
 
 对于整数a和b，想要使得a和b对x取余之后的数字相同，那么有两种情况：
 
 
 
 
 4 11
 4 % 7 = 4
 11 % 4 = 11
 x * n + 3
 4 * 5 + 3 = 23
 4 * 7 + 3 = 31
 
 23 - 15 = 8
 23 % 8 = 7
 15 % 8 =
 
 
 
 
 23 7 12 31
 10000
 6
 835608231 250161633 540462096 700680816 677947153 912494375
 13
 934940809 586707169 704667379 889641940 385643061 559231259 264769004 362475141 661158340 932318678 389458459 293770018 953165327
 17
 275644300 705087020 770767780 980251260 817665660 786246320 474073920 868790060 333410520 315180680 585002260 417592420 960179760 309855760 975857080 336756000 670215320

 
 
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
        int cnt = 0;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            if (n == 1) cout << 0 << endl;
            else {
                int ans = 0;
                int l = 0, r = n - 1;
                while (l < r && ans != 1) {
                    if (a[l] != a[r]) {
                        int tmp = abs(a[l] - a[r]);
                        if (tmp < ans) {
                            if (ans % tmp == 0) ans = tmp;
                            else ans = 1;
                        }
                        else {
                            if (ans) {
                                if (tmp % ans != 0) ans = 1;
                            }
                            else {
                                ans = tmp;
                            }
                        }
                    }
                    ++l;
                    --r;
                }
                cout << ans << endl;
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
 
