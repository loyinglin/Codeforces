//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/812/problem/B
 题目大意：
 在一栋大厦里，有n层，每层有m个房间，同时每层的左右两侧都存在一个楼梯；
 有些人晚上离开大厦没有关灯，小明是大厦的管理员，每天晚上需要把所有的房间的灯关掉；
 输入n行数据，每行有m+2个数字，第一列和最后一列表示楼梯，第2列到第m+1列表示房间的灯（1表示亮着）；
 小明一开始在最底层（第n行）左边的楼梯的位置，假设小明上一层楼梯的时间为1，经过一个房间的时间也为1，关灯的不耗费时间；
 并且小明会把这一行的灯都关掉，再走到上一层。
 
 问，小明最少需要多少时间，才能关掉所有的灯；
 
 Example
 input
 3 4
 001000
 000010
 000010
 output
 12

 
 
 
 题目解析：
 典型的动态规划。
 每次的状态只有两种：在最左或者最右；
 trick就是可能某一层为全部为0.
 
 
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
const int N = 110, M = 3010100, inf = 0xfffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
char a[N][N];
int dp[N][2];
int lMax[N], rMax[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '1') {
                rMax[i] = j;
            }
        }
        for (int j = m; j >= 1; --j) {
            if (a[i][j] == '1') {
                lMax[i] = m - j + 1;
            }
        }
    }
    
    dp[n + 1][0] = -1, dp[n + 1][1] = inf;
    for (int i = n; i >= 1; --i) {
        int upStep = 1;
        // 1 从右到左，从左到左
        dp[i][0] = dp[i + 1][1] + upStep + (m + 1);
        dp[i][0] = min(dp[i][0], dp[i + 1][0] + upStep + rMax[i] * 2);
        
        //
        dp[i][1] = dp[i + 1][0] + upStep + (m + 1);
        dp[i][1] = min(dp[i][1], dp[i + 1][1] + upStep + lMax[i] * 2);
    }
    
    int cur = 1;
    while (cur < n && lMax[cur] == 0) { // 找到最后一层有灯的
        ++cur;
    }
    
    cout << min(dp[cur + 1][0] + rMax[cur] + 1, dp[cur + 1][1] + lMax[cur] + 1) << endl;
    
    
    
    
    return 0;
}
