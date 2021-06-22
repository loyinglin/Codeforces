//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1536/problem/A)
 **题目大意：**
 n个数字，要求任意两个数字的差，仍然在数组中。
 
  **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤250).
 每个样例第一行是整数𝑛 (1≤𝑛≤100).
 **输出：**
 如果有解，则输出n行，每行n个整数；
 如果无解则输出-1；
 
 **Examples**
 **input**


 
 **output**

 
 **题目解析：**
 数组中不会存在负数，反证法：
 假设a[i]-a[j]，a[j]小于零，则必然需要一个比a[i]的数字a[k]，但是a[k]-a[j]又会变大；
 
 其他的情况，就用1、2、3、4到max来填充即可。
 
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
public:

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int maxNum = 0, minNum = 200;
            for (int i = 1; i <= n; ++i) {
                int k;
                cin >> k;
                maxNum = max(maxNum, k);
                minNum = min(minNum, k);
            }
            if (minNum < 0) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                cout << maxNum + 1 << endl;
                for (int i = 0; i <= maxNum; ++i) {
                    cout << i << " ";
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
