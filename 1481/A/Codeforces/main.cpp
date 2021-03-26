//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1481/problem/B)
 **题目大意：**
 
 n个原数字a[i]，n个目标数字b[i]；
 现在有m个替补数字c[i]，必须把c[i]放在a中的某一个位置，问最终是否a == b；


 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 找到数组a和b的差别，差别部分
 
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
