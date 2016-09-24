//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/711/problem/C
 题目大意：输入一个n*n的数组矩阵，在数字为0的位置填入一个正数（只有一个位置为0），让矩阵的行列对角线和相同。如果没有答案输出-1，多个答案任意输出。
 
 input
 3
 4 0 2
 3 5 7
 8 1 6
 output
 9

 
 input
 4
 1 1 1 1
 1 1 0 1
 1 1 2 1
 1 1 1 1
 output
 -1
 
 
 题目解析：
 只有一个位置为0，那么根据上一行和当前行的差值，可以计算出0应该填的数字。
 
 再判断一下结果是否符合即可。
 
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
const int N = 1100;
lld a[N][N], n, sum;


bool check() {
    lld left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        lld col = 0, row = 0;
        for (int j = 0; j < n; ++j) {
            row += a[i][j];
            col += a[j][i];
        }
        if (col != sum || row != sum) {
            return 0;
        }
        left += a[i][i];
        right += a[i][n - i - 1];
    }
    
    if (left != sum || right != sum) {
        return 0;
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                x = i, y = j;
            }
        }
    }
    
    if (n == 1) {
        cout << 1 << endl;
    }
    else {
        lld ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != x) {
                for (int j = 0; j < n; ++j) {
                    sum += a[i][j];
                }
                break;
            }
        }
        lld tmp = 0;
        for (int j = 0; j < n; ++j) {
            tmp += a[x][j];
        }
        ans = sum - tmp;
        a[x][y] = ans;
        
        if(check() && ans > 0) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    
    
    
    
    return 0;
}
