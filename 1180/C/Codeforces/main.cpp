//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1180/problem/C)
 **题目大意：**
 有一个数组a，长度为n；
 现在有一个操作，从数组最前面（a[0],a[1]）拿出两个数字假设是x，y；
 如果x<y，则把x放在数组的最后面，把y放在数组的最前面；
 如果x>=y,则把x放在数组的最前面，把y放在数组的最前面；
 
 问这个操作进行若干次之后，每次拿出来的数字x、y是什么；
 
 输入：
 
 
 输出：
 
 
 
 **题目解析：**
 若干次之后，数组中最大值会始终占据第一位；
 剩余的则在1~n-1的位置不断轮换。
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

pair<int, int> ans[M];
int r[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, t;
    cin >> n >> t;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        q.push_back(k);
    }
    
    for (int i = 1; i < n; ++i) {
        int a = q.front();
        q.pop_front();
        int b = q.front();
        q.pop_front();
        ans[i] = make_pair(a, b);
        if (a > b) {
            q.push_front(a);
            q.push_back(b);
        }
        else {
            q.push_front(b);
            q.push_back(a);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        r[i] = q.front();
        q.pop_front();
    }
    

    while (t--) {
        lld k;
        cin >> k;
        if (k < n) {
            cout << ans[k].first << " " << ans[k].second << endl;
        }
        else {
            --k;
            k = k % (n-1);
            cout << r[0] << " " << r[k + 1] << endl;
        }
    }
    
    return 0;
}
