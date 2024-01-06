//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1913/problem/C)
 **题目大意：**
 给出一个空的数组，现在有两个操作：
 操作1，往数组添加一个数字2^x；
 操作2，询问数组中的若干个数字，数字和是否可以为w；
  
 
 **输入：**
 第一行，整数𝑡 表示m个操作 (1≤m≤100000)
 每个操作一行
 操作1，是输入1和x  (0≤x≤29 ).
 操作2，是输入2和w；(0≤w≤1e9 ).
 
  
 **输出：**
 每个操作2输出一行，存在则输出YES，不存在输出NO；
 
 **Examples**
 **input**
 5
 1 0
 1 0
 1 0
 2 3
 2 4

 **output**
 YES
 NO


 **题目解析：**
 题目的数据范围简化了题目，首先x比较小，数组中最多只有30个整数类型，那么可以按照这个规则聚类；
 其次，在判断数组是否存在某个元素和时，可以从大到小遍历数组，对于某个元素y如果小于等于当前w，则优先取用，并且w=w-y，直到数组末尾；如果此时w=0，则有解，否则无解；
 
 
 
 
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
    static const int M = 536870912; // 2^29
    int a[30];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int k, x;
            cin >> k >> x;
            if (k == 1) a[x]++;
            else {
                int cur = M;
                for (int i = 29; i >= 0; --i) {
                    if (a[i] > 0 && x >= cur) {
                        int left = 1, right = a[i] + 1;
                        int find = left;
                        while (left < right) {
                            int mid = (left + right) / 2;
                            lld sum = 1LL * mid * cur;
                            if (sum > x) {
                                right = mid;
                            }
                            else {
                                find = mid;
                                left = mid + 1;
                            }
                        }
                        x -= find * cur;
                    }
                    cur /= 2;
                }
                cout << (x == 0 ? "YES" : "NO") << endl;
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
 
