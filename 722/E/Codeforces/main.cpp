//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/722/problem/C
 题目大意：
 一个网格，总共有n*m的cell，cell可以上下左右走，一个人带着一个电量为x的电池，从(1,1)出发到(n,m)，随机选择一条最短路径；
 有k个特殊的cell，经过这个cell时，电池的电量会减半；（向上取整）
 输入n、m、k和k个cell的位置，求到达终点时，电池电量的期望值。（P/Q mod 1e9+7)。
  (1 ≤ n, m ≤ 100 000, 0 ≤ k ≤ 2000, 1 ≤ x ≤ 1 000 000)
 
 input
 3 3 2 11
 2 1
 2 3
 output
 333333342
 
 1 1 1
 1 2
 
 
 
 题目解析：
 最多有logS个选择，把障碍点排序；（如果起点和终点也要加入）
 f[i][j] 表示前i个，经过j个障碍的可能数；
 g[i][j] 表示前i个，至少经过j个障碍物的可能数；
 
 g[i][j]=∑f[i−1][k]∗Ways[k][j]
 f[i][j]=g[i][j]−∑f[i][k]∗Ways[k][j]
 
 Ways[i][j]表示i到j的方案数
 
 C(n,m) = A(n,m)/A(n,n)=m! / ((m-n)! * n!) = m! * (m-n)!^(-1) * n!^(-1);
 
 
 
 http://blog.csdn.net/acdreamers/article/details/8220787 逆元详解
 
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
const int N = 222222, M = 22, K = 2222;

pair<int, int> p[K];
int f[M][K], g[M][K], ways[K][K], fac[N], fac_inv[N];
int a[M], cnt;

const lld mod = 1e9 + 7;

//费马小定理：已知p是质数且gcd(a, p) = 1，则 a^(p-1) ≡ 1 (mod p),  所以 a*a^(p-2) ≡ 1 (mod p)。得到 a^(p-2)是a的逆元
lld find(lld x) //x在%mod下的逆元
{
    lld k = mod - 2, ans = 1;
    while(k)
    {
        if (k & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        k >>= 1;
    }
    return ans;
}


lld ex_gcd(lld a,lld b,lld &x,lld &y)//扩展欧几里得（扩展gcd）
{
    if (a == 0 && b == 0) return -1;
    if (b == 0) { x = 1; y = 0; return a; }
    lld d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

lld mod_inverse(lld a,lld n)//乘法逆元
{
    lld x,y;
    lld d = ex_gcd(a,n,x,y);
    return (x % n + n) % n;
}

int Combine(int n, int m) {
    return (lld)fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main(int argc, const char * argv[]) {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= k; ++i) {
        cin >> p[i].first >> p[i].second;
        --p[i].first;
        --p[i].second;
    }
    sort(p + 1, p + 1 + k);
    p[++k].first = n - 1;
    p[k].second = m - 1;
    p[0].first = p[0].second = 0;
    fac[0] = fac_inv[0] = fac[1] = fac_inv[1] = 1;
    for (int i = 2;  i <= n + m; ++i) {
        fac[i] = (lld)fac[i - 1] * i % mod;
        fac_inv[i] = (lld)fac_inv[i - 1] * find(i) % mod;
    }
    
    a[0] = s;
    while (s > 1) {
        a[++cnt] = s = (s - s / 2);
    }
    
    for (int i = 1; i <= k; ++i) {
        f[0][i] = g[0][i] = Combine(p[i].first + p[i].second, p[i].first);
        for (int j = 1; j < i; ++j) {
            if (p[i].second >= p[j].second) {
                ways[j][i] = Combine(p[i].first - p[j].first + p[i].second - p[j].second, p[i].first - p[j].first);
                f[0][i] = (f[0][i] + mod - (lld)f[0][j] * ways[j][i] % mod) % mod;
            }
        }
    }
    
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            for (int x = i; x < j; ++x) {
                if (p[x].second <= p[j].second) {
                    g[i][j] = (g[i][j] + (lld)f[i - 1][x] * ways[x][j]) % mod;
                }
            }
            f[i][j] = g[i][j];
            for (int x= i; x < j; ++x) {
                if (p[x].second <= p[j].second) {
                    f[i][j] = (f[i][j] + mod - (lld)f[i][x] * ways[x][j] % mod) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        ans = (ans + (lld)a[i] * f[i][k] % mod) % mod;
    }
    ans = (ans + g[cnt][k]) % mod;
    ans = (lld)ans * fac[n - 1] % mod * fac[m - 1] % mod * fac_inv[n + m - 2] % mod;
    cout << ans << endl;
    
    return 0;
}
