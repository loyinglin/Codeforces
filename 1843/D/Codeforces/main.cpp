//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/D)
 **题目大意：**
 有n个节点的树，由n-1条边组成；
 已知根节点1为最上面节点，其他节点向下成长；
 现在有两个苹果，生长在节点x和节点y上面；
 苹果成熟后会顺着每个节点的边，朝着远离根节点的方向下落；
 如果某个节点是叶子节点，则会从树上落下；
 
 现在有q个询问，每次输入苹果生长节点x和节点y，问苹果落下的位置节点组合（posX，poxY)）的可能性，posX和posY分别表示节点X和节点Y苹果落下的节点位置；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例，第一行整数𝑛 (1≤𝑛≤2e5)
 接下来有n-1行表示相连边，每行两个整数 𝑢𝑖 and 𝑣𝑖 (1≤𝑢𝑖,𝑣𝑖≤𝑛 , 𝑢𝑖≠𝑣𝑖 )
 然后是整数𝑞，表示q个询问 (1≤𝑞≤2⋅1e5)
 接下来是q行整数，每行有整数 𝑥𝑖 and 𝑦𝑖 ，表示苹果生长节点 (1≤𝑥𝑖,𝑦𝑖≤𝑛 )
 
 
 **输出：**
 每个样例q行，输出每次询问的位置组合数；
 
 **Examples**
 **input**
 2
 5
 1 2
 3 4
 5 3
 3 2
 4
 3 4
 5 1
 4 4
 1 3
 3
 1 2
 1 3
 3
 1 1
 2 3
 3 1


 **output**
 2
 2
 1
 4
 4
 1
 2


 **题目解析：**
 题目看起来复杂，其实就是算每个节点的子树中，有多少个叶子节点，用数组cnt[i]来表示；
 由于苹果x和苹果y是相互独立的，最终答案就是cnt[x] ✖️cnt[y]；
 
 快速求cnt[i]可以用dfs，对于每个节点，统计其子节点的叶子节点数量，然后累加即可。
 
 
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
    static const lld N = 201010;
    vector<int> g[N];
    lld cnt[N];
    
    lld dfs(int u, int f) {
        int sub = 0;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v == f) continue;;
            sub += dfs(v, u);
        }
        cnt[u] = sub == 0 ? 1 : sub;
        return cnt[u];
    }
    
public:
    void solve() {
        lld t;
        cin >> t;
        while (t--) {
            lld n;
            cin >> n;
            for (int i = 1; i <= n; ++i) {
                g[i].clear();
            }
            for (int i = 0; i < n - 1; ++i) {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            dfs(1, 0);
            
            int q;
            cin >> q;
            while (q--) {
                int x, y;
                cin >> x >> y;
                cout << cnt[x] * cnt[y] << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
