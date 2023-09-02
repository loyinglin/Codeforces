//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/F1)
 **题目大意：**
 有棵树初始时只有根节点1，该节点的值为1；
 现在可以往树上增加节点，每个节点新增时序号是当前树上最大节点的加1，节点的值为1或者-1；
 现在想知道，随着不断增加节点，对于某两个节点u和v之间，是否存在路径，使得经过的节点和为k；（每个节点只能经过一次，集合可以为0）
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例，第一行整数𝑛 (1≤𝑛≤2e5 )
 接下来有n行，每行有两种情况：
 情况1，由符号'+'和两个整数v x组成，表示增加一个新节点v，值为x  (x为-1或者1）
 情况2，由符号'?'和三个整数u v k组成，表示询问u到v的路径中，是否存在某一个段路径的值为k；（u=1，v保证是存在节点）
 
 
 **输出：**
 对于每一个询问，如果存在则输出YES，如果不存在则输出NO；
 
 **Examples**
 **input**
 1
 8
 + 1 -1
 ? 1 1 2
 ? 1 2 1
 + 1 1
 ? 1 3 -1
 ? 1 1 1
 ? 1 3 2
 ? 1 1 0

 **output**
 NO
 YES
 NO
 YES
 YES
 YES


 **题目解析：**
 先简化题目思考，假如不是树，而是线段；
 这个题目在考虑是否存在区间和为k时，其实就询问这条线段中，最大和是多少、最小和是多少；
 因为最大和就是每个节点的累加值，而节点的值为1和-1，证明能覆盖1、2、3、4、5、、、、MaxSum整个区间；
 
 于是题目简化为，在每新增一个节点时，我们计算以这个节点结尾时，路径的最大和dpMax、最小和dpMin；
 同时我们维护一个ansMax和ansMin表示从根节点1到该节点路径上，所有节点的dpMax的最大值、dpMin的最小值；
 假设n是新增节点序号，fat是新增节点的父节点序号，那么有状态转移方程：
 dpMax[n] = max(0, dpMax[fat]) + a[n];
 dpMin[n] = min(0, dpMin[fat]) + a[n];
 ansMax[n] = max(dpMax[n], ansMax[fat]);
 ansMin[n] = min(dpMin[n], ansMin[fat]);
 
 
 扩展思考：
 hard version是去掉u=1的限制，题目就复杂很多。
 通过lca算法找到u和v的共同祖先，在这条路径上，按照上述思路再处理一次，但是这样的复杂度达到了O(N)级别。
 没有太好的优化思路了。
 
 
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
    static const int inf = 1e9;
    vector<int> g[N];
    int dpMax[N], dpMin[N];
    int ansMax[N], ansMin[N];
    int a[N];
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n = 1;
            a[1] = dpMax[1] = dpMin[1] = 1;
            ansMax[1] = ansMin[1] = 1;
            int tmp;
            cin >> tmp;
            while (tmp--) {
                char c[10];
                cin >> c;
                if (c[0] == '+') {
                    int fat;
                    ++n;
                    cin >> fat >> a[n];
                    dpMax[n] = max(0, dpMax[fat]) + a[n];
                    dpMin[n] = min(0, dpMin[fat]) + a[n];
                    ansMax[n] = max(dpMax[n], ansMax[fat]);
                    ansMin[n] = min(dpMin[n], ansMin[fat]);
                }
                else {
                    int u, v, sum;
                    cin >> u >> v >> sum;
                    if ((ansMin[v] <= sum && sum <= ansMax[v]) || sum == 0) {
                        cout << "YES" << endl;
                    }
                    else {
                        cout << "NO" << endl;
                    }
                }
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
 
