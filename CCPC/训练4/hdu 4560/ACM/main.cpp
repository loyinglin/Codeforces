//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
  2013年一开始，一档音乐节目“我是歌手”就惊艳了大家一回。闲话少说，现在，你成为了这档节目的总导演，你的任务很简单，安排每一期节目的内容。
  现在有N个歌手，M种歌曲流派（Rock，Pop之类），每个歌手都有自己擅长的流派领域，这些资料都已整理好。你的工作是，安排尽可能多场的演唱比赛。每一场比赛所有歌手都必须上场，为了提高收视率，每个人演唱的歌曲类型不能相同，即便一些歌手要被迫选择一些他们不擅长的。同时，为了展现全面性，在不同的演唱比赛上，每个歌手都会安排不同的歌曲流派。
  但是问题是，对于任何一个歌曲流派的歌迷，如果超过K个不擅长的歌手演唱了这种歌曲，他们就会表示不满，比如，发一些宣泄不满的帖子微博，为了表示观点挑起事端等等。你当然不希望这些事情与你的节目有关，在这个前提下，你可以任意安排尽可能多的比赛场次。
 
 Input
 输入第一行为T，表示有T组测试数据。
 每组数据以四个数字N，M，L, K开始。L表示有L组擅长关系，接下来的L行，每一行有两个数字Ai，Bi，表示歌手Ai擅长Bi类型的歌曲。
 
 [Technical Specification]
 
 1. 1 <= T <= 100
 2. 1 <= N <= M <= 74, 0 <= K <= N
 3. 0 <= L <= N*M
 4. 1 <= Ai <= N, 1 <= Bi <= M, 相同关系不会重复出现
 
 Output
 对每组数据，先输出为第几组数据，然后输出最多比赛场次
 
 题目解析：
 建图：
 当前二分的场次为mid。
 每种流派分为两个点，一个代表是被擅长的歌手演唱(设为i)，一个代表不擅长（i+m）。
 s->i           流量m
 i->i+m         k
 i->擅长歌手        1
 i+m->不擅长歌手    1
 歌手->dest   mid

 
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
const int N = 310, M = 500000, inf = 100100100; //注意修改点的范围
struct Edge{
    int s, t, f, id;
    int next;
}e[M];
int pre[N], tpre[N], dis[N], ans[M], cnt;
int a[N][N];
void addedge(int s, int t, int f, int id){ //有上下界的最大流模板
    e[cnt].s = s, e[cnt].t = t, e[cnt].f = f, e[cnt].id = id, e[cnt].next = pre[s];
    pre[s] = cnt++;
    e[cnt].s = t, e[cnt].t = s, e[cnt].f = 0, e[cnt].id = 0, e[cnt].next = pre[t];
    pre[t] = cnt++;
}
int bfs(int s, int t){
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i = pre[id]; i != -1; i = e[i].next)
            if(dis[e[i].t] == 0 && e[i].f > 0){
                dis[e[i].t] = dis[id] + 1;
                q.push(e[i].t);
            }
    }
    return dis[t] != 0;
}
int dfs(int s, int t, int cur_flow){
    int lev = cur_flow;
    if(s == t) return cur_flow;
    for(int &i = tpre[s]; i != -1; i = e[i].next)
        if(dis[e[i].t] == dis[s] + 1 && e[i].f > 0 && lev > 0){
            int temp = dfs(e[i].t, t, min(lev, e[i].f));
            e[i].f -= temp;
            e[i^1].f += temp;
            lev -= temp;
        }
    return cur_flow - lev;
}
int dinic_flow(int s, int t){    //注意是从s到t，故而s最小，t最大
    int sum = 0;
    while(bfs(s, t)){
        int flow;
        for(int i = s; i <= t; i++) tpre[i] = pre[i];
        while((flow = dfs(s, t, inf))) sum += flow;
    }
    return sum;
}

void flow_init(){
    memset(pre, -1, sizeof(pre));
    memset(ans, 0, sizeof(ans));
    cnt = 0;
}

int limit_min_flow(int n, int m, int mid, int k, int &flow){
    int src = 0, dest = n + 2 * m + 1;
    for (int i = 1; i <= n; ++i) {
        addedge(src, i, 1, 0);
    }
    if (mid == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j]) {
                    addedge(i, n + j, 1, 0);
                }
                else {
                    addedge(i, n + m + j, 1, 0);
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        addedge(n + i, dest, 1, 0);
        if (mid == 1) {
            addedge(n + m + i, n + i, k, 0);
        }
        
    }
    flow += dinic_flow(src, dest);
    return flow >= mid * n;
}


int main(){
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        int n, m, L, k;
        cin >> n >> m >> L >> k;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < L; ++i) {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        int ans = 0, flow = 0;
        flow_init();
        
        while (true) {
            if (limit_min_flow(n, m, ans + 1, k, flow)) {
                ++ans;
            }
            else {
                break;
            }
        }
        printf("Case %d: %d\n", ++ca, ans);
    }
    return 0;
}

