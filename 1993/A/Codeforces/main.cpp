//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1993/problem/A)
 **题目大意：**
 小明参加考试，一共有4n道选择题，每个选择题的答案只有一个，并且A/B/C/D分别是n个题目的答案；
 小明做题时，会从 A/B/C/D/? 中选择一个作为答案，?表示小明这个题目没有选；
 现在已知道所有题目的结果，问 小明最多能选对多少个题目；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤676)
 每个样例2行
 第一行，整数n  (1≤n≤100 ).
 第二行，长度为4n的字符串，字符只会从{𝙰,𝙱,𝙲,𝙳,?}出现；
  
 **输出：**
 每个样例一行，输出小明最多能做对的题目；
 
 **Examples**
 **input**
 6
 1
 ABCD
 2
 AAAAAAAA
 2
 AAAABBBB
 2
 ????????
 3
 ABCABCABCABC
 5
 ACADC??ACAC?DCAABC?C


 **output**
 4
 2
 4
 0
 9
 13



 **题目解析：**
 首先，分别统计A/B/C/D字符出现的次数a[4]；
 按照题目的要求，每个题目最多有n次结果，那么就是min（a[i]，n）；
 累加4个字符的结果，得到答案。

 
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
            int n;
            string str;
            cin >> n >> str;
            int a[4] = {0};
            for (int i = 0; i < n * 4; ++i) {
                if (str[i] != '?') {
                    a[str[i] - 'A']++;
                }
            }
            int ans = 0;
            for (int i = 0; i < 4; ++i) {
                ans += min(a[i], n);
//                cout << (char)('A' + i) << " : " << a[i] << endl;
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
 
