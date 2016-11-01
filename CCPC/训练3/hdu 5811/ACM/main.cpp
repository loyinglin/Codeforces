//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：有n只monster；
 输入一个矩阵mat，表示monster之间的关系；
 mat[i][j]=1表示i怪物能打败j怪物；
 mat[j][i]=0表示i怪物打不过j怪物；
 注意，mat[j][i]=0 <=> mat[i][j]=1 可以互推，但是没有传递性，A能打败B、B能打败C => C能打败A 是不满足的。
 
 输入m，再输入m个数字，表示挑选出m只monster组成T1队，剩下n-m只monster组成T2队，询问T1队与T2队是否合法 （合法是指存在某种排列，排列中任意一只monster都能打败他右边所有monster）？
 如果合法，最多从T2队中能选出几只monster插入到T1中，并保证T1合法？

 
 题目解析：
 要求1，可以用拓扑排序；（O（n^2））
 要求2，先按照T2队从大到小的顺序，求出T2队中每个monster对应在T1队的位置pos[i]，这样就转换成求pos数组的最长不下降子序列；（O（n^2）的dp）
 注意1、2、2、3这种序列是合法的，因为原来T2本来就满足顺序要求（排列中任意一只monster都能打败他右边所有monster)；
 
 
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

int a[N][N];
int flag[N];
int num[N]; // 入度
int dp[N];
int p[N];
int n, m;
vector<int> vec[2];

bool check() {
    for (int i = 1; i <= n; ++i) {
        int j;
        for (j = 1; j <= n; ++j) {
            if (!num[j]) {
                break;
            }
        }
        if (j == n + 1) {
            return 0;
        }
        --num[j];
        vec[flag[j]].push_back(j);
        for (int k = 1; k <= n; ++k) {
            if (flag[j] == flag[k] && a[j][k]) {
                --num[k];
            }
        }
    }
    return 1;
}

int look() {
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    int ans = 0;
    for (int i = 0; i < vec[0].size(); ++i) {
        int u = vec[0][i];
        int pos = 0;
        for (int j = vec[1].size() - 1; j >= 0; --j) {
            int v = vec[1][j];
            if (a[v][u]) {
                if (!pos) {
                    pos = j + 1;
                }
            }
            else if (pos != 0){
                pos = -1;
                break;
            }
        }
        if (pos != -1) {
            p[i] = pos;
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (p[i] >= p[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}


int main()
{
    
    while(scanf("%d%d", &n, &m))
    {
        if (n + m == 0) {
            break;
        }
        memset(flag, 0, sizeof(flag));
        vec[0].clear();
        vec[1].clear();
        char str[2111];
        gets(str);
        for(int i = 1; i <= n; ++i)
        {
            gets(str);
            for(int j = 1; j <= n; ++j)
            {
                char ch = str[j * 2 - 2];
                a[i][j] = ch - '0';
            }
        }
        
        for (int i = 0; i < m; ++i) {
            int k;
            scanf("%d", &k);
            flag[k] = 1;
        }
        
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (flag[i] == flag[j]) { // same team
                    if (a[i][j]) {
                        ++num[j];
                    }
                    if (a[j][i]) {
                        ++num[i];
                    }
                }
            }
        }
        
        if (!check()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES "  << look() << endl;
        }
        
    }
    return 0;
}
