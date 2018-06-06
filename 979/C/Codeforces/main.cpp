//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/979/problem/C)
 **题目大意：**
 Kuro生活在一个有n个小镇的国家，n个小镇由n-1条路相连，任意两个小镇都可以通过这些路相通。
 n个小镇里面有两个特殊的小镇a和b，小镇a养了很多花，小镇b养了很多蜜蜂；
 如果先经过小镇a，再经过小镇b，就会在小镇b吸引到很多蜜蜂，造成很严重的后果。
 Kuro想定一条旅游路线（u，v）从小镇u到小镇v，每个小镇只能经过一次；（但不能先经过小镇a，再经过小镇b）
 问，有多少条可能的路线？（u到v和v到u是不同的路线）
 
 
 输入：
 第一行：n , x and y，表示小镇数量和小镇a、b ( 1 ≤ n ≤ 3 * 1e5 , 1 ≤ x , y ≤ n , x ≠ y )
 接下来n-1行，每行两个数字u，v 表明u和v之间存在相通。
 
 输出：
 可能的路线数量。
 
 
 **Examples**
 **input**
 3 1 3
 1 2
 2 3
 **output**
 5
 
 **题目解析：**
 如果不考虑小镇a、b的影响，那么有n*(n-1)的路线；
 那么先经过小镇a，再经过小镇b的路线有哪些呢？
 小镇a到小镇b的路只有一条，这一条路把n个小镇分成两部分，小镇a部分（假设数量是sumA) 和 小镇b部分（假设数量是sumB）。
 那么先经过a再经过b的路线有sumA*sumB。
 那么ans=n*(n-1)-sumA*sumB。
 
  
 **思考🤔：**
 
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<lld> g[N];
int vis[N];
lld cnt[N];

lld dfs(lld u) {
    vis[u] = 1;
    lld sum = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        lld v = g[u][i];
        if (!vis[v]) {
            sum += dfs(v);
        }
    }
    return cnt[u] = sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, x, y;
    cin >> n >> x >> y;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    lld ans = n * 1LL * (n - 1);
    
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        lld v = g[x][i];
        dfs(v);
        if (vis[y]) { // 这个子树包括y
            lld sumA = n - cnt[v];
            lld sumB = cnt[y];
            ans -= sumA * sumB;
            break;
        }
    }
    
    cout << ans << endl;
    
    
    
    
    return 0;
}
