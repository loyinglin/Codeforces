//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1228/problem/A)
 **题目大意：**
 
 
 
 输入：

 
 输出：

 
 **题目解析：**
 
 
 
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


void add_pre(string x, int index, int vis[], int op) {
    if (index == 0) {
        vis[x[index]] = 0;
        x[index] = x[index] + 1 + op;
        if (x[index] - '0' == 10) {
            vis['0'] = 1;
            vis['1'] = 1;
        }
        else {
            vis[x[index]] = 1;
        }
    }
    else {
        vis[x[index]] = 0;
        if (x[index] - '0' + op + 1 == 10 || vis[x[index] + 1]) {
            add_pre(x, index - 1, vis, x[index] - '0' + op + 1 == 10);
            for (int i = '0'; i <= '9'; ++i) {
                if (!vis[i]) {
                    vis[i] = 1;
                    x[index] = i;
                    break;
                }
            }
        }
        else {
            
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string x, y;
    cin >> x >> y;
    int vis[1000] = {0};
    int i = 0, tmp = -1;
    while (i < x.length()) {
        int num = x[i];
        if (!vis[num]) {
            vis[num] = 1;
        }
        else {
            // 找到重复的数字，开始往前+1
            tmp = i - 1;
            break;
        }
    }
    
    
           
    
    return 0;
}


/**
 9877
 10234
 
 
 
 */
