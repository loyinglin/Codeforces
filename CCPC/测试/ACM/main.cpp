
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 100000073
#define N 5000005
#define P(x,y) max(y-1,f[x-(y)])
using namespace std;

int a[N],b[N],s[N],sum[N],f[N];
int main(){
    f[1]=a[1]=b[1]=s[0]=s[1]=sum[0]=1; sum[1]=2;
    int i,j;
    for (i=2; i<=5000000; i++){
        for (b[i]=b[i-1]; b[i]<i && P(i,b[i]+1)<=P(i,b[i]); b[i]++);
        f[i]=P(i,b[i])+1;
        for (a[i]=a[i-1]; a[i]<i && P(i,a[i])>=f[i]; a[i]++);
        for (; a[i]>1 && P(i,a[i]-1)<f[i]; a[i]--);
        s[i]=(sum[i-a[i]]-sum[i-b[i]-1]+mod)%mod; sum[i]=(sum[i-1]+s[i])%mod;
    }
    while (~scanf("%d%d",&i,&j)) printf("%d %d\n",f[j-i+1],s[j-i+1]);
    return 0;
}
