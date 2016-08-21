//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/702/problem/D
 题目大意：从起点到终点的距离为d，骑车速度为a秒/公里，走路速度为b秒/公里(a < b)。车子每走k公里就要修理一次，时间为t秒。车子最初k公里不需要修理，问最短的时间到达终点。
 题目解析：
 先让车子走k公里（因为a<b)，接下来把剩下的路分成若干段，每段k公里，最后剩下的部分为left公里。
 对于每段的k公里，根据k * a + t 和 k * b 的大小决定走路还是骑车；
 最后的left公里，根据t + left * a 和 left * b的大小决定走路还是骑车；
 
 是否存在前面走路，后面骑车的情况？
 假设最后一段是骑车，那么前面的k公里必然也是骑车。
 
 
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N], b[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long long ret = 0;
    long long d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    
    if (d <= k) {
        ret = d * a;
    }
    else {
        
        d -= k;
        ret = a * k;
        
        long long left = d % k;
        long long c = d / k;
        
        ret += min(k * a + t, k * b) * c;
        
        ret += min(t + left * a, left * b);
    }
    
    
    
    cout << ret;
    
    return 0;
}


