//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/937/problem/A)
 **题目大意：**
 n个人参加比赛，每个人都有一个分数a[i]，现在需要给这些人发奖牌，要求：
 1、至少一个人拿到奖牌；
 2、分数为0的不能拿奖牌；
 3、某个人拿奖，则所有分数不低于他的人也要拿奖牌；
 问总共能有多少种分配方式？
 
 输入：
 第一行，n (1 ≤ n ≤ 100)
 第二行，n个数字 (0 ≤ a[i] ≤ 600)
 输出：
 一个数字，表示分配方式的数量。
 
 **Examples**
 **input**
 4
 1 3 3 2
 **output**
 3
 样例解释：3种方式：
 1、只发给3分；
 2、发给2、3分；
 3、所有人都发；
 
 
 **题目解析：**
 根据题目的意思，由条件3我们容易知道，n种分数（非零），就有n种分法。
 但对于这类型题目，除了做题外，很重要一点是如何把代码写得优雅。
 
 比如说这样写，就很精简。
 int ans = a[0] > 0;
 for (int i = 1; i < n; ++i) {
 if (a[i - 1] != a[i]) {
 ++ans;
 }
 }
 cout << ans << endl;
 
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int ans = a[0] > 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] != a[i]) {
            ++ans;
        }
    }
    cout << ans << endl;
    
    return 0;
}
