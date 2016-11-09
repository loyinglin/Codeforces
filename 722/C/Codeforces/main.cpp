//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/722/problem/C
 题目大意：给出n个数字a[i]的数组。(1 ≤ a[i] ≤ 1e9)
 给出一个位置p[i]（1<=p[i]<=n），把p[i]对应的数字destroy，数字所在的数组分为两部分。
 现在给出n个位置（不重复），输出每次destroy后，最大的数组段数字和。
 (1<=n<=10w)
 
 input
 4
 1 3 2 5
 3 4 1 2
 output
 5
 4
 3
 0
 
 题目解析：
 f[i] 表示 数字i所在序列最左边的数字，sum[i]表示第i个数字所在序列的数字和。
 反着来看这个操作，每次插入一个数字，合并数字所在左右区间，然后询问最大的区间和。（并查集） 
 
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

lld  f[N];
lld  a[N];
lld  p[N];
lld  ans[N];
lld  sum[N];

lld find(lld x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}


int main(int argc, const char * argv
         []) {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = i;
        sum[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = n; i >= 1; --i) {
        lld x = p[i];
        lld temp = a[x];
        lld left = find(x);
        if (left - 1 >= 1) { // 存在左边的节点
            left = find(left - 1);
            lld leftSum = sum[left];
            if (leftSum != -1) {
                temp += leftSum;
                f[x] = f[left];
            }
        }
        if (x + 1 <= n) { // 存在右边的节点
            lld right = x + 1;
            lld rightSum = sum[right];
            if (rightSum != -1) {
                temp += rightSum;
                f[right] = f[x];
            }
        }
        sum[find(x)] = temp;
        ans[i - 1] = max(ans[i], sum[f[x]]);
        
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    
    
    return 0;
}
