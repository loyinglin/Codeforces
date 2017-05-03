//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/762/problem/A
 题目大意：
 给出一个数字n，求数字n所有因子中，第k大的数字；
 如果没有输出-1；
 
 n and k (1 ≤ n ≤ 1e15, 1 ≤ k ≤ 1e9)
 
 Examples
 input
 4 2
 output
 2
 input
 5 3
 output
 -1
 
 
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
    
    lld n, k;
    cin >> n >> k;
    
    int t = sqrt(n);
    vector<lld> ans;
    
    for (int i = 1; i <= t; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }
    
    sort(ans.begin(), ans.end());
    if (ans.size() >= k) {
        cout << ans[k - 1] << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    
    return 0;
}
