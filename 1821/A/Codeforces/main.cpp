//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1821/problem/A)
 **题目大意：**
 给出一个由整数和?组成的字符串，其中符号?可以匹配任何单个数字；
 For example:
 42 matches 4?;
 1337 matches ????;
 1337 matches 1?3?;
 1337 matches 1337;
 3 does not match ??;
 8 does not match ???8;
 1337 does not match 1?7.
 
 现在问给出的字符串，最多存在多少个合法的匹配数字；（不包括前导零，整数大于零）
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤20000)
 每个样例1行，字符串𝑠 (1≤|𝑠|≤5)
 
  
 **输出：**
 每个样例一行，输出最多存在多少个合法的匹配数字；
 
 **Examples**
 **input**
 8
 ??
 ?
 0
 9
 03
 1??7
 ?5?
 9??99


 **output**
 90
 9
 0
 1
 0
 100
 90
 100

 
 **题目解析：**
 分情况讨论：
 1、给出的字符串就存在前导零，那么结果为0；
 2、给出的字符串合法，并且存在x个?号，那么有两种情况：
 2.1，?号之前已经有整数，此时?号可以取任意数字，那么x个?号可以得到10^x个整数；
 2.2，?号前面没有整数，此时第一个?号只能取1-9数字，所以会减少10^(x-1)个答案；
 
 
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
    char s[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int n = strlen(s);
            int x = 0;
            for (int i = 0; i < n; ++i) x += (s[i] == '?');
        
            if (s[0] == '0') cout << 0 << endl;
            else if (s[0] == '?') {
                if (!x) cout << 1 << endl;
                else cout << (int)pow(10, x) - (int)pow(10, x - 1) << endl;
            }
            else {
                cout << (int)pow(10, x) << endl;
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
 
