//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/705/problem/C
    题目大意：
 题目为模拟手机系统本地推送。
 输入n、q。 
 n为应用数量，q为操作数量。(1 ≤ n, q ≤ 300 000)
 每行有两个数字x、y；
 x=1的时候表示id=y的应用产生一条notify；
 x=2的时候表示已读所有id=y的应用；
 x=3的时候表示读取前y个notify；
  问每次输入后，剩余的未读数量。
 
    题目解析：
 题目的难点在于操作2会更新应用所有的通知 以及 操作3读取前y个notify的去重。
 观察题目，发现只关注未读的数量，而未读的数量只有操作1能产生。
 
 把操作1形成的数字看成一串数列，num[i]记录id为i的应用目前的未读数量；
 对于操作2，只需把num[y]清空，添加flag[y]=k的标志，表示应用y在第k个以前全部已读；
 对于操作3，只需向右遍历数字，直到个数大于等于y。
 
 
 PS：因为没看清题目的操作3，导致误认为是最新的前y个，实际是最初产生的y个，这样导致的难度相差比较多。
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
const int N = 330100, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
lld num[N]; //未读数量
lld flag[N]; //已读标志位
lld a[N];
lld look[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m, ls = 1, k = 0, sum = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        lld x, y;
        cin >> x >> y;
        if (x == 1) {
            a[++k] = y;
            ++num[y];
            ++sum;
        } else if (x == 2) {
            sum -= num[y];
            num[y] = 0;
            flag[y] = k;
        }
        else if (x == 3) {
            for (; ls <= y; ++ls) {
                if (ls > flag[a[ls]]) {
                    flag[a[ls]] = ls;
                    --num[a[ls]];
                    --sum;
                }
            }
        }
        cout << sum << endl;
    }
    
    
    return 0;
}


//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//   
//    int n, m, k = 0, sum = 0;
//    cin >> n >> m;
//    
//    for (int i = 0; i < m; ++i) {
//        lld x, y;
//        cin >> x >> y;
//        if (x == 1) {
//            a[++k] = y;
//            ++num[y];
//            ++sum;
//        } else if (x == 2) {
//            sum -= num[y];
//            num[y] = 0;
//            flag[y] = k;
//        }
//        else if (x == 3) {
//            int l = k;
//            while (y > 0) { // 还没读
//                if (look[l] == 0) {
//                    if (l > flag[a[l]]) { // 没有全部度过
//                        --num[a[l]];
//                        --sum;
//                    }
//                    look[l] = max(y, look[l]);
//                    --l;
//                    --y;
//                }
//                else {
//                    y = y - look[l];
//                    l -= look[l];
//                }
//            }
//        }
//        cout << sum << endl;
//    }
//    
//    
//    return 0;
//}
