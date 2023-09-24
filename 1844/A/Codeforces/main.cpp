//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1844/problem/A)
 **题目大意：**
 有一堆石子，初始的时候有若干个；
 有两个人在玩游戏，每个人轮流移除石子，每次可以移除a个石子或者b个石子，无法移除者失败；
 假设两个都采用了理想最优策略，现在已知a和b，问最初的时候有多少个石子，能够保证后手者胜利。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例一行，整数𝑎 and 𝑏 (1≤𝑎<𝑏≤100)
 
 **输出：**
 每个样例一行，输出初始化状态的石子数量𝑛 (1≤𝑛≤1e6 )；
 
 **Examples**
 **input**
 3
 1 4
 1 5
 9 26

 **output**
 2
 6
 3




 **题目解析：**
 只要让先手者不能取，那么后手者胜利。
 a>1，则直接n=1，先手无解；
 a=1，则n=a+b，先手不管取a或者b，后手跟着取b或者a即可；
 
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
            int x, y;
            cin >> x >> y;
            if (x > 1) cout << 1 << endl;
            else cout << x + y << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
