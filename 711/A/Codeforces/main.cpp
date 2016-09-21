//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/711/problem/A
 题目大意：输入n行字符，每行5个；表示公交车上n排位置，X表示有人，O表示空位，|是过道。找到两个连续的空位，并且改为++后输出。如果没有输出NO。
 
 
 input
 5
 XX|XX
 XX|XX
 XO|OX
 XO|OO
 OX|XO
 output
 YES
 XX|XX
 XX|XX
 XO|OX
 XO|++
 OX|XO
 
 
 
 input
 4
 XO|OX
 XO|XX
 OX|OX
 XX|OX
 output
 NO
 
 
 
 题目解析：
 只有两种情况，前两个或者最后两个。特判一次即可。
 
 
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
const int N = 1110;
const lld llinf = 0x7fffffff7fffffffll;
char a[N][10];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    for (int i  = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int find = 0;
    
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == a[i][1] && a[i][0] == 'O') {
            find = 1;
            a[i][0] = a[i][1] = '+';
            break;
        }
        if (a[i][3] == a[i][4] && a[i][3] == 'O') {
            find = 1;
            a[i][3] = a[i][4] = '+';
            break;
        }
    }
    
    if (find) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
