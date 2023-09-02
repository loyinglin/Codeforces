//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/D)
 **题目大意：**
 在一个二维坐标系上面，有若干个三角形， [如图](https://espresso.codeforces.com/474b2cf0a851296d0f59d5d1c82633f324fac566.png)
 所有三角形的底为d(平行于x轴)，高为h，被y轴分为完全平分。
 现在想知道所有三角形的覆盖面积是多少。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数 𝑛,𝑑,ℎ （1≤𝑛,𝑑,ℎ≤2⋅1e5）
 接下来一行是n个整数 𝑦𝑖 ，表示每个三角形底的高度 (1≤𝑦𝑖≤19,𝑦1<𝑦2<...<𝑦𝑛)
 
 **输出：**
 每个样例一行，输出具体覆盖面积，误差小于10^-6；
 
 **Examples**
 **input**
 5
 3 4 2
 1 4 5
 1 5 1
 3
 4 6 6
 1 2 3 4
 2 1 200000
 1 200000
 2 4 3
 9 11


 **output**
 11
 2.5
 34.5
 199999.9999975
 11.333333



 **题目解析：**
 分情况讨论。
 1、完全分开，就是纯三角形面积，ans += d * h / 2;
 2、有交集，此时三角形面积有部分三角形被重叠。
 假设重叠三角形的底部为y，高为x，这个重叠三角形和整个大三角形相似，可以得知：
 x/y = h/d
 x=a[i+1]-a[i]，h和d已知，那么有y=x*h/d，可以求得重叠三角形的面积。
 
 
  
 
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
            int n, d, h;
            cin >> n >> d >> h;
            for (int i = 0; i < n; ++i) cin >> a[i];
            double ans = 0;
            for (int i = 0; i < n; ++i) {
                if (i + 1 < n && a[i + 1] - a[i] < h) {
                    // 第i个三角形是梯形
                    int x = h - (a[i + 1] - a[i]);
                    ans += (1.0 * x * d / h + d) * (a[i + 1] - a[i]) / 2;
                }
                else {
                    ans += 1.0 * d * h / 2;
                }
            }
            printf("%.6lf\n", ans);
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
