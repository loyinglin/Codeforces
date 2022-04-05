//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/F1)
 **题目大意：**
 给出由+和-组成的字符串，我们称字符串为平衡的字符串，假如+和-的字符是相同的；
 现在可以对字符串执行操作，每次将两个相邻的-号合并为+号；假如若干次操作之后，字符串变成了平衡的字符串，那么这个字符串可以称之为特殊的字符串；
 
 现在给出长度为n的字符串，问字符串中有多少子串是特殊的；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例
 每个样例两行，第一行是整数𝑛
 第二行是字符串；
 
 **输出：**
输出满足要求的子串数量；
 
 **Examples**
 **input**
 
 **output**
 
 **题目解析：**
 这是easy难度，题目给出来的范围比较小；
 那么可以使用最暴力的办法，O(N\*N)的复杂度，枚举所有字符串的子串；
 再分别计算这个子串是否符合要求；
 判断一个字符串是否是特殊的，可以遍历整个字符串中+和-的数量（假如总数是x和y）；
 如果x==y，或者x<y并且`(y-x)%3==0 && (y-x)%3 < z`，则子串满足要求。
 统计x或者y是一个比较快的过程，用countx[i][j]表示区间[i, j]内的+数量，那么countx[i][j]可以由countx[i][j-1]来快速计算；y的计算同理；

 
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
    static const int N = 3010;
    char str[N];
    int a[N];
    int dp[N]; // dp[i] 前i个字符，以i结尾，并且x==y的子串数量
    int countx[N][N], county[N][N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> (str + 1);
            // 如果x==y，或者x<y并且`(y-x)%3==0
            
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = i; j <= n; ++j) {
                    if (str[j] == '+') {
                        countx[i][j] = countx[i][j - 1] + 1;
                        county[i][j] = county[i][j - 1];
                    }
                    else {
                        countx[i][j] = countx[i][j - 1];
                        county[i][j] = county[i][j - 1] + 1;
                    }
                    if (countx[i][j] == county[i][j] || ((countx[i][j] < county[i][j] && (county[i][j] - countx[i][j]) % 3 == 0))) {
                        ++ans;
                    }
                }
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

/**
 */
