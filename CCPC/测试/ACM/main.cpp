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
#define maxn 10010
#define MOD 1000000007

long long Log(long long x)
{
    long long k = -1;
    while(x)
    {
        k++;
        x >>= 1;
    }
    return k;
}
long long solve(long long x,long long y,long long s)
{
    long long k = Log(y-x+1);
    if((1<<k) == y-x+1)
        return k;
    long long last = max((long long)0,y+1-(1<<(k+1)));
    return min(k+1+max((long long)0,x-last-s),k+1+solve(x,y+1-(1<<k),s+1));
}
int main()
{
    int t,C = 1;
    scanf("%d",&t);
    while(t--)
    {
        long long p,q;
        scanf("%lld%lld",&p,&q);
        if(p <= q)
            printf("%lld\n",q-p);
        else
            printf("%lld\n",solve(q,p,0));
    }
    return 0;
}
