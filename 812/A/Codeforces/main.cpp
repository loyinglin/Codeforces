//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/812/problem/A
 题目大意：
 在一个十字路口（见图），一共有4个路口；
 每个路口的机动车道有三个方向，分别是左转、直行、右转，同时路口有一条人行道；
 每行输入有四个数字l，s，r，p，分别表示左转、直行、右转、人行道的交通信号灯是否亮起；
 
 如果某个路口人行道的灯亮起，同时有机动车可以通过这个路口，那么会发生交通事故，输出"YES"；
 如果所有的路口都不会发生交通事故，则输出"NO";
 
 
 
 Examples
 input
 1 0 0 1
 0 1 0 0
 0 0 1 0
 0 0 0 1
 output
 YES
 样例解释：
 路口1的人行道信号灯亮起的同时，路口1和4的机动车可以通过这个路口，会发生交通事故；
 同时路口4的人行道信号灯亮起的同时，路口2、3的机动车可以通过路口4，会发生交通事故；
 
 
 
 题目解析：
 题意很清晰，分别判断每个路口是否有人行道信号灯亮起，如果有再判断是否有机动车通过。
 
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
const int N = 10, M = 3010100, inf = 0x7fffffff;
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
int a[N][5];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 4;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (a[i][4] == 1) { // pedestrian light on
            int l = i > 1 ? i - 1 : 4, r = i < 4 ? i + 1 : 1, s = i + 2 > 4 ? (i + 2) % 4 : i + 2;
            if (a[l][3] || a[r][1] || a[s][2] || a[i][1] || a[i][2] || a[i][3]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
  
    
    return 0;
}
