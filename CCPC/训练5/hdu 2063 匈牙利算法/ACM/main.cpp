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
#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Hungary {
    static const int N = 1000;
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
        for(int u = 0; u< nx; ++u) {
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
        g[u][v] = 1; //注意，这里是mat[a][b]=mat[b][a]=0
    }
}acm;

int main(){
    int k;
    while(cin >> k >> acm.nx >> acm.ny, k){
        acm.reset();
        for(int i = 1; i <= k; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            acm.addEdge(a - 1, b - 1);
        }
        printf("%d\n", acm.look());
    }
}
