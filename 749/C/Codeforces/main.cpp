//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/749/problem/C
 题目大意：
 n个人分配两派，分别用D、R表示；
 现在他们进行选举，每个人轮流投票，每次可以否决一个人，这个人就退出选举；
 每次都是从左到右进行投票，直到剩下最后一个人，这个人代表的阵营胜利。
 假设他们的投票都是理性的，问最后哪方阵营能获胜？
 
 **输入数据：**
 n (1 ≤ n ≤ 200 000)
 
 >**Examples**
 **input**
 5
 DDRRR
 **output**
 D
 样例解释：
 第一轮投票：
 1号 否决 5号；
 2号 否决 3号；
 3号 退出；
 4号 否决 2号；
 5号 退出；
 第二轮投票：
 1号 否决 4号；
 2号 退出；
 4号 退出；
 只剩下1号，所以1号的阵营D胜利。
 
 题目解析：
 每个人会淘汰一个人出局，那这个人必然是对方阵营，如果不得已要淘汰己方的阵营，那就代表着胜利；
 那么，每个人必然会选择距离下一次投票最近的敌方阵营的人；
 那么模拟一遍，直到获取结果。
 
 时间复杂度：每次至少淘汰n/2个人，log(N)次数，每次O(N)的时间，总得复杂度是O(NlogN);
 空间复杂度：循环利用原来的数据，空间复杂度为O(N);
 
 
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
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];
char a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    cin >> a;
    int d = 0, r = 0;
    while (n) {
        int id = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 'D') {
                if (r > 0) {
                    --r;
                }
                else {
                    ++d;
                    a[id++] = 'D';
                }
            }
            else {
                if (d > 0) {
                    --d;
                }
                else {
                    ++r;
                    a[id++] = 'R';
                }
            }
        }
        int ok = 1;
        for (int i = 1; i < id; ++i) {
            if (a[i] != a[i - 1]) {
                ok = 0;
            }
        }
        if (ok) {
            cout << a[0] << endl;
            break;
        }
        else {
            n = id;
        }
        
    }
    
    return 0;
}
