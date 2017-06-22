//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/724/problem/D
 题目大意：
 给出一个字符串s，全小写字母组成；再给出整数m。
 现在让你从s中选择某些位置，把对应位置的字符标记为 绿色；
 要求s的所有长度为m的子串，都存在至少一个绿色字符；
 把所有绿色字符按字典序最小重新排列得到的字符串str，求让str的字典序最小。
 s的长度不大于10w。
 
 Examples
 input
 3
 cbabc
 output
 a
 input
 2
 abcab
 output
 aab
 
 样例解释
 样例1：选择第3个字符为绿色字符；
 样例2：选择第1、2、4个字符为绿色字符，把绿色字符重新排序，字典序最小字符串的是aab;
 
 题目解析：
 字母要求的是不是最后的字符串长度最短，而是字典序最小；那么，aab相对于ab而言是更优解。
 可以想到一个贪心：先尽可能选择字符a，再尽可能选择b，再到c、d、e...
 假设a可行，那么如何找到尽可能少的字符串a，能够覆盖整个字符串？
 这里用到另外一个贪心：在字符串[0, m-1]中，必然会有一个绿色字符，而且这个字符串越靠近m-1，越有利于后面的字符串被绿色字符串覆盖；
 于是，可以设定一个区间[posStart, posEnd]=[0, m)，从posEnd-1开始倒着选择字符，找到目标字符再扩展posEnd，直到posEnd>=n；
 如果当前字符串c作为绿色字符不能覆盖整个字符串，那么从c+1开始枚举；
 
 这里还有一个trick，在枚举字符串c的时候，需要用<c的字符串先扩展，再枚举字符c；
 
 虽然代码里面有一个for，两个while，但是整体的复杂度仍是：O(N)！！
 
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
