#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 200001;
const int MAX_K = 200001;




struct Node
{
    int c;
    int v;
};

int n, k, s, t;
Node a[MAX_N];
int b[MAX_N];


int Min(int num1, int num2)
{
    if(num1 < num2) return num1;
    return num2;
}
bool Cmp(Node &node1, Node &node2)
{
    if(node1.v < node2.v) return true;
    else if(node1.v == node2.v)
        return node1.c <= node2.c;
    return false;
}
int Calc(int idx)
{
    int minT = 0;
    for(int i = 0; i <= k; ++i)
    {
        int dist = b[i+1] - b[i];
        int maxY = a[idx].v - dist;
        int minY = Min(maxY, dist);
        //printf("%d %d\n", dist, minY);
        if(minY < 0) return -1;
        minT += 2 * dist - minY;
    }
    //printf("minT: %d\n", minT);
    if(minT > t)
        return -1;
    return 1;
}

int BSearch()
{
    b[k+1] = s;
    int st = 0;
    int end = n - 1;
    bool f = false;
    while(st <= end)
    {
        int mid = (st + end) >> 1;
        int ret = Calc(mid);
        //printf("%d %d\n", ret, mid);
        if(ret >= 0)
        {
            end = mid - 1;
            f = true;
        }
        else
            st = mid + 1;
    }
    if(!f) return -1;
    return st;
}

int main()
{
    scanf("%d %d %d %d", &n, &k, &s, &t);
    for(int i = 0; i < n; ++i)
        scanf("%d %d", &a[i].c, &a[i].v);
    for(int i = 1; i <= k; ++i)
        scanf("%d", &b[i]);
    
    sort(a, a + n, Cmp);
    int minC = -1;
    for(int i = n - 1; i >= 0; --i)
    {
        if(minC == -1)
        {
            minC = a[i].c;
            continue;
        }
        if(a[i].c >= minC)
        {
            --n;
            swap(a[i], a[n]);
        }
        else
        {
            minC = a[i].c;
        }
    }
        
    sort(a, a + n, Cmp);
    sort(b + 1, b + k + 1);
    int idx = BSearch();
    //printf("%d\n", idx);
    if(idx < 0)
        printf("-1\n");
    else
        printf("%d\n", a[idx].c);
    return 0;
}
