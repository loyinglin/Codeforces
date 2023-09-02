//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/A)
 **题目大意：**
 有n个整数的数组a，现在需要给数组每个元素进行染色，注意：
 1、每个元素只能有一个颜色；
 2、每个元素都要染色；
 每个颜色的收益，等于染该色的元素中最大值减去最小值；
 问，染色完所有元素后，最大的收益是多少。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例2行，第一行整数𝑛 (1≤𝑛≤50)
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤50)
 
 
 **输出：**
 每个样例一行，输出最大的收益。
 
 **Examples**
 **input**
 6
 5
 1 5 6 3 4
 1
 5
 4
 1 6 3 9
 6
 1 13 9 3 7 2
 4
 2 2 2 2
 5
 4 5 2 2 3

 **output**
 7
 0
 11
 23
 0
 5



 **题目解析：**
 每个颜色如果只有1个元素，没有收益；
 如果有3个元素，生效的只有最小和最大值，所以每个颜色最多染色2个元素；
 那么将元素排序，每次选择最小和最大值即可。
 
 
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
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n);
            int sum = 0;
            for (int i = 0; i < n / 2; ++i) {
                sum += a[n - i - 1] - a[i];
            }
            cout << sum << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
