//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1684/problem/A)
 **题目大意：**
 给出一个整数n，现在可以对整数执行一个操作：
 选择整数上两个不同位数的数字交换位置，然后移除整数最右边一位的数字；
 重复这个过程，直到整数只剩下1位；
 现在想知道这个剩下的数字最小可能为多少。
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤10000)
 每个样例俩行，第一行 整数 𝑛 (10≤𝑛≤1e9)
  
 **输出：**
 每个样例一行，剩下最小的数字；
 
 
 **Examples**
 **input**
 3
 12
 132
 487456398
 **output**
 2
 1
 3
 
 
 **题目解析：**
 右边第二位是必胜位，每次都选择其他位数的数字进行交换，在只剩下2位数字的时候，将第一位和第二位交换，然后会去掉右边的数字，剩下原来右边第二位的数字；
 也就是说，当时数字位数大于等于3的时候，可以选择整数上最小的数字，将这个数字放在右边第二位，再采用上面的策略必然可以留下来；
 当数字位数只有2位时，留下来的数字必然是最右边的数字；
 
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

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            if (n < 99) {
                cout << n % 10 << endl;
            }
            else {
                int ans = 9;
                while (n) {
                    ans = min(ans, n % 10);
                    n /= 10;
                }
                cout << ans << endl;
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
 */
