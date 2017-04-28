//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2017年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/760/problem/D
 题目大意：
 小明出去旅行，需要购买车票，一共有三种类型的车票：
 1、一次性票，价格是20；
 2、90分钟票，价格是50；
 3、日票（1440分钟），价格是120；
 
 有效时间为x分钟的车票在第t分钟使用，能在[t, t+x-1]的区间内使用；
 所有的旅行只持续1分钟；（所以一次性票只能用一分钟）
 小明一共旅行n次，分别在t[i]分钟发生；(t[i] < t[i+1])
 第i次旅行的代价为前i次旅行的最小代价减去前i-1次旅行的最小代价；
 现在小明想知道每一次旅行的代价。
 
 n (1 ≤ n ≤ 1e5)
 ti (0 ≤ ti ≤ 1e9， t[i] < t[i+1])
 
 Examples
 input
 3
 10
 20
 30
 output
 20
 20
 10
 样例解释：
 第一次旅行，买一次性票20；
 第二次旅行，买一次性票20；
 第三次旅行，买90分钟票50，减去前两次的最小代价40，代价是10；
 
 
 
 题目解析：
 典型的动态规划题，每次有三个抉择（状态转移）：
 （我们用dp[i]来表示前i次旅行的最小代价）
 1、一次性票，dp[i] = min(dp[i], dp[i-1]+20);
 2、90分钟票，dp[i] = min(dp[i], dp[k]+50); (a[i] - a[k] < 90)
 3、日票，dp[i] = min(dp[i], dp[k]+50); (a[i] - a[k] < 1440)
 
 状态数是N，转移复杂度是1440，总体的复杂度是10^8，较大；
 优化方案：
 用优先队列来维护a[i]-a[k]<90和a[i]-a[k]<1440的两个最优解，并把无效的解去掉；
 总体的复杂度变为10^6级别；
 
 
 
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
        if (first != tmp.first) return first > tmp.first;
        else return second > tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
};


int a[N];
int dp[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = inf;
    }
    priority_queue<Node> minuteQueue, dayQueue;
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 20); // one trip ticket
        
        // minute ticket
        while (!minuteQueue.empty()) {
            Node top = minuteQueue.top();
            if (a[i] - top.second >= 90) {
                minuteQueue.pop();
            }
            else {
                break;
            }
        }
        if (!minuteQueue.empty()) {
            dp[i] = min(dp[i], minuteQueue.top().first);
        }
        minuteQueue.push(Node(dp[i - 1] + 50, a[i]));
        
        // day ticket
        while (!dayQueue.empty()) {
            Node top = dayQueue.top();
            if (a[i] - top.second >= 1440) {
                dayQueue.pop();
            }
            else {
                break;
            }
        }
        if (!dayQueue.empty()) {
            dp[i] = min(dp[i], dayQueue.top().first);
        }
        dayQueue.push(Node(dp[i - 1] + 120, a[i]));
        printf("%d\n", dp[i] - dp[i - 1]);
    }
    
    return 0;
}

/*
 6
 1
 11
 21
 31
 41
 51
 
 
 */
