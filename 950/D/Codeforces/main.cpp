//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/950/problem/D)
 **题目大意：**
 有若干个格子排成一行序号是1、2、3、4、5、、、，有1~n的n个整数分别放在格子里，第i个数字放在第2i-1格子；
 现在对数字进行操作：
 每次把最右边的数字x，放在x左边最近的空格里；
 不断重复，直到x左边没有空的格子；
 
 现在有q个询问，每个询问是数字x[i]，求第x[i]个格子上面的数字；
 
 
 
 **输入数据：**
 n and q (1 ≤ n ≤ 1e18, 1 ≤ q ≤ 200 000)
 
 >**Examples**
 **input**
 4 3
 2
 3
 4
 **output**
 3
 2
 4
 样例解释：
 分3个子序列010，010，0；
 
 **题目解析：**
 从题目的操作结果来看，最后操作停止的结果必然是n个数字分布在第1到n个格子里；
 容易知道，小于等于n/2的数字是不会动的。（因为数字的左边没有格子）
 相当于后面(x - n/2)数字排列紧密（没有空格），然后数字的最后一个跳到前面；
 于是可以用递归的思想解决问题，不断重复，直到数字剩下1个。
 
 
 如何看出递归的想法：
 我们用0表示空格，当n=8的时候，原序列为1，0，2，0，3，0，4，0，5，0，6，0，7，0，8
 
 
 
  **思考🤔：**
 trick: long long。
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
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

char str[N];
vector<int> ans[N];

/**
 1 2 3 4 5 6 按照原来的规则进行选择，最右边的一个

 @param n 前n个
 @return 最右边的一个
 */
lld solve(lld n) {
    if (n % 2) {
        return (n + 1) / 2;
    }
    return n / 2 + solve(n - n / 2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    lld n, q;
    cin >> n >> q;
    while (q--) {
        lld x;
        cin >> x;

        if (x % 2 == 1) {
            cout << (x + 1) / 2 << endl;
        }
        else {
            cout << solve(n - x / 2) + x / 2 << endl;
        }
    }
    
    
    return 0;
}
