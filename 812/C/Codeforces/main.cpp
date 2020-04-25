//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/812/problem/C
 题目大意：
 小明到商店买东西，商店里有n个物品，小明带了总共s的钱；
 每个商品有个基础的价格a[i]，同时商品还有一个附加价格：
 当小明购买k个物品的时候，每个商品的价格=基础价格+附加价格=a[i]+i*k；
 
 现在小明希望在总价格不超过s的前提下，尽可能买更多的物品；
 如果物品一样多，小明希望总价格price尽可能的少；
 
 输入数据
 n and s (1 ≤ n ≤ 1e5 and 1 ≤ s ≤ 1e9)
 (1 ≤ ai ≤ 1e5)
 输出数据
 能买到物品数量和总价格price；
 
 Examples
 input
 3 11
 2 3 5
 output
 2 11
 
 样例解释：
 样例中，小明无法购买3个物品，因为购买3个时，价格是 [5, 9, 14]，总价格是28；
 如果购买2个物品，价格是 [4, 7, 11]，小明可以买前两个。
 
 
 题目解析：
 在不考虑附加价格的时候，可以直接对价格排序，从价格最小的物品开始，直到无法购买即可；
 附加价格的影响是当购买的物品越多的时候，物品的的价格是越贵，这里是具有单调性的。
 那么通过二分购买的数量mid，即可排除附加价格的影响。
 每次得到二分的购买数量mid后，更新每个物品的价格，再排序进行求值。
 总得复杂度是二分复杂度*排序复杂度=O(NlogNlogN);
 
 
 
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
const int N = 110000, M = 3010100, inf = 0xfffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N], node[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    lld n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &node[i]);
    }
    
    lld l = 0, r = n + 1, ans = 0, ansTotal = 0;
    while (l < r) {
        lld mid = (l + r) / 2;
        if (mid == 0) {
            break;
        }
        lld sum = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = node[i] + mid * i;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= mid; ++i) {
            sum += a[i];
        }
        if (sum > s) {
            r = mid;
        }
        else {
            ans = mid;
            ansTotal = sum;
            l = mid + 1;
        }
    }
    cout << ans << " " << ansTotal << endl;
    
    
    return 0;
}
