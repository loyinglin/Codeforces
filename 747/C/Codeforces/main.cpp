//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/747/problem/C
 题目大意：
 n个服务器，序号从1到n，有q个任务；
 每个任务在t[i]秒的时间到，需要k[i]台服务器，每台占用t[i]秒的时间；
 询问：当每个任务到达时，是否有足够的机器完成任务；
 如果可以完成，则选择序号最小的机器，输出机器的序号和；
 如果不能完成，输出-1；
 
 n and q (1 ≤ n ≤ 100, 1 ≤ q ≤ 1e5)

 t[i], k[i] and d[i] (1 ≤ t[i] ≤ 1e6, 1 ≤ k[i] ≤ n, 1 ≤ d[i] ≤ 1000)
 
 
 Examples
 input
 4 3
 1 3 2
 2 2 1
 3 4 3
 output
 6
 -1
 10
 样例解释：
 第一个任务在第1秒到达，所有机器空闲，选择1、2、3号机器，所以输出6；
 第二个任务在第2秒到达，这时空闲的机器只有机器4，任务无法完成，输出-1；
 第三个任务在第3秒到达，所有机器都空闲，选择1、2、3、4号机器，输出10；
 
 
 题目解析：
 非常简单的实现，一个一维数组表示机器，每个机器有两个属性：序号和空闲时间。
 每次从序号最小的机器开始遍历，看是否有合适的机器；
 如果选中机器，就把机器的空闲时间变成任务的完成时间。
 
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
        if (tmp.pos != pos) return pos > tmp.pos;
        else return value > tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

char a[N];

int main(int argc, const char * argv[]) {
    int n, q;
    cin >> n >> q;
    vector<Node> servers(n);
    for (int i = 0; i < n; ++i) {
        servers[i] = Node(i + 1, 0);
    }
    while (q--) {
        int comeTime, needServer, needTime;
        scanf("%d%d%d", &comeTime, &needServer, &needTime);
        vector<Node> readyServers;
        for (int i = 0; i < servers.size() && readyServers.size() < needServer; ++i) {
            if (servers[i].pos <= comeTime) {
                readyServers.push_back(servers[i]);
            }
        }
        if (readyServers.size() == needServer) {
            int ans = 0;
            for (int i = 0; i < readyServers.size(); ++i) {
                ans += readyServers[i].value;
                readyServers[i].pos = comeTime + needTime;
            }
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
        for (int i = 0; i < readyServers.size(); ++i) {
            servers[readyServers[i].value - 1].pos = readyServers[i].pos;
        }
    }
    return 0;
}
