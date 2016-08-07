//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/699/problem/C
 题目大意：n天，每天有四种可能，如下。问最少能休息几天。
  1、on this day the gym is closed and the contest is not carried out;
 2、on this day the gym is closed and the contest is carried out;
 3、on this day the gym is open and the contest is not carried out;
 4、on this day the gym is open and the contest is carried out.
 不能连续两天比赛，也不能连续两天锻炼。
 
 题目解析：
 典型的动态规划。
 d[i][j]表示第i天，状态为j时的最小休息天数。
 // j = 0 都不去
 // J = 1 去contest
 // J = 2 去gym

 这样j = 0可以由前面三种状态转换过来；
 j = 1只能由0和2转换；
 j = 2只能由1和2转换；
 
 然后动态规划一遍得最优解。
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

#define N 200200

struct Node {
    int x, y;

    bool operator<(const Node &tmp) const
    {
        if (tmp.x == x) {
            return tmp.y < y;
        }
        else {
            return tmp.x < x;
        }
    };
    bool operator==(const Node &tmp) const
    {
        return x == tmp.x && y == tmp.y;
    };
}node[N];
set<Node> nodes;
long long a[N], d[N][4];
// d[i][j] 第i天，状态为j时，休息的最小天数。
// j = 0 都不去
// J = 1 去contest
// J = 2 去gym

int main(int argc, const char * argv[]) {
    // insert code here...

    long long n;
    cin >> n;
//    d[0] = d[1] = d[2] = 
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        d[i][0] = min(min(d[i - 1][0] + 1, d[i - 1][1] + 1), d[i - 1][2] + 1);
        if (k == 0) {
            d[i][1] = d[i][2] = N;
        }
        if (k == 1) { // can to contest
            d[i][1] = min(d[i - 1][2], d[i - 1][0]);
            d[i][2] = N;
        }
        if (k == 2) { // can to gym
            d[i][1] = N;
            d[i][2] = min(d[i - 1][1], d[i - 1][0]);
        }
        if (k == 3) {
            d[i][1] = min(d[i - 1][2], d[i - 1][0]);
            d[i][2] = min(d[i - 1][1], d[i - 1][0]);
        }
    }
    
    cout << min(min(d[n][0], d[n][1]), d[n][2]) << endl;
    
    

    return 0;
}





