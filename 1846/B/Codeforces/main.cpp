//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/B)
 **题目大意：**
 在一个3x3的矩形棋盘上，如果有三个相同图案连在一起，则该图案获胜；
 现在给出最终的结果，询问最终获胜者；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行，表示3x3棋盘最终结果。
 "X" 、"O" 、 "+" 是表示不同棋子， "." 表示该位置是空的。
 
 **输出：**
 每个样例，如果有获胜棋子，则输出对应的棋子图案；（"X" 、"O" 、 "+" ）
 如果没有获胜者，则输出DRAW；
 
 **Examples**
 **input**
 5
 +X+
 OXO
 OX.
 O+.
 +OX
 X+O
 .XO
 OX.
 +++
 O.+
 X.O
 +..
 .++
 X.O
 +..

 **output**
 X
 O
 +
 DRAW
 DRAW




 **题目解析：**
代码实现题，横竖斜三种情况分开处理。
这里有个trick，当找到获胜者的时候，可以直接结束，避免后续处理的影响。
 
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
    string str[3];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            for (int i = 0; i < 3; ++i) cin >> str[i];
            char result = '.';
            for (int i = 0; i < 3; ++i) {
                if (str[i][0] == str[i][1] && str[i][1] == str[i][2] && result == '.') {
                    result = str[i][0];
                }
            }
            for (int i = 0; i < 3; ++i) {
                if (str[0][i] == str[1][i] && str[1][i] == str[2][i] && result == '.') {
                    result = str[0][i];
                }
            }
            if (str[0][0] == str[1][1] && str[1][1] == str[2][2] && result == '.') {
                result = str[0][0];
            }
            if (str[0][2] == str[1][1] && str[1][1] == str[2][0] && result == '.') {
                result = str[0][2];
            }
            if (result == '.') {
                cout << "DRAW" << endl;
            }
            else {
                cout << result << endl;
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
 
