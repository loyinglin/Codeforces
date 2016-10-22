//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：在坐标轴的第一象限上，有很多紧密排列的长方形，每个长方形的宽度为1。
 输入n个数，代表从原点开始的n个长方形的高度。
 求最大的矩形的面积。
 
 n=100w，高度=100w；
 
 例如输入：
 3
 1 2 2
 
 输出：
 4
 
 
 
 题目解析：
 做法1。
 假设最长的矩形的区间为[i, j]，高度为h，容易知道，h=a[i]或者h=a[j];
 引入left[i]数组，表示第i个数字的最远边界，在[left[i], i]的区间中，所有的数字大于等于a[i];
 那么有以i为结尾，高度为a[i]的最大矩形为[left[i], i]；
 于是遍历n个矩形，枚举a[i]*left[i]，可以得到以a[i]为高度的矩形的最优解。
 然后把数据反过来，再来一遍。（a[i]可以为左边界，也可以为矩形的右边界）
 
 
 
 
 
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
const int N = 1010000;
const lld llinf = 0x7ffffffffffff;

lld a[N];
int n;
lld Left[N], Right[N], ans;
stack<pair<lld, lld> > s;


void solveLeft() {
    while (!s.empty()) {
        s.pop();
    }
    for (int i = 1; i <= n; ++i) {
        pair<lld, lld> p = make_pair(1, i), top;
        while (!s.empty()) {
            top = s.top();
            if (a[i] <= a[top.second]) {
                p.first += top.first;
                s.pop();
            }
            else {
                break;
            }
        }
        Left[i] = a[i] * p.first;
        s.push(p);
    }
}


void solveRight() {
    while (!s.empty()) {
        s.pop();
    }
    for (int i = 1; i <= n; ++i) {
        pair<lld, lld> p = make_pair(1, i), top;
        while (!s.empty()) {
            top = s.top();
            if (a[i] <= a[top.second]) {
                p.first += top.first;
                s.pop();
            }
            else {
                break;
            }
        }
        Right[i] = a[i] * p.first;
        s.push(p);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 数据
//        freopen("inputBig.txt", "w", stdout);
//        int t = 5;
//        while (t--) {
//            int n = 999999;
//            cout << n << endl;
//            for (int i = 0; i < n; ++i) {
//                cout << arc4random_uniform(100000) << " ";
//            }
//            cout << endl;
//        }
//        return 0;
    
    //    // 暴力标程
    //    freopen("input.txt", "r", stdin);
    //    freopen("answer.txt", "w", stdout);
    //    int n;
    //    while (scanf("%d", &n) != EOF) {
    //        for (int i = 1; i <= n; ++i) {
    //            cin >> a[i];
    //        }
    //        lld ans = 0;
    //        for (int i = 1; i <= n; ++i) {
    //            for (int j = i; j <= n; ++j) {
    //                lld height = llinf;
    //                for (int k = i; k <= j; ++k) {
    //                    height = min(height, a[k]);
    //                }
    //                ans = max(ans, (j - i + 1) * height);
    //            }
    //        }
    //        cout << ans << endl;
    //    }
    //
    //
    //    return 0;
    //
    
    
    // dp
    freopen("inputBig.txt", "r", stdin);
    freopen("outputBig.txt", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        ans = 0;
        solveLeft();
        reverse(a + 1, a + 1 + n);
        solveRight();
        reverse(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, Left[i] + Right[n - i + 1] - a[i]);
        }
        cout << ans << endl;
    }
    
    
    return 0;
}
