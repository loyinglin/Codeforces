//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/814/problem/C
 题目大意：
 有一个长度为n字符串，现在可以对某些字符进行修改，总共可以修改m次（每次修改一个字符），现在有q次询问：
 每次会有两个输入分别是m和c，表示可以对字符串中m个字符进行修改，输出修改完的字符串中，全部由c构成的子串的最大长度。
 比如说字符串koyomi，只修改1次，可以把字符y改为o，则kooomi全部由字符'o'构成的最长子串是'ooo'，长度为3；
 
 输入
 总共有q次询问，每次询问包括修改次数m，和特定字符c；
 n (1 ≤ n ≤ 1 500)
 q (1 ≤ q ≤ 200 000) 
 m (1 ≤ m ≤ n)
 输出
 输出q次询问的最长子串长度。
 
 Examples
 input
 6
 koyomi
 3
 1 o
 4 o
 4 m
 output
 3
 6
 5
 样例解释：
 第一个询问，可以把'y'替换为'o'，得到最大长度3；
 第二个询问，替换后最大长度的字符串是"oooooo"，长度为6；
 第三个询问，满足题意的解有 "mmmmmi" and "kmmmmm"，长度均为5；
 
 
 题目解析：
 先不考虑多次询问，对于修改次数m，字符c，我们求最大长度；
 容易知道贪心的解法不适用于此题，因为字符串的间隔有长有短，形成间隔的字符串长度不一定；
 这里可以用到一种动态规划的做法：
 dp[i][j] 表示前i个，修改j个字符，且第i个字符为c的最大长度；
 那么有：
 1. a[i]==c => dp[i][j]=dp[i-1][j]+1;
 2. a[i]!=c => dp[i][j]=dp[i-1][j-1]+1;
 这里的初始化条件比较容易出错，对于所有dp[i][0]，根据a[i]==c决定dp[i][0]=dp[i-1][0]+1，还是dp[i][0]=0；
 
 单次求解的复杂度是O(N^2)的状态，O(1)的转移；（这里需要思考，为何不需要dp[1~(i-1)]所有状态进行转移）
 因为q的大小有10^6，直接应用显然不行。
 
 根据询问的数据范围，我们知道总共只有m*26种可能；
 我们直接枚举出所有的情况，用ans[i][j]表示可修改次数为i，字符为j的最大字符串长度，进行预处理的过程更新ans[i][j]即可。
 
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
const int N = 1511, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
char str[N];
int a[N];
short dp[N][N][26];
int ans[N][26];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    cin >> (str + 1);
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            char c = 'a' + j;
            if (c == str[i]) {
                dp[i][0][j] = dp[i - 1][0][j] + 1;
            }
            else {
                dp[i][0][j] = 0;
            }

            for (int k = 1; k <= n; ++k) {
                dp[i][k][j] = max(dp[i][k][j], dp[i][k - 1][j]);
                if (c == str[i]) {
                    dp[i][k][j] = dp[i - 1][k][j] + 1;
                }
                else {
                    dp[i][k][j] = dp[i - 1][k - 1][j] + 1;
                }
                ans[k][j] = max(ans[k][j], (int)dp[i][k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        char c;
        scanf("%d %c", &t, &c);
        printf("%d\n", ans[t][c - 'a']);
    }
    
    
    return 0;
}

/**
 20
 aacbadbdaaba

 11
 1 a
 2 a
 3 a
 4 a
 5 a
 6 a
 
 
 
 **/
