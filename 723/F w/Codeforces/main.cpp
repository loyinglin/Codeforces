//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/723/problem/F
 题目大意：
 给出一个无向连通图，n个点m条边，无重边和自环。
 给出两个顶点s、t，两个整数ds 和 dt，构建一个生成树，要求：
 点s、t的度数不超过ds、dt；
 (2 ≤ n ≤ 200 000, 1 ≤ m ≤ min(400 000, n·(n - 1) / 2))
 
 如果存在，输出Yes，然后输出生成树的边；
 不存在输出No。
 
 Examples
 input
 3 3
 1 2
 2 3
 3 1
 1 2 1 1
 output
 Yes
 3 2
 1 3
 
 

 
 题目解析：
 第一反应是最小生成树：给边加权值；
 要满足一个条件：
 能不用s、t就不用s、t的边；
 如果非要用s、t的边，那么尽可能先用度数残留较大的边；
 那么会遇到一个问题，最小生成树的算法无法评估s、t的边。。
 
 考虑另外一种做法：
 这个题目的抉择在于s、t的边如何抉择，以保证度数合法。
 那么非s、t的点可以按照连通块缩点，有三种情况：
 1、只和s连接，那么连s；
 2、只和t连接，那么连t；
 3、和s、t连接，取剩余度数较大的边；
 （特殊考虑s、t直接相连的情况）
 
 
 那么遍历所有s的边，如果这个边对应的连通块只与s相连，直接dfs（不经过t），可以解决情况1、2；
 
 现在问题在如果一个连通块与s和t相连，要考虑这个连通块是否可以经过t；
 于是先对t遍历，所有边先不经过s；
 
 最后对s的边遍历，如果发现没有与s相连，需要连一条s；
 特殊的情况，就是s和t相连；
 
 
 
 ************************* 题解 ***********************/

/*
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
const int N = 222222;
stack<int> S;
vector<int> g[N];
int sv[N], dfn[N], low[N];
int in[N], out[N], num[N];
int id, s, t, ds, dt; //连通分支个数
int con[N][2];
int vis[N];
int ans[N][2], ant = 0;

map<pair<int, int>, int> Hash;

void dfs(int u, int dep){
    low[u] = dfn[u] = dep;
    S.push(u);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(dfn[v] == -1) dfs(v, dep + 1);
        if(sv[v] == -1) low[u] = min(low[u], low[v]);  // 判断不可少
    }
    if(low[u] == dfn[u]){
        ++id;
        while(S.top() != u){
            sv[S.top()] = id;
            S.pop();
        }
        sv[S.top()] = id;
        S.pop();
    }
}
int tarjan(int n){
    while(!S.empty()) S.pop();
    memset(dfn, -1, sizeof(dfn));
    memset(sv, -1, sizeof(sv));
    id = 0;
    dfn[s] = dfn[t] = sv[s] = sv[t] = N - 1;
    for(int i = 1; i <= n; ++i) if (dfn[i] == -1) dfs(i, 0);
    return id;
}

void addAns(int u, int v) {
    ans[ant][0] = u;
    ans[ant++][1] = v;
    Hash[make_pair(u, v)] = 1;
    Hash[make_pair(v, u)] = 1;
}

void look(int u) {
    if (vis[u]) {
        return ;
    }
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            addAns(u, v);
            look(v);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s >> t >> ds >> dt;
    tarjan(n);
    for (int i = 0; i < g[s].size(); ++i) {
        int v = g[s][i];
        con[sv[v]][0] = 1;
    }
    for (int i = 0; i < g[t].size(); ++i) {
        int v = g[t][i];
        con[sv[v]][1] = 1;
    }
    vis[s] = vis[t] = 1;
    for (int i = 0; i < g[s].size(); ++i) {
        int v = g[s][i];
        int k = sv[v];
        if (con[k][0] == 1 && con[k][1] == 0 && !vis[v]) {
            --ds;
            addAns(s, v);
            look(v);
        }
    }
    for (int i = 0; i < g[t].size(); ++i) {
        int v = g[t][i];
        int k = sv[v];
        if (con[k][0] == 0 && con[k][1] == 1 && !vis[v]) {
            --dt;
            addAns(t, v);
            look(v);
        }
    }
    for (int i = 0; i < g[s].size(); ++i) {
        int v = g[s][i];
        int k = sv[v];
        if (con[k][0] == 1 && con[k][1] == 1 && !vis[v]) { // 不经过t点的dfs
            if (ds > 0) {
                --ds;
                addAns(s, v);
                look(v);
            }
        }
    }
    for (int i = 0; i < g[t].size(); ++i) {
        int v = g[t][i];
        int k = sv[v];
        if (con[k][0] == 1 && con[k][1] == 1 && !vis[v]) { // 不经过s点的dfs
            if (dt > 0) {
                --dt;
                addAns(t, v);
                look(v);
            }
        }
    }
    int ok = 0, k, *kp;
    if (ds > dt) {
        k = s;
        kp = &ds;
    }
    else {
        k = t;
        kp = &dt;
    }
    for (int i = 0; i < g[k].size(); ++i) {
        int v = g[k][i];
        if (con[sv[v]][0] + con[sv[v]][1] == 2 && v != (s + t - k) && Hash[make_pair(k, v)] == 0) {
            *kp = *kp - 1;
            ok = 1;
            addAns(k, v);
            break;
        }
    }
    if (!ok) {
        for (int i = 0; i < g[s].size(); ++i) {
            if (g[s][i] == t) {
                --ds;
                --dt;
                addAns(s, t);
            }
        }
    }
    
    if (ant == n - 1 && ds >= 0 && dt >= 0) {
        cout << "Yes" << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}
 */
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
const int MAX=4e5+9;
int a[MAX],b[MAX],s,t,ds,dt,n,m,fa[MAX];
bool ms[MAX],mt[MAX];
vector<int> vs,vt;
vector<pair<int,int> > ans;
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}

void merge(int a,int b) {
    if (a==s) ds--;
    if (a==t) dt--;
    fa[findfa(a)]=findfa(b),ans.push_back(make_pair(a,b));
}
int main() {
    
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++) fa[i]=i;
    for (int i=1; i<=m; i++) cin>>a[i]>>b[i];
    cin>>s>>t>>ds>>dt;
    for (int i=1; i<=m; i++)
        if (a[i]!=s && a[i]!=t && b[i]!=s && b[i]!=t) {
            if (findfa(a[i])!=findfa(b[i]))
                merge(a[i],b[i]);
        } else {
            if (a[i]==s) vs.push_back(b[i]);
            if (b[i]==s) vs.push_back(a[i]);
            if (a[i]==t) vt.push_back(b[i]);
            if (b[i]==t) vt.push_back(a[i]);
        }
    for (int i=0; i<vs.size(); i++) ms[findfa(vs[i])]=1;
    mt[t]=1,ms[s]=1;
    for (int i=0; i<vt.size(); i++) {
        int x=vt[i];
        mt[findfa(x)]=1;
        if (!ms[findfa(x)] && findfa(x)!=findfa(t))
            merge(x,t),dt--;
    }
    for (int i=0; i<vs.size(); i++) {
        int x=vs[i];
        if (!mt[findfa(x)] && findfa(x)!=findfa(s))
            merge(x,s),ds--;
    }
    for (int i=0; i<vs.size(); i++) {
        int x=vs[i];
        if (findfa(x)!=findfa(s) && findfa(x)!=findfa(t) && ds)
            merge(x,s),ds--;
    }
    for (int i=0; i<vt.size(); i++) {
        int x=vt[i];
        if (findfa(x)!=findfa(s) && findfa(x)!=findfa(t))
            merge(x,t),dt--;
    }
    for (int i=0; i<vs.size(); i++) {
        int x=vs[i];
        if (x==t && !dt) ;
        else if (findfa(x)!=findfa(s) && ds)
            merge(x,s),ds--;
    }
    for (int i=0; i<vt.size(); i++) {
        int x=vt[i];
        if (x==s && !ds) ;
        else if (findfa(x)!=findfa(t))
            merge(x,t),dt--;
    }
    bool flg=0;
    for (int i=2; i<=n; i++) if (findfa(i)!=findfa(1)) flg=1;
    if (dt<0 || ds<0 || flg) return cout<<"No\n",0;
    cout<<"Yes\n";
    for (int i=0; i<ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}

/*
 9 11
 1 2
 1 8
 2 9
 3 4
 4 9
 4 5
 5 6
 6 9
 6 7
 7 8
 8 9
 
 3 2 1 1
 
 
 
 
 
 4 5
 1 2
 2 3
 1 3
 1 4
 4 3
 
 1 3 1 2
 
 
 10 15
 4 1
 5 10
 2 1
 5 7
 9 2
 4 6
 6 7
 9 1
 6 9
 8 4
 8 3
 9 8
 3 9
 2 3
 7 10
 10 1 2 3
 
 
 
 6 8
 3 1
 3 2
 3 5
 3 6
 4 1
 4 2
 4 5
 4 6
 3 4 2 3
 
 
 4 3
 1 2
 2 3
 3 4
 2 3 2 2
 
 
 
 6 6
 1 2
 2 4
 2 3
 4 5
 3 5
 5 6
 2 5 4 1
 
 
 
 7 8
 1 2
 2 4
 2 3
 4 5
 3 5
 5 6
 2 7 
 7 5
 2 3 2 2
 */
