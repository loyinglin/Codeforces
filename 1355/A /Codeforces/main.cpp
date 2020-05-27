//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1355/problem/A)
 **题目大意：**
 给出一个整数a[1]，假设有下面这样一个迭代公式：
 
 
 按照上面的规则，迭代k次之后，得到a[k]；
 现在给出a[1]和k，求最终迭代出来的a[k]值是多少？
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，2个整数 𝑎1  and 𝐾 (1≤𝑎1≤1e18, 1≤𝐾≤1e16)

 
 **输出：**
 每个样例一行，输出a[k]；
 
 **Examples**
 **input**
 8
 1 4
 487 1
 487 2
 487 3
 487 4
 487 5
 487 6
 487 7
 
 **output**
 42
 487
 519
 528
 544
 564
 588
 628
 
 **题目解析：**
 题目咋一看，会很复杂；同时数字的范围特别大，又也没有什么明显规律。
 
 这种时候，先尝试的模拟算一下，当我们多重复几次，直到x·y=0的时候，我们发现这个数字会停滞不动；
 那么我们可以模拟这个过程，直到有数字为0。
 
 那么有没有可能出现，x·y永远不为零呢？答案是不可能的，因为会进位。
 数字的百位，最终总是会归零，并且不会需要很多次。
 
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

bool cmp(int a, int b) {
    return a > b;
}

lld calc(lld a) {
    lld x = 0, y = 9;
    while (a) {
        x = max(x, a%10);
        y = min(y, a%10);
        a /= 10;
    }
    return x*y;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        lld a, k;
        cin >> a >> k;
        while (--k) {
            lld tmp = calc(a);
            a += tmp;
            if (tmp == 0) {
                break;
            }
        }
        cout << a << endl;
    }   
    
    return 0;
}
