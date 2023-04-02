//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1788/problem/A)
 **题目大意：**
 给出n个整数的数组a，数组的元素可能是1或者2；
 现在想要找到一个最小的位置k满足：
 𝑎1⋅𝑎2⋅…⋅𝑎𝑘=𝑎𝑘+1⋅𝑎𝑘+2⋅…⋅𝑎𝑛
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例2行，第一行整数𝑛 (2≤𝑛≤1000）
 第二行n个整数，𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤2).
 
  
 **输出：**
 每个样例一行，输出最小的位置k；如果不存在k，则输出-1；
 
 **Examples**
 **input**
 3
 6
 2 2 1 2 1 2
 3
 1 2 1
 4
 1 1 1 1

 **output**
 2
 -1
 1

 
 **题目解析：**
 由于题目数字取值范围只有1和2，1不影响乘积，那么只需要考虑2；
 如果数组中有偶数个整数，那么题目有解；
 注意如果是0个数字2，那么答案是1；
 
 
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
            vector<int> pos;
            for (int i = 1; i <= n; ++i) {
                int tmp;
                cin >> tmp;
                if (tmp == 2) pos.push_back(i);
            }
            int ans = 1;
            if (pos.size() % 2) ans = -1;
            else if (pos.size() > 0) ans = pos[pos.size() / 2 - 1];
            
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
