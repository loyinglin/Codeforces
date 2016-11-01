//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1003&cid=729
 题目大意：
 给出A，B 2个整数，要求：
 找到所有A≤C≤B, A≤D≤B ，且 A/B+B/A≤C/D+D/C的CD，并输出。
 
 Sample Input
 2
 10 10
 9 27
 
 Sample Output
 Case #1:
 1
 10 10
 Case #2:
 2
 9 27
 27 9

 
 题目解析：
 
 
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
const int N = 1001000, M = 3010100, inf = 0x7fffffff;

char str[N * 2];
int Right[5];

int main(int argc, const char * argv[]) {
    // insert code here...
    lld t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        lld a, b;
        cin >> a >> b;
        printf("Case #%d:\n", i);
        if (a == b) {
            puts("1");
            cout << a << " " << b << endl;
        }
        else {
            puts("2");
            cout << a << " " << b << endl;
            cout << b << " " << a << endl;
        }
    }
    
    
    return 0;
}
