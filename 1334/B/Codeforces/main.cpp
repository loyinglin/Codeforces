//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1334/problem/B)
 **题目大意：**
 给出n个数字，每次可以选择若干个数字，将他们进行平均；这个操作的次数不限制；
 
 问最终最多有多少个数字可以大于x？
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 每个样例第一行， 整数𝑛 and 𝑥 (1≤𝑛≤10^5, 1≤𝑥≤10^9)
 接下来一行n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10^9)
 
 
 **输出：**
 每个样例一行，最终大于数字x的数量；
 
 **Examples**
 input
 4
 4 3
 5 1 2 1
 4 10
 11 9 11 9
 2 5
 4 3
 3 7
 9 4 9

 ⁣output
 ⁣2
 4
 0
 3
 
 
 **题目解析：**
 把数字从大到小排序，从数字大的开始选择：
 1、如果该数字大于x，直接入选；
 2、如果该数字小于x，并且加进来不会导致sum/count 小于x，则加进来；
 
 直到数字不能选择，则得到最多的数字。
 
 **思考🤔：**
贪心。
 
 
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
const int N = 300010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N], val[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        lld n, x;
        cin >> n >> x;
        
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        lld sum = 0, ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (sum + a[i] >= x * (ans + 1)) {
                sum += a[i];
                ++ans;
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}


/**
 44
 4
 6 8
 9 3
 8 1
 9 7
  
 */
