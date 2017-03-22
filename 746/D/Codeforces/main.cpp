//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/746/problem/D
 题目大意：
 小明喜欢喝茶，他有a个绿茶包，b个黑茶包，a+b=n，每个茶包只能用一次，一次用一天；
 小明不喜欢连续喝同一种茶超过k天。
 问是否存在适合的茶包分配方案，使得小明能喝到n天。
 如果存在，则输出茶包的使用顺序，G表示绿茶包，B表示黑茶包；
 如果不存在，则输出NO;
 输入数据
 n, k, a and b (1 ≤ k ≤ n ≤ 1e5, 0 ≤ a, b ≤ n)
 
 
 Examples
 input
 5 1 3 2
 output
 GBGBG
 input
 7 2 2 5
 output
 BBGBGBB
 input
 4 3 4 0
 output
 NO
 
 
 
 
 
 题目解析：
 题目的要求是分配茶包。
 容易想到这样的贪心：尽可能使用多的茶包，当使用了k次之后，就用一次少的茶包，直到茶叶包一样多，之后可以采取交替的方式。
 这样的实现方案会比较复杂，首先需要每天判断一次a、b的大小，然后还要记录当前茶包是否连续使用了k次。
 我们可以利用到另外一个贪心：当a>b的时候，我们直接连续使用min(k, a - b)个G茶包。
 容易知道，当使用的是a-b的茶包时，剩下的茶包数量相等，交替使用即可；
 如果使用的是茶包k时，证明G比B多超过k，这时先使用k个G不会影响最后的结果。
 
 
 
 
 
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

char str[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    bool turnToGreen = a > b;
    int day = 0;
    while (day < n && a >= 0 && b >= 0) {
        int eat = 1;
        if (turnToGreen) { // turn to eat green
            if (a > b) {
                eat = min(k, a - b);
            }
            for (int i = 0; i < eat; ++i, --a) {
                str[day++] = 'G';
            }
        }
        else {
            if (b > a) {
                eat = min(k, b - a);
            }
            for (int i = 0; i < eat; ++i, --b) {
                str[day++] = 'B';
            }
        }
        turnToGreen = !turnToGreen;
    }
    if (a >= 0 && b >= 0) {
        str[day] = '\0';
        cout << str << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
