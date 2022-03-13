//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1647/problem/A)
 **题目大意：**
 给出一个整数n，求一个最大整数满足：
 1、整数各个数字加起来等于n；
 2、没有两个相同的数字相邻；
 3、数字中不包括0；
 
 比如说n=2，满足条件1的整数有11、2、20等，但是满足条件1、2、3的就是数字2；
 
  **输入：**
 第一行，整数𝑡 表示t个样例 (1≤𝑡≤1000)
 每个样例一行，整数𝑛 (1≤𝑛≤1000)
 **输出：**
每个样例输出一行，满足条件的最大整数。
 
 **Examples**
 **input**
 5
 1
 2
 3
 4
 5
 **output**
 1
 2
 21
 121
 212
 
 **题目解析：**
 题目要求的数字尽可能的大，那么数字的位数会比数字的大小更加重要，那么可以论证最终数字中不存在大于3的数字；
 假如最大整数是3xx的整数，那么可以构造出来21xx使得结果更大；
 同时由于条件2的存在，结果必然是以1212或者2121这样的交替结果。
 为了便于计算，我们将n%3，得到一个余数q；
 q=0时，结果是2121...；
 q=1时，结果是12121...；
 q=2时，结果是21212...；

 
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
            int k = n % 3;
            if (k == 0) {
                for (int i = 0; i < n / 3; ++i) {
                    cout << "21";
                }
                cout << endl;
            }
            else if (k == 1) {
                cout << 1;
                for (int i = 0; i < n / 3; ++i) {
                    cout << "21";
                }
                cout << endl;
            }
            else {
                cout << 2;
                for (int i = 0; i < n / 3; ++i) {
                    cout << "12";
                }
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
