//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1061/problem/B)
 **题目大意：**
 在n*m的网格中，每一列网格有一个高度a[i]，表示这一列网格的底部会有a[i]个方块。
 如下，这个图表示在4*4的网格中，分别有[2,1,3,1]个方块。
 
 现在假设从上面和从右边去看这个网格，会生成两个视图。
 希望拿掉尽可能多的方块，但是上视图和右视图保持不变。
 
 输入：
 第一行， 𝑛 and 𝑚 (1≤𝑛≤100000, 1≤𝑚≤1e9)
 第二行，n个数字𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑚)
 
 输出：
 一个数字，最大的可移除方块数量。
 
 Examples
 input
 5 6
 3 3 3 3 3
 output
 10
 input
 3 5
 1 2 4
 output
 3
 
 **题目解析：**
 
 直观的想法，是保留最高的一列，然后每列只保留一个格子，这样可以保证右视图和俯视图不变；
 但是这样不是最优解，比如说样例：
 00x
 0xx
 xxx
 按照上述的逻辑，保留最右边的一列，然后每列留一个，于是只能去掉中间列底部的x；
 但实际上，第三列的下面两个格子，也是处于可以去掉的部分。
 基于此思路进行优化，先保留最高的一列，对于每一列保留一个顶部的格子，并记录对应格子的高度h[i]；
 
 最后再针对格子的高度数组h[i]，从最高的列中计算有哪些格子可以去掉；
 为了方便计算，先对结果排个序。
 
 
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
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    lld sum = 0, ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (sum < a[i]) {
            ++sum;
        }
        if (a[i]) {
            ans += a[i] - 1;
        }
    }
    if (n >= 2 && sum >= a[n - 1]) {
        --sum;
    }
    cout << ans + sum << endl;
    
    
    return 0;
}
