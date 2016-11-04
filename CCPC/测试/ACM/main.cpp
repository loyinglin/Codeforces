#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define L(i) i<<1
#define R(i) i<<1|1
#define INF  0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-9
#define maxn 100100
#define MOD 1000000007

const int MAXN = 100010;
const int MAXM = 400010;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tot,n,m,N,l;
int head[MAXN];
int gap[MAXN],dep[MAXN];
int pre[MAXN],cur[MAXN];
int cost[220],TIME[220],tTIME[220];
int val[220],shop[220][220];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w,int rw = 0)
{
    edge[tot].to = v;
    edge[tot].cap = w;
    edge[tot].flow = 0;
    edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].cap = rw;
    edge[tot].flow = 0;
    edge[tot].next = head[v];
    head[v] = tot++;
}
int sap(int start,int en)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == en)
        {
            int Min = INF;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        int flag = 0;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = 1;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])
            return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start)
            u = edge[pre[u]^1].to;
    }
    return ans;
}
int solve(int x)
{
    init();
    int vis[220] = {0};
    int t = tTIME[x],sum = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= shop[i][0]; j++)
            add_edge(i,shop[i][j]+m,INF);
    for(int i = 1; i <= n; i++)
        if(TIME[i] <= t)
        {
            vis[i] = 1;
            add_edge(m+i,m+n+1,cost[i]);
        }
    for(int i = 1; i <= m; i++)
    {
        int flag = 1;
        for(int j = 1; j <= shop[i][0]; j++)
            if(!vis[shop[i][j]])
                flag = 0;
        if(flag)
        {
            sum += val[i];
            add_edge(0,i,val[i]);
        }
    }
    int ans = sap(0,m+n+1);
    ans = sum - ans;
    if(ans >= l)
    {
        printf("%d %d\n",t,ans);
        return 1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,C = 1;
    scanf("%d",&t);
    while(scanf("%d%d%d",&n,&m,&l) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&cost[i],&TIME[i]);
            tTIME[i] = TIME[i];
        }
        sort(tTIME+1,tTIME+n+1);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&val[i],&shop[i][0]);
            for(int j = 1; j <= shop[i][0]; j++)
                scanf("%d",&shop[i][j]);
        }
        N = m + n + 2;
        printf("Case #%d: ",C++);
        int flag = 0;
        for(int i = 1; i <= n; i++)
            if(solve(i))
            {
                flag = 1;
                break;
            }
        if(!flag)
            printf("impossible\n");
    }
    return 0;
}
