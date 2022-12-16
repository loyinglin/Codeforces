//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1761/problem/A)
 **题目大意：**
 给出整数n、a、b，询问是否存在由数字1到n组成的排列p和q，满足下面条件：
 排列p和q的最长公共前缀长度是a；
 排列p和q的最长公共后缀长度是b；
 
 如果排列p和q存在，则输出Yes，否则输出No；
 
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤1000)
 每个样例一行 整数  𝑛, 𝑎, and 𝑏 (1≤𝑎,𝑏≤𝑛≤100).
  
 **输出：**
 每个样例一行，如果排列p和q存在，则输出Yes，否则输出No；
 
 
 **Examples**
 **input**
 4
 1 1 1
 2 1 2
 3 1 1
 4 1 1
 **output**
 Yes
 No
 No
 Yes
 
 **题目解析：**
 有题目的意思可以知道，通常情况下，应该是a+b+c=n，其中a是公共前缀、b是公共后缀、c是中间部分。
 那么有c=n-a-b，如果c>=2，那么只需要将c最左和最右部分的数字进行调换即可。
 比如说n=6,a=2,b=2，那么有排列[1,2,3,4,5,6]，其中[1,2]是前缀，[5,6]是后缀，那么只需要将[3,4]调转得到[4,3]，最终生成新的排列[1,2,4,3,5,6]这样即可。
 
 特殊情况，当a=b=n时，也是一种有解的方案。
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
 
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, a, b;
            cin >> n >> a >> b;
            if ((n == a && n == b) || (n - a - b >= 2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
