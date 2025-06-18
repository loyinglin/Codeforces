//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2111/problem/C)
 **题目大意：**
给你一个由 n 个整数组成的数组 a₁，a₂，…，aₙ。
在一次操作中，你可以执行以下操作之一：
选择一个位置 i（1 <i ≤ n），并将 i 左边的所有元素都设为 aᵢ。也就是说，将 aⱼ（1 ≤ j < i）的值都赋为 aᵢ。这样操作的成本是 (i - 1)・aᵢ。
选择一个位置 i（1 ≤ i <n），并将 i 右边的所有元素都设为 aᵢ。也就是说，将 aⱼ（i < j ≤ n）的值都赋为 aᵢ。这样操作的成本是 (n - i)・aᵢ。
需要注意的是，操作影响的元素可能已经等于 aᵢ，但这不会改变操作成本。
你可以执行任意次数的操作（包括零次）。要使数组的所有元素都相等，最小的总成本是多少？

输入
第一行包含一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
每个测试用例的第一行包含一个整数 n（2 ≤ n ≤ 5・10⁵）。
第二行包含 n 个整数 a₁，a₂，…，aₙ（1 ≤ aᵢ ≤ n）。
所有测试用例的 n 之和不超过 5・10⁵。
输出
对于每个测试用例，输出一个整数 —— 使数组所有元素相等所需操作的最小总成本。
 
 
 **Examples**
 **input**
3
4
2 4 1 3
3
1 1 1
10
7 5 5 5 10 9 9 4 6 10


**output**
3
0
35
 
**题目解析：**
由于最终的数字是确定的，我们可以枚举最终的数字，然后计算出每种情况下的成本，取最小值即可。
并且题目限制，最终数字一等于于某个位置的数字，那么在枚举到为止i时，我们可以知道最终结果是a[i]，假如a[i+1]!=a[i]，那么a[i+1]需要操作；假如a[i+1]==a[i]，那么久可以往后考虑。
这样往右边，往左边计算一遍，就可以得到最终结果。

但是题目数据量级较大，如果直接枚举每个位置，时间复杂度就是O(N^2)，会超时；
考虑优化，我们可以先从左到右计算一遍，把每个相同数据聚合在一起，然后操作的时候，直接从数据段之外的范围操作，这样的时间复杂度就是O(N)；
 
 
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
    static const int N = 501010;
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
            int last = -1;
            lld ans = -1;
            for (int i = 0; i < n; ++i) {
                lld tmp = 0;
                if (i > 0 && a[i] != a[i - 1]) {
                    last = i - 1;
                }
                tmp += 1LL * (last + 1) * a[i];
                if (i < n - 1) {
                    tmp += 1LL * (n - i - 1) * a[i];
                }
                if (ans < 0 || ans > tmp) {
                    ans = tmp;
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
 
