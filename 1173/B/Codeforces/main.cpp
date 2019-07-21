//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1173/problem/B)
 **题目大意：**
 在一个 m x m 的棋盘上，要放置n个棋子。
 假设第i个棋子放置在𝑟𝑖行，𝑐𝑖列，那么要满足以下条件：
 对于所有的i、j，都有 |𝑟𝑖−𝑟𝑗|+|𝑐𝑖−𝑐𝑗|≥|𝑖−𝑗| 。
 
 问，m的最小值是多少？
 
 输入：
 一行，数字𝑛 (1≤𝑛≤1000)，表示棋子数量。
 
 输出：
 第一行是数字m，表示棋盘大小；
 接下来有n行，每行两个数字𝑟𝑖 and 𝑐𝑖 (1≤𝑟𝑖,𝑐𝑖≤𝑚），分别表示第i个棋子放置的行数和列数。
 
 Examples
 input
 2
 output
 2
 1 1
 1 2
 input
 4
 output
 3
 1 1
 1 3
 3 1
 3 3
 
 
 **题目解析：**
 尝试构造一种最优解：
 123
 004
 005
 
 1234
 0005
 0006
 0007
 
 因为相对1而言，往右、往下都存在(x,y)坐标的递增；
 从上面可以知道，这种填充方式已经是最优解。
 比如说当我们往6的左边填入一个数字时，因为6相对1已经是距离最大值，而向左填入会导致y坐标减1，那么填入的数字只能比6更小。
 
 代码非常简洁：
 
 思考：
 如何得到这个最优解？
 还是贪心的原则，1是最小，放在最边上肯定没错；
 2贴着1放，也是最优解；
 同理，3也要贴着2进行放置；
 ...
 
 
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
    
    int n, m;
    cin >> n;
    m = n / 2  + 1;
    cout << m << endl;
    int index = 0;
    while (n && index < m) {
        --n;
        ++index;
        cout << "1 " << index << endl;
    }
    index = 1;
    while (n && index < m) {
        --n;
        ++index;
        cout << index << " " << m << endl;
    }
    
    
    return 0;
}
