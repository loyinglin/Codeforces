//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1313/problem/C1)
 **题目大意：**
 建筑公司要建n栋楼（排成一行），第i栋的设计最大高度是m[i]；
 并且当地城市有规定：每栋楼不能在左右两边同时出现比它高的建筑；
 用数学的语言来描述，即是每栋楼的最终高度a[i]必须要小于等于m[i]；不能存在j和k，满足j<i<k并且a[j]>a[i]<a[k]；
 现在想知道建筑公司如何分配每栋楼的高度，使得最终所有楼的总高度最大？
 
 
 **输入：**
 第一行整数𝑛 (1≤𝑛≤1000)
 第二行整数𝑚1,𝑚2,…,𝑚𝑛 (1≤𝑚𝑖≤10^9)
 
 **输出：**
 n个整数a[i]，如果有多个分配组合，输出任何一个总高度最大的组合；
  
 **Examples**
 input
 5
 1 2 3 2 1
 output
 1 2 3 2 1
 
 
 **题目解析：**
 根据题目的要求，可以知道最终的高度，是一个递增再递减的序列；
 即是存在k，从k到1，数字逐渐递减；从k到n，数字逐渐递增；
 由于题目n范围较小，枚举这个k，既可以知道最优解；
 
 
 
 **思考🤔：**
 注意题目范围， 数字之和会超过int32；
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

int a[N], ans[N], f[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    lld sumMax = 0;
    for (int k = 0; k < n; ++k) {
        f[k] = a[k];
        int tmp = k - 1;
        while (tmp >= 0) {
            f[tmp] = min(a[tmp], f[tmp + 1]);
            --tmp;
        }
        tmp = k + 1;
        while (tmp < n) {
            f[tmp] = min(a[tmp], f[tmp  - 1]);
            ++tmp;
        }
        
        lld sumTmp = 0;
        for (int i = 0; i < n; ++i) {
            sumTmp += f[i];
        }
        if (sumTmp > sumMax) {
            sumMax = sumTmp;
            memcpy(ans, f, sizeof(int) * n);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
