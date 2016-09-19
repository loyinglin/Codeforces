//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/710/problem/C
 题目大意：输入一个奇数n，输出一个n*n的矩阵，矩阵内数字从1到n*n。
 矩阵的要求是行列对角线的和都是奇数。
 题目解析：
 我们把1到n*n的数字抽象成0，1.（根据奇偶性）
 我们来看n=1的时候，1.
 n=3
 010
 111
 010
 
 问题是当n=5的时候，如何构造？
 已知，n=3的矩阵，那么只要保证n=3外面的矩阵行列和都是偶数就行。
 1 010 1
 
 0 010 0
 1 111 1
 0 010 0
 
 1 010 1
 
 那么题目可以变成这样一圈圈的去构造。
 并且为了方便，从中心开始构造最为简单。

 
 以下的做法是从最外层往里面构造，故而稍显啰嗦。 
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
const int N = 300, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];
lld a[N][N];

int main(int argc, const char * argv[]) {
    // insert code here...

    int n;
    cin >> n;
    
    int k = 1, l = n * n;
    a[(n + 1) / 2][(n + 1) / 2] = l--;
    for (int i = 1; i <= n; ++i) {
        int x = i, y = i;

        for (int j = 1; j < n - 2 * (i - 1); ++j) {
            if (i % 2 != (n % 4 - 1) / 2) {
                a[x][y++] = k++;
            }
            else {
                a[x][y++] = l--;
            }
        }
        for (int j = 1; j < n - 2 * (i - 1); ++j) {
            if (i % 2 != (n % 4 - 1) / 2) {
                a[x++][y] = k++;
            }
            else {
                a[x++][y] = l--;
            }
            
        }
        for (int j = 1; j < n - 2 * (i - 1); ++j) {
            if (i % 2 != (n % 4 - 1) / 2) {
                a[x][y--] = k++;
            }
            else {
                a[x][y--] = l--;
            }
        }
        for (int j = 1; j < n - 2 * (i - 1); ++j) {
            if (i % 2 != (n % 4 - 1) / 2) {
                a[x--][y] = k++;
            }
            else {
                a[x--][y] = l--;
            }
        }
    }
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
   
    
    
    return 0;
}
