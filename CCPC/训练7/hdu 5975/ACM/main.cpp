//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 n个数，q个操作。
 给出一个通项公式：f(x) = lowbit(x)，然后给出操作：
 1 l r ， 询问区间[l,r] 的区间和；（f[i]的和, i = l ~ r)
 2 x, 询问树状数组中，修改x的需要修改几次值；
 
 n≤10^18,q≤10^5
 
 题目解析：
 暴力推出解：
 x  1   2   3   4   5   6   7   8   9   10  11  12
    1   2   1   4   1   2   1   8   1   2   1   4
 
 容易推出：
 前n项和由1、2、4、8等组成，其中1的间隔是2，2的间隔4，4的间隔8，这样暴力算一遍即可；
 
 
 
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

lld lowbit(lld x)
{
    return x & (-x);
}

lld fast(lld k)
{
    lld ret = 1, t = 1;
    //   cout << "fast " << k;
    while (t <= k)
    {
        ret += (k / t - k / (t << 1)) * t;
        t <<= 1;
    }
    //   cout << " "<< ret << endl;
    return ret;
}

lld look(lld a, lld b)
{
    return fast(b) - fast(a - 1);
}

int main()
{
    lld n, q;
    while (cin >> n >> q)
    {
        while(q--)
        {
            lld t;
            scanf("%lld", &t);
            if (t == 1)
            {
                lld a, b;
                scanf("%lld%lld", &a, &b);
                printf("%lld\n", look(a, b));
            }
            else
            {
                lld x;
                scanf("%lld", &x);
                lld ans = 0;
                while (x <= n)
                {
                    x += lowbit(x);
                    ++ans;
                }
                printf("%lld\n", ans);
            }
        }
        
    }
    
    return 0;
}
