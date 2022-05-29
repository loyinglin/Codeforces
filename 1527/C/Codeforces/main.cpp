//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1527/problem/C)
 **题目大意：**
 有n个整数的数组，对于一个数组的weight，定位数组中所有的[i, j]，有多少个满足a[i]==a[j]；
 问数组的所有子数组中，所有的weight有多少。
 
 
 
 **输入：**
 第一行是整数t，表示有t个样例(1≤𝑡≤1e4).
 每个样例一行，第一行是整数n(1≤𝑛≤1e9).
 **输出：**
 每个样例一行，输出1到n的整数中，有多少个由相同数字组成的数。

 
 **Examples**
 **input**
 6
 1
 2
 3
 4
 5
 100

 **output**
 1
 2
 3
 4
 5
 18

 
 
 **题目解析：**
 以数字[1,1,2,2,1,1]为例，看看中间[2,2]有多少种情况：
 向左边延伸，左边起点有[2, x]  [1,2,x]  [1,1,2,x]三种可能；
 向右边延伸，右边结尾有[x, 2]  [x, 2,1]  [x,2,1,1]三种可能；
 包括[2,2]的所有子数组，即是从左边起点选择一个起点（3种可能），从右边结尾选择一个结点（3种可能，一共有3x3=9种可能。
 容易知道，对于[i, j]，假如有a[i]==a[j]，则一共会有i*(n-j+1)的可能。（i下标从1开始）
 我们用left[i]来表示i，right[i]来表示n-i+1，则上面的公式表示为left[i]*right[j]。
 
 当有[i,j,k] 满足 a[i] == a[j] == a[k]的时候，我们有left[i]*right[j]+left[i]*right[j] + left[j]*right[k]。
 
 
 所分组累计下，用map区分；然后逐个计算下即可。
 
 注意超long long的trick。
 
 
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
    int n, m;
    int a[N];
    map<int, vector<int>> h;
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            h.clear();
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            for (int i = 0; i < n; ++i) {
                if (h.find(a[i]) != h.end()) {
                    h[a[i]].push_back(i + 1);
                }
                else {
                    vector<int> tmp;
                    tmp.push_back(i + 1);
                    h[a[i]] = tmp;
                }
            }
            lld ans = 0;
            for (map<int, vector<int> > :: iterator it = h.begin(); it != h.end(); ++it) {
                vector<int> vec = it->second;
                lld sum = 0;
                for (int i = 0; i < vec.size(); ++i) {
                    sum += (n - vec[i] + 1);
                }
                for (int i = 0; i < vec.size(); ++i) {
                    sum -= (n - vec[i] + 1);
                    ans += 1LL * vec[i] * sum;
                }
            }
            cout << ans << endl;
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
 
 Example
 inputCopy
 3
 3
 110
 2
 00
 4
 1010
 outputCopy
 ALICE
 BOB
 ALICE
 
 
 5
 10011
 
 5
 00010
 
 
 */
