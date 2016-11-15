//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/723/problem/D
 题目大意：
 给出一个字符串s，全小写字母组成；再给出整数m。
 现在让你从s中选择某些位置，把对应位置的字符标记为 绿色；
 要求s的所有长度为m的子串，都存在至少一个绿色字符；
 把所有绿色字符重新排列，输出绿色字符最小的字典序。
 s = 10w。
 
 
 题目解析：
 
 贪心：从a开始，从左到右，尽可能贪心向右；可行输出解，不行到下一行；
 // 记得先走前面可行的解；
 
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
const int N = 101001;

char str[N];
int sum[26];
int cnt[26];

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m;
    cin >> str;
    n = strlen(str);
    for (int i = 0; i < n; ++i) {
        sum[str[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        int posStart = 0, posEnd = m;
        while (posEnd <= n) {
            while (posEnd <= n) { // 去掉前面已经存取过的值
                int find = 0;
                for (int j = posEnd - 1; j >= posStart; --j) {
                    if (str[j] < c) {
                        posStart = j + 1;
                        posEnd = posStart + m;
                        find = 1;
                        break;
                    }
                }
                if (!find) {
                    break;
                }
            }
            if (posEnd > n) {
                break;
            }
            int find = 0;
            for (int j = posEnd - 1; j >= posStart; --j) {
                if (str[j] == c) {
                    posStart = j + 1;
                    posEnd = posStart + m;
                    ++cnt[i];
                    find = 1;
                    break;
                }
            }
            if (!find) {
                break;
            }
        }
        
        if (posEnd > n) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < sum[j]; ++k) {
                    putchar('a' + j);
                }
            }
            for (int k = 0; k < cnt[i]; ++k) {
                putchar('a' + i);
            }
            puts("");
            break;
        }
    }
    
    
    return 0;
}
