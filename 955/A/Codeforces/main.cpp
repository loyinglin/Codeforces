//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/955/problem/A)
 **题目大意：**
 小明有一只猫，现在猫的饥饿值为H，并且每分钟会增加D；
 他可以选择现在就买猫粮，1份猫粮价格为C，可以减少猫的饥饿值N；（猫粮只能一份一份购买）
 他也可以选择晚上20点之后购买，商店会打8折；（当前的时间为hh时mm分）
 问，小明最少需要花费多少，才能把猫的饥饿值降到0；
 
 输入：
 第一行，hh and mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59)
 第二行，H, D, C and N (1 ≤ H ≤ 1e5, 1 ≤ D, C, N ≤ 1e2).
 输出：
 小明最少的花费，精确到小数点4位。
 
 **Examples**
 **input**
 19 00
 255 1 100 1
 **output**
 25200.0000
 
 
 **题目解析：**
 从题目已经给出的条件我们可以判断，在没打折的时候，花费是(H+N-1)/N*C；
 如果有打折，就要加上猫增加的饥饿值。
 那么，我们容易得到一种方法：用max(0LL, 20 * 60 - hh * 60 - mm) * d计算猫增加的饥饿值，再统一计算价格；
 
 lld cost1 = (h + n - 1) / n * c;
 double cost2 = (max(0LL, 20 * 60 - hh * 60 - mm) * d + h + n - 1) / n * c * 0.8;
 
 再从cost1、cost2中选择一个较小值即可。
 
 **思考🤔：**
 题目有个小trick，打折后的数字是浮点数。
 
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

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld hh, mm;
    lld h, d, c, n;
    cin >> hh >> mm;
    cin >> h >> d >> c >> n;
    
    lld cost1 = (h + n - 1) / n * c;
    double cost2 = (max(0LL, 20 * 60 - hh * 60 - mm) * d + h + n - 1) / n * c * 0.8;
    
    cout << min((double)cost1, cost2) << endl;
    
    return 0;
}
