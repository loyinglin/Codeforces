//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/702/problem/A
    题目大意：n个数字，找出连续一串上升序列的长度。
    题目解析：
 对于一串序列，假如是以a[i]结尾，如果a[i+1] > a[i] 那么a[i+1]会让序列+1；如果a[i+1] <= a[i] 那么a[i+1]会重新开始新的序列。


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
long long a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxNum = 1, k = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            ++k;
            maxNum = max(maxNum, k);
        }
        else {
            k = 1;
        }
    }
    cout << maxNum << endl;
    
    return 0;
}
