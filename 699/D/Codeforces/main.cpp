//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/699/problem/C
 题目大意：n个点，每个点对应的a[i]表示第i个点的parent节点，问使其变成一棵树，最少需要修改多少条边，并且把所有值输出。
 题目解析：
 n个点，n条边。如果是树必然是一条边指向自己，其余n-1条边没有环。（有且仅有一个环）
 那么假设有一个根节点root，当出现环的时候，直接将环某个点指向root即可；
 需要修改的数量=环的数量 - 1。
 
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 201010, inf = 100001000;

lld f[N], a[N], root;

lld find(lld x) {
    lld ret = f[x];
    if (ret != x) {
        ret = find(ret);
    }
    return f[x] = ret;
}


int main(){
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = i;
        if (a[i] == i) {
            root = a[i];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i != root) {
            lld x = find(i);
            lld y = find(a[i]);
            if (x == y) {
                ++ans;
                if (!root) {
                    root = x;
                }
                a[i] = root;
            }
            else {
                f[x] = f[y];
            }
            
        }
    }
    cout << ans << endl;;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    
}




