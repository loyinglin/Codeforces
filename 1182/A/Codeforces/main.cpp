//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1182/problem/A)
 **题目大意：**
 有基础的三角图案，需要填充到3xN的大图案中，要求不留空隙，并且没有重叠；
 问有多少种填充的组合方式。
 
 输入：
 数字n，表示3*N的大图案宽度；(1≤𝑛≤60)
 
 输出：
 填充的方式。
 
 
 **Examples**
 **input**
 **output**

 Examples
 input
 4
 output
 4
 input
 1
 output
 0
 
 
 **题目解析：**
 n为奇数，则会出现填不满的情况，此时为0；
 n为偶数，对于每3*2的6个格子，只有两种组合方式。
 那么总共的方案是2^(n/2)的个数。
 
 **思考🤔：**
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    if (n % 2) {
        cout << 0 << endl;
    }
    else {
        lld ans = 1;
        for (int i = 0; i < n / 2; ++i) {
            ans *= 2;
        }
        
        cout << ans << endl;
    }
    
    
    return 0;
}
