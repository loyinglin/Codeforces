#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 1008
#define mo 1000000007

int dp[N][N][3][3];
int a[N];

void add(int &x,int y){
    x = x + y;
    if (x >= mo) x -= mo;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int n,s;
        scanf("%d%d",&n,&s);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=s;j++)
                for (int s1=0;s1<=2;s1++)
                    for (int s2=0;s2<=2;s2++){
                        add(dp[i][j][s1][s2],dp[i-1][j][s1][s2]);
                        if (j>=a[i]) add(dp[i][j][s1][s2],dp[i-1][j-a[i]][s1][s2]);
                        if (s1>0 && j>=a[i])
                            add(dp[i][j][s1][s2],dp[i-1][j-a[i]][s1-1][s2]);
                        if (s2>0)
                            add(dp[i][j][s1][s2],dp[i-1][j][s1][s2-1]);
                    }
        int ans=0;
        for (int i=0;i<=s;i++) add(ans,dp[n][i][2][2]);
        printf("%lld\n",ans*4ll % mo);
    }
}
