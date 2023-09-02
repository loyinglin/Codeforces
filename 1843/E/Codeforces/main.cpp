//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1843/problem/E)
 **题目大意：**
 有n个整数的数组，初始状态元素都是0；
 有m个区间[ 𝑙𝑖,𝑟𝑖]，我们定义一个区间是beautiful的，只要这个区间内，数字1的数量严格大于数字0的数量；
 有q个操作依次执行，每次操作是将q𝑖位置的元素变为1；
 现在想知道，当第几次操作后，m个区间中将出现至少1个beautiful的区间。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例，第一行整数𝑛 and 𝑚 (1≤𝑚≤𝑛≤1e5 )
 接下来有m行，每行两个整数表示区间 𝑙𝑖 and 𝑟𝑖 (1≤𝑙𝑖≤𝑟𝑖≤𝑛 )
 然后是整数𝑞，表示q个操作 (1≤𝑞≤ n)
 接下来是q行整数，每行有整数 𝑥 (1≤𝑥≤𝑛)
 
 
 **输出：**
 每个样例1行，输出该次操作后，m个区间中将出现至少1个beautiful的区间。
 
 **Examples**
 **input**
 6
 5 5
 1 2
 4 5
 1 5
 1 3
 2 4
 5
 5
 3
 1
 2
 4
 4 2
 1 1
 4 4
 2
 2
 3
 5 2
 1 5
 1 5
 4
 2
 1
 3
 4
 5 2
 1 5
 1 3
 5
 4
 1
 2
 3
 5
 5 5
 1 5
 1 5
 1 5
 1 5
 1 4
 3
 1
 4
 3
 3 2
 2 2
 1 3
 3
 2
 3
 1

 **output**
 3
 -1
 3
 3
 3
 1


 **题目解析：**
 假设不考虑复杂度，对于每次操作，遍历每个区间得到区间内整数1的数量，判断是否有解；
 总的复杂度是操作次数q ✖️区间数量m ✖️区间长度n，远远超过题目要求。
 分析优化空间，我们发现区间[l, r]总是比[l, r+1]更优，那么所有区间可以拆分为，左右区间节点各不相同的区间（只要有一个节点相同，则存在更优解）；
 操作同样如此，对于某个位置的重复操作是无意义的，操作可以优化为无重复位置的操作；
 但是，上述两个操作都属于常数级别优化，对于特定样例优化空间很小。
 
 当我们考虑最坏情况，即结果是否有解的时候，我们可以把所有操作都执行一遍，得到一个0/1数组，此时再去判断是否存在beautiful区间；
 方式有很多，这里可以用前n项和，即sum[i]表示位置i前面所有元素的1数量，这样区间[x, y]就可以用sum[y] - sum[x]快速计算得到区间1的数量，从而很快判断区间是否为beautiful；
 这样就可以用O(N)的复杂度，快速判断；
 接着就可以用二分的方式，来处理1-q个操作的情况。
 
 
 
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
    static const lld N = 102010;
    pair<int, int>  seg[N];
    int a[N];
    int b[N];
    int sum[N];
    
    bool check(int n, int m, int len) {
        for (int i = 0; i <= n; ++i) {
            b[i] = sum[i] = 0;
        }
        for (int i = 0; i < len; ++i) {
            b[a[i]] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] += sum[i - 1] + b[i];
        }
        for (int i = 0; i < m; ++i) {
            int x = seg[i].first, y = seg[i].second;
            if ((sum[y] - sum[x - 1]) * 2 > (y - x + 1)) {
                return true;
            }
        }
        return false;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < m; ++i) cin >> seg[i].first >> seg[i].second;
            int q;
            cin >> q;
            for (int i = 0; i < q; ++i) cin >> a[i];
            
            if (!check(n, m, q)) {
                cout << -1 << endl;
            }
            else {
                int left = 1, right = q;
                int ans = right;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (check(n, m, mid)) {
                        ans = mid;
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                cout << ans << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
