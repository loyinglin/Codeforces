#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 200010;
int a[MAXN];

int main () {
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i) if (i!=s) {
        if (a[i]==0) {a[i]=MAXN+MAXN;}
    }
    if (a[s]!=0){ans=1;a[s]=0;}
    sort(a+1, a+n+1);
    int d = 0, j = n;
    for (int i = 1; i <= n; ++ i) {
        if (a[i] == -1) break;
        if (a[i] == MAXN+MAXN) {
            ans++; continue;
        }
        if (a[i] > d+1) {
            d++;
            a[j--] = -1;
            i--;
            ans ++;
            continue;
        }
        d = a[i];
    }
    printf("%d\n", ans);
    return 0;
}
