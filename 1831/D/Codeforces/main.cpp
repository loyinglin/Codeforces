//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1831/problem/D)
 **题目大意：**
 有两个长度为n的整数数组a和b；
 现在想要找到所有的(i, j)组合，满足 1≤𝑖<𝑗≤𝑛 且 𝑎𝑖⋅𝑎𝑗=𝑏𝑖+𝑏𝑗 .
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤𝑛)
 第二行整数𝑏1,𝑏2,…,𝑏𝑛 (1≤𝑏𝑖≤𝑛 )
   
 **输出：**
 对于每个样例，输出存在的组合数量。
 
 **Examples**
 **input**
 3
 3
 2 3 2
 3 3 1
 8
 4 2 8 2 1 2 7 5
 3 5 8 8 1 1 6 5
 8
 4 4 8 8 8 8 8 8
 8 8 8 8 8 8 8 8

 **output**
 2
 7
 1

 
 
 **题目解析：**
 最直接做法，只需要枚举所有的i和j，计算是否满足要求，但是复杂度O(N^2)，明显超过题目要求；
 分析题目的要求，组合数量对原有位置没有要求，那么可以对数组进行排序；
 但是不管数组a排序还是数组b排序，都无法满足快速求解；

 继续分析题目给出的条件，发现a和b的范围比较小，那么bi+bj应该小于2n；
 对于组合(i,j)，我们假设ai<bi，那么ai作为乘法的较小值可以满足ai <= sqrt(2n)=633，这样ai的枚举范围就缩小很多，这似乎是一个突破口。
 
 那么是不是直接按照数组a的大小排序，然后遍历数组a，直到ai <= sqrt(2n)即可？
 这样当数组所有元素ai都<= sqrt(2n)时，复杂度依然超标。
 
 所以枚举的应该是ai所取的值。
 对于组合(i, j)，有数字a[i]和a[j]，以及b[i]和b[j]，一共四个未知数；（注意这里我们假设了a[i] < a[j])
 我们枚举a[i]的值，先假设ai=x，那么对于数字a[j]和b[j]我们同样去枚举j∈[0, n]的情况，这样我们就知道了3个未知数，根据a[i]*a[j] = b[i] + b[j]，我们可以推出 b[i] = y = a[i] * a[j] - b[j] = x * a[j] - b[j];
 此时我们只要知道在枚举到j时，前面出现过所有的a[i] = x并且 b[i]的值为y的数字即可；
 
 我们在遍历数组过程，要统计前面出现过的值为y的整数，可以用哈希来解决，用h[value]++的方式来记录，然后统计前面value出现次数就是h[value]；
 
 注意：数组要按照a从小到大排序。
 因为，我们假设了a[i] < a[j]，为了保证这个要求，我们需要对数组排序，并且在枚举到位置j时，另外一个位置i只能考虑[1, j - 1]这个区间。
 
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
    static const int N = 202010;
    pair<int, int> a[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &a[i].first);
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &a[i].second);
            }
//            sort(a, a + n);
            int m = sqrt(n * 2) + 1;
            lld ans = 0;
            for (int i = 1; i <= m; ++i) {
//                map<int, int> h;
                vector<int> h(n+1);
                for (int j = 0; j < n; ++j) {
                    int y = i * a[j].first - a[j].second; // x = i时， second应该等于y
                    if (1 <= y && y <= n) {
                        ans += h[y];
                        if (h[y]) cout << i << "*" << a[j].first << "=" << y << "+" << a[j].second << endl;
                    }
                    if (a[j].first == i) {
                        h[a[j].second]++;
                    }
                }
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
 
