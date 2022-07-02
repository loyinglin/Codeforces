//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1691/problem/B）
 **题目大意：**
 给出n个整数a，a[i]<=a[i+1]；
 现在需要调整这些整数，得到数组b；
 要求b[i]>=a[i]；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例俩行，第一行 整数  𝑛 (1≤𝑛≤1e5)
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e9,  𝑎𝑖≤𝑎𝑖+1)
  
 **输出：**
 每个样例一行，如果有解则输出调换后的顺序；（不能和原来一样）
 如果无解则输出-1；
 
 
 **Examples**
 **input**
 2
 5
 1 1 1 1 1
 6
 3 6 8 13 15 21
 
 **output**
 5 1 2 3 4
 -1
 
 
 **题目解析：**
 由于调换之后，要保持新的数字大于旧的数字，那么可以推出只能换相同的数字，因为假如换过来一个更大的数字，那么这个数字所在的位置就无法得到一个更大的数字；
 
 于是，我们只需要遍历数组，遇到不同的数字，则检查下前面不同整数的情况，如果大于1个，则挪一个位置即可；
 
 
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
    static const int N = 201010;
    int a[N];
    int c[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> vec;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &a[i]);
            }

            int left = 0, right = 0;
            int ans = 1;

            for (int i = 1; i <= n; ++i) {
                if ((i == n) || (a[i] != a[i - 1])) {
                    right = i;
                    // [left, right)
                    if (right - left <= 1) {
                        ans = 0;
                        break;
                    }
                    for (int j = left; j < right - 1; ++j) {
                        c[j] = j + 1;
                    }
                    c[right - 1] = left;
                    left = i;
                }
            }
            if (ans) {
                for (int i = 0; i < n; ++i) {
                    cout << c[i] + 1 << " ";
                }
                cout << endl;
            }
            else {
                cout << -1 << endl;
            }
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
 
 
 112
 5
 1 1 1 1 1
 6
 1 1 2 2 3 3
 
 6
 1 2 2 2 3 4
 
 6
 1 1 2 2 2 3
 
 
 
 */
