//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/G)
 **题目大意：**
 小明生病了，出现了若干症状，现在需要吃药治疗；
 所有症状一共有n种，小明的症状可以用由字符0和1组成的字符串s来表示，第i个字符为0表示第i种症状未出现，第i个字符为1表示第i种症状出现；
 现在有m种药，每种药可以治疗若干症状，但是也会造成若干副作用的症状，分别用字符0和字符1组成的字符串x和字符串y表示；（规则同上）
 已知每种药只能单独吃，并且吃完需要一段时间；
 想知道小明消除所有症状需要的时间。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例的第一行整数𝑛,𝑚(1≤𝑛≤10,1≤𝑚≤1000)
 第二行是长度为n的字符串s，表示小明已经出现的症状
 接下来m · 3行，表示m种药品
 第一行，整数𝑑，表示该药吃完需要的时间(1≤𝑑≤1000)
 第二行，字符串x，表示该药能治疗的症状
 第三行，字符串y，表示该药会产生的副作用症状
 
 
 **输出：**
 每个样例一行，输出小明消除所有症状需要的时间；如果无解，则输出-1；
 
 
 **Examples**
 **input**
 4
 5 4
 10011
 3
 10000
 00110
 3
 00101
 00000
 3
 01010
 00100
 5
 11010
 00100
 4 1
 0000
 10
 1011
 0100
 2 2
 11
 2
 10
 01
 3
 01
 10
 2 3
 11
 3
 01
 10
 3
 10
 00
 4
 10
 01



 **output**
 8
 0
 -1
 6



 
 **题目解析：**
 假如有一种药，那么小明就只能吃这种药；
 假如有两种药A和B，那么小明就会有两个选择，先A后B，先B后A；
 有没有可能出现一种药吃两次的情况？不会，因为假如出现某种药吃两次，那么第一次吃的药，效果会被第二次药替代，因为两次吃效用、副作用是一样的。
 假如有多种药A/B/C...，此时情况就复杂很多，需要通过搜索法来进行枚举，这样的复杂度是阶乘量级；
 
 考虑到症状数量不多，我们将所有可能的症状梳理出来，发现最多就只有1024种情况（n的最大值为10）；
 假如每种情况是一个点，那么每种药可以抽象为从情况a变成情况b的一条边，这样就建立了一张图。
 而题目想要的，就是从初始状态的点，走到点0（全部症状为0）的最短路。
 这里选用迪杰斯特拉算法来实现。
 
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
    static const int inf = 0x7ffffff;
    static const int N = 1030;
    int g[N][N];
    int strToInt(string s) {
        int ret = 0, tmp = 1;
        while (s.length()) {
            ret += (s[s.length() - 1] - '0') * tmp;
            tmp *= 2;
            s.pop_back();
        }
        return ret;
    }
    string intToString(int t, int n) {
        string ret(n, '0');
        int tmp = n - 1;
        while (t) {
            ret[tmp] = '1';
            --tmp;
            t /= 2;
        }
        return ret;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            int sum = (1 << n);
            
            for (int i = 0; i <= sum; ++i) {
                for (int j = 0; j <= sum; ++j)
                g[i][j] = inf;
            }
            string str;
            cin >> str;
            for (int k = 1; k <= m; ++k) {
                int cost;
                string x, y;
                cin >> cost >> x >> y;
                for (int u = 0; u < sum; ++u) {
                    string s;
                    for (int j = 0; j < n; ++j) {
                        if ((1 << j) & u) s.insert(s.begin(), '1');
                        else s.insert(s.begin(), '0');
                    }
                    for (int j = 0; j < n; ++j) {
                        s[j] = '0' + ((s[j] == '1') && (x[j] == '0'));
                    }
                    for (int j = 0; j < n; ++j) {
                        s[j] = '0' + ((s[j] == '1') || (y[j] == '1'));
                    }
                    int v = strToInt(s);
                    g[u][v] = min(g[u][v], cost);
//                    cout << u << " to " << v << " cost " << g[u][v]  << endl;
                }
            }
            priority_queue<pair<int, int> > q; // dis, u
            
            int u = strToInt(str);
            vector<int> dis(N), vis(N);
            for (int i = 0; i < N; ++i) dis[i] = inf;
            dis[u] = 0;
            q.push(make_pair(0, u));
            while (!q.empty()) {
                pair<int, int> top = q.top();
                q.pop();
                u = top.second;
                if (!vis[u]) {
                    vis[u] = 1;
                    // not vis
                    for (int v = 0; v < sum; ++v) {
                        if (g[u][v] != inf) {
                            dis[v] = min(dis[v], dis[u] + g[u][v]);
                            if (!vis[v]) q.push(make_pair(-dis[v], v));
                        }
                    }
                }
            }
            if (dis[0] == inf) {
                dis[0] = -1;
            }
            cout << dis[0] << endl;
            
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
