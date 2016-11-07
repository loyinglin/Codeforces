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

struct KM {
    static const int N = 2010, inf = 10000000;
    int lx[N], ly[N], mat[N][N];
    int vx[N], vy[N], link[N], slack[N], a[N];
    int dfs(int k, int n){
        vx[k] = 1;
        for(int i = 1; i <= n; i++){
            if(vy[i]) continue;
            int t = lx[k] + ly[i] - mat[k][i];
            if(t == 0){   //注意此处的虚拟边，权值为零不影响最佳匹配的边，方便遍历
                vy[i] = 1;
                if(link[i] == -1 || dfs(link[i], n)){
                    link[i] = k;
                    return 1;
                }
            }
            else slack[i] = min(t, slack[i]);
        }
        return 0;
    }
    int look(int n){
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) lx[i] = max(lx[i], mat[i][j]);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) slack[j] = inf;
            while(true){
                memset(vx, 0, sizeof(vx));
                memset(vy, 0, sizeof(vy));
                if(dfs(i, n)) break;
                int Min = inf;
                for(int t = 1; t <= n; t++)
                    if(!vy[t]) Min = min(Min, slack[t]);
                for(int t = 1; t <= n; t++)
                    if(vx[t]) lx[t] -= Min;
                for(int t = 1; t <= n; t++)
                    if(vy[t]) ly[t] += Min;
                    else slack[t] -= Min;
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++)
            if(link[i] != -1) sum += mat[link[i]][i];
        return sum;
    }
    
    void reset(int n) {
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) mat[i][j] = 0; //初始化, 默认存在权值为0的边, 如果是最小值，要初始化成负无穷
        for(int i = 1; i <= n; i++) lx[i] = 0;  //初始化,如果最小值需修改-inf
        memset(link, -1, sizeof(link));
        memset(ly, 0, sizeof(ly));
    }
}acm;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        acm.reset(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                scanf("%d", &acm.mat[i][j]);
            }
        }
        int ans = acm.look(n);
        printf("%d\n", ans);
    }
}
