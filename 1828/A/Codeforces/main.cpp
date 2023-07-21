//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1828/problem/A)
 **题目大意：**
 给出一个整数n，构造一个长度为n的整数数组a，满足：
 1、1≤𝑎𝑖≤1000 对于所有的 1≤𝑖≤𝑛；
 2、𝑎𝑖 能整除𝑖，对于所有的 1≤𝑖≤𝑛；
 3、𝑎1+𝑎2+…+𝑎𝑛 能够整除 𝑛 .
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤200)
 每个样例一行，整数𝑛 (1≤𝑛≤200)
 
 
 **输出：**
 对于每个样例，输出符合要求的n个整数；
 
 **Examples**
 **input**
 7
 1
 2
 3
 4
 5
 6
 7

 **output**
 1
 2 4
 1 2 3
 2 8 6 4
 3 4 9 4 5
 1 10 18 8 5 36
 3 6 21 24 10 6 14


 **题目解析：**
 对于要求1和要求2比较容易满足，用1、2、3、4、5、、、这样的序列即可；
 对于要求3比较特殊，但是可以利用位置1的任何值都能整除1特性，将数组和多余的部分累计在位置1上面。
 
 
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
            int sum = (1 + n) * n / 2;
            int first = 1;
            if (sum % n != 0) {
                first += n - (sum % n);
            }
            cout << first << " ";
            for (int i = 2; i <= n; ++i) cout << i << " ";
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
 
