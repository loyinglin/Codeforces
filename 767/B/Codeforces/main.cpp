//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/767/problem/B
 题目大意：
 小明要去一个地方办业务，业务员上班时间是Ts到Td；
 办业务的人很多，排成一列，业务员为每个人办业务都需要时间Tf;
 已知n个人的到达时间a[i], a[i]为正整数；（a[i] < a[i+1])
 小明可以在任何非负整数的时间到达，如果和其他人同时到达，小明会让其他人先，自己排队；
 现在小明希望排队时间最短，问：他应该在哪个时间点到达；如果有多个答案，输出任何一个；
 
 (0 ≤ n ≤ 100 000)
 Ts和Td最大不超过1e12；
 
 Examples
 input
 10 15 2
 2
 10 13
 output
 12
 input
 8 17 3
 4
 3 4 5 8
 output
 2
 
 
 
 题目解析：
 
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
    
    int n;
    cin >> n;
    
    string ret = "I hate ";
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            ret += "that I love ";
        }
        else {
            ret += "that I hate ";
        }
    }
    ret += "it";
    cout << ret << endl;
    
    return 0;
}
