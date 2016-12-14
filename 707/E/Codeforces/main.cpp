//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/707/problem/E
 题目大意：输入k条链，链上的节点在n*m的矩阵上；
 每条链有len[i]个点，每个点的输入包括x、y、w表示在n*m矩阵上的坐标和权值。
 
 q次操作，操作1把链上的点翻转（权值由w变成0，或者从0变成w）；操作2，询问子矩阵内点的权值;
 操作2最多2000次；
 n,m,k = 2000, q=10^6.
 Examples
 input
 4 4 3
 5
 1 1 2
 1 2 3
 2 2 1
 2 1 4
 3 1 7
 4
 1 3 1
 2 3 3
 2 4 3
 1 4 1
 7
 4 1 1
 4 2 9
 3 2 8
 3 3 3
 4 3 4
 4 4 1
 3 4 1
 2
 ASK 2 2 3 3
 ASK 1 1 4 4
 output
 15
 52
 
 题目解析：
 先看最暴力的做法，对于每个switch，把点的值Switch；对于每个ask，遍历所有的链得出结果。
 优化部分，添加flag，标志每次switch，询问时再进行计算。
 每条链复杂度为O（Len），k条链的修改为O（n)*O(m)，询问的时间为O(n)*O(m)。
 总的复杂度为O(n*m*2000)*2=16*10e9。（*2是因为每次询问都要修改一次、求和一次）
 
 接着使用数据结构来优化。
 易知，子矩阵求和使用树状数组即可。求和操作可以优化为O(logN)*O(logM)。
 同样在询问的时候再来修改权值，那么有修改复杂度为O(logN)*O(logM)*O(N)*O(M)。
 求和复杂度可以忽略，总得复杂度为2000 * log2000 * log2000 * 2000 * 2000 = 8 * 10e10。 （虽然理论上q=10e6限制了当矩阵数为2000时，每次询问前的switch操作有限，但是一条链可以很长，对很长的链进行操作即可，所以最后的修改次数我们还是按N*M来计算）
 为什么变大了？
 
 因为每次询问前的修改操作变成耗时操作，如果题目每次在询问前都修改所有的值，复杂度会很高。
 继续优化。
 每次修改的都是同一个值（整条链为0，整条链恢复），那么可以预处理出这个值d[i][j]，表示第i条链对第j个子矩阵的贡献。
 这样就可以避免每次询问前修改值，使用之前预处理的计算值即可。
 复杂度为5*2000*2000*log2000*log2000 = 2billion；
 全部为加法，并且题目给出的时限为3s，可行。
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
const int N = 2010, M = 1000100, inf = 10110110;

struct Node {
    int type, x, y, w;
    Node(int x, int y, int w):x(x), y(y), w(w){};
    Node(){};
};
vector<Node> g[N];
lld d[N][N]; // 前i条链对第j个矩阵的贡献
lld flag[N]; // 标志是否关闭

int n, m, k;

inline void fastRead(int &x){
    char t = getchar();
    bool sign = true;
    while(t < '0' || t > '9') {
        if(t == '-') {
            sign = false;
        }
        t = getchar();
    }
    for(x = 0; t >= '0' && t <= '9'; t = getchar()) {
        x = x * 10 + t - '0';
    }
    if(!sign) {
        x = -x;
    }
}

lld tree[N][N];

struct Ask {
    int x1, y1, x2, y2;
    Ask(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){};
};
vector<Ask> matrix;
int ask[M];


char ch[10];

inline int lowbit(int x) {
    return x & -x;
}

void tree_add(int x,int y,int w){
    for(int i = x;i <= n; i += lowbit(i))
        for(int j = y; j <= m; j += lowbit(j))
            tree[i][j] += w;
}
lld tree_sum(int x,int y){
    lld sum = 0;
    for(int i = x; i > 0;i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            sum += tree[i][j];
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int len;
        fastRead(len);
        while (len--) {
            int x, y, w;
            fastRead(x);
            fastRead(y);
            fastRead(w);
            g[i].push_back(Node(x, y, w));
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        scanf("%s", ch);
        if (ch[0] == 'S') {
            fastRead(ask[i]);
        }
        else {
            int x1, y1, x2, y2;
            fastRead(x1);
            fastRead(y1);
            fastRead(x2);
            fastRead(y2);
            matrix.push_back(Ask(x1, y1, x2, y2));
        }
    }
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            tree_add(g[i][j].x, g[i][j].y, g[i][j].w);
        }
        for (int j = 0; j < matrix.size(); ++j) {
            d[i][j] = tree_sum(matrix[j].x2, matrix[j].y2) + tree_sum(matrix[j].x1 - 1, matrix[j].y1 - 1) - tree_sum(matrix[j].x1 - 1, matrix[j].y2) - tree_sum(matrix[j].x2, matrix[j].y1 - 1);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        if (ask[i] == 0) {
            lld ret = 0;
            for (int j = 0; j < k; ++j) { // 枚举k条链
                if (flag[j] == 0) {
                    if (j == 0) {
                        ret += d[j][ans];
                    }
                    else {
                        ret += d[j][ans] - d[j - 1][ans];
                    }
                }
            }
            cout << ret << endl;
            ++ans;
        }
        else {
            flag[ask[i] - 1] ^= 1;
        }
    }
    
    return 0;
}
