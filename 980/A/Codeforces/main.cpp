//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Numbers Exchange
 [题目链接](http://codeforces.com/contest/980/problem/C)
 **题目大意：**
 
 **输入数据：**
 
 >**Examples**
 **input**
 **output**
 
 **题目解析：**
 默认都不染色，某个点，尽可能往前找能够染色的点，如果都没找到，那么以cur=max(0, x-k+1)为界；
 如果找到已经被染色过的点，那么看其已经染色过点的长度，如果还能容得下，则兼容进去，否则以cur+1为界，开始染色；
 
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
int color[1000];

int checkLen(int x) {
    int sum = 1;
    for (int i = x - 1; i >= 0; --i) {
        if (color[i] == color[x]) {
            ++sum;
        }
        else {
            break;
        }
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string str;
    cin >> str;
    int x = 0, y = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '-') {
            ++x;
        }
        else {
            ++y;
        }
    }
    
    if (y == 0 || x % y == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
    
    return 0;
}
