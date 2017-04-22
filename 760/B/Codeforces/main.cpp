//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/760/problem/B
 题目大意：
 n个人，m个枕头；
 现在n个人睡成一行，每个人至少需要一个枕头，并且和隔壁的人的枕头数量差距最多不能超过1个；
 现在小明是第k个人，问小明最多能分到多少个枕头？
 
  n, m and k (1 ≤ n ≤ m ≤ 1e9, 1 ≤ k ≤ n)
 
 Examples
 input
 4 6 2
 output
 2
 input
 3 10 3
 output
 4
 
 
 
 题目解析：
 先每个人分一个，保证第一个条件；再看个数限制的条件；
 在不考虑每个人都有的一个枕头下，我们可以想象，最后的枕头分布情况应该是：
 小明分到t个，左右的人分到t-1个，再左右的人分到t-2个；
 细节：
 如果左、右遇到边界，那么不再计算；
 如果t-i < 0, 那么不再计算；
 
 这样可以用两个通项公式来算：
 第一部分，计算k到两边的最小边界，seg = min(k - 1, m - k);
 在seg的范围内的求和公式是sum1 = t + 2 * (t - 1) + 2 * (t - 2)... = 2 * (t + (t-1) + (t-2)...) - t
 项数是 min(seg + 1, t)
 第二部分，剩下部分用sum2 = t + (t-1) + (t-2) + ...的公式
 
 因为两个公式的项数依赖于k的大小，很难统一成求和公式；
 
 沿着这个思路，我们加入一个二分，假设小明最后拥有mid个枕头；（这个很容易看出满足单调性，小明能拥有mid个枕头，必然可以拥有mid-1个枕头）
 小明周边的人必然是mid-1,mid-2...直到遇到边界；
 为了计算方便，我们分成两个区间来计算，[1, k-1], [k+1, n]，这样两个区间都可以直接用公式2来计算；
 再分别考虑 mid与k的大小关系即可。
 
 
 trick：
 自己在写二分的时候，考虑边界情况失误，WA了一次，忘了先减去m WA了一次；
 思考：先写解析，隔天再做题，一定要细看下解析，把自己的上下文切换到当时写解析的状态；
 一个简单的题目如此，真正写需求的周期可能会长达半个月、一个月，更容易出现问题。
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != second) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

lld find(int k, int n, int mid) {
    lld ret = mid;
    ret += 1LL * mid * (mid - 1); // 1, 2, 3 ... mid-1    * 2
    if (k < mid) { // 如果k到边界的距离不够
        ret -= (1LL + mid - k) * (mid - k) / 2;
    }
    if ((n - k + 1) < mid) {
        ret -= (1LL + mid - (n - k + 1)) * (mid -(n - k + 1)) / 2;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m, k;
    cin >> n >> m >> k;
    m -= n;
    int l = 1, r = m + 1;
    int ret = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (find(k, n, mid) <= m) { // ok
            ret = mid;
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << ret + 1 << endl;
    return 0;
}


//3 3 2
