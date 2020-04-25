//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1236/problem/A)
 **题目大意：**
 有三堆石头，分别有a、b、c个；
 现在可以执行操作：
 1、从第一堆拿出1个石头，第二堆拿出2个石头；
 2、从第二堆拿出1个石头，第三堆拿出2个石头；
 以上的操作，必须有足够石头才允许操作。
 
 问最多，可以从这三堆石头中拿出多少个。
 
 
 输入：
 第一行，是样例个数 𝑡 (1≤𝑡≤100)；
 接下来t行表示t个样例，每个样例一行，每行有三个数字a、b、c (0≤𝑎,𝑏,𝑐≤100)；
 
 输出：
 每个样例一行，输出拿到的石头数量。
 
 input
 3
 3 4 5
 1 0 5
 5 3 2
 
 output
 9
 0
 6
 
 
 **题目解析：**
 贪心，先执行操作2，再执行操作1，O(1)得到结果。
 
 
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


int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b, c;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = min(c / 2, b);
        cout << min((b - ans) / 2, a) * 3 + ans * 3 << endl;
    }
    
           
    
    return 0;
}


/**
 
 */
