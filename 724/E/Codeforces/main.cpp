//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/724/problem/E
 题目大意：
 n个城市，单向边；每个城市都会产出p[i]单位的货物；每个城市最多卖出s[i]单位的货物；
 对于所有编号为 i、j的城市（1 <= i < j <= n） 都存在一条边i=>j，能运送一次，最多为c单位；
 
 输入n、c以及p[i] 和 s[i]，输出能卖出去的最大单位数；
 
 input
 3 0
 1 2 3
 3 2 1
 output
 4
 
 解释：不能运输，那么只能卖出1 + 2 + 1 = 4 单位；
 
 N=1W
 
 
 题目解析：
 题目给出的就是网络流，但是N=1w，边的数量非常多；
 按照题目给的条件建图：
 
        点           流量
    src 到 n个城市    p[i]
 n个城市 到 dest      s[i]
  i城市 到 i+1的城市   c
 
 容易知道最大流=最小割，在给出题目中因为所有的城市都存在边到src和dest，
 那么必然存在边p[i]或者s[i]为割，而且流量为c的边必然不会在最小割内；
 （因为如果p[i] 和 s[i]都不在割内，那么点i就和src与dest相连）
 
 那么问题变成：
 
 dp[i][j] 表示最小割中，前i个城市有j个城市与src相连的最小割容量；
 dp[i][j] = min(dp[i-1][j-1] + s[i], dp[i-1][j] + j*c + p[i]);
 
 dp[i-1][j-1] + s[i] 表示第i个城市直接连src的边，加入最小割；
 dp[i-1][j]+ j*c + p[i] 表示i城市连src的边不加入最小割，那么为了断开点i与dest的关系，需要断开前i个点中，所有与src相连的点到i的边（c*j），还有p[i]的边；
 
 
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
const int N = 222222, M = 22;

int p[N], s[N];
lld f[N];


int main(int argc, const char * argv[]) {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        f[i] = 1LL << 62;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j; --j) {
            f[j] = min(f[j-1] + s[i], f[j] + (lld)j * c + p[i]);
        }
        f[0] += p[i];
    }
    lld ans = f[0];
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    
    
    
    return 0;
}
