//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/701/problem/A
    题目大意：N（N为偶数）个数字，把数字平分 N/2 组，使得每组的数字和相等。
    题目解析：
 假设最后的和为k，那么有k = sum / (N / 2); sum为所有数字之和。
 对于数字a[i]，在数组中查找没有分配过的a[j] = k - a[i]即可。
 
 优化：对n个数字的数组从小到大排序，对于a[0]（最小），它的另一个必然是a[n - 1]（最大）;
 证明：假设a[0]对应的是a[n -2]，并且a[n -2] < a[n -1]，那么对于a[n -1]的数字和另外一个数字之和必然大于a[0]+a[n - 2]；

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
