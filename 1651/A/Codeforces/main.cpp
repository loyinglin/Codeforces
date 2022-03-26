//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1651/problem/A)
 **题目大意：**
 有2^𝑛个人参加比赛，编号是1到2^n；
 比赛采用的是淘汰赛的机制，1和2比，3和4比，然后接着是胜者按照编号大小继续比赛；
 已知编号x和y的人参加比赛，会有下面的结果：
 1、x+y是奇数，则胜者是编号较小者；
 2、x+y是偶数，则胜者是编号较大者；
 
  **输入：**
 第一行，整数𝑡 表示t个样例 (1≤𝑡≤1000)
 每个样例一行，整数𝑛 (1≤𝑛≤30)
 **输出：**
每个样例输出一行，输出最后的胜者编号。
 
 **Examples**
 **input**
 2
 3
 1
 **output**
 7
 1
 
 **题目解析：**
 仔细看图中的条件，发现这里面条件的x+y是奇数，只会出现在第一轮比赛；
 从第二轮比赛开始，参赛全部是奇数，则一定是较大者获胜；
 
 
 **思考🤔：**
 假设参加比赛初始顺序是乱序的呢？那就手动算一遍，因为轮次是log级别递进，总体的复杂度可以控制在NlogN；
 
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
    static const int N = 200010;
    string str;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cout << (1 << n) - 1 << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
