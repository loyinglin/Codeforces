//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1515/problem/C)
 **题目大意：**
 有n个整数a[i]，需要将n个整数分成m组，要求每组数字和之差不超过x；
 
 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 有一个很重要的点，是所有的数字都比x小，那么必然可以满足题目要求，比如说下面这种方式：
 从左到右放数字，每次从m组数字中，挑出数字和最小的一组，放入该数字；
 由于放入之前数字和之差小于等于x，那么往最小数字和的分组放入数字，并且该数字小于等于x，可以知道最终仍满足数字和之差小于等于x；
 用数学的方式来描述：
 已知A<=B且A+x>=B，然后我们有数字t（t<=x）
 那么必然有A+t <= B+x，也就是A+t和B之差仍不会超过x；
 
 
 
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

class Solution {
    static const int N = 100010;
public:
    int n, m, x, tmp;
    priority_queue<pair<lld, int> > top;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> m >> x;
            
            while (!top.empty()) {
                top.pop();
            }
            for (int i = 0; i < m; ++i) {
                top.push(make_pair(0, i + 1));
            }
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                cin >> tmp;
                pair<lld, int> cur = top.top();
                top.pop();
                cur.first -= tmp;
                top.push(cur);
                printf("%d ", cur.second);
            }
            cout << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 2
 5 2 3
 1 2 3 1 2
 4 3 3
 1 1 2 3
 */
