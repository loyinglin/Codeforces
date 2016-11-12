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
    int n;
    cin >> n;
    cin >> str;
    int len = strlen(str);
    for (int i = 0; str[i] != '\0'; ++i) {
        sum[str[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; ++i) {
        int ok = 1, p = n - 1, t = n;
        while (p < len) {
            if (str[p] <= 'a' + i) {
                ++cnt[str[p] - 'a'];
                p += n;
                t = n;
                continue;
            }
            --p;
            --t;
            if (t <= 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
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
        else {
            cnt[i] = sum[i];
            continue;
        }
    }
    
    
    return 0;
}
