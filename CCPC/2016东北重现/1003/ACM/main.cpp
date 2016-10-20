//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1001&cid=729
 题目大意：n个点，从1到n。两点的边权值为两个顶点的最小公倍数，求出在n个点的完全图中，最小生成树的最小代价。
 
 样例解释：
 
 
 题目解析：
 以1为中心即可，1~n的求和公式-1得到答案。
 
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
