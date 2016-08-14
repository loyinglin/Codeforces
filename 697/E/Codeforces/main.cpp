//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/697/problem/E
 题目大意：有三个一模一样盒子从左到右排列。中间的盒子有一个特殊物品，每次操作随机选择左右两边的盒子和中间交换。
 问n次操作后，中间盒子有特殊物品的概率。答案按照最简分数化简后，分子分母再mod值10E9+7。
 
 题目解析：
 给盒子编号1、2、3，那么盒子的排列有：
 123、132、213、231、312、321；其中123、321是中间有特殊物品。
 假设d[i][j]是第i次操作后，盒子排列为j的次数。
 d[i][123] = d[i-1][213] + d[i-1][132];
 d[i][321] = d[i-1][231] + d[i-1][312];
d[i][123] + d[i][132] + d[i][213] + d[i][231] + d[i][312] + d[i][321] = 2 ^ i。（每次操作产生2种可能）
 
 令f[i] = d[i][123] + d[i][321]。
 f[i] = d[i-1][213] + d[i-1][132] + d[i-1][231] + d[i-1][312]
      = 2 ^ (i - 1) - d[i-1][123] - d[i-1][321]
      = 2 ^ (i - 1) -f[i-1].
 其中f[0] = 1;
 
当i=2k的时候，f[2k] = 2^(2k-1) - 2^(2k-2) + 2^(2k-3) ... + 2^1 - 2^0 + 1;
            f[2k+1] = 2^(2k) - 2^(2k-1) + 2^(2k-2) ... - 2^1 + 2^0 - 1;
等比数列求和，化简后有：
            f[2k] =  (2^(2k)+2)/3;
            f[2k+1] = (2^(2k+1)-2)/3;
 
最终的答案为: ans = f[n] / 2^n.
 当n=2k的时候，ans = f[2k] / 2^(2k) = (2^(2k-1)+1)/(2^(2k-1)*3);
 当n=2k+1的时候，ans = f[2k+1] / 2^(2k+1) = (2^(2k)-1)/(2^(2k)*3);
 
 ans = x / y;
 统一下，当n为奇数，x = (2^(n-1)+1) / 3, y = 2^(n-1);
 当n为偶数， y = (2^(n-1)-1) / 3, y = 2^(n-1);
 
 性质：如p是质数，且gcd(a,m)=1，那么 a^(m-1)≡1（mod m）。 （费马小定理）
 推论：(a/b) % m = (a/b * 1) % m 
                = (a/b * b^(m-1)) % m 
                = (a * b^(m-2)) % m
                = a%m * b^(m-2)%m
 
 2^(n-1) % m = (2^n / 2) % m
             = 2^n % m * 2^(m-2)%m
 

 备注：感谢胡浩大神提供最后推论的思路。
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
const int N = 10100, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
lld a[N];


lld fastPower(lld x, lld n, lld mod)
{
    lld ret = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ret = ((ret * x) % mod);
            
        }
        n >>= 1;
        x = ((x * x) % mod);
    }
    return ret;
}


int main()
{
    lld mod = pow(10, 9) + 7;
    lld even = -1;
    lld t = 2, y;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        lld tmp;
        cin >> tmp;
        t = fastPower(t, tmp, mod);
        if (tmp % 2 == 0)
        {
            even = 1;
        }
    }
    y = t = (t * fastPower(2, mod - 2, mod)) % mod;
    lld x = (((t + even) % mod) * fastPower(3, mod - 2, mod)) % mod;
    
    cout << x << '/' << y;
}
