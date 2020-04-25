//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1288/problem/C)
 **题目大意：**
 
 
 输入：
 
 
 输出：


 
 input
 
 output
 
 
 **题目解析：**
 
 
 
 
 
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
const int N = 301010, M = 256, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

class SolutionA {
    int a[N][8];
    int n, m;
    
    bool check(int mid, pair<int, int> &ans) {
        int index[M];
        for (int i = 0; i < M; ++i) {
            index[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                t <<= 1;
                if (a[i][j] >= mid) {
                    t++;
                }
            }
            index[t] = i;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = i; j < M; ++j) {
                if (index[i] == -1 || index[j] == -1) {
                    continue;
                }
                
                int k = i | j;
                if (k == ((1 << m) - 1)) {
                    ans.first = index[i];
                    ans.second = index[j];
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    void solve() {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        
        int l = 0, r = 1e9;
        pair<int, int> ans_index;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, ans_index)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        cout << ans_index.first + 1 << " " << ans_index.second + 1 << endl;
        
    }
    
}binary_ans;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    binary_ans.solve();
           
    
    return 0;
}


/**
 6 4
 3 0 0 3
 0 3 3 1
 0 1 1 1
 1 1 0 1
 2 2 2 2
 1 1 1 1
 */
