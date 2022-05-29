//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1673/problem/A)
 **题目大意：**
 给出一个字符串，由小写字母组成；
 现在Alice和Bob在玩游戏，轮流从字符串中移除一个子串，Alice先操作；
 Alice允许移除偶数长度子串，Bob允许移除奇数长度子串；（也允许不移除）
 最终看每个人移除子串的分数总和，字母a是1分，b是2分、、、z是26分；
 问最终谁能赢得游戏，以及胜者领先的分数；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡  (1≤𝑡≤5⋅1e4)
 每个样例一行，字符串𝑠  (1≤|𝑠|≤2⋅1e5)
  
 **输出：**
 每个样例一行，胜者和胜者领先的分数；
 
 
 **Examples**
 **input**
 5
 aba
 abc
 cba
 n
 codeforces
 **output**
 Alice 2
 Alice 4
 Alice 4
 Bob 14
 Alice 93
 
 **题目解析：**
 Alice先手，并且可以移除偶数字符串，那么字符串如果是偶数，Alice会移除所有字符；
 如果是奇数，Alice只会留下1个字符串，要么是最左边，要么是左右边的字符，选择一个较小值；
 Bob后手，只能选择alice剩下的字符串。
  
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
    string str;

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> str;
            int sum = 0;
            for (int i = 0; i < str.length(); ++i) {
                sum += str[i] - 'a' + 1;
            }
            if (str.length() % 2) {
                int bob = min(str[0], str[str.length() - 1]) - 'a' + 1;
                int alice = sum - bob;
                cout << (alice > bob ? "Alice" : "Bob") << " " << abs(alice - bob) << endl;
            }
            else {
                cout << "Alice " << sum << endl;
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
 */
