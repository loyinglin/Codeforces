//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/701/problem/A
    题目大意：N（N为偶数）个数字，把数字平分 N/2 组，使得每组的数字和相等。
 

************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];


int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        node[i].pos = i + 1;
        cin >> node[i].value;
    }
    
    sort(node, node + n);

    for (int i = 0; i < n / 2; ++i) {
        cout << node[i].pos << " " << node[n - i - 1].pos << endl;
    }
    
    return 0;
}
