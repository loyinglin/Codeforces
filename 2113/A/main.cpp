//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2113/problem/A)
 烤羊肉串（Shashliks）
你是一家热门烤羊肉串餐厅的老板，而你的烤架是厨房的核心。
不过，这台烤架有个特点：每烤完一串羊肉串后，它的温度会下降。
你需要尽可能多地烤制羊肉串，并且有无限量的两种类型的串可供烤制：
- 第一种类型在开始烤制时，要求烤架温度至少为α度，烤制完成后，烤架温度会下降x度。
- 第二种类型在开始烤制时，要求烤架温度至少为b度，烤制完成后，烤架温度会下降y度。
最初，烤架的温度是k度。请确定最多能烤制的羊肉串份数。
注意，烤架的温度可以是负数。

输入
每个测试包含多个测试用例。第一行包含测试用例的数量t（t ≤ 10⁴）。接下来是各测试用例的描述。
每个测试用例仅一行，包含五个整数k、a、b、x、y（1 ≤ k, a, b, x, y ≤ 10⁹）
分别是烤架的初始温度、烤制第一种和第二种羊肉串所需的起始温度，以及烤制第一种和第二种羊肉串后烤架的温度下降值。

输出
对于每个测试用例，输出一个整数——即你最多能烤制的羊肉串份数。
示例
输入
5
10 3 4 2 1
1 10 10 1 1
100 17 5 2 3
28 14 5 2 4
277 5 14 1 3

输出
8
0
46
10
273


 
**题目解析：**
假设只有一种肉串，那么可以直接计算得到结果，计算k与a之间的差值，除以x就可以得到数量；
假设只有两种肉串，我们会优先烤制温度下降更少的类型，当无法烤制这种肉串时，再去烤制另外一种类型的肉串，这样就得到最优解了。

我们可以通过交换，使得假设温度下降更多的类型为a，温度下降更少的类型为b；
如果x>y，我们可以交换x和y，以及a和b，这样可以保证x<=y；
如果k<a，那么无论如何都无法烤制到第一种类型的肉串，输出0；
如果k>=a，先计算可以烤制a类型的肉串的数量，再计算可以烤制b类型的肉串的数量；
 
 
 
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
            int k, a, b, x, y;
            cin >> k >> a >> b >> x >> y;
            int ans = 0;
            if (x > y) {
                swap(x, y);
                swap(a, b);
            }
            if (k >= a) {
                ans += (k - a) / x + 1;
                k -= ans * x;
            }
            if (k >= b) {
                ans += (k - b) / y + 1;
            }
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
