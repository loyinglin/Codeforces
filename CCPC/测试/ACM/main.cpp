#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INF 110000000
#define NN 600
#define MM 50100


struct edge{int u,v,c;}ed[MM];//MM要为连接关系数量的两倍
int fi[NN],ne[MM],te,lev[NN];

int pe[NN],cap[NN],tc[NN],sta[NN];//模拟栈用数组

void init(){
    memset(fi,-1,sizeof(fi));
    te=0;
}

void insert(int u,int v,int c){
    ed[te].u=u;ed[te].v=v;ed[te].c=c;
    ne[te]=fi[u];fi[u]=te++;
    ed[te].u=v;ed[te].v=u;ed[te].c=0;
    ne[te]=fi[v];fi[v]=te++;
}

int dinic_bfs(int s,int t){
    memset(lev,0,sizeof(lev));
    lev[s]=1;
    queue<int> q;
    q.push(s);
    int u,v,e,c;
    while(!q.empty()){
        u=q.front();q.pop();
        for(e=fi[u];e!=-1;e=ne[e]){
            v=ed[e].v;c=ed[e].c;
            if (!lev[v]&&c){
                lev[v]=lev[u]+1;
                q.push(v);
            }
        }
        if (u==t) break;
    }
    return lev[t];
}

int dinic_dfs1(int u,int t,int cap){//直接深搜
    int tc=cap;
    if (u==t) return cap;
    int v,e,c,tf;
    for(e=fi[u];e!=-1&&tc;e=ne[e]){
        v=ed[e].v;
        c=ed[e].c;
        if (lev[v]==lev[u]+1&&c>0){
            tf=dinic_dfs1(v,t,min(tc,c));
            tc-=tf;
            ed[e].c-=tf;
            ed[e^1].c+=tf;
        }
    }
    if (e==-1) lev[u]=-10;//重要优化
    return cap-tc;
}



int dinic_dfs(int s,int t,int tn){//模拟栈深搜
    int top=0,i,flow=0;
    sta[++top]=s;
    cap[s]=tc[s]=INF;
    pe[s]=fi[s];
    int u,v,c,tf;
    while(top){
        u=sta[top];
        if (u!=t)
            for(int &e=pe[u];e!=-1&&tc[u];e=ne[e]){
                v=ed[e].v;c=ed[e].c;
                if (lev[v]==lev[u]+1&&c){
                    sta[++top]=v;pe[v]=fi[v];tc[v]=cap[v]=min(c,tc[u]);
                    break;
                }
            }
        else tc[u]=0;
        if (tc[u]==0||pe[u]==-1) {
            tf=cap[u]-tc[u];
            if (pe[u]==-1) lev[u]=-10;//重要优化
            top--;
            if (top){
                tc[sta[top]]-=tf;
                ed[pe[sta[top]]].c-=tf;
                ed[pe[sta[top]]^1].c+=tf;
                pe[sta[top]]=ne[pe[sta[top]]];
            }
            else flow+=tf;
        }
    }
    return flow;
}



int dinic(int s,int t,int tn){//起点终点相等需要特判
    int flow=0;
    int tf=0;
    while(dinic_bfs(s,t)){
        flow+=dinic_dfs(s,t,t+1);
    }
    return flow;
}

#define KK 110

int n,m,tte,k;
int g[KK][KK];
int s,t;


void input(int tte){
    int i;
    int a,b;
    memset(g,0,sizeof(g));
    for(i=1;i<=tte;++i){
        scanf("%d%d",&a,&b);
        g[b][a]=1;
    }
}

int work(int now){
    init();
    s=0;t=3*m+1;
    int i,j;
    for(i=1;i<=m;++i){
        insert(s,i,now);
        insert(i,i+m,k);
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if (g[i][j]==1){
                insert(i,j+2*m,1);
            }
            else {
                insert(i+m,j+2*m,1);
            }
        }
    }
    for(i=1;i<=n;++i){
        insert(i+2*m,t,now);
    }
    int flow = dinic(s,t,t+1);
    if (flow==now*n) return 1;
    else return 0;
}




int main(){
    int tcas,cas;
    scanf("%d",&tcas);
    for(cas=1;cas<=tcas;++cas){
        scanf("%d%d%d%d",&n,&m,&tte,&k);
        input(tte);
        int l=0,r=m,ans=0,mid;
        while(l<=r){
            mid=(l+r)/2;
            if (work(mid)) {
                ans=max(ans,mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}





