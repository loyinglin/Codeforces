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
 
 
 
 
 **输入数据：**
 
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
const int N = 401000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first > tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

struct cmp
{
    bool operator()(Node a,Node b) { return  a.first < b.first; }
};


char str[N];
int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    priority_queue<Node> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        q.push(Node(a[i], i));
    }
    cin >> str;
    
    priority_queue<Node, vector<Node>, cmp> qBig;
    
    for (int i = 0; i < n * 2; ++i) {
        if (str[i] == '0') {
            Node top = q.top();
            q.pop();
            cout << top.second << endl;
            qBig.push(top);
        }
        else {
            Node top = qBig.top();
            qBig.pop();
            cout << top.second << endl;
        }
    }
    

    return 0;
}
