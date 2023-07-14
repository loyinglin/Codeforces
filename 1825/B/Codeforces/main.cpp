//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1825/problem/B)
 **题目大意：**
 给出一个n x m的整数矩阵，现在我们定义矩阵和为：
 对于矩阵中每一个位置，都计算一遍该位置到左上角所组成的子矩阵，将子矩阵的最大值减去最小值。
 （参考链接截图）
 ∑𝑖=1-𝑛
 ∑𝑗=1-𝑚
 (1≤𝑥≤𝑖, 1≤𝑦≤𝑗)a[𝑥,𝑦]的最大值   −   (1≤𝑥≤𝑖, 1≤𝑦≤𝑗)a[𝑥,𝑦]的最小值。
 
 现在可以对矩阵中的元素任意调整位置，求最大的矩阵和。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤200)
 每个样例2行，第一行整数𝑛 和 𝑚 (2≤𝑛,𝑚≤100)
 第二行 n x m个整数，𝑏1,𝑏2,…,𝑏𝑛⋅𝑚 (−1e5≤𝑏𝑖≤1e5)
   
 **输出：**
 对于每个样例，输出最大的矩阵和。
 
 **Examples**
 **input**
 5
 2 2
 1 3 1 4
 2 2
 -1 -1 -1 -1
 2 3
 7 8 9 -3 10 8
 3 2
 4 8 -3 0 -7 1
 4 3
 -32030 59554 16854 -85927 68060 -64460 -79547 90932 85063 82703 -12001 38762

 **output**
 9
 0
 64
 71
 1933711

 
 **题目解析：**
 题目的意思看着比较复杂，实则要素并不多，对于一个矩阵，真正有意义的就只有4个数字：最小的2个和最大的2个。
 按照规则，所有的子矩阵，都由这4个数字组成，因为只关注子矩阵的最大值和最小值。
 
 于是两种，一种是最小值在左上角，相邻位置放最大值和次大值；
 一种是最大值在左上角，相邻位置放最小值和次小值；
 
 以样例1来看，就有两种可能：
 1 3
 4 1
 或者
 4 1
 1 3
 
 针对两种情况都进行计算，取最大值即可。
 
 下面分析一下具体的计算方式，以第一种为例。
 当我们在摆放时，首先取出最小值放左上角，那么最大值应该放在相邻最长的一边，这样能最大利用最大值和最小值的差。
 为了方便计算，我们令 n <= m；（如果n > m那么交换他们的位置）
 这样就可以单独两条边（第一行、第一列）的子矩阵和，最后用（最大值-最小值）x（n-1）x（m-1）即可。
 
 
 
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
    lld a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            if (n > m) {
                int tmp = m;
                m = n;
                n = tmp;
            }
            for (int i = 0; i < n * m; ++i) scanf("%lld", &a[i]);
            sort(a, a + n * m);
            lld ans1 = 0;
            ans1 += (a[n * m - 1] - a[0]) * (m - 1);
            ans1 += (a[n * m - 2] - a[0]) * (n - 1);
            ans1 += (a[n * m - 1] - a[0]) * (n - 1) * (m - 1);
            
            lld ans2 = 0;
            ans2 += (a[n * m - 1] - a[0]) * (m - 1);
            ans2 += (a[n * m - 1] - a[1]) * (n - 1);
            ans2 += (a[n * m - 1] - a[0]) * (n - 1) * (m - 1);
            cout << max(ans1, ans2) << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
