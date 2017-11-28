//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/895/problem/A
 题目大意：小明有一个圆披萨，分成n块（扇形）；（1<=n<=360)
 每块的角度是a[i](整数，1<=a[i]<=360)，并且总的角度和是360。
 把这些披萨分成**连续**的两部分，求两部分披萨的最小角度差。
 
 
 题目解析：
 分成两部分，并且差最小，相当于尽可能逼近180°。
 又因为题目要求是连续，所以直接枚举区间的起点和终点，大概是360^2的复杂度。
 
 
 思考：如果改成不连续的俩部分呢？
 >180容量的背包。
 
 
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
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    int ans = 360;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; sum < 180 && j < n; ++j) {
            sum += a[j];
            ans = min(ans, abs(sum - 180));
        }
    }
    
    cout << ans * 2 << endl;
    
    return 0;
}
