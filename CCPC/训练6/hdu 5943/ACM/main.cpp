//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 (s+1,s+2,⋯,s+n) n个数，放在1~n的位置上，第i个数字必须满足x[i] % i == 0.问能不能放。
 
 4 11 总共8个数，可以这么放：
 1   2   3    4   5 6 7 8
 11 10   9    4   5 6 7 8
 
 s 和 n的范围是1e9.
 
 题目解析：
 重叠的部分可以对齐放；
 不重叠的部分，如果存在2个质数，无解；
 
 小于1000的部分，用匈牙利算法；
 
 
 
 
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
const int N = 1100, M = 500000, inf = 100100100; //注意修改点的范围

struct Hungary {
    int nx, ny, g[N][N], linker[N];
    bool used[N];
    int dfs(int u) {
        for(int v = 0; v < ny; ++v) {
            if(g[u][v] && !used[v]) {
                used[v]=true;
                if(linker[v] == -1 || dfs(linker[v])) {
                    linker[v] = u;
                    return 1;
                }
            }
        }
        
        return 0;
    }
    int look() {
        int res = 0;
        for(int u = 0; u < nx; ++u) {
            memset(used, 0, sizeof(used));
            res += dfs(u);
        }
        return res;
    }
    void reset() {
        memset(g, 0, sizeof(g));
        memset(linker, -1, sizeof(linker));
    }
    void addEdge(int u, int v) {
//        cout << u << " -- " << v << endl;
        g[u][v] = 1; //注意，这里是mat[a][b]=mat[b][a]=0
    }
}acm;

int main(){
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        int n, s;
        cin >> n >> s;
        if (s + 1 <= n) { //有重叠的部分
            int t = n;
            n = s;
            s = t;
        }
        int ok = 1;
        if (n + 1 < N) {
            acm.nx = acm.ny = n;
            acm.reset();
            for (int i = s + 1; i <= s + n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (i % j == 0) {
                        
                        acm.addEdge(i - s - 1, j - 1);
                    }
                }
            }
            if (acm.look() < n) {
                ok = 0;
            }
        }
        else {
            ok = 0;
        }
        
        
        printf("Case #%d: ", ++ca);
        if (ok) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}

/*
 
 11
 5
 0 0 1 5
 100000000 100000000 1 6
 0 1 1 7
 3 0 2 10
 5 0 1 4
 
 
 5
 0 0 1 5
 1 1 1 6
 0 1 1 7
 3 0 2 10
 5 0 2 4
 
 
 5
 0 0 3 5
 1 1 1 6
 0 1 1 7
 3 0 3 10
 5 0 2 4
 
 
 5
 0 0 1 5
 100000000 100000000 1 6
 0 1 1 7
 3 0 2 10
 5 0 1 4
 
 */

