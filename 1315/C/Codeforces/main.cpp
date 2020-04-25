//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1315/problem/C)
 **题目大意：**
 给出n个整数b[i]，现在希望构造一个数组，包括2n整数a[i]；
 这个数组字典序尽可能的小，并且满足 𝑏[𝑖]=min(𝑎[2𝑖−1],𝑎[2𝑖])；
 
 **输入：**
 第一行 整数𝑡 (1≤𝑡≤10^4)
 接下来t个样例，每个样例两行
 第一行1个整数n， (1≤𝑛≤100).
 第二行n个整数b[i]  (1≤b[i]≤2𝑛）
 
 **输出：**
 每个样例一行，每行2n个整数；
 
 **Examples**
 input
 5
 1
 1
 2
 4 1
 3
 4 1 3
 4
 2 3 4 5
 5
 1 5 7 2 8
 
 
 output
 1 2
 -1
 4 5 1 2 3 6
 -1
 1 3 5 6 7 9 2 4 8 10
 
 **题目解析：**
 考察的是构造能力。
 从要求来看，就是最终的结果是2个就有1个原来的数字；
 由于字典序要求最小，并且𝑏[𝑖]是min(𝑎[2𝑖−1],𝑎[2𝑖])，所以b[i]肯定是放在前面的位置；
 整个构造的数组是b[0], x, b[1], x, b[2], x....
 问题变成，如何在1~2n的数字中，找到合适的数字分配到x的位置中。
 按照题目的要求，可以每次从1~2n中没出现的数字找到一个，然后分到x中；如果所有合法的数字都不存在，则题目无解。
 
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
const int N = 100100, M = 3010100, inf = 0x7fffffff;
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

int a[N], mp[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(mp, 0, sizeof(int) * (n * 2 + 1));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        
        int ok = 1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(a[i]);
            int find = 0;
            for (int j = a[i] + 1; j <= 2*n; ++j) {
                if (!mp[j]) {
                    find = 1;
                    mp[j] = 1;
                    ans.push_back(j);
                    break;
                }
            }
            if (!find) {
                ok = 0;
                break;
            }
        }
        
        if (!ok) {
            cout << -1 << endl;
        }
        else {
            for (int i = 0; i < n*2; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}


/**
 5
 2 2 1
 BB
 1 1 1
 AB
 3 2 8
 AABBBBAABB
 5 3 4
 BBBBB
 2 1 1
 ABABAB
 
 */
