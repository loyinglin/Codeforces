//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1180/problem/D)
 **题目大意：**
有 n x m 的网格，小明站在第一个格子(1,1）；
小明可以跳到一个还未访问过格子，每次会产生一个向量(dx, dy)。
当小明访问完所有的格子时，希望所有的向量都是不重复的。
 
 输入：
 一行，𝑛,𝑚 (1≤𝑛⋅𝑚≤10^6)
 
 输出：
 如果无解，输出 -1.
 如果有解，按照小明的访问顺序输出每个格子的坐标，一共n x m行，每行两个数字𝑥𝑖,𝑦𝑖 (1≤𝑥𝑖≤𝑛,1≤𝑦𝑖≤𝑚)
 
 
 **题目解析：**
 这是一道典型的构造类题目，需要我们去构造一个走法。
 按照题目的要求，每次访问格子的向量不重复，那么产生越大的向量越好，因为越大越不会重复。
 基于思路，我们可以知道，(1, 1)往(n, m)跳是最优的；
 其次，(n, m)往(1, 2)跳也是OK的；
 再接着，（1，2）可以往(n, m-1)跳；
 循环往返，就可以得到一个序列。
 
 以4x4的格子为例，走完第一行和最后一行之后，可以得到以下的向量：
 (3, 3)
 (-2, -3)
 (1, 3)
 (0, -3)
 (-1, 3)
 (2, -3)
 可以看出来，这些向量都没有重复。
 那么同理，对于第二行和倒数第二行，向量也不会重复。

 综上，可以知道这个走法是合理的。
 题目也不存在无解的情况。
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int r[N];
int n, m;
vector<vector<int>> a;
int topX, topY, bottomX, bottomY;
int topDir, bottomDir;

vector<pair<int, int> > ans;

int main(int argc, const char * argv[]) {
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<int> t(m);
        a.push_back(t);
    }
    
    topX = topY = 0;
    bottomX = n - 1, bottomY = m - 1;
    topDir = 1;
    bottomDir = -1;
    bool isBottom = 0;
    while (ans.size() < n * m) {
        if (isBottom) { // jump bottom
            ans.push_back(make_pair(bottomX, bottomY));
            
            bottomY += bottomDir;
            if (bottomY < 0) {
                bottomY = 0;
                bottomX--;
                bottomDir = -bottomDir;
            }
            else if (bottomY >= m) {
                bottomY = m - 1;
                bottomX--;
                bottomDir = -bottomDir;
            }
        }
        else {
            ans.push_back(make_pair(topX, topY));
            
            topY += topDir;
            if (topY < 0) {
                topY = 0;
                topX++;
                topDir = -topDir;
            }
            else if (topY >= m) {
                topY = m - 1;
                topX++;
                topDir = -topDir;
            }
        }
        isBottom = !isBottom;
    }
    
    for (int i = 0; i < n * m; ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    
    
    return 0;
}
