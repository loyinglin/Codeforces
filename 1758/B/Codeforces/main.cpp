//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1758/problem/A)
 **题目大意：**
 给出整数n，现在需要找到n个整数𝑎1,𝑎2,…,𝑎𝑛 满足   1≤𝑎[𝑖]≤1e9，并且有：
 𝑎1⊕𝑎2⊕⋯⊕𝑎𝑛=(𝑎1+𝑎2+⋯+𝑎𝑛)/𝑛。

 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例1行，整数 𝑛 (1≤𝑛≤1e5)
   
 **输出：**
 每个样例一行，输出满足要求的n个整数。
 
 
 **Examples**
 **input**
 3
 1
 4
 3
 **output**
 69
 13 2 8 1
 7 7 7
 
 **题目解析：**
 先从n=1开始考虑，此时任意数字都满足；
 n=2时，首先a1+a2必须是偶数，那么我们可以推测二进制尾部一定都是0或者1，假设a1+a2结果是4，那么有1和3符合要求；
 n=3时，类似n=1，我们加入两个相同数字，1+1+1也满足；
 n=4时，我们知道n=2时，有1+3满足要求，并且结果是2，那么可以加入2个2，得到1、3、2、2；
 ...
 
 思考：
 题目的重点在于关注到异或的特点，两个相同数字异或值为0；
 
 
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
#include<cstring>
#include<iostream>

using namespace std;
 
typedef long long lld;
 
class Solution {
    static const int N = 201010;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            if (n % 2) {
                for (int i = 0; i < n; ++i) cout << 1 << " ";
                cout << endl;
            }
            else {
                cout << "1 3 ";
                for (int i = 0; i < n - 2; ++i) cout << 2 << " ";
                cout << endl;
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
 
