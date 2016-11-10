#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define fi first
#define se second

using namespace std;

const int maxs=25,maxn=25,mo=1e9+7,N=22;

typedef long long LL;

typedef double db;

typedef pair<int,int> PII;

int n,m,k,s,M,Energy[N],f[N][maxs],g[N][maxs],All[maxs][maxs],Fac[maxn],Fac_Inv[maxn],Inv[maxn],ans;

PII Point[maxs];

char c;

int read()
{
    for (c=getchar();c<'0' || c>'9';c=getchar());
    int x=c-48;
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-48;
    return x;
}

bool cmp(PII a,PII b)
{
    return a.fi<b.fi || a.fi==b.fi && a.se<b.se;
}

void Init()
{
    n=read(); m=read(); k=read(); s=read();
    for (int i=1;i<=k;i++)
    {
        Point[i].fi=read()-1; Point[i].se=read()-1;
    }
    sort(Point+1,Point+k+1,cmp);
    Point[++k].fi=n-1; Point[k].se=m-1;
    Point[0].fi=Point[0].se=0;
    Fac[0]=Fac_Inv[0]=Fac[1]=Fac_Inv[1]=Inv[1]=1;
    for (int i=2;i<=n+m;i++)
    {
        Fac[i]=(LL)Fac[i-1]*i%mo;
        Inv[i]=(LL)Inv[mo%i]*(mo-mo/i)%mo;
        Fac_Inv[i]=(LL)Fac_Inv[i-1]*Inv[i]%mo;
    }
    Energy[0]=s;
    while (s>1) Energy[++M]=s=ceil((db)s/2);
}

int Comb(int N,int M)
{
    return (LL)Fac[N]*Fac_Inv[M]%mo*Fac_Inv[N-M]%mo;
}

void Work()
{
    for (int i=1;i<=k;i++)
    {
        f[0][i]=g[0][i]=Comb(Point[i].fi+Point[i].se,Point[i].fi);
        for (int j=1;j<i;j++)
            if (Point[i].se>=Point[j].se)
            {
                All[j][i]=Comb(Point[i].fi-Point[j].fi+Point[i].se-Point[j].se,Point[i].fi-Point[j].fi);
                f[0][i]=(f[0][i]+mo-(LL)f[0][j]*All[j][i]%mo)%mo;
            }
    }
    for (int i=1;i<=M;i++)
    {
        for (int j=i+1;j<=k;j++)
        {
            for (int x=i;x<j;x++) if (Point[x].se<=Point[j].se)
                g[i][j]=(g[i][j]+(LL)f[i-1][x]*All[x][j])%mo;
            f[i][j]=g[i][j];
            for (int x=i;x<j;x++) if (Point[x].se<=Point[j].se)
                f[i][j]=(f[i][j]+mo-(LL)f[i][x]*All[x][j]%mo)%mo;
        }
    }
    ans=0;
    for (int i=0;i<M;i++) ans=(ans+(LL)Energy[i]*f[i][k]%mo)%mo;
    ans=(ans+g[M][k])%mo;
    ans=(LL)ans*Fac[n-1]%mo*Fac[m-1]%mo*Fac_Inv[n+m-2]%mo;
    printf("%d\n",ans);
}

int main()
{
    Init();
    Work();
    return 0;
}
