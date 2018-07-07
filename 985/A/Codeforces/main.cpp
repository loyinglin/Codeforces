//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Chess Placing
 [题目链接](http://codeforces.com/contest/985/problem/A)
 **题目大意：**
 有1xn的棋盘（n为偶数），棋盘上的格子颜色为黑白交替；（BWBWBW..BW这样分布，B表示黑，W表示白)
 现在已经有n/2个棋子放置在棋盘上，每个格子只能放置1个棋子；
 每一步可以移动一个棋子向左或者向右，但是不能移到已经被棋子占有的格子；
 现在需要把棋子移动到同一个颜色的格子上面，问最少需要多少步。
 
 
 **输入数据：**
 第一行 n (2 ≤ n ≤ 100, n是偶数)
 第二行 n/2个数字p[i]，表示已经放置棋子的格子 (1 ≤ p[i] ≤ n)
 
 
 >**Examples**
 **input**
 6
 1 2 6
 **output**
 2
 
 **题目解析：**
 只有两种可能，全部移到黑色or全部移到白色的代价；
 因为数量较小，直接算出来两种可能的最小步数。
 
 怎么计算移到黑色的最小步数？
 因为只有n/2个黑色格子，最终的布局必然是1、3、5、7这样的格局；
 那么可以采用这样的策略：
 先把第一个移到1、第二个移到3...
 
 
 **思考🤔：**
 trick: 给出的位置p[i]是无序的。
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
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
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n/2; ++i) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n / 2);
    
    int costB = 0, costW = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            costB += abs(i - a[(i+1)/2]);
        }
        else {
            costW += abs(i - a[(i+1)/2]);
        }
    }
    
    cout << min(costB, costW) << endl;
    
    
    return 0;
}
