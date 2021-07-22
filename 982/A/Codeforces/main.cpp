//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Row
 [题目链接](http://codeforces.com/contest/982/problem/A)
 **题目大意：**
 有一排椅子，总共有n个；
 有若干个人坐在上面，我们用数字'0'表示这个位置是空的，'1'表示这个位置已经有人；
 人们不想靠的太近，所以不能有两个座位连着坐人；
 同时人们也不喜欢浪费，所以希望椅子尽可能多的坐人；
 
 现在已知n个椅子的情况，问这排椅子是否已经坐满？
 
 
 
 
 **输入数据：**
 𝑛  (1≤𝑛≤1000)
 
 **输出数据：**
 YES或者NO，表示是否已经坐满。
 
 Examples
 input
 3
 101
 output
 Yes
 input
 4
 1011
 output
 No
 
 **题目解析：**
 反过来思考，如果椅子没坐满，肯定可以有一个位子可以坐下人，并且仍然满足题目要求。
 题目数据量不大，可以枚举每一个为0的位置，将其改为1判断是存在合法数字。
 
 
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
char a[N];
int dp[N];

bool check_adjacent(int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] == '1' && a[i] == a[i - 1]) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    cin >> a;
    
    if (check_adjacent(n)) {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            a[i] = '1';
            if (!check_adjacent(n)) {
                cout << "No" << endl;
                return 0;
            }
            a[i] = '0';
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}
