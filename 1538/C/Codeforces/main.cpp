//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1538/problem/C)
 **题目大意：**
从n个整数的数组中，找到(i, j)  要求 l ≤ a[i]+a[j] ≤ r，问有多少(i, j)符合要求；
 
  **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤10000 ).
 每个样例第一行是整数𝑛,𝑙,𝑟 (1≤𝑛≤2⋅1e5, 1≤𝑙≤𝑟≤1e9)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).
 
 **输出：**
 (𝑖,𝑗)的数量，要求是 (𝑖<𝑗) 并且 𝑙≤𝑎𝑖+𝑎𝑗≤𝑟.
 
 **Examples**
 **input**
 4
 3 4 7
 5 1 2
 5 5 8
 5 1 2 4 3
 4 100 1000
 1 1 1 1
 5 9 13
 2 5 5 1 1

 **output**
 yes
 2
 7
 0
 1

 
 **题目解析：**
 题目要求的是任意a[i]和a[j]，那么数组的顺序没有意义，可以直接将数组进行排序；
 如果不考虑复杂度，我们可以枚举pair(i, j)是否满足要求，这样复杂度是N*N；
 由于排序完之后，数组是有序的，我们在枚举pair(i, j)的时候，可以采用下面的策略：
 从小到大枚举i，假设已经先取了数字a[i]并且i<j，要求是找到l<=a[i]+a[j]<=r，那么就是在区间[i+1, n]里面找到l-a[i]作为起点，r-a[i]作为终点的区间；
 我们可以采用二分查找来，也可以使用快捷方法lower_bound。
 
 
 **思考🤔：**
 
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
    static const int N = 200010;
public:
    int a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, l, r;
            cin >> n >> l >> r;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n);
            lld sum = 0;
            for (int i = 0; i + 1 < n; ++i) {
                int left = l - a[i];
                int right = r - a[i] + 1;
                // 从i+1开始，找到第一个大于等于left的数字作为起点x
                int x = lower_bound(a + i + 1, a + n, left) - a;
                if (x >= n) {
                    continue;;
                }
                // 新x开始，找到第一个大于right的数字作为终点y
                int y = lower_bound(a + x, a + n, right) - a;
                sum += y - x;
            }
            cout << sum << endl;
        }
    }
}
ac;
    

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 111
 5 3 5
 1 2  3 4 5
 
 5 1 5
 3 4 5 6 7
 */
