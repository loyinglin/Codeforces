//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1635/problem/B)
 **题目大意：**
 给出n个整数的数组，每次可以选择数组其中一个元素修改为任意整数；
 现在不希望数组中出现任何元素满足，𝑎[𝑖]>𝑎[𝑖−1] and 𝑎[𝑖]>𝑎[𝑖+1]；
 
 问最少需要操作修改多少次元素，才能满足要求。
 
  **输入：**
 第一行样例数，(1≤𝑡≤10000)
 每个样例两行，第一行是𝑛  (2≤𝑛≤2⋅1e5)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e9)
 
 **输出：**
 每个样例两行，第一行输出最小修改次数；
 第二行输出修改之后的n个整数；
 
 **Examples**
 **input**
 5
 3
 2 1 2
 4
 1 2 3 1
 5
 1 2 1 2 1
 9
 1 2 1 3 2 3 1 2 1
 9
 2 1 3 1 3 1 3 1 3
 **output**
 0
 2 1 2
 1
 1 3 3 1
 1
 1 2 2 2 1
 2
 1 2 3 3 2 3 3 2 1
 2
 2 1 3 3 3 1 1 1 3
 
 **题目解析：**
 先找到元素a[i]满足𝑎[𝑖]>𝑎[𝑖−1] and 𝑎[𝑖]>𝑎[𝑖+1]，要使得满足题目要求，只有三种可能：
 1、修改a[i-1]；
 2、修改a[i]；
 3、修改a[i+1]；
 
 为了方便决策，我们假设从左到右遍历数组，现在遇到了a[i]不符合要求，那么可以选择将a[i-1]或者a[i+1]变大，或者将a[i]变小；
 容易知道这三者对于已经遍历到的元素a[1]到a[i+1]是没有区别的（因为都满足要求），但是考虑到后续还有a[i+2]的元素，那么将a[i+1]变大的选择会更优；
 并且我们可以使得a[i+1]=max(a[i], a[i+2])，这样就可以最大程度利用这一次修改机会。
 
 然后不断循环这个操作直到数组末尾。
 
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
    static const int N = 200010;
    string str;
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            int ans = 0;
            for (int i = 1; i + 1 < n; ++i) {
                if ((a[i] > a[i - 1]) && (a[i] > a[i + 1])) {
                    a[i + 1] = max(a[i], a[i + 2]);
                    ++ans;
                }
            }
            cout << ans << endl;
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
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
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
