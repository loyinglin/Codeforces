#include<cstdio>
#include<cstring>
using namespace std;

long long fact[22]={1};

long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int p,n,m,N,x[22];
long long d[1<<20];

int main(){
    for(int i=1; i<22; ++i) fact[i]=fact[i-1]*i;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&p,&n,&m);
        N=n+m;
        for(int i=n; i<N; ++i){
            scanf("%d",&x[i]);
        }
        
        memset(d,0,sizeof(d));
        d[0]=1;
        for(int s=0; s<(1<<N); ++s){
            if(d[s]==0) continue;
            
            int A=0,B=0,damage=0;
            for(int i=n; i<N; ++i){
                if(s>>i&1){
                    damage+=x[i];
                    ++B;
                }
            }
            if(damage>=p) continue;
            for(int i=0; i<n; ++i){
                if(s>>i&1) ++A;
            }
            
            if(A-B+1<=0) continue;
            
            for(int i=0; i<N; ++i){
                if(s>>i&1) continue;
                d[s^(1<<i)]+=d[s];
            }
        }
        
        long long xx=0,yy=fact[N];
        for(int s=0; s<(1<<N); ++s){
            if(d[s]==0) continue;
            int A=0,B=0,damage=0;
            for(int i=n; i<N; ++i){
                if(s>>i&1){
                    damage+=x[i];
                    ++B;
                }
            }
            for(int i=0; i<n; ++i){
                if(s>>i&1) ++A;
            }
            if(damage>=p){
                xx+=d[s]*fact[N-A-B];
            }
        }
        long long g=gcd(xx,yy);
        printf("%lld/%lld\n",xx/g,yy/g);
    }
    return 0;
}
