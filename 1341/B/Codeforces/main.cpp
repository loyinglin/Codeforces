//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1341/problem/B)
 **题目大意：**
 n个数字的数组，如果某个数字比相邻左右两个数字大，则称为峰；
 
 从n个数字里面选出连续的k个数字区间，希望包括尽可能多的峰，一个峰可以把区间两部分；
 如果有多种可能，则使得第一个数字的位置尽可能小；
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例第一行，整数n和k  (3≤𝑘≤𝑛≤2⋅1e5)
 第二行n个整数, 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤1e9, 𝑎𝑖 ≠ 𝑎[𝑖+1])
 

 
 **输出：**
 每个样例一行，输出整数t和l，分别表示k个连续数字最多能被峰分为几部分，以及区间开始位置；
 
 **Examples**
 **input**
 2
 8 6
 1 2 4 1 2 4 1 2
 5 3
 3 2 3 2 1

 
 **output**
 3 2
 2 2
 
 样例解释：
 样例一选择的数字区间是[2, 7]，峰的数字有4和4，可以把区间分为3部分，区间开始位置是2；
 样例二的区间是[2, 4]，峰的数字只有3，可以把区间氛围2部分，区间开始位置是2；
 
 **题目解析：**
 先找出所有的山峰，假设是m个，遍历这些山峰；
 对于第1个山峰，直接放入队列q；
 对于第2个山峰，直接放入队列q，接下来判断队列中的距离是否超过k：如果满足q.back() - q.front() + 2 >= k 则表示队列中山峰已经无法用连续的k个数字来包括；
 此时需要pop掉队头的山峰，也是最早加入的数字。
 
 每加入一个数字到山峰，检查完队列数字的合法性，接着计算这个队列的结果是否更优；
 
 
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
const int N = 300010, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

int a[N];
queue<int> q;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        while (!q.empty()) {
            q.pop();
        }
        
        int ans = 0, start = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                q.push(i);
                while (q.back() - q.front() + 2 >= k) {
                    q.pop();
                }
                if (q.size() > ans) {
                    ans = q.size();
                    start = q.back() + 1 - (k - 1);
                }
            }
        }
        cout << ans + 1 << " " << max(0, start) + 1 << endl;
    }   
    
    return 0;
}


/**
 
 5
 8 6
 1 2 4 1 2 4 1 2
 5 3
 3 2 3 2 1
 10 4
 4 3 4 3 2 3 2 1 0 1
 15 7
 3 7 4 8 2 3 4 5 21 2 3 4 2 1 3
 7 5
 1 2 3 4 5 6 1
 
 
 outputCopy
 3 2
 2 2
 2 1
 3 1
 2 3
 
 */
