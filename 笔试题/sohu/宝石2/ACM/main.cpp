//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：无
 题目大意：有一串宝石首尾相连，用一个大写字母表示一个宝石，每个宝石有相应价值；
 现在需要从这一串宝石中截取一段宝石，要求这一段宝石包含ABCDE这5种字母；求剩下最大价值数？（宝石长度小于等于10w，单个宝石价值小于等于10^9)
 
 input
 8
 AFBCFFDE
 1 2 3 4 5 6 7 8
 
 output
 11
 
 
 
 
 
 题目解析：
 把字符串复制一篇，append到最后，题目变成在字符串长度为2*N的字符串中，找到价值最小的一串包含ABCDE5个字母的子串。
 容易知道，如果[i, j]包含ABCDE，那么[i, j + 1]必然也包含ABCDE；（性质1）
 如果[i, j]包含ABCDE的状态为01010, 那么当j+1的字符为'A'的之后，[i, j + 1]包含的状态为11010;（性质2）
 
 
 我们用dp[i][j]来表示，以第i个字符结尾，字串包括ABCDE的状态为j的最小价值；（把是否包含ABCDE转成01010）
 那么有dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]); （因为如果i-1包含j，那么j也包含，以上性质1）
 dp[i][j | k] = min(dp[i][j | k], dp[i - 1][j] + a[i]); （性质2）
 
 
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
const int N = 100100, M = 1<<5;
const lld llinf = 0x7fffffffffffffll;

char str[N * 2];
lld dp[N * 2][M];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 数据
//    freopen("input.txt", "w", stdout);
//    int t = 10;
//    while (t--) {
//        int n = arc4random_uniform(100) + 10;
//        cout << n << endl;
//        for (int i = 0; i < n; ++i) {
//            putchar('A' + arc4random_uniform(10));
//        }
//        cout << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << arc4random_uniform(1000) + 10 << " ";
//        }
//        cout << endl;
//    }
//    return 0;
    
    // 暴力标程
//    freopen("input.txt", "r", stdin);
//    freopen("answer.txt", "w", stdout);
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        scanf("%s", str + 1);
//        lld total = 0;
//        for (int i = 1; i <= n; ++i) {
//            cin >> a[i];
//            total += a[i];
//        }
//        lld minSum = llinf;
//        for (int i = 1; i <= n * 2; ++i) {
//            for (int j = i; j <= n * 2; ++j) {
//                int ok = 1, flag[5];
//                memset(flag, 0, sizeof(flag));
//                for (int k = i; k <= j; ++k) {
//                    int id = str[k > n ? k - n : k] - 'A';
//                    if (id < 5) {
//                        flag[id] = 1;
//                    }
//                }
//                for (int k = 0; k < 5; ++k) {
//                    if (!flag[k]) {
//                        ok = 0;
//                    }
//                }
//                if (ok) {
//                    lld sum = 0;
//                    for (int k = i; k <= j; ++k) {
//                        sum += a[k > n ? k - n : k];
//                    }
//                    minSum = min(minSum, sum);
//                }
//            }
//        }
//        if (minSum == llinf) {
//            cout << -1 << endl;
//        }
//        else {
//            cout << total - minSum << endl;
//        }
//    }
//
//    
//    return 0;
//    
    
    // DP做法
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", str + 1);
        lld total = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            total += a[i];
        }
        for (int i = 0; i <= n * 2; ++i) {
            for (int  j = 1; j < M; ++j) {
                dp[i][j] = llinf;
            }
        }
        dp[0][0] = 0;
        lld minSum = llinf;
        for (int i = 1; i <= n * 2; ++i) {
            int id = str[i > n ? i - n : i] - 'A';
            for (int j = 0; j < M; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i > n ? i - n : i]);
                if (id < 5) {
                    dp[i][j | (1 << id)] = min(dp[i][j | (1 << id)],
                                                     dp[i - 1][j] + a[i > n ? i - n : i]);
                }
                
            }
            minSum = min(minSum, dp[i][M - 1]);
        }
        if (minSum == llinf) {
            cout << -1 << endl;
        }
        else {
            cout << total - minSum << endl;
        }
        
    }
    
    
    
    return 0;
}
