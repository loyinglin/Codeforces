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

struct HungaryHK {
    static const int N = 1000, inf = 1<<28;
    bool bmap[N][N], bmask[N];
    int nx,ny,dis;
    int cx[N], cy[N], dx[N], dy[N];
    
    bool bfs()
    {
        queue<int> q;
        dis = inf;
        memset(dx,-1,sizeof(dx));
        memset(dy,-1,sizeof(dy));
        for(int i = 0;i < nx; ++i) if(cx[i] == -1) dx[i] = 0, q.push(i); //从未匹配点X[i]出发
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(dx[u] > dis) break;
            for(int v = 0; v < ny; ++v)
                if(bmap[u][v] && dy[v]== -1){
                    dy[v] = dx[u] + 1;
                    if(cy[v] == -1) dis = dy[v]; // 找到未匹配点Y，即是增广路存在
                    else dx[cy[v]] = dy[v] + 1, q.push(cy[v]);
                }
        }
        return dis != inf;
    }
    int dfs(int u)
    {
        for(int v = 0; v < ny; ++v){
            if(!bmask[v] && bmap[u][v] && dy[v] == dx[u]+1){
                bmask[v]=1;
                if(cy[v] != -1 && dy[v] == dis) continue;
                if(cy[v] == -1 || dfs(cy[v])){
                    cy[v] = u;
                    cx[u] = v;
                    return 1;
                }
            }
        }
        return 0;
    }
    int look(){
        int res = 0;
        memset(cx, -1, sizeof(cx));
        memset(cy, -1, sizeof(cy));
        while(bfs()){
            memset(bmask, 0, sizeof(bmask));
            for(int i = 0; i < nx; ++i) if(cx[i]==-1)
                res += dfs(i);
        }
        return res;
    }
    
    void reset() {
        for(int i = 0; i <= nx; ++i) for(int j = 0; j <= ny; ++j) bmap[i][j] = 0;
    }
    
    void addEdge(int u, int v) {
        bmap[u][v] = 1; //注意，这里不是mat[a][b]=mat[b][a]=0
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
