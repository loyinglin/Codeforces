//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1559/problem/B)
 **题目大意：**
 长度为n的字符串，一共有三种字符，'B', 'R', '?'；
 '?'的字符需要填充为'B'或者'R'；
 现在小明不喜欢相连两个字符是一样的， 现在需要知道怎么填充使得最终相连两个字符相同的情况尽可能少？
 比如说"BRRRBBR"就有3个相连的字符相同，"BB"出现一次，"RR"出现两次；
 
  **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤100)
 接下来每个样例两行，第一行整数𝑛 (1≤𝑛≤100)
 第二行长度为n的字符串s
 
 **输出：**
 每个样例一行，输出由'B'和'R'字符串构成的字符串。

 
 **Examples**
 **input**
 5
 7
 ?R???BR
 7
 ???R???
 1
 ?
 1
 B
 10
 ?R??RB??B?

 
 **output**
 BRRBRBR
 BRBRBRB
 B
 B
 BRRBRBBRBR
 
 
 **题目解析：**
 方案1，动态规划，dp[i][2]表示前i个字符，第i个字符为B、R的最小重复次数；
 初始化的时候，如果第1个字符是？则dp[1][0]=dp[1][1]=0；
 第1个字符是B，则dp[1][0]=0，dp[1][1]=n;（n是极大值，表示dp[1][1]不可取）
 第1个字符是R，则dp[1][1]=0，dp[1][0]=n;（n是极大值，表示dp[1][0]不可取）
 状态转移的时候，dp[i]可以由dp[i-1]来进行计算；
 如果a[i]==B，则dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1])； dp[i][1]=n;
 如果a[i]==R，则dp[i][1] = min(dp[i-1][1]+1, dp[i-1][0])； dp[i][1]=n;
 这样看最终dp[n]的最小值即可。
 
 方案2，找到第一个不为?的字符，从这个位置分别向左右开始填充，每次优先选择相邻字符不相同的方案；
 ??R??
 RBRBR
 
 方案3，通过数学直接计算；
 从左到右，如果第i个字符串前面??没有确定字符，则这段?不会产生特殊字符；若？？前面有确定字符k，则根据a[i]和a[k]以及(i-k)可以直接计算出来有多少个相同字符；（0或者1）
 
 考虑到题目要输出结果，还是方案2比较简单。
 
 
 **思考🤔：**
 如果是要连续3个字符串不一样呢？
 
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
    static const int N = 200010;
    string str;
    char ans[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> str;
            int pos = n;
            for (int i = 0; i < n; ++i) {
                if (str[i] != '?') {
                    pos = i;
                    break;
                }
            }
            ans[n] = '\0';
            if (pos == n) {
                for (int i = 0; i < n; ++i) {
                    ans[i] = i % 2 ? 'B' : 'R';
                }
            }
            else {
                ans[pos] = str[pos];
                for (int i = pos - 1; i >= 0; --i) {
                    if (str[i] == '?') {
                        ans[i] = 'B' + 'R' - ans[i + 1];
                    }
                    else {
                        ans[i] = str[i];
                    }
                }
                for (int i = pos + 1; i < n; ++i) {
                    if (str[i] == '?') {
                        ans[i] = 'B' + 'R' - ans[i - 1];
                    }
                    else {
                        ans[i] = str[i];
                    }
                }
            }
            printf("%s\n", ans);
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
