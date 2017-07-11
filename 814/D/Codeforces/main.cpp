//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/814/problem/D
 题目大意：
 n个大妈在广场上跳舞，假设每个大妈的影响区域是一个圆，广场是在二维的坐标系上；
 已知n个大妈分别在(x[i], y[i])的位置上，影响范围的半径是r[i]；
 已知大妈的影响范围的圆，只会出现包含的情况，不会出现部分覆盖的情况，见图。
 
 现在希望把这些人分成到两个时间段， 要求被奇数个大妈覆盖到的面积尽可能的大，见图。
 
 n (1 ≤ n ≤ 1 000)
 ( - 106 ≤ xi, yi ≤ 106, 1 ≤ ri ≤ 106),
 
 
 
 题目解析：
 1、对于圆x和圆y，如果x被y包含，那么有x∈y；
 2、假设有n个点a[i]，分别对应n个圆；
 对于x∈y，我们认为a[y]是a[x]的父节点；
 3、如果节点t没有父节点，我们新增点a[0]，a[0]是a[t]的父节点；
 4、根据题目要求，没有圆相交，那么a[0 ~ n]的节点构成一棵树；
 5、假设根节点深度为1且面积为0，我们用红色和黑色对节点进行染色，规则如下：
 根节点为黑色；
 深度为1的节点为红色，深度为2的节点为红色；
 其余所有节点，如果父节点为红色/黑色，则当前节点为黑色/红色；
 题目要求的最大面积就是红色节点的面积。
 
 原理：对于任何一个非根的节点t，子树所有节点能覆盖的面积不会超过t的面积；
 所以把深度为1的所有节点分配到上半夜，剩下的所有的点都分配在下半夜；（剩下的点必然是红黑交错）
 
 简化代码：
 对于任何一个圆，求出其被覆盖的次数c[i];
 如果c[i]=0，sum += area(i);
 如果c[i]%2=1, sum += area(i);
 如果c[i]%2=0, sum -= area(i);
 
 
 
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
const int N = 1511, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld x[N], y[N], r[N];
lld c[N];

double dist(int i, int j) {
    return sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

#define M_PI        3.14159265358979323846264338327950288

double area(int i) {
    return M_PI * r[i] * r[i];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (r[i] < r[j] && dist(i, j) <= r[j]) {
                ++c[i];
            }
        }
    }
    
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            sum += area(i);
        }
        else if (c[i] % 2 == 1) {
            sum += area(i);
        }
        else {
            sum -= area(i);
        }
    }
    printf("%.10f", sum);
    
    return 0;
}

/**
 
 
 **/
