//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1684/problem/D)
 **题目大意：**
 给出n x m的矩阵a，a[i][j]是一个整数；
 现在需要选择任意两列进行交换，现在想知道是否存在一种交换方式，满足：
 交换之后，每一行的元素，从左到右都是非递减的；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤100)
 每个样例第一行是整数𝑛 and 𝑚 (1≤𝑛,𝑚≤2⋅1e5)
 接下来会有n行m列的整数 𝑎[𝑖,𝑗] (1≤𝑎[𝑖,𝑗]≤1e9)；
  
 **输出：**
 每个样例一行，输出满足的交换位置；
 如果无解则输出-1；
 
 
 **Examples**
 **input**
 5
 4 4
 8 7 1 4
 4 1
 5 10 11 5
 7 5
 8 2 5 15 11 2 8
 6 3
 1 2 3 4 5 6
 1 1
 7
 
 **output**
 0
 21
 9
 6
 0

 
 **题目解析：**
 
 6
 7 1
 8 2 5 15 11 2 8
 7 2
 8 2 5 15 11 2 8
 7 3
 8 2 5 15 11 2 8
 7 4
 8 2 5 15 11 2 8
 7 5
 8 2 5 15 11 2 8
 7 6
 8 2 5 15 11 2 8

 
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
    static const int N = 201010;
    int a[N];
    int b[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                b[i] = 0;
            }
            priority_queue<pair<int, int>> q;
            int size = 0;
            
            for (int i = n - 1; i >= 0; --i) {
                if (m) {
                    --m;
                    q.push(make_pair(-a[i], i));
                }
                else {
                    int top = -q.top().first;
                    if (top < a[i] - size - 1) {
                        q.pop();
                        q.push(make_pair(-(a[i] - size - 1), i));
                    }
                    ++size;
                }
            }
            while (!q.empty()) {
                int pos = q.top().second;
                b[pos] = 1;
                q.pop();
            }
            
            lld sum = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (b[i]) {
                    ++cnt;
                }
                else {
                    sum += a[i] + cnt;
                }
            }
            cout << sum << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 */
