//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1061/problem/B)
 **题目大意：**
 
 输入：
 输出：
 
 **Examples**
 **input**
 **output**
 
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
