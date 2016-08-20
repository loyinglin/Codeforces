//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/702/problem/C
 题目大意：给出n个目标点，m个源点，求最小的r，使得每个目标点的r范围内至少存在一个源点。
 题目解析：
 对目标点和源点排序。
 易得r具有线性特点，即如果r可行，那么r+1必然可行。可以用二分。
 同时，目标点i对应的源点为j，那么有i+1目标点的源点>=j。
 
 
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N], b[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long long n, m, mMax = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mMax = max(mMax, abs(a[i]));
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    
    long long ret = (long long)2 * 10E9;
    long long left = 0, right = ret;
    while (left < right) {
        long long mid = (left + right) / 2;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m) {
                if (a[i] >= b[j] - mid && a[i] <= b[j] + mid) {
                    break;
                }
                ++j;
            }
        }
        if (j < m) {
            ret = mid;
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << ret;
    
    return 0;
}


