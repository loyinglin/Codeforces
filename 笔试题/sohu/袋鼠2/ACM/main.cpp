//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：袋鼠喜欢在弹簧上弹跳；
 有n个弹簧排成一列，每个弹簧可以弹到下一个弹簧；
 输入n个数字，代表袋鼠对n个弹簧的喜欢值；
 袋鼠只喜欢跳到喜欢值大于等于起始位置喜欢值的弹簧；
 袋鼠可以在任意弹簧位置起跳；
 袋鼠的开心值=起始点的喜欢值*经过的弹簧数；
 求袋鼠最大的开心值。
 
 input
 5
 1 2 3 4 5
 
 output
 9
 
 袋鼠在位置1，2，3，4，5起跳的开心值分别为5，8，9，8， 5。
 
 
 题目解析：
 倒着来,dp[i]表示第i个能往后跳的位置，然后对i-1，如果a[i-1]>a[i]，证明i-1的位置是不能往后跳的；如果a[i-1]<=a[i]，那么ans=max(ans, (dp[i] + 1)*a[i-1]);  同时更新dp[i-1]。
 
 
 
 
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
#include <queue>
using namespace std;

typedef long long lld;
const int N = 1001000, M = 3010100, inf = 0x7fffffff;



struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value > tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

lld d[N];
lld a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
//    freopen("input.txt", "w", stdout);
//    int t = 20;
//    while (t--) {
//        int n = arc4random_uniform(1000) + 10;
//        cout << n << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << arc4random_uniform(1000) + 10 << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//    
//    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            d[i] = 0;
        }
        
        lld ans = a[n];
        d[n] = 1;
        for (int i = n - 1 ; i > 0; --i) {
            if (a[i] <= a[i + 1]) {
                d[i] = d[i + 1] + 1;
                ans = max(ans, d[i] * a[i]);
            }
            else {
                ans = max(ans, a[i]);
                d[i] = 1;
            }
        }
        
        
        cout << ans << endl;
    }
    
    
    return 0;
}
