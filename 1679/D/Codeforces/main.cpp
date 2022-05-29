//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1679/problem/D)
 **题目大意：**
 有一个n个节点的有向图，每个节点有一个数字a[i]；
 现在可以选择某个节点，从这个节点开始沿着有向边走，记录每个访问到的节点，并将这个访问顺序记录下来；
 现在想知道，如果需要访问k个节点，访问顺序中的节点数字最大值的最小值是多少；
 
  **输入：**
 整数  𝑛, 𝑚 and 𝑘 (1≤𝑛≤2⋅1e5, 0≤𝑚≤2⋅1e5, 1≤𝑘≤10e18)
 接下来n个整数 𝑎𝑖 (1≤𝑎𝑖≤1e9)
 接下来是m条行，每行有整数 𝑢 and 𝑣 ，表示u到v的边(1≤𝑢≠𝑣≤𝑛)
 题目保证没有指向自己的边，也没有多重边；
  
 **输出：**
 输出k个节点，节点数字最大值的最小值是多少；
 如果无法访问到k个节点，则输出-1；
 
 
 **Examples**
 **input**
 6 7 4
 1 10 2 3 4 5
 1 2
 1 3
 3 4
 4 5
 5 6
 6 2
 2 5
 
 **output**
 4
 
 **题目解析：**
 先用朴素的思维来分析，假如我们需要访问1个节点，那么就是寻找节点的最小值；
 如果是需要访问2个节点，那么问题就变得复杂，因为节点2->3的解是比 节点1->4的解更优；那么节点的最小值就失去了意义；
 如果是想遍历整个图，并且在遍历过程中去保留这个最大值的最小，无疑是非常复杂的；
 
 那么换一种思想，假如我用二分来处理这个最大值，得到mid，如果a[i]<=mid认为a[i]可以访问，如果a[i]>mid则认为节点不可方案；
 题目变成在有向图中，询问遍历步数最多是否能到k；
 
 先不考虑环的情况，在一个有向图中要去判断遍历步数最多情况，可以枚举所有起点出发的情况，然后通过深度优先搜索来记录遍历过程中的步数；
 当出现环的时候，我们可以把步数设置为一个很大的值，这样也可以统一逻辑处理。
 
 那么，问题又变成如何在有向图中判断环的存在？
 当我们在深度优先遍历的过程中，假如当前点是u，下一个节点是v，此时有两种情况，v是已经访问过，v还没访问过；
 如果v没有访问过，那么就访问v即可；
 如果v已经访问过，此时又有两种情况，如果v已经访问过，但是还在当前的递归栈中，则证明v已经可以和u构成环；（step[u]=inf，inf表示一个很大值）
 如果是v已经访问过，但是和当前递归栈中没有关系，怎么v只是普通访问过的节点；（此时step[u]=max(step[u], step[v]+1);
 
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

class Solution {
    static const lld N = 201001;
    static const lld inf = 0x7fff7fff3fff7fff;
    lld a[N];
    int vis[N]; // 0表示没访问，1表示访问中，2表示访问后
    lld step[N], n;
    vector<lld> g[N];
    
    void dfs(lld u, lld cur, lld mid) {
        vis[u] = 1;
        step[u] = 1;
        for (lld i = 0; i < g[u].size(); ++i) {
            lld v = g[u][i];
            if (a[v] > mid) {
                continue;
            }
            if (!vis[v]) {
                dfs(v, cur + 1, mid);
                step[u] = max(step[u], step[v] + 1);
            }
            else {
                if (vis[v] == 1) {
                    step[u] = inf;
                }
                else {
                    step[u] = max(step[u], step[v] + 1);
                }
            }
        }
        vis[u] = 2;
    }
    
    bool check(lld mid, lld k) {
        memset(vis, 0, sizeof(vis));
        memset(step, 0, sizeof(step));
        dfs(0, 0, mid);
        for (lld i = 1; i <= n; ++i) {
            if (a[i] > mid) {
                continue;;
            }
            if (step[i] >= k) {
                return true;
            }
        }
        return false;
    }

public:
    void solve() {
        lld m, k;
        cin >> n >> m >> k;
        lld l = 0, r = 0x7fffffff;
        for (lld i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            r = max(r, a[i]);
        }
        for (lld i = 0; i < m; ++i) {
            lld u, v;
            scanf("%lld%lld", &u, &v);
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
            g[0].push_back(i);
        }
        lld ans = -1;
        while (l <= r) {
            lld mid = (l + r) / 2;
            if (check(mid, k)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 173070 169783 989451008964122129
 451276734 456804188 91403220 755410874
 
 
 6 7 1
 10 1 2 3 4 5
 1 2
 1 3
 3 4
 4 5
 5 6
 6 2
 2 5
 
 4 4 4
 1 2 3 4
 1 3
 1 2
 3 4
 4 2
 
 */
