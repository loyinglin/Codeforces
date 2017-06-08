//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/767/problem/B
 题目大意：
 小明要去一个地方办业务，业务员上班时间是Ts到Td；
 办业务的人很多，排成一列，业务员为每个人办业务都需要时间Tf;
 已知n个人的到达时间a[i], a[i]为正整数；（a[i] < a[i+1])
 小明可以在任何非负整数的时间到达，如果和其他人同时到达，小明会让其他人先，自己排队；
 现在小明希望排队时间最短，问：他应该在哪个时间点到达；如果有多个答案，输出任何一个；
 
 (0 ≤ n ≤ 100 000)
 Ts和Td最大不超过1e12；
 
 Examples
 input
 10 15 2
 2
 10 13
 output
 12
 input
 8 17 3
 4
 3 4 5 8
 output
 2
 
 
 
 题目解析：
 从题意知道，小明如果0点就到达，一定可以得到服务，故答案必然有解；
 用贪心的思想，所有的情况可以分为两种：
 1、小明可以在某个人到达的时间的前一秒钟到达；
 2、小明在所有人办理业务完成后再到达；
 
 于是枚举a[i]-1到达的时间的最小等待时间，并且再统一考虑最后一种情况即可。
 时间复杂度O(N)；
 
 
 
 
 
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
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    lld ts, td, t;
    cin >> ts >> td >> t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    lld m = llinf, cur = ts, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] + t <= td) { // 如果 > td 表示这个人得不到服务，不用考虑
            if (max(cur, a[i] - 1) + t <= td && cur - a[i] + 1 < m)  {
                m = cur - a[i] + 1; // m 表示最小的等待时间，
                ans = min(a[i] - 1, cur); // 只要在第i个人来的前一秒到达
            }
            cur = max(cur, a[i]) + t; // 之前可能排队了若干个人，导致a[i]也要等待到cur才能办理业务
        }
    }
    if (cur + t <= td) {
        ans = cur;
    }
    cout << ans << endl;
    
    
    return 0;
}
