//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 一个盒子里有k个红球，1个黑球，两个人轮流从盒子取球（不放回），取出红球者胜出；
 现在给出k，要求：
 输出0表示，先后手一样的胜率；
 1表示，先手有优势；
 2表示，后手有优势；
 
 k = 10^5
 
 题目解析：
 容易知道，
 k=1的时候，先手优势；
 k=2的时候，均势；
 k=3的时候，先手优势；
 k=4的时候，均势；
 接着推导，
 k=5的时候，又是先手优势；k=6的时候，还是均势；
 猜想，根据奇偶性即可判断结果。
 
 
 验证：
 用sg函数来表示，sg[i]=0表示均势，sg[i]=1表示先手优势，sg[i]=2表示后手优势；
 如果sg[i]=0，那么有sg[i+1]=1，因为k=i+1的时候，多了1/(i+1)的直接获胜概率；
 如果sg[i]=1, 那么有sg[i+1]=0，因为k=i+1的时候，先手有1/k的概率直接获胜，后手有(k-1)/k * (1 / (k-1))=1/k的概率直接获胜，剩下的是均势；
 
 
 
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
const lld N = 1111;

int a[N];

int main()
{
    int n;
    while (cin >> n) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            while(k) {
                char c = k & 0x000000ff;
                if (c == 'a')
                    ++ans;
                k >>= 8;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
