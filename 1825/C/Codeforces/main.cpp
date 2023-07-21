//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1825/problem/C)
 **题目大意：**
 有m个位置排成一行，标号分别为1、2、3、、、m；
 给出n个整数代表n个人，分别由-1、-2和正整数组成：
 -1表示选择所有已经有人位置的最左边，在该位置的左边坐下，如果左边已经没有位置（比如到位置1了），那么则选择放弃就坐；如果之前没有人就坐，那么会选择位置m；
 -2表示选择所有已经有人位置的最右边，在该位置的右边坐下，如果右边已经没有位置（比如到位置m了），那么则选择放弃就坐；如果之前没有人就坐，那么会选择位置1；
 正整数x表示选择位置x就坐，如果该位置已经有就坐则放弃；
 
 现在问题，假如可以任意安排n个人的就坐时间，请问最多可以安排多少人就坐。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例2行，第一行整数𝑛 和 𝑚 (1≤𝑛,𝑚≤10000)
 第二行 n个整数， 𝑥1,𝑥2,…,𝑥𝑛 (−2≤𝑥𝑖≤𝑚, 𝑥𝑖≠0)
   
 **输出：**
 对于每个样例，输出最大的就坐人数。
 
 **Examples**
 **input**
 10
 3 10
 5 5 5
 4 6
 1 -2 -2 1
 5 7
 -1 -1 4 -2 -2
 6 7
 5 -2 -2 -2 -2 -2
 6 6
 -1 1 4 5 -1 4
 6 8
 -1 -1 -1 3 -1 -2
 6 7
 5 -1 -2 -2 -2 -2
 3 1
 -2 -2 1
 2 5
 5 -2
 1 2
 -1
 
 **output**
 1
 3
 5
 6
 5
 5
 5
 1
 2
 1

 
 
 
 **题目解析：**
 简化下题目，所有的数字可以分为三类，-1、-2 和 非负正整数（固定位置），相同位置的数字仅需保留一个；
 由题目要求，我们容易知道最初如果选择-1之后，则无法选择-2；（因为m占用了）
 同理，选择-2之后也无法选择-1；（因为1占用了）
 但是如果已经有固定位置x，那么x左边可以填-1，x右边可以填-2。

 三种情况：
 1、先考虑-1，那么从n开始，不断往左，最大数量就是-1 和 固定位置的数量；
 2、先考虑-2，那么从1开始，不断往右，最大数量就是-2 和 固定位置的数量；
 3、先考虑固定位置，假设是最开始是选中位置x，那么从x开始，用-1填充x的左边位置，用-2填充x的右边位置；
 并且由题目意思可以知道，-1将无法再进行填充x右边的位置，-2将无法再进行填充x左边的位置，那么最终结果就是x左边合法位置（固定数量和-1数量） + x右边合法位置（固定位置和-2数量）。这个过程可以做到O(1)；
 由于无法确定x位置，那么可以用枚举的方式，整体复杂度O(N)；
 
 
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
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a, a + n);
            int tmp = 0;
            for (int i = 1; i < n; ++i) {
                if (a[i] == a[i - 1] && a[i] != -1 && a[i] != -2) {
                    a[i - 1] = m + 1;
                    ++tmp;
                }
            }
            sort(a, a + n);
            n -= tmp;
            int cnt1 = 0, cnt2 = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == -1) ++cnt1;
                else if (a[i] == -2) ++cnt2;
                else ++cnt;
            }
            int ans = 0;
            // case1, -1
            ans = max(ans, min(m, cnt1 + cnt));
            ans = max(ans, min(m, cnt2 + cnt));
            tmp = 0;
            for (int i = cnt1 + cnt2; i < n; ++i) {
                int sum = 1;
                // left
                sum += min(a[i] - 1, tmp + cnt1);
                // right
                sum += min(m - a[i], cnt - tmp - 1 + cnt2);
                // 最终结果就是x左边合法位置（固定数量和-1数量） + x右边合法位置（固定位置和-2数量）
                ans = max(ans, sum);
                ++tmp;
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
 
