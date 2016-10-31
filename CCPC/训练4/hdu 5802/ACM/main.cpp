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


lld look(lld t, int add, int rest) { // 把t变为0的消耗
    if (t == 0) {
        return 0 + max(add, rest);
    }
    if (t == 1) {
        return 1 + max(add, rest);
    }
    lld ret = 1e9;
    lld i = 1;
    for (; (1LL << i) - 1 < t; ++i);
    if ((1LL << i) - 1 == t) { // 刚好是最优解
        return i + max(add, rest);
    }
    ret = min(ret, i - 1 + look(t - (1LL << (i - 1)) + 1, add, rest + 1)); //考虑小于的部分
    
    lld addCost = add + (1LL << i) - 1 - t; // 先增加，再减去
    lld restCost = rest;
    ret = min(ret, i + max(addCost, restCost)); // 取增加和休息的最大值即可
    
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


int main(int argc, const char * argv[]) {
    int t = 20;
    cin >> t;
    while (t--) {
        int p, q;
        scanf("%d%d", &p ,&q);
        p = t, q = 0;
        if (p <= q) {
            printf("%d\n", q - p);
        }
        else {
            printf("%lld\n", look(p - q, 0, 0));
//            if (look(p - q, 0, 0) != bfs(p - q) || 1) {
//                cout << p << " " << q << endl;
//                cout << look(p - q, 0, 0) << " bfs " << bfs(p - q) << endl;
//            }
        }
    }
}
