//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1841/problem/A)
 **题目大意：**
 Alice和Bob在玩游戏。
 初始有n个数字1，每次可以选择2个或者以上相同的数字，将这些数字移除，然后添加这些数字的和；
 比如说[1, 1, 1, 1]，可以选择2个1合并，得到[2, 1, 1]；
 现在Alice和Bob轮流进行操作，Alice先手；
 如果遇到没有2个相同的数字，那么该轮选手获胜。

 输入整数n，表示有n个数字1；
 输出Alice或者Bob，表示获胜者；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤99)
 每个样例一行，整数𝑛 (2≤𝑛≤200)
 
 
 **输出：**
 每个样例一行，输出获胜者。
 
 **Examples**
 **input**
 2
 3
 6

 **output**
 Bob
 Alice


 **题目解析：**
 先从小样例入手：
 n=2，[1, 1] = B
 n=3，1,1,1 = B
 n=4，1,1,1,1 = B
 n=5，1,1,1,1,1 = 1,1 + 3 = A
 n=6，1,1,1,1,1,1 = 1,1 + 4 = A
 ...
 这里比较容易得到一个必胜策略，只需要拆分为 [1,1] + (n-2) = A，并且n-2比2大即可。
 
 
 
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
    static const int N = 201010;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cout << (n > 4 ? "Alice" : "Bob") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
