//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/707/problem/D
 题目大意：n*m的格子，q个操作 (1 ≤ n, m ≤ 10e3, 1 ≤ q ≤ 10e5) 每次有4种操作：
 1 i j, a[i][j] = 1
 2 i j, a[i][j] = 0
 3 i,   for j in a[i], a[i][j] = !a[i][j]
 4 k,   返回操作到第k次的状态，k=0表示起始状态。
 每次操作后输出当前格子为1的数量。
 
 Examples
 input
 2 3 3
 1 1 1
 3 2
 4 0
 output
 1
 4
 0
 
 题目解析：
 操作1、2比较简单，操作3是组操作，设置flag[i]表示第i行在最终结算时是否翻转，那么有
 操作1为a[i][j] = !flag[i].
 操作2为a[i][j] = flag[i].
 操作3为flag[i] = !flag[i].
 
 操作4较为复杂，回到操作k，k为之前的操作。
 考虑到题目对k没有限制，那么k可以为之前的某个回退操作，从而产生递归回退的效果；
 同时回退到操作i之后，下一步可以再回退到操作j，这样线性的操作不可取。
 但是单个操作只会是一个线性的分支，整个操作序列可以形成多个线性的分支，汇总在一起就是一颗树的表现。
 对于第i个操作，操作完毕后的状态为j，连一条边从i到j，表示从第i个操作完之后会进入操作j的状态。
 那么对操作1、2、3，i会连上一条边到i+1；操作4，i会连上一条边到k。
 对于某一个操作，先执行，然后dfs，最后撤销执行即可。
 
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
const int N = 1100, M = 100100, inf = 10110110;

struct Node {
    int type, x, y, k;
}node[M];
int flag[N]; // 标志第i行是否翻转
int dfn[M]; // 第i个操作是否已经执行
int a[N][N]; // a[i][j]
int num[N], m; //第i行为1的数量
int sum;    // 当前数量
int ans[M]; // 第i个操作答案
vector<int> g[M]; // 顶点


void lookNext(int k) {
    dfn[k] = 1;
    for (int i = 0; i < g[k].size(); ++i) {
        int u = g[k][i];
        if (dfn[u] == 0) {
            if (node[u].type == 1) {
                if (a[node[u].x][node[u].y] == flag[node[u].x]) {
                    ++sum;
                    ++num[node[u].x];
                    ans[u] = sum;
                    a[node[u].x][node[u].y] = !flag[node[u].x];
                    lookNext(u);
                    a[node[u].x][node[u].y] = flag[node[u].x];
                    --num[node[u].x];
                    --sum;
                }
                else {
                    ans[u] = sum;
                    lookNext(u);
                }
            }
            else if (node[u].type == 2) {
                if (a[node[u].x][node[u].y] != flag[node[u].x]) {
                    --sum;
                    --num[node[u].x];
                    a[node[u].x][node[u].y] = flag[node[u].x];
                    ans[u] = sum;
                    lookNext(u);
                    a[node[u].x][node[u].y] = !flag[node[u].x];
                    ++num[node[u].x];
                    ++sum;
                }
                else {
                    ans[u] = sum;
                    lookNext(u);
                }
            }
            else if (node[u].type == 3) {
                sum = sum - num[node[u].x] + (m - num[node[u].x]);
                num[node[u].x] = m - num[node[u].x];
                flag[node[u].x] = !flag[node[u].x];
                ans[u] = sum;
                lookNext(u);
                flag[node[u].x] = !flag[node[u].x];
                num[node[u].x] = m - num[node[u].x];
                sum = sum + num[node[u].x] - (m - num[node[u].x]);
            }
            else if (node[u].type == 4) {
                ans[u] = sum;
                lookNext(u);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> node[i].type;
        if (node[i].type == 1 || node[i].type == 2) {
            cin >> node[i].x >> node[i].y;
        }
        else if (node[i].type == 3) {
            cin >> node[i].x;
        }
        else {
            cin >> node[i].k;
        }
        if (node[i].type == 4) {
            g[node[i].k].push_back(i);
        }
        else {
            g[i - 1].push_back(i);
        }
    }
    
    lookNext(0);
    
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
