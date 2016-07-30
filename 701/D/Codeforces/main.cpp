//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/701/problem/D
    题目大意：n个人要走一段路，路的长度为l，人的速度为v1，租了一辆载客
    量为k的车，速度为v2，上下车和车掉头的时间忽略不计；所有人只坐一次汽车；
    问：最少需要多少时间才能完成这段路程？
    
 题目解析：
 要尽快的到达目的地，我们可以制定如下的策略：
 1、车每次都要尽可能载更多的人；
 2、车在开的同时人也走；
 3、车开一段路后就让人下车，接着走，然后回去接新的人；
 
 要让时间最少，则必须所有人到达终点时间的时间一致；
 * 因为每个人只能坐一次车，那么每个人坐车的时间应该是一致的，假设其为T1；车子每次载客完之后还要回来，这个时间为T2；
 * 把人分成m组（由n和k统计而得），除了最后一组人，车每次都要经历一次T1+T2，最后一次组是T2的时间；
 * 每个人走路的路程=v1 * （T1 + T2) * (m - 1)；
 每个人坐车的路程=v2 * t；
 v1 * （T1 + T2) * (m - 1) + v2 * t = l
 * T1和T2受到速度v1和v2的影响
 车子开出去的路程 v2 * T2;
 人被接到之前走的路程 v1 * (T1 + T2);
 车子返程的时间 v2* T2;
 v2 * T2 = v1 * (T1 + T2) + v2 * T2;
 
************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

#define N 200000


int flag[N];
int c[N];
char str[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    long long n, v1, v2, l, k;
    cin >> n >> l >> v1 >> v2 >> k;
    long m = (n + k - 1) / k;
    double tmp = (v2 - v1) * 1.0 / (v1 + v2);
    double t2 = l /((m - 1) * 1.0 * v1 * (tmp + 1) + v2);
    double tb = tmp * t2;
    double ret = (m - 1) * tb + m * t2;
    printf("%.7f", ret);
    
    
    return 0;
}
