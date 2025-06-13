//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2111/problem/A)
 **题目大意：**
 有3个整数，最初都是0；
 现在想把3个整数都变成x，可以多次进行以下操作：
 挑选其中一个数字，改变数字的大小，要求是操作之后，数组中的最大值/2（向下取整），不能小于最小值；
 问，最少需要多少次操作。
 
  
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例1行，整数𝑥  (1≤𝑥≤1e9 )
 
  
 **输出：**
 每个样例一行，输出最小操作次数。
 
 **Examples**
 **input**
 7
 1
 5
 14
 2025
 31415
 536870910
 1000000000

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
 假如不考虑最小操作次数，从左到右，分别挑选一个数字进行+1操作（这样肯定不会导致数字过大），3x次操作之后就可以满足要求。
 但是题目要求的是最小操作次数，那么需要每次操作尽可能的大，也就一定是数组的最大值；（由贪心可以知道，每次也会选择数组的最小值去操作）
 
 假设另外两个数字的最小值是x，那么就是2x+1，因为再大就会大于最小值了。
 
 按照这样的思路，就可以找到最小值了。
 由于每次操作有乘2操作，最终可以在O(logN)级别求得答案，直接模拟即可。

 
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
            lld n;
            cin >> n;
            lld a[3] = {0};
            int ans = 0;
            while (true) {
                sort(a, a + 3);
                if (a[0] == n) break;
                lld bigger = min(a[1] * 2 + 1, n);
                a[0] = bigger;
                ++ans;
            }
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "test loyinglin" << endl;
    freopen("data.in", "r", stdin);
    ac.solve();
    
    return 0;
}
 
