//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/706/problem/A
    题目大意：
 q个操作, q=200,000
 操作1：在集合A，加入数x
 操作2：在集合A，删除数x
 操作3：输入数x，寻找集合A中，与x异或值最大。
    题目解析：
 简单的做法，对每个询问，遍历查找集合。复杂度太高。
 把异或操作按二进制来看，对于每一位，都尽量使其变为1。
 那么，可以按照二进制，从高位开始枚举是否可以为1。
 第i位为1，如果x的第i位为1，需要寻找第i位为0数；
 如果x的第i位为0，需要寻找第i位为1的数；
 
 如何确定集合里面是否存在第i位为0或者为1的数字？
 对于第i位为1，集合A存在大于等于1<<（i-1）的数字，那么就存在第i位为1的数字；
 对于第i位为0，集合A存在大于等于0的数字，那么就存在第i位为0的数字；
 
 用multiset和upper_bound来处理，即可。
 
 备注：用字典树亦可解。 
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
const int N = 201000, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
lld a[N];
multiset<lld> sets;

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n;
    cin >> n;
    
    while (n--) {
        char type[20];
        scanf("%s", type);
        lld x;
        cin >> x;
        sets.insert(0);
        if (type[0] == '+') {
            sets.insert(x);
        }
        else if (type[0] == '-') {
            sets.erase(sets.find(x));
        }
        else {
            lld ans = 0;
            lld sum = 0;
            for (int i = 30; i >= 0; --i) {
                lld k = 1LL << i;
                lld t = sum + k ^ (x & k);
                
                if (sets.lower_bound(t) != sets.end()) { //存在解
                    lld find =  *sets.lower_bound(t);

                    if (find <= t + (k - 1)) {
                        ans += k;
                        sum = t;
                    }
                    else {
                        sum = sum + (x & k);
                    }
                }
                
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}
