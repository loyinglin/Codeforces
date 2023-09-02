//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/A)
 **题目大意：**
 在地面上有n个点，点都在同一条垂直地面的线上面，每个点的高度为a[i]；
 每个点有一条绳子，绳子长度为b[i]，一端连着点，一端连着小球（每个点相连的小球是同一个），[如图](https://espresso.codeforces.com/00f14114dd979e028305fc59f7fa58a0718d918f.png)；
 现在想知道，切掉多少条绳子，小球会掉落到地面。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数𝑛 (1≤𝑛≤50).
 接下来n行，每行两个整数 𝑎𝑖 and 𝑏𝑖 (1≤𝑎𝑖,𝑏𝑖≤200 )
 
 **输出：**
 每个样例一行，输出最少需要剪断的绳子数量；
 
 **Examples**
 **input**
 4
 3
 4 3
 3 1
 1 2
 4
 9 2
 5 2
 7 7
 3 4
 5
 11 7
 5 10
 12 9
 3 2
 1 5
 3
 5 6
 4 5
 7 7


 **output**
 2
 2
 3
 0




 **题目解析：**
阅读理解题，如果某个点的高度大于绳子的长度，那么需要切断这个绳子。
 那么只要遍历每个点，计算a[i]>b[i]的数量。
 
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
            int ans = 0;
            while (n--) {
                int x, y;
                cin >> x >> y;
                ans += x > y;
            }
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
 
