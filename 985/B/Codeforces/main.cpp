//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Chess Placing
 [题目链接](http://codeforces.com/contest/985/problem/B)
 **题目大意：**
 有n个开关，m个灯；
 开始时，m个灯是处于关闭状态；
 一个开关可以对应多个灯，如果按下按钮可能会有多个灯被打开，我们用二维数组a[i][j]来表示第i个开关按下之后第j个灯的状态，1表示打开，0表示无反应；
 灯就会一直处于打开的状态，即使其他控制这个灯的开关被按下；
 问，是否存在无用开关（即使不用这个开关也能打开m个灯）？
 如果有，输出YES；否则输出NO。
 
 
 
 
 **输入数据：**
 第一行 n and m (1 ≤ n, m ≤ 2000)
 接下来是n*m的矩阵，表示a[i][j]；
 
 
 >**Examples**
 **input**
 4 5
 10101
 01000
 00111
 10000
 **output**
 YES
 
 **题目解析：**
 枚举每个开关不打开，其他开关全部按下的情况，看是否灯全亮。
 但是这样的复杂度是O(N^3)=2000^3=8*10^9，这个数量级已经超过时间限制。
 留意到，这个复杂度里面有很多是重复计算，比如说我们在枚举开关2、3不打开的时候，会计算俩遍第1个开关对应的灯；
 那么这个算法存在O(N)的优化空间。
 从这里去思考，可以得到优化方案：
 先把每个灯能控制的开关数加起来，用ans[i]表示控制灯i亮的开关数量；
 当枚举某个开关不打开的时候，只要看看他控制的灯是不是ans[i]>1即可！
 
 
 
 
 
 
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
const int N = 2100, M = 3010100, inf = 0x7fffffff;
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
int ans[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> (a[i] + 1);
    }
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans[j] += (a[i][j] == '1');
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int ok = 1;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '1' && ans[j] <= 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    

    cout << "NO" << endl;
    return 0;
}
