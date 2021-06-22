//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/980/problem/A)
 **题目大意：**
 我们用一个字符串来描述一串项链，字符串由'o'和'-'组成，o表示珠子，-表示链条；（字符串第一个字符和最后一个字符相连）
 现在可以对项链进行重新组合，即对'o' '-'的字符串重新排列，问是否能满足要求：
 珠子之间链条的数量是相同；
 
 输入：
 第一行：字符串str，表示项链；（注意，可能出现一个珠子、多个珠子、没有珠子的情况）
 输出：
 YES如果能满足要求，NO如果不能满足要求；
 
 **输入数据：**
 
 **Examples**
 **input**
 -o-o--
 **output**
 YES
 
 **题目解析：**
 先统计-和o的数量x，y；
 分类讨论：
 y=0的时候，那么必然是YES；
 y!=0，那么当x%y==0的时候，是YES；否则是NO；
 
 
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
