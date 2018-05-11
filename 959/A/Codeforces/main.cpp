//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/959/problem/A)
 **题目大意：**
 Mahmoud和Ehab在玩一个数字游戏。有一个整数n，从Mahmoud开始，轮流选择一个数字a，要求：
  * 1 <= a <= n;
  * 如果是Mahmoud选择，a必须是偶数；如果是Ehab选择，a必须是奇数。
 选完数字之后，n=n-a；
 不能选则输掉游戏。
 假设两人的决策都很完美， 现在给出数字n，请问谁能赢。
 
 **输入数据：**
 n (1 ≤ n ≤ 1e9)
 
 >**Examples**
 **input**
 1
 **output**
 Ehab
 **input**
 2
 **output**
 Mahmoud
 
 
 **题目解析：**
 n=1时，Mahmoud必输；
 n=2时，Mahmoud必胜；
 n=奇数时，因为Mahmoud只能取偶数，取完之后还是奇数，那么Ehab直接取n就可以；
 n=偶数时，因为Mahmoud只能取偶数，那么直接取n就必胜。
 
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

int main(int argc, const char * argv[]) {
    // insert code here...
    lld n;
    cin >> n;
    cout << (n % 2 ? "Ehab" : "Mahmoud") << endl;
    return 0;
}
