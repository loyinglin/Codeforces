//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 题目解析：
 
 
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
const int N=100010;
int n;
vector<int> G[N];
int a[N], dfn[N], sz[N], dep[N], fa[N], tim;
void dfs(int x,int f) {
    dfn[x]=++tim;
    fa[x]=f;
    sz[x]=1;
    if(f==-1)dep[x]=0;
    else dep[x]=dep[f]+1;
    for (int i=0;i<G[x].size();++i) {
        int y=G[x][i];
        if(y==f)break;
        dfs(y, x);
        sz[x] += sz[y];
    }
}
bool cmp(int x, int y) {return dep[x] > dep[y];}
int boom[N];
int main () {
    int casnum;
    scanf("%d", &casnum);
    for (int cas=1;cas<=casnum;++cas){
        int q;scanf("%d%d",&n,&q);
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<n;++i) {
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        tim=0; dfs(1,-1);
        printf("Case #%d:", cas);
        while (q--) {
            int m; scanf("%d", &m);
            int ans=n-m;
            for (int i = 0; i < m; ++ i) scanf("%d", &a[i]);
            sort(a, a+m, cmp);
            for (int i = 0; i < m; ++ i) {
                int x = a[i];
                int cnt=0;
                for (int j = 0; j < G[x].size(); ++ j) {
                    int y = G[x][j];
                    if (y == fa[x]) continue;
                    if (!boom[y])cnt++;
                }
                if(cnt==0)boom[x]=1;
                if(cnt>=2)ans++;
            }
            for (int i = 0; i < m; ++ i)
                boom[a[i]] = 0;
            printf("%d\n", ans);
        }
    }
    return 0;
}
