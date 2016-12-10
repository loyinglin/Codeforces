//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/741/problem/A
 题目大意：
 n个物品，每个物品有选中代价cost[i]和价值value[i];
 同时有m个关系，每个关系由u和v组成，表示u和v是同一组内；
 限制：每一组只能选一个，或者全部选；
 现在有一个容量为w的背包，希望选出最大价值的物品组合放入；
 
 
 题目解析：
 (1  ≤  n  ≤  1000, , 1 ≤ w ≤ 1000)
 
 
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

int a[N], used[N];

//最大公约数
int gcd(int m,int n){
    int t;
    if(m<n){t = n;n = m;m = t;}
    if(n == 0)
        return m;
    else
        return gcd(n,m % n);
}

//最小公倍数
int lcm(int a,int b){
    return a/gcd(a,b) * b;
}



int main(int argc, const char * argv
         []) {
    lld n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            int t = i, k = 0;
            while (!used[t]) {
                used[t] = 1;
                ++k;
                t = a[t];
            }
            if (t != i) {
                ans = -1;
                break;
            }
            if (k % 2 == 0) {
                k /= 2;
            }
            ans = lcm(ans, k);
        }
    }
    
    cout << ans << endl;
    return 0;
}
