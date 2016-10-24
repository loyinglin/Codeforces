//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 
 样例解释：

 
 题目解析：
 首先，1到n的所有区间共有(n * n)/2个。
 假如对每个区间[l, r]计算 cost(l-1) + cost(r);
 那么1~n每个数字刚好会出现n次。
 
 1到n的所有cost，很容易用数位dp求出来。（枚举第i位从1变成0之后，产生的数字的1的数量，记得加上数字n本身的1）
 
 这中间会出现重复的部分，比如说cost(5)=5+4和cost(6)=6+4, 4的代价是应该消除的；
 用repeat[i][j] 表示前i个出现j个1的pair数量；
 这样，repeat[i+1][j] 可以用 repeat[k][j]来表示，k在区间[1,i+1]；两个数，我们一个在第k位置0，一个在第k位置1；这样第k位后面可以任意取数字，总共会产生2^(i+1-k)位数字，pair数量为2^(i+1-k) * 2^(i+1-k) * 2，最后乘以2是因为区间可以反过来；
 前面的部分有k位，任取j位为1，其余的为0，总共有c[k][j]种可能。
 
 repeat的数位dp：
 枚举第i位，cur表示第i位后面所有数字表示的值，表示能取到的范围；
 把第i位从1重置为0，那么会产生2^(length - i)个数字，这部分数字与第i位为1的时候，可以组成pair，且公共前缀为[1, i]，这部分的pair数量为cur * 2^(length-1) * 2；
 然后枚举第i位后面可能有共同的1，与[1, i]练成公共的前缀，这部分用到了之前预处理出来的repeat[i][j]；
 
 注意n很大，乘以n的时候要先mod再乘以n。 
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
const lld N = 66, M = 3010100, mod = 1000000007ll;

char str[N * 2];
lld d[N], POW[N];
lld a[N], cnt, n;
lld c[N][N], repeat[N][N];



lld look() {
    lld ret = 0;
    for (int i = 0; i < cnt; ++i) {
        ret += a[i];
    }
    lld tmp = 0;
    for (lld i = cnt - 1; i >= 0; --i) {
        if (a[i]) {
            if (i > 0) {
                ret = (ret + (POW[i - 1] * i) % mod) % mod; // 把i位变为0的后面cost
            }
            ret = (ret + tmp * POW[i] % mod) % mod; // 把i位变为0的前面的cost
            tmp++;
        }
    }
    return (ret * (n % mod)) % mod;
}

lld lookRepeat() {
    lld ret = 0;
    lld tmp = 0;
    lld cur = n;
    for (lld i = cnt - 1; i >= 0; --i) {
        if (a[i]) {
            cur -= (1LL << i); // 当前位之前为公共前缀，后面最大的数字
            lld sum = (((cur + 1) % mod) * POW[i]) % mod; // +1是因为有0，POW[i]是当1变为0能产生的可能数。
            ret += ((sum * tmp) % mod * 2) % mod; // *2 考虑[l,r] 和 [r, l]
            ret %= mod;
            for (int k = 0; k < i; ++k) {
                ret = (ret + repeat[i][k] * (k + tmp) % mod) % mod; // 枚举当前位后面，出现1的可能次数。乘以所有的1
            }
            tmp++;
        }
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    
    POW[0] = 1;
    for (int i = 1; i < N; ++i) {
        POW[i] = (POW[i - 1] << 1) % mod;
    }
    for (int i = 0; i < N; ++i) {
        c[i][0] = 1;
        c[0][i] = 0;
    }
    c[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    for (int i = 1; i < N; ++i) {
        repeat[i][0] = (repeat[i][0] + (POW[i] * POW[i - 1]) % mod) % mod; // 每新增一个1，会产生POW[i - 1]个数，这些数和前面POW[i-1]个数没有公共前缀；
        // 新增的所有的数都可以和原来的POW[i-1]和新增的POW[i-1]个数相乘
        for (int k = 1; k < i; ++k) {
            for (int j = 0; j <= k; ++j) {
                lld tmp = (c[k][j]) % mod; // 前k个中取j个相同的1
                lld tmp2 = (tmp * POW[i - k] % mod * POW[i - k - 1]) % mod; //前k个取j个1，第k个取0和1，剩下的部分可以任意取
                repeat[i][j] = (repeat[i][j] + tmp2) % mod;
            }
        }
    }
    
    lld t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        lld k;
        cin >> k;
        n = k;
        cnt = 0;
        while (k) {
            a[cnt++] = k & 1;
            k = k >> 1;
        }
        cout << " " << look() << " " << lookRepeat() << endl;
        printf("Case #%d: %lld\n", z, (look() - lookRepeat() + mod) % mod);
    }
    
    return 0;
}
