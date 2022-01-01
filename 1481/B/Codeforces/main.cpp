//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1481/problem/B)
 **题目大意：**
 给出n个数字表示n个山峰的高度，这n个山峰排成一行；
 每次从最左边放上一个石头，如果这个山峰的高度比右边的小，则这个山峰（乐高积木）加一；
 如果这个山峰的高度 大于等于 右边的山峰，则石头会滚向右边的山峰；
 下个山峰再重复这个过程，直到最右边的山峰；如果石头到达最右边一个山峰，则会继续滚下去，最右边的山峰高度不变。
 
 **输入：**
 第一行整数𝑡，表示t个样例  (1≤𝑡≤100)
 每个样例有两行：
 第一行 𝑛 and 𝑘 (1≤𝑛≤100; 1≤𝑘≤1e9)
 第二行  ℎ1,ℎ2,…,ℎ𝑛 (1≤ℎ𝑖≤100)
 
 **输出：**
每个样例输出一行，如果落出山峰则输出-1；否则输出具体的停留位置。
 
 **Examples**
 **input**
 4
 4 3
 4 1 2 3
 2 7
 1 8
 4 5
 4 1 2 3
 3 1
 5 3 1
 **output**
 2
 1
 -1
 -1
 
 
 **题目解析：**
 题目的数据范围很小，可以直接模拟，枚举从第1个石头到第k个石头的位置。
 但如果数据范围比较大呢？由于模拟的解法比较简单，这里分享一种数据量较大的情况的处理方法，具体可以见下面：
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];
int b[N];

lld calcMaxCount(int left, int right) {
    b[right] = 0;
    lld sum = 0;
    for (int i = right - 1; i >= 0; --i) {
        b[i] = max(a[i], b[i + 1]);
        sum += b[i] - a[i];
    }
    return sum;
}

// N * N的复杂度
int look(int left, int right, int k) {
    if (left == right) {
        return left;
    }
    int maxHeight = a[left];
    for (int i = left + 1; i < right; ++i) {
        maxHeight = max(maxHeight, a[i]);
    }
    
    lld sum = 0;
    for (int i = left; i < right; ++i) {
        sum += maxHeight - a[i];
    }
    if (k > sum) {
        // 开始累积木
        int pos = ((k - sum) % (right - left)); // maxHeight持平之后，必然第一个落在right-1，第二个是right-2
        return pos == 0 ? left : (right - pos);
    }
    else {
        // 不能全部达到maxHeight高度并且有剩余，那么根据maxHeight看看是落在左边，还是右边
        lld leftSum = 0;
        int maxPos = left + 1;
        for (int i = left; a[i] != maxHeight; ++i) {
            leftSum += maxHeight - a[i];
            maxPos = i + 1;
        }
        if (leftSum >= k) {
            int ret = look(left, maxPos, k);
            return ret;
        }
        else {
            int ret = look(maxPos, right, k - (int)leftSum);
            return ret;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        lld sum = calcMaxCount(0, n);
//        cout << sum << endl;
        if (k > sum) {
            cout << -1 << endl;
        }
        else {
            cout << look(0, n, k) + 1 << endl;
        }
    }   
    
    return 0;
}

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
