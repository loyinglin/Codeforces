//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 一个32位的数字，每个bytes包括8bit，所以一个整数是由4bytes组成；
 现给出n个数字，问组成数字的bytes中，有多少个'a'。
 
 Sample Input
 3
 97 24929 100
 Sample Output
 3
 
 
 题目解析：
 对于每个数字，用0x000000ff进行与操作，取出最后8位，然后与'a'判断，然后右移8位，知道数字为0即可；
 
 
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
