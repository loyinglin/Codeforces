//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1845/problem/C)
 **题目大意：**
 小明要设置密码，密码长度为m，由数字0到9组成，并且密码不能为字符串s的子序列；
 同时有字符串l和字符串r，小明设置的密码a要满足 l[i] <= a[i] 且 a[i] <= r[i];
 问，小明是否能够找到满足要求的密码。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例4行
 第一行字符串𝑠(1≤|𝑠|≤3⋅1e5)
 第二行整数𝑚 ，表示字符串l和m的长度 (1≤𝑚≤10 )
 第三行字符串l
 第四行字符串r
 
 
 **输出：**
 每个样例一行，如果有满足要求的密码，则输出YES；如果不存在则输出NO；
 
 **Examples**
 **input**
 5
 88005553535123456
 2
 50
 56
 123412341234
 3
 111
 444
 1234
 4
 4321
 4321
 459
 2
 49
 59
 00010
 2
 10
 11


 **output**
 YES
 NO
 YES
 NO
 YES



 **题目解析：**
 如果采用暴力做法，枚举小明可能存在的密码数量，会有比较大的数量，并且判断是否为子序列也有O(N)的复杂度；
 换一种分析的思路，站在小明的角度，对于第i个密码，他一共有vec若干个选择，也就是区间（l[i]， r[i]）；
 对于字符串s，我们从左到右遍历，如果某个字符没有出现在vec中，那么这个字符对题目没有影响，可以直接跳过；
 如果某个字符c在vec中出现，那么可以在vec中移除这个字符，表示小明无法选择这个字符；
 不断重复这个过程，直到vec为空（进入i+1个密码字符），或者字符串s遍历完。
 如果最终字符串s遍历完了，vec还有字符，那么存在vec中存在的字符，必然就是字符串s不存在的字符子序列。
 
 证明：
 这个题目没有想到很好的证明方式，就是在分析题目过程中，突然浮现在脑海中的一种贪心思路。
 核心思想，字符串想用更少字符区间去覆盖小明能选择的字符。
 对于第1个字符，假设有若干个选择，那么字符串s最少需要区间[1, pos1]才能覆盖到这么多选择；
 同理对于第2个字符，我们需要[pos1 + 1, pos2]这样的区间去覆盖；
 ...
 直到第m个字符。
 假设字符串m能切割出来m个这样的区间，那么必然小明是无解的。
 
 
 
 
 
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
    string s;
    char a[20], b[20];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int m;
            cin >> m;
            cin >> a >> b;
            
            int ans = 0, pos = 0;
            for (int i = 0; i < m; ++i) {
                vector<char> v;
                for (int j = a[i]; j <= b[i]; ++j) {
                    v.push_back(j);
                }
                while (!v.empty() && pos < s.length()) {
                    vector<char>::iterator it =  find(v.begin(), v.end(), s[pos]);
                    if (it != v.end()) {
                        v.erase(it);
                    }
                    ++pos;
                }
                if (pos == s.length() && !v.empty()) {
                    ans = 1;
                }
            }
            cout << (ans == 1 ? "YES":"NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
