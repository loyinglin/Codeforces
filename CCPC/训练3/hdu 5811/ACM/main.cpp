//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：

 
 题目解析：
 
 
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
