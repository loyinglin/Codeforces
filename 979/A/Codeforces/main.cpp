//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/979/problem/A)
 **题目大意：**
 小明邀请了n个朋友过来吃披萨，披萨只有一个且是圆形的；
 现在需要把披萨分成形状完全相同的n+1块，问需要至少切多少刀？
 
 输入：
 第一行：n，表示朋友人数 ( 0 ≤ n ≤ 1e18 )
 输出：
 至少需要切多少刀。
 
 **Examples**
 **input**
 3
 **output**
 2
 样例解释：
 两刀垂直切，得到4块。
 
 **题目解析：**
 由题目意思知道，一个圆切分成n+1块，那么每个扇形的弧度是2π/(n+1)；
 那么按照这个弧度平分，不过圆心的切，(n+1)刀必定可以平分；
 
 有另外一种情况，是过圆心切，比如样例的情况，两刀可以切成4块。
 在这种切法情况下，切线经过的扇形，分成两部分。
 
 即是说：
 如果是分成奇数块，那么不能用过圆心的切法（因为每次都是切成偶数块）；
 如果是分成偶数块，那么可以只用过圆心的切法；
 
 于是有：
 (n+1)是奇数，ans=(n+1);
 (n+1)是偶数，ans=(n+1)/2;
 
 **思考🤔：**
 trick1：n很大，如果用int会爆；
 trick2：n=0的时候，ans=0；
 
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
    
    lld n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    ++n;
    if (n % 2) {
        cout << n << endl;
    }
    else {
        cout << n / 2 << endl;
    }
    
    return 0;
}
