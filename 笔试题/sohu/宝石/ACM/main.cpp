//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：无
 题目大意：有一串宝石首尾相连，用一个大写字母表示一个宝石；
 现在需要从这一串宝石中截取一段宝石，要求这一段宝石包含ABCDE这5种字母；求剩下最多有多少个宝石？
 input
 AFBCFFDE
 output
 2
 
 
 样例解释：
 因为宝石是收尾相连的，所以AFBC和DE是相连的，可以截取这一段下来，剩下FF两个宝石，所以答案为2。
 
 题目解析：
 容易知道，我们想要截取一段最短的宝石，包含ABCDE5种宝石；
 首先解决首尾相连的问题：把字符串复制一遍放在最后，这样就可以表示循环；
 问题变成在字符串str中，找到一个最短的，包含ABCDE 5种字符的子串。
 因为对ABCDE的顺序没有要求，故而可以用贪心来解决这个问题：
 我们对每一种宝石都设置一个Right数组，Right[i]表示第i种宝石最右边的位置；
 假设我们找到了这个最短子串，设最左边的节点为i，最右边的节点为j，有[i, j]，那么有 i = min_element(Right, Right + 5)。
 然后遍历 N*2的字符串，不断更新Right数组和ans即可。
 
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
const int N = 1001000, M = 3010100, inf = 0x7fffffff;

char str[N * 2];
int Right[5];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while (scanf("%s", str + 1) != EOF) {
        int n = strlen(str + 1);
        int ans = 0;
        memset(Right, 0, sizeof(Right));
        for (int i = 1; i < n * 2; ++i) {
            int id;
            if (i <= n) {
                id = str[i] - 'A';
            }
            else {
                id = str[i - n] - 'A';
            }
            if (id < 5) { //在钻石列表里
                Right[id] = i;
                
                bool ok = 1;
                for (int i = 0; i < 5; ++i) {
                    if (Right[i] == 0) {
                        ok = 0;
                    }
                }
                if (ok) {
                    int t = i;
                    ans = max(ans, n - (t - *min_element(Right, Right + 5) + 1));
                }
            }
        }
        cout << ans << endl;
        
    }
    
    
    
    return 0;
}
