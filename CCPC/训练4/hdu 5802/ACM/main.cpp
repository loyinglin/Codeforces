//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 
 
 
 
 题目解析：
 
 
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

const int Max = 1000100100;


lld look(lld p, lld q, int add, int rest) { // 把t变为0的消耗
    if (p <= q) {
        p = max(p, 0LL);
        return max(add + (q - p), (lld)rest);
    }
    if (p == q + 1) {
        return 1 + max(add, rest);
    }
    lld ret = 1e9;
    lld i = 1;
    lld t = p - q;
    for (; (1LL << i) - 1 < t; ++i);
    if ((1LL << i) - 1 == t) { // 刚好是最优解
        return i + max(add, rest);
    }
    ret = min(ret, i - 1 + look(p - (1LL << (i - 1)) + 1, q, add, rest + 1)); //考虑小于的部分
    ret = min(ret, i + look(p - (1LL << i) + 1, q, add, rest));
    return ret;
}

// dp[i][j] 表示状态为i，上一次减去的是2^(j-1)次方，最短的时间。 j=0的时候表示上一次没有减去

struct Node {
    int time, last, value; //0,1,2,3
};

int bfs(int t) {
    queue<Node> q;
    Node top;
    top.time = 0, top.last = 0, top.value = t;
    q.push(top);
    while (true) {
        top = q.front();
        if (top.value == 0) {
            break;
        }
        q.pop();
        top.time++;
        if (top.value >= (1 << top.last)) {
            top.value -= 1 << top.last;
            top.last++;
            q.push(top);
            top.last--;
            top.value += 1 << top.last;
        }
        top.value++;
        top.last = 0;
        q.push(top);
        
        top.value--;
        q.push(top);
    }
    return q.front().time;
}


long long Log(long long x)
{
    long long k = -1;
    while(x)
    {
        k++;
        x >>= 1;
    }
    return k;
}
long long solve(long long x,long long y,long long s)
{
    long long k = Log(y-x+1);
    if((1<<k) == y-x+1)
        return k;
    long long last = max((long long)0,y+1-(1<<(k+1)));
    return min(k+1+max((long long)0,x-last-s),k+1+solve(x,y+1-(1<<k),s+1));
}




int main(int argc, const char * argv[]) {
    int t = 1000;
    cin >> t;
    while (t--) {
        int p, q;
        scanf("%d%d", &p ,&q);
//        p = arc4random_uniform(1000000001), q = arc4random_uniform(1000000001);
        
        if (p <= q) {
            printf("%d\n", q - p);
        }
        else {
//            cout << p << " " << q << endl;
            printf("%lld\n", look(p, q, 0, 0));
//            if (look(p, q, 0, 0) != solve(q, p, 0)) {
//                cout << p << " " << q << endl;
//                cout << look(p, q, 0, 0) << "  vs " << solve(q, p, 0) << endl;
//            }
        }
    }
}
