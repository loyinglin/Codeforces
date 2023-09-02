//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1845/problem/A)
 **题目大意：**
 有一个整数n，现在有无限个整数1到k；
 现在需要从整数1-k中选择任意个数字，要求满足：
 1、这些整数的和等于n；
 2、这些整数不包括整数x；
 
 问，是否存在这样的组合；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例一行整数𝑛,𝑘 and 𝑥 (1≤𝑥≤𝑘≤𝑛≤100 ).
 
 **输出：**
 每个样例，如果无解直接输出NO；
 如果有解，则先输出YES；然后下一行输出组合的整数个数m，接下来一行输出m个整数；
 
 **Examples**
 **input**
 5
 10 3 2
 5 2 1
 4 2 1
 7 7 3
 6 1 1

 **output**
 YES
 6
 3 1 1 1 1 3
 NO
 YES
 2
 2 2
 YES
 1
 7
 NO


 **题目解析：**
 分类讨论，假设x!=1，那么必然可以用1来组合所有的数字；
 如果 x=1，那么整数1不能选：
 1、如果k=1，无解；
 2、如果k=2，偶数有解（全部是2），奇数无解；
 3、如果k=3，偶数有解（全部是2），奇数有解（去掉一个3变成偶数，剩下全部是2）；
 
 扩展思路：
 这个题目还有个实现方式，采用动态规划，我们用dp[i]表示整数i是否有解，同时用pre[i]记录整数i有解的上一个整数（用于输出）；
 用提供的整数分别去计算所有状态，最终看dp[n]是否有解。
 
 
 
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
            int n, k, x;
            cin >> n >> k >> x;
            if (x != 1) {
                cout << "YES" << endl;
                cout << n << endl;
                while (n--) {
                    cout << "1 ";
                }
                cout << endl;
            }
            else {
                if (k == 1) {
                    cout << "NO" << endl;
                }
                else if (k == 2) {
                    if (n % 2) {
                        cout << "NO" << endl;
                    }
                    else {
                        cout << "YES" << endl;
                        cout << n / 2 << endl;
                        while (n) {
                            cout << 2 << " ";
                            n -= 2;
                        }
                        cout << endl;
                    }
                }
                else {
                    // 2 & 3
                    cout << "YES" << endl;
                    cout << n / 2 << endl;
                    if (n % 2) {
                        cout << 3 << " ";
                        n -= 3;
                    }
                    while (n) {
                        cout << 2 << " ";
                        n -= 2;
                        }
                    cout << endl;
                }
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
 
