//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：有n个弹簧排成一列，袋鼠起始位置在第一个弹簧；
 输入n个数字，代表n个弹簧的力量；
 弹簧的力量为5表示可以往后跳最多5个弹簧；
 问袋鼠到达第n个弹簧的最小弹跳次数？
 
 
 题目解析：
 dp[i] 表示到达第i个的最小步数； dp[1]=1；
 对于第i个数字是a[i]，那么有枚举j， 1<= j <= a[i]
 d[i+j]=min(d[i+j], d[i]+1);
 表示到达i+j的最优解；
  复杂度最多可以到O(N*N)。
 
 优先队列优化：
 对dp[i], 打包成pair(i, a[i])  放入优先队列；
 这样每次取出来的都是最小步数，然后判断i+a[j]是否大于等于当前位置，是则更新，不是则丢弃这个解，重新在队列里面取；
 
 
 单调队列优化：
 对dp[i]，i+a[i] 是这个最优解的有效区间；
 如果维护一个dp[i]从大到小的单调队列，里面的a[i]+i不具备单调性，因为相同的dp[i]我们保留一个较大的a[i]+i即可；
 
 
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
#include <queue>
using namespace std;

typedef long long lld;
const int N = 1001000, M = 3010100, inf = 0x7fffffff;



struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value > tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

int d[N];
int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
//    freopen("input.txt", "w", stdout);
//    int t = 10;
//    while (t--) {
//        int n = arc4random_uniform(1000) + 10;
//        cout << n << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << arc4random_uniform(1000) + 10 << " ";
//        }
//        cout << endl;
//    }
//    return 0;
    
    

    freopen("input.txt", "r", stdin);
    freopen("output_priority.txt", "w", stdout);
    int n;
    priority_queue<Node> queue;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            d[i] = inf;
        }
        while (!queue.empty()) {
            queue.pop();
        }
        d[1] = 0;
        queue.push(Node(d[1], 1 + a[1]));
        
        for (int i = 2; i <= n; ++i) {
            while (!queue.empty()) {
                Node top = queue.top();
                if (top.pos < i) {
                    queue.pop();
                }
                else {
                    d[i] = top.value + 1;
                    queue.push(Node(d[i], i + a[i]));
                    break;
                }
                
            }
        }
        
        if (d[n] == inf) {
            d[n] = -1;
        }
        cout << d[n] << endl;
    }
    
    
    return 0;
}
