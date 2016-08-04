//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/699/problem/A
    题目大意：n个点，坐标x[i]从小到大，每个点可以选择L或者R的方向前进，求相遇的时间。
    题目解析：对于点i，有两种碰撞情况：
 1、方向是L，遇到左边的点方向是R；
 2、方向是R，遇到右边的店方向是L；
 假设点i和点j是碰撞的点，那么点1的情况1就是点2的情况2；
 那么对于点i只考虑左边的点即可；
 题目变成：对于每个点，求左边最近的方向为R 的点。
 


************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200200

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N];
char str[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    long long n, ret = -1;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int right = -1;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'R') {
            right = i;
        }
        else {
            if (right != -1 && a[i] != a[right]) {
                if (ret == -1) {
                    ret = (a[i] - a[right]) / 2;
                }
                else {
                    ret = min(ret, (a[i] - a[right]) / 2);
                }
            }
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
