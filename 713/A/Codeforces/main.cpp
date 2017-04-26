//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/713/problem/A
 题目大意：给出一个集合T，n个操作；
 每个操作有3种情况：
 1、往集合T里面添加一个数字x；
 2、往集合T里面删除一个数字x；
 3、询问集合T里面，里面与s能匹配的数量。
 匹配的方式：
 对于两个数字x、y，如果两个数字每一位的奇偶性都相同，则认为匹配（不足的位数补0）。
 357和135：
 357
 135
 匹配；
 
 13和257：
 013
 257
 匹配；
 
 13和247：
 013
 247
 不匹配；
 
 input
 4
 + 200
 + 200
 - 200
 ? 0
 output
 1
 
 n=10w, x的范围10^18，添加的数字可以相同，删除时如果有多个数字x只删除一个；
 
 
 
 题目解析：
 从匹配方式入手。
 奇偶性相同，意思就是对于每一个数字，可以转换成01010111的字符串。
 那么数字x是否和数字y匹配，就相当于他们的010101字符串是否相同，那么我们可以定义一个trans操作。
 数字x和数字y匹配，当且仅当trans(x) = trans(y)。
 
 再来看操作1和操作2，对于询问来说245、45和5是等价的（001，01，1）。
 那么操作1可以简化成加入一个trans(x)的数字，操作2简化成删除一个trans(x)的数字。
 题目可解。 
 
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
const int N = 3010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int a[N];

int trans(lld x) {
    int ret = 0, t = 1;
    while (x) {
        ret += (x % 10) % 2 * t;
        x /= 10;
        t *= 2;
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    while (n--) {
        char op[11];
        lld k;
        scanf("%s%lld", op, &k);
        if (op[0] == '+') {
            a[trans(k)]++;
        }
        else if (op[0] == '-') {
            a[trans(k)]--;
        }
        else {
            cout << a[trans(k)] << endl;
        }
    }
    
    
    return 0;
}
