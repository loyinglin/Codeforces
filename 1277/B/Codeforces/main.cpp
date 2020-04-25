//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1277/problem/B)
 **题目大意：**
 
 
 输入：
 
 输出：

 
 input
 
 output
 
 
 **题目解析：**
 每次可以选择一个数字x，将数组所有的x=x/2;

 通过贪心的思想可以知道，每次会选择最大的数字开始贪心；
 并且数字出现个数的多少没有影响，那么可以采用这样的策略：
 1、把数组中的数字排序，从大到小开始遍历；
 2、每次拿出最大的数字，如果是奇数则直接通过；如果是偶数，则需要++ans，进入第3步；
 3、判断原来数组里面是否有这个数字；如果有对应数字，则直接通过；如果没有出现过x/2，则把x/2放回数组；
 循环处理，直到结束。
 
 
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

int a[N];
map<int, int> h;
vector<int> s;
priority_queue<int> q;

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        h.clear();
        while (!s.empty()) {
            s.pop_back();
        }
        
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            ++h[k];
        }
        
        for (map<int, int>::iterator iter = h.begin(); iter != h.end(); ++iter) {
            q.push(iter->first);
        }
        
        int ans = 0;
        while (!q.empty()) {
            int top = q.top();
            q.pop();
            if (top % 2 == 0) {
                if (!h[top/2]) {
                    q.push(top / 2);
                }
                ++ans;
            }
        }
        
        cout << ans << endl;
        
    }
           
    
    return 0;
}


/**
 
 */
