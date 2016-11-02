//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 给出a、b、c、d四个数字，询问
 a+c>b+d && a+d≥b+c && 0≤a≤A && 0≤b≤B && 0≤c≤C && 0≤d≤D
  满足这些式子的四元数(a,b,c,d)有多少；
 0≤A,B,C,D≤1e18
 
 
 题目解析：
 dp[len][x][y][mask] len表示当前dp的位数，x表示当前式子1的值，y表示当前式子2的值，mask表示abcd当前是否可以任取
 这样直接数位dp即可，需要注意，当枚举到第i位的之后，上一位保留的x、y需要乘以2（因为进位了）
 
 
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

const int Max = 1000100100, mod = 1000000007;

int dp[66][5][5][16]; // dp[len][x][y][mask] len表示当前dp的位数，x表示当前式子1的值，y表示当前式子2的值，mask表示abcd当前是否可以任取

int cnt;
lld p[4];
int a[4][66];
map<int, int> Hash;


int look(int len, int x, int y, int mask) {
    if (len == 0) {
        return x > 0 && y >= 0;
    }
    
    if (dp[len][Hash[x]][Hash[y]][mask] != -1) {
        return dp[len][Hash[x]][Hash[y]][mask];
    }

    int ret = 0, t[4];
    for (int i = 0; i < 4; ++i) {
        int k = 1 << i;
        t[i] = k & mask ? a[i][len] : 1;
    }
    for (int i = 0; i <= t[0]; ++i) {
        for (int j = 0; j <= t[1]; ++j) {
            for (int k = 0; k <= t[2]; ++k) {
                for (int l = 0; l <= t[3]; ++l) {
                    int s1 = x << 1, s2 = y << 1, mk = 0; // dp到下一位，上一位的差值*2
                    s1 += i + k - j - l;
                    s2 += i + l - j - k;
                    if (s1 <= -2 || s2 <= -2) {
                        continue;
                    }
                    if (s1 > 2) {
                        s1 = 2;
                    }
                    if (s2 > 2) {
                        s2 = 2;
                    }
                    if (i == t[0]) {
                        mk |= 1;
                    }
                    if (j == t[1]) {
                        mk |= 2;
                    }
                    if (k == t[2]) {
                        mk |= 4;
                    }
                    if (l == t[3]) {
                        mk |= 8;
                    }
                    ret = (ret + look(len - 1, s1, s2, mask & mk)) % mod;
                }
            }
        }
    }
    return dp[len][Hash[x]][Hash[y]][mask] = ret;
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 4; ++i) {
        Hash[i - 2] = i;
    }
    int t = 1000;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 4; ++i) {
            cin >> p[i];
        }
        cnt = 1;
        while (1) {
            int ok = 0;
            for (int i = 0; i < 4; ++i) {
                a[i][cnt] = p[i] & 1;
                p[i] >>= 1;
                if (p[i]) {
                    ok = 1;
                }
            }
            if (!ok) {
                break;
            }
            cnt++;
        }
        cout << look(cnt, 0, 0, 15) << endl;
    }
}
