//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/703/problem/A
    题目大意：2个人，投掷n次骰子，大的赢，问谁赢，平局输出"Friendship is magic!^^"。
    题目解析：如题，照着写即可。
 


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
   
    int n, scoreA = 0, scoreB = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            ++scoreA;
        }
        else if (x < y) {
            ++scoreB;
        }
    }
    
    if (scoreA < scoreB) {
        cout << "Chris";
    }
    else if (scoreA == scoreB) {
        cout << "Friendship is magic!^^";
    }
    else {
        cout << "Mishka";
    }
//    cout << maxNum << endl;
    
    return 0;
}
