//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 XK Segments
 [题目链接](http://codeforces.com/contest/895/problem/B)
 **题目大意：**
 给出一个数组a，一个整数x。
 pair(i, j)的定义是： 满足a[i]<=a[j]，且存在k个整数y，a[i]<=y<=a[j] 和 y%x等于0；
 pair(i, j）等于pair(j, i) 当且仅当 i==j;
 求满足要求的所有pair数量。
 
 **输入数据：**
 n, x, k (1 ≤ n ≤ 1e5, 1 ≤ x ≤ 1e9, 0 ≤ k ≤ 1e9)
 a[i] (1 ≤ a[i] ≤ 1e9)
 
 >**Examples**
 **input**
 4 2 1
 1 3 5 7
 **output**
 3
 样例解释：
 pair(1,2), pair(2,3), pair(3,4)满足要求；
 当k==1，x==2时，对于pair(1,2)，满足a[1]<=a[2]，且存在1个整数y，满足a[1]<=y<=a[2] 和 y%2==0；（y=2）
 
 **题目解析：**
 根据题意，pair(i, j)要求在区间[a[i], a[j]]中存在k个x的倍数；
 假设pair(i, j)满足要求，且t是区间中x的倍数最小的一个，那么剩余满足%x==0的数字必然是t+x,t+2*x,t+3*x....直到t+(k-1)*x;
 
 为了方便，先将数组排个序；（从小到大）
 我们设p = ((a[i]+x-1)/x)*x; （大于等于a[i]，能被x整除的最小整数）
 那么取值区间就是[p+(k-1)*x, p+k*x)；
 特殊的，当k=0的时候，p+(k-1)*x=p+x，是不合理的，此时的区间应该是[a[i], p+k*x);（题目有要求,a[i]<=a[j])
 故而答案是[max(a[i], p+(k-1)*x, p+k*x)；
 
  **思考🤔：**
 trick: long long。
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, x, k;
    cin >> n >> x >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    lld ans = 0;
    for (int i = 0; i < n; ++i) {
        lld p = (a[i] + x - 1) / x * x;
        ans += lower_bound(a, a + n, p + k * x) - lower_bound(a, a + n, max(a[i], p + (k - 1) * x));
    }
    cout << ans << endl;
    
    return 0;
}
