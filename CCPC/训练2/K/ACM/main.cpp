#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 70;
const int mod = 1000000007;
int a[N];
int dp[N][N][2];
long long xx[N];
void add(int &x, int y) {
    x+=y; if(x>=mod)x-=mod;
}
int main () {
    int casnum; scanf("%d", &casnum);
    for (int cas = 1 ; cas <= casnum; ++ cas) {
        long long n; cin >> n;
        long long tn = n;
        int c = 0;
        while (tn) {
            a[c++] = tn&1;
            tn>>=1;
        }
        reverse(a, a+c); xx[c+1] = 0;
        for (int i = c; i > 0; -- i) {
            a[i]=a[i-1];
            xx[i] = (xx[i+1]*2+a[i])%mod;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0][1] = 1;
        
        long long res1 = 0, res2 = 0;
        for (int i = 0; i < c; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                int tt = (1LL<<(c-(i+1)))%mod;
                if (a[i+1]) {
                    add(dp[i+1][j+1][1], dp[i][j][1]);
                    add(dp[i+1][j][0] , dp[i][j][1]);
                    
                    int t1 = 1LL*(xx[i+2]+1)*dp[i][j][1]%mod;
                    res1 += 1LL*t1*tt%mod*j%mod;
                    res2 += 1LL*dp[i][j][1]*(j+1)%mod;
                }
                else {
                    add(dp[i+1][j][1] , dp[i][j][1]);
                }
                
                add(dp[i+1][j][0] , dp[i][j][0]);
                add(dp[i+1][j+1][0] , dp[i][j][0]);
                int t1 = 1LL*tt*dp[i][j][0]%mod;
                res1 += 1LL*t1*tt%mod*j%mod;
                res2 += 1LL*dp[i][j][0]*(j+1)%mod;
            }
        }
        res1%=mod;res1=2LL*res1%mod;
        res2%=mod;res2=n%mod*res2%mod;
        cout<<res1 <<" "<<res2<<endl;
        int ans = (int)res2-(int)res1;
        if (ans<0)ans+=mod;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
