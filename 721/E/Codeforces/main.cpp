//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/721/problem/E
 题目大意：
 在一条数轴上，Bob要学校（点0）走到家（点L），其中有n个路灯，路灯照耀的范围是(l[i], r[i])（路灯的范围不会重叠）；
 Bob会在灯亮的的范围内唱歌，每次唱的距离为p；（必须唱完，中间必须全部是在路灯照耀范围内）
 当Bob唱完一次的时候，下一次唱的地点必须满足以下其中一点：
 1、开始唱的地点和上一次唱结束的地点重合；
 2、开始唱的地点和上一次唱结束的地点距离>=t;
 
 问最多，能唱几次。
 (1 ≤ L ≤ 1e9, 0 ≤ n ≤ 100 000, 1 ≤ p ≤ 1e9, 1 ≤ t ≤ 1e9)
 
 Examples
 input
 17 2 2 6
 0 9
 13 17
 output
 5

 
 题目解析：
 先看清题目条件的重点：路灯(l[i], r[i])不会重叠，并且唱歌必须在路灯照耀范围内，两次唱歌的距离间隔要么为0，要么>=t；
 那么对于bob来说，每到一个路灯的范围内，他需要作出的是否唱歌的抉择：
 1、唱歌。需要看当前是否满足唱歌的条件：剩下的路灯距离是否足够p，当前位置和上次唱歌的位置是否满足唱歌的距离条件；
 2、不唱歌。对前面没有要求。
 
 那么这里就有一个典型的最优子结构：
 假设dp[i]为到距离i能唱的最多次数（并且要求是以唱歌结尾），且区间[i-p, i]是在路灯范围内，那么有：
 dp[i] 可以由 dp[i-p]转移过来；
 dp[i] 可以由 max(dp[0 ~ (i-t-p)]) + 1；
 这样的状态数为L，L是距离的范围；
 状态转移的复杂度同样为O(L);
 再回归到题目的数据范围，进行数据优化：
 其中的max(dp[0 ~ (i-t-p)])，可以采取dmax[i]来表示前i个位置的最优解，这样max(dp[0 ~ (i-t-p)])就等于dmax[i-t-p];
 这样状态转移的复杂度就将为O(1)，但是状态数仍有O(L)，而L非常大；
 考虑到路灯的区间性，dp[i]改为到距离r[i]能唱的最多次数，需要注意的是，这里不能要求到r[i]以唱歌结尾，因为以唱歌结尾不满足最优解，比如说(1, 3)的区间，唱歌p=2，此时最优解应该是1次，距离为(1, 2)，而不是唱歌结尾的(2, 3)；
 我们引入一个新的变量g[i]，表示dp[i]取到最优解的最左边距离；
 这样在状态转移的时候，假设是从dp[k]转移到dp[i]，那么从g[k]开始，连续t的距离不唱歌，然后剩下min(r[i]-l[i], r[i]-g[k]-t)的距离用于唱歌，这里我们用count(L)表示距离L能唱的次数，最后得到dp[i]取最优解的时候g[i]=max(l[i], g[k]+t) + count(L)*p;
 
 对于所有g[k] + t <= r[i]的k，都可以进行状态转移：
 dp[i] = max(dp[i], dp[k] + count(L));
 g[i] = g[k] + count(L) * p + t, L=min(r[i]-l[i], r[i]-g[k]-t)
 这样的状态数为O(N), 转移的复杂度为O(N)，总的复杂度仍为O(N^2);
 仍然需要进行优化，观察转移的过程，对于dp[k]是固定值，count(L)中的L会随着i的增加而增加，而当L很大之后，dp[k]较小的状态再进行最优化转移是无效的过程，因为dp[k+1]等会是更合适的解；
 状态的决策因素有两个,dp[k]和g[k]；
 对于dp[k]小，g[k]小的解，不能舍弃，因为g[k]小存在转移的可能；
 对于dp[k]大，g[k]大的解，不能舍弃，因为dp[k]大存在转移的可能；
 对于dp[k]小，g[k]大的解，舍弃；
 对于dp[k]大，g[k]小的解，不能舍弃，因为g[k]小和dp[k]大均存在转移的可能；
 以上这四种情况，就是dp[k]+count(L)在转移可能遇到的情况；
 count(L)函数是关于L单调递增的函数；
 因为对于i < j, 有 r[i] < l[j], 必然有 g[i] <= g[j]，对于i<j, 有count(L[i]) < count(L[j])；
 可以看出dp[k]+count(L)是具有决策单调性，同时每个决策有一个有效区间r[i]-g[k]-t>=0开始；
 
 那么维护一个决策的队列，根据dp[k]+count(L)可以算出当前所有的有效决策中的最优解；
 并且随着r[i]的的增加，从r[i]-g[k]-t>=的队列备选方案中，不断更新决策队列的dp[k]+count(L)；
 
 详见代码：
 
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
const int N = 110000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int l[N], r[N];
int dp[N];
int g[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, L, p, t;
    cin >> L >> n >> p >> t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    deque<int> q;
    q.push_back(0);
    g[0] = -t;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = -1;
        while (!q.empty() && g[q.front()] + t <= r[i]) { //每次检测是否进入下一个值的有效区间
            int nl = max(l[i], g[q.front()] + t), nr = r[i];
            if (dp[q.front()] + (nr - nl) / p > dp[i]) {
                dp[i] = dp[q.front()] + (nr - nl) / p;
                g[i] = nl + (nr - nl) / p * p;
            }
            else if (dp[q.front()] + (nr - nl) / p == dp[i]) {
                g[i] = min(g[i], nl + (nr - nl) / p * p); // 同样的dp值，只保留最小的g[i]值
            }
            k = q.front();
            q.pop_front();
        }
        if (k != -1) {
            q.push_front(k);
        }
        if (dp[i] > ans) {
            ans = dp[i];
            q.push_back(i);
        }
        
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    
    return 0;
}

/*
 10 3 2 2
 1 3
 4 8
 9 10
 
 
 
 20 3 3 3
 0 6
 7 8
 9 12
 
 
 
 1000 10 1 3
 0 1
 2 3
 4 5
 6 7
 8 9
 10 11
 12 13
 14 15
 16 17
 18 19
 
 
 
 */
