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

const int maxn=1050;
int uN,vN;
int T,n,s;
int g[maxn][maxn];
int linker[maxn];
bool used[maxn];

bool dfs(int u){
    for(int v=0;v<vN;v++)
        if (g[u][v]&&!used[v]){
            used[v]=true;
            if (linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    return false;
}

int hungary(){
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<uN;u++){
        memset(used,false,sizeof(used));
        if (dfs(u)) res++;
    }
    return res;
}

int main(){
    scanf("%d",&T);
    for(int Case=1;Case<=T;Case++){
        scanf("%d%d",&n,&s);
        memset(g,0,sizeof(g));
        if (n<=1000){
            uN=vN=n;
            for(int i=s+1;i<=s+n;i++)
                for(int j=1;j<=n;j++)
                    if (i%j==0)
                        g[i-s-1][j-1]=1;
            if (hungary()==n)
                printf("Case #%d: Yes\n",Case);
            else
                printf("Case #%d: No\n",Case);
        }
        else if (s<=1000){
            uN=vN=s;
            for(int i=n+1;i<=n+s;i++)
                for(int j=1;j<=s;j++)
                    if (i%j==0)
                        g[i-n-1][j-1]=1;
            if (hungary()==s)
                printf("Case #%d: Yes\n",Case);
            else
                printf("Case #%d: No\n",Case);
        }
        else
            printf("Case #%d: No\n",Case);
    }
    return 0;  
}
