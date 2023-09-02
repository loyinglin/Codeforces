//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1845/problem/B)
 **题目大意：**
 在一个二维的网格上，每次可以走向相邻格子；
 Alice和Bob在网格位置（xA, yA）上，Bob要前往格子(xB, yB)，Alice要前往格子(xC, yC)；
 假设Alice和Bob都只会选择到达目的地的最短路径，现在想知道，他们两个可以共同经过的格子数，最大为多少；
 
 [如图所示](https://espresso.codeforces.com/7e6b0a24e49029cda9464b3f2987a9d2ce0c4888.png)
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例3行
 第一行整数𝑥𝐴 and 𝑦𝐴 (1≤𝑥𝐴,𝑦𝐴≤1e8 )
 第二行整数𝑥B and 𝑦B (1≤𝑥B,𝑦B≤1e8 )
 第三行整数𝑥C and 𝑦C (1≤𝑥C,𝑦C≤1e8 )
 
 
 
 **输出：**
 每个样例一行，输出可以共同经过的最大格子数。
 
 **Examples**
 **input**
 3
 3 1
 1 3
 6 4
 5 2
 2 2
 7 2
 1 1
 4 3
 5 5

 **output**
 3
 1
 6


 **题目解析：**
 首先以位置A为坐标原点，重新绘制坐标轴，我们得到新的坐标位置B和C。
 此时两个人都在坐标原点，坐标B、C分别在四大象限或者数轴上。
 可以分情况讨论2个人坐标位置在相同象限、不同象限的情况，但是这样分析简单，实现起来比较复杂。
 另外一种做法，就是拆解从原点到坐标B和坐标C的过程。
 比如说先考虑横坐标X，如果他们两个人方向相同，则得到两个人X坐标较小值为共同距离；
 再考虑横坐标Y，如果他们两个人方向相同，则得到两个人Y坐标较小值为共同距离；
 加上在原点的共同格子，就得到答案了。
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            pair<int, int> a, b, c;
            cin >> a.first >> a.second;
            cin >> b.first >> b.second;
            cin >> c.first >> c.second;
            b.first -= a.first;
            b.second -= a.second;
            c.first -= a.first;
            c.second -= a.second;
            
            int ans = 1;
            // 判断x相同的数量
            if (b.first > 0 && c.first > 0) ans += min(abs(b.first), abs(c.first));
            if (b.first < 0 && c.first < 0) ans += min(abs(b.first), abs(c.first));
            // 判断y相同的数量
            if (b.second > 0 && c.second > 0) ans += min(abs(b.second), abs(c.second));
            if (b.second < 0 && c.second < 0) ans += min(abs(b.second), abs(c.second));
            
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
 
