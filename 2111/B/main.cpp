//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2111/problem/B)
 **题目大意：**
 有n个立方体，立方体的边长分别是a1、a2、a3、...、an，并且a是从1开始的Fibonacci数列，也即是1、2、3、5、8...；
 有m个盒子，长宽高长为 𝑤𝑖, 𝑙𝑖, ℎ𝑖。
 现在需要问，是否能把所有的立方体放入盒子中，盒子的长、宽、高都必须严格大于立方体的长、宽、高，并且立方体必须紧贴着盒子，或者紧贴着其他立方体。
 [!参考样式](https://espresso.codeforces.com/54966256bccdbc30210ab7bdc8f99c3da1e1312f.png)
 
  
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e3)
 每个样例，第一行整数 𝑛 and 𝑚 (2≤𝑛≤10,1≤𝑚≤2⋅1e5）
 接下来m行，每行有3个整数𝑤𝑖 , 𝑙𝑖 , and ℎ𝑖  (1≤𝑤𝑖,𝑙𝑖,ℎ𝑖≤150)
   
 **输出：**
 每个样例一行，有m个01整数，第i个整数表示第i个立方体是否能放入盒子中；
 
 **Examples**
 **input**
2
5 4
3 1 2
10 10 10
9 8 13
14 7 20
2 6
3 3 3
1 2 1
2 1 2
3 2 2
2 3 1
3 2 4


 **output**
 3
 7
 9
 23
 31
 59
 61

 样例解释：
 样例1
 [0,0,0]→[1,0,0]→[1,0,1]→[1,1,1]

 样例2
 [0,0,0]→[1,0,0]→[1,1,0]→[1,1,2]→[3,1,2]→[3,5,2]→[5,5,2]→[5,5,5]
 
 **题目解析：**
 

 
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
    int a[11];
public:
    void solve() {
        int t;
        cin >> t;
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= 10; ++i) {
            a[i] = a[i - 1] + a[i - 2];
        }
        while (t--) {
            int n, m;
            cin >> n >> m; 
            string ans;
            while (m--) {
                int w[3];
                for (int i = 0; i < 3; ++i) {
                    cin >> w[i];
                }
                sort(w, w + 3);
                if (w[0] >= a[n] && (w[2] >= a[n] + a[n - 1])) {
                    ans += "1";
                }
                else {
                    ans += "0";
                }
            }
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    // cout << "test B" << endl;
    freopen("data.in", "r", stdin);
    ac.solve();
    
    return 0;
}
 
