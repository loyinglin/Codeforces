//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1883/problem/B)
 **题目大意：**
 给出一个长度为n的字符串s，现在需要移除字符串中的k个字符，剩下的字符可以随意排列；
 问，剩下的字符能否组成一个回文串？
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，𝑛 and 𝑘 (0≤𝑘<𝑛≤1e5)
 第二行，字符串s；（小写字母组成）
  
 **输出：**
 每个样例一行，如果有解则输出YES；如果无解则输出NO；
 
 **Examples**
 **input**
 14
 1 0
 a
 2 0
 ab
 2 1
 ba
 3 1
 abb
 3 2
 abc
 6 2
 bacacd
 6 2
 fagbza
 6 2
 zwaafa
 7 2
 taagaak
 14 3
 ttrraakkttoorr
 5 3
 debdb
 5 4
 ecadc
 5 3
 debca
 5 3
 abaac

 **output**
 YES
 NO
 YES
 YES
 YES
 YES
 NO
 NO
 YES
 YES
 YES
 YES
 NO
 YES



 **题目解析：**
 最终的字符串可以任意调整顺序，那么重点在于每个字符的数量；
 题目是要求构造回文串，如果某个字符数量是偶数，那么可以组成回文串；如果某个字符数量是奇数，那可能会导致无法构成回文串。
 假设统计所有字符的数量，有x个偶数字符，有y个奇数字符；那么能构成回文串的条件就是y<=1；（如果只有1个奇数，可以把多出来这个字符放在回文串中间）
 由于题目增加了一个限制，要去除k个字符，那么奇数字符就可以有更多（因为移除时优先移除奇数字符），所以最终条件是y<=1+k；
 
 
 
 
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
            int n, k;
            string s;
            cin >> n >> k;
            cin >> s;
            vector<int> cnt(26);
            for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
            int y = 0;
            for (int i = 0; i < 26; ++i) y += (cnt[i] % 2);
            if (y <= 1 + k) cout << "YES" << endl;
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
 
