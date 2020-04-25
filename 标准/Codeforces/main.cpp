//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接]()
 **题目大意：**
 
 **输入：**
 **输出：**
 
 **Examples**
 
 
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

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n/2; ++i) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n / 2);
    
    int costB = 0, costW = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            costB += abs(i - a[(i+1)/2]);
        }
        else {
            costW += abs(i - a[(i+1)/2]);
        }
    }
    
    cout << min(costB, costW) << endl;
    
    
    return 0;
}
