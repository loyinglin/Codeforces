//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1731/problem/B)
 **题目大意：**
 有一个n x n的网格，每经过一个格子都可以获得分数，第i行第j列格子可以获得i*j的分数；
 小明站在左上角的格子（1，1），每次可以向下或者向右，每个格子只能经过一次；
 现在想知道从左上角（1，1）到右下角（n，n）最多能获得多少分数；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤1e4).
 每个样例1行，第一行整数 𝑛 (2≤𝑛≤1e9).
  
 **输出：**
 每个样例一行，输出分数和乘以2022 mod  1e9+7 的值。
 
 **Examples**
 **input**
 4
 2
 3
 50
 1000000000
 **output**
 14154
 44484
 171010650
 999589541
 
 **题目解析：**
 当n=1的时候，答案就是1；
 当n=2的时候，我们可以选择在（1，1）先向下到达（2，1），再向右到达（2，2），最终分数是1+2+4=7；
 当n=3的时候，我们站在（2，2）的位置，先向下到达（3，2），再向右到达（3，3），最终分数是7+6+9=22；
 同理，我们得到a[n] = a[n-1] + n * n + n * (n - 1) = a[n-1]+ n * n * 2 - n ；
 这个递归式不断执行，我们可以得到a[n] = ∑n² * 2 - ∑n；
 通过数据知识，我们知道前n项和是n*(n+1)/2，前n项平方和是n*(n+1)(2n+1)/6；
 带入上面的通项公式得到结果a[n]=(n * (4 * n - 1) * (n + 1) ) / 6。
 
 最终需要取模，需要用到一个费马小定理。。。
 
 
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
 
class Solution {
    static const int Mod = 1000000007;
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            lld n;
            cin >> n;
            lld sum = (n * (4 * n - 1) * (n + 1) ) / 6;
            cout << (sum * 2022) % Mod << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
