#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define min(a,b) (((a) < (b)) ? a : b)
#define max(a,b) (((a) > (b)) ? a : b)
using namespace std;

int f[maxn],g[maxn];

int l,n,p,t;

int head,tail;

int ans;

int main(){
    scanf("%d%d%d%d",&l,&n,&p,&t);
    head=1;
    tail=1;
    f[tail]=0;
    g[tail]=-t;
    fo(i,1,n) {
        int x,y,ans1,ans2;
        scanf("%d%d",&x,&y);
        ans1=ans2=0;
        if (head>1) head--;
        while (head<=tail && g[head]+t<=y) {
            int nx=max(x,g[head]+t),ny=y;
            if (f[head]+(ny-nx)/p>ans1) {
                ans1=f[head]+(ny-nx)/p;
                ans2=nx+(ny-nx)/p*p;
            }
            else if (f[head]+(ny-nx)/p==ans1) {
                ans2=min(ans2,nx+(ny-nx)/p*p);
            }
            ++head;
        }
        if (ans1>ans) {
            ans=ans1;
            tail++;
            f[tail]=ans1;
            g[tail]=ans2;
        }
    }
    printf("%d",ans);
    return 0;
}
