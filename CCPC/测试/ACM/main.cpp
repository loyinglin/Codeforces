#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long lld;
const int N = 100010;
const int M = 20*N;
vector<int> vec[M];
int vecnum = 0;
int id[20][N];

char s[N];
void build(int n) {
    while (vecnum) vec[vecnum--].clear(); // from 1
    vector<pair<char, int> > vt;
    for (int i = 1; i <= n; ++ i) {
        vt.push_back(make_pair(s[i], i));
    }
    sort(vt.begin(), vt.end());
    char last = 0;
    for (int i = 0; i < vt.size(); ++ i) {
        if(last!=vt[i].first)
            ++vecnum;
        vec[vecnum].push_back(vt[i].second);
        id[0][vt[i].second] = vecnum;
        last=vt[i].first;
    }
    
    for (int j = 1; (1<<j) <= n; ++ j) {
        vector<pair<lld, int> > vt;
        for (int i = 1; i + (1<<j)-1 <= n; ++ i) {
            vt.push_back(make_pair(1LL*id[j-1][i]*M+id[j-1][i+(1<<(j-1))], i));
        }
        sort(vt.begin(), vt.end());
        lld last = -1;
        for (int i = 0; i < vt.size(); ++ i) {
            if(last!=vt[i].first)
                ++vecnum;
            vec[vecnum].push_back(vt[i].second);
            id[j][vt[i].second] = vecnum;
            last=vt[i].first;
        }
    }
    
    
    //    for (int j = 0; (1<<j) <= n; ++ j) {
    //        for (int i = 1; i + (1<<j)-1 <= n; ++ i) {
    //            printf("%d\t", id[j][i]);
    //        }
    //        puts("");
    //    }
    
    
}
bool same (int a, int b, int len) {
    for (int i = 0; i < 20; ++ i) if (len&(1<<i)) {
        if (id[i][a]!=id[i][b]) return false;
        a+=(1<<i);
        b+=(1<<i);
    }
    return true;
}
int query(int l, int r) {
    if(l==r)return 1;
    if(l==r-1) {
        if(s[l]==s[r])return 1;
        else return 2;
    }
    int k = 20;
    while ((1<<k) >= r-l+1) k--; //[len/2, len)
    //cout<<"K " << k << endl;
    int num = id[k][l];
    auto it = lower_bound(vec[num].begin(), vec[num].end(), l+1);
    //    for (int i = 0; i < vec[num].size(); ++ i) {
    //        cout << vec[num][i] << " ";
    //    }cout << "VECEND"<<endl;
    //
    if(it!=vec[num].end() && (*it)+(1<<k)-1<=r) {
        //cout<<"IT "<<*it<<endl;
        if(same(l, *it, r-(*it)+1)) return *it-l;
    }
    //else puts("OUT");
    while (k--) {
        //cout<<"NOWK" << k << endl;
        num = id[k][l];
        //        for (int i = 0; i < vec[num].size(); ++ i) {
        //            cout << vec[num][i] << " ";
        //        }cout << "VECEND"<<endl;
        
        auto lit1 = lower_bound(vec[num].begin(), vec[num].end(), l);
        auto lit2 = lower_bound(vec[num].begin(), vec[num].end(), l+(1<<k));
        int ln = (int)(lit2-lit1);
        if(ln==0)continue;
        lit2--;
        
        auto rit1 = lower_bound(vec[num].begin(), vec[num].end(), r-(1<<(k+1))+2);
        auto rit2 = lower_bound(vec[num].begin(), vec[num].end(), r-(1<<k)+2);
        int rn = (int)(rit2-rit1);
        if(rn==0)continue;
        rit2--;
        
        int now = 0;
        
        if(ln > rn) {
            now = *rit1;
        }
        else if (ln>1) {
            int p = (*rit2-*rit1)/(rn-1);
            now = *rit2 - (ln-1)*p;
            //cout<<"P"<<p<<" "<<now<<endl;
        }
        else now = *rit2;
        if (same(l, now, r-now+1)) return now-l;
    }
    return r-l+1;
}

int ansLook(char *str, int n, int p) {
    for (int i = 1; i + p <= n; ++i) {
        if (str[i] != str[i + p]) {
            return 0;
        }
    }
    return 1;
}

int main () {
      
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int casnum; scanf("%d",&casnum);
    for (int cas=1;cas<=casnum;++cas) {
        scanf("%s", s+1);
        int n = (int)strlen(s+1);
        build(n);
        printf("Case #%d:\n",cas);
        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d%d",&l,&r);
            printf("%d\n",query(l,r));
        }
    }
    return 0;
}
/*
 111
 aaaaaxaaaaaa
 11
 1 12
 */
