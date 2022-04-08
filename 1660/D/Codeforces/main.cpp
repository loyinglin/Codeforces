//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/D)
 **题目大意：**
 给出n个整数的数组a，其中数组的元素绝对值满足 abs(a[i]) <= 2；
 现在可以移除数组前面x个元素和后面y的个元素，求剩下的元素乘积尽可能的大；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例两行，第一行是整数𝑛  (1≤𝑛≤2⋅1e5)
 接下来是n个整数𝑎1,𝑎2,…,𝑎𝑛 (|𝑎𝑖|≤2)；
 
 **输出：**
 每个样例一行，包括整数x和y，x和y分别表示：移除数组前面x个元素和后面y的个元素；
 允许移除所有的元素，这样乘积为1；
 如果有多个答案，输出任意一个；

 
 **Examples**
 **input**
 5
 4
 1 2 -1 2
 3
 1 1 -2
 5
 2 0 -2 2 -1
 3
 -2 -1 -1
 3
 -1 -2 -2
 
 **output**
 
 0 2
 3 0
 2 0
 0 1
 1 0

 **题目解析：**
 题目的要求是乘积尽可能大，那么数字0首先被排除，因为0乘以任意数字都0，而移除所有元素的乘积结果都是1；
 那么按照0，将数组切分成若干段，题目变成了在某一个子区间[left, right]中，寻找乘积最大的子区间；
 假如区间[left, right]没有负数，或者有偶数个负数，那么这个区间所有数字的乘积就是最大的；
 假如区间[left, right]有奇数个负数，那么肯定是去掉最左边的负数（假如位置是posLeft），或者去掉最右边的负数（假如位置是posRight）；
 这样就可以得到区间[left, right]的最大乘积；
 
 由于乘积会比较大，这里只需要统计2和-2的数量即可，这个结果越大，则乘积越大。
 
 
 
 
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
    static const int N = 201010;
    int a[N];
    int ansTotal, ansLeft, ansRight;
    int pos[N], k;
    
    void find(int left, int right) {
        int total = 0, posLeft = 0, posRight = right;
        int cntTotal = 0, cntLeft = 0, cntRight = 0;
        for (int i = left; i <= right; ++i) {
            if (a[i] < 0) {
                ++total;
            }
            if (abs(a[i]) == 2) {
                ++cntTotal;
            }
            if (a[i] < 0 && !posLeft) {
                posLeft = i;
            }
            if (a[i] < 0) {
                posRight = i;
            }
        }
        for (int i = left; i <= posLeft; ++i) {
            if (abs(a[i]) == 2) {
                ++cntLeft;
            }
        }
        for (int i = posRight; i <= right; ++i) {
            if (abs(a[i]) == 2) {
                ++cntRight;
            }
        }
        if (total % 2 == 0) {
            if (cntTotal > ansTotal) {
                ansTotal = cntTotal;
                ansLeft = left;
                ansRight = right;
            }
        }
        else {
            if (cntLeft < cntRight) {
                cntTotal -= cntLeft;
                if (cntTotal > ansTotal) {
                    ansTotal = cntTotal;
                    ansLeft = posLeft + 1;
                    ansRight = right;
                }
            }
            else {
                cntTotal -= cntRight;
                if (cntTotal > ansTotal) {
                    ansTotal = cntTotal;
                    ansLeft = left;
                    ansRight = posRight - 1;
                }
            }
        }
    }

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &a[i]);
            }
            
            k = 0;
            pos[k++]= 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 0) { //
                    pos[k++] = i;
                }
            }
            pos[k++] = n + 1;
            ansTotal = 0;
            ansLeft = 1;
            ansRight = 0;
            for (int i = 1; i < k; ++i) {
                int l = pos[i - 1];
                int r = pos[i]; // (l, r)
                find(l + 1, r - 1);
            }
            cout << ansLeft - 1 << " " << (n - ansRight) << endl;
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
 */
