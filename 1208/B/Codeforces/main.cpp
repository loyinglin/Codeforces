//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1208/problem/B)
 **题目大意：**
 有n个整数，𝑎1,𝑎2,…,𝑎𝑛；
 可以去掉中间某一段连续的数字，要求剩下的数字没有重复。
 问，最少需要去掉多少个数字。
 
 
 输入：
 第一行，整数𝑛 (1≤𝑛≤2000)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9)
 
 输出：
 最少需要去掉数字个数
 
 Examples
 input
 3
 1 2 3
 output
 0
 input
 4
 1 1 2 2
 output
 2
 
 **题目解析：**
 不考虑复杂度，直接枚举去掉区间的坐标[l, r]，有n^2的可能；
 判断剩下数字有没有重复需要O(N)的时间，总的时间复杂度是O^3，超过了可接受范围；
 
 假如去掉x个数字有解，则去掉x+1个数字也有解，可以用2分来优化；
 这样复杂度可以优化为O(N*N*logN)，可接受范围内。
 
 TLE 1次，数字较大，map耗时较多；改为scanf，添加hash处理；
 
 
 更优化的做法：
 假设去掉的数字区间是[l, r]，那么剩下的就是[0, l-1]和[r+1, n-1]的区间。
 容易知道[0, l-1]和[r+1, n-1]里面是没有重复元素的。
 从0开始遍历，可以很容易得到以0为起点的不重复元素区间；
 同理，从n-1开始向左遍历，可以得到以n-1为结束的不重复元素区间；
 以上两步的处理都是O(N)复杂度。
 
 假设得到左边最大的不重复元素区间，也得到右边最大不重复元素区间；
 那么就可以枚举左边区间长度（从长度为0开始），对于[0, k)的区间，求出[0, k)中所有元素的最右边距离difMax，那么从difMax+1开始，右边的元素就不会再和左边的[0, k)相同，这样再和右边最大不重复元素区间取一个较小值。

 可以O(N)解决这个问题。
 
 
 WA 1次，少考虑了左边完全不需要的情况，ans的初始化有误；
 
 8
 1 1 1 1 5 6 7 1
 这样的样例会返回7，因为默认了第一个1数字会选择，实际上还有一种情况是第一个数字1不取。
 
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
const int N = 201234, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];
int vis[N];
int cnt = 0;
// [l, r)
bool check(int n, int l, int r) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < l; ++i) {
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
        }
        else {
            return false;
        }
    }
    for (int i = r; i < n; ++i) {
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    
    map<int, int> leftMap, rightMap, gapMap;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        gapMap[a[i]] = i;
    }
    
    int leftDifMax = 0, rightDifMax = 0;
    for (int i = 0; i < n; ++i) {
        if (leftMap[a[i]]) {
            break;
        }
        leftMap[a[i]] = 1;
        leftDifMax = i;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        if (rightMap[a[i]]) {
            break;
        }
        rightMap[a[i]] = 1;
        rightDifMax = i;
    }
    
    int tmp = 0, ans = (n - rightDifMax);
    for (int i = 0; i <= leftDifMax; ++i) {
        tmp = max(tmp, gapMap[a[i]]);
        int r = max(rightDifMax, tmp + 1);
        ans = max(ans, i + 1 + (n - r));
    }
    
    cout << (n - ans) << endl;
    
//    map<int, int> h;
//    for (int i = 0; i < n; ++i) {
//        int t;
//        scanf("%d", &t);
//        if (!h[t]) {
//            h[t] = ++cnt;
//        }
//        a[i] = h[t];
//    }
//
//    int left = 0, right = n; // [left, right)
//    int ans = n - 1;
//    while (left < right) {
//        int mid = (left + right) / 2;
//        int ok = 0;
//        for (int k = 0; k < n; ++k) { //
//            if (check(n, k, k + mid)) {
//                ok = 1;
//                break;
//            }
//        }
//        if (ok) {
//            ans = mid;
//            right = mid;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    cout << ans << endl;
    
    return 0;
}


/*
 8
 1 1 1 1 5 6 7 1
 
 8
 1 5 6 7 1 1 1 1
 
 24
 623615829 623615829 623615829 623615829 623615829 623615829 623615829 623615829 623615829 623615829 407228527 407659002 938974561 145034182 304784853 734389859 509465143 593514344 611908590 228947543 794898928 558092682 152787547 623615829
 
 */
