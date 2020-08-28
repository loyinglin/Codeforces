//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1401/problem/A)
 **题目大意：**
 在数轴上，有一个点A放在x=n的位置上，现在想找到一个点B，B的所在位置是一个整数，并且满足：
 原点O到B的距离 和 A到B的距离 两者的差为k；
 
 有时候该位置不存在，我们可以每次把A的位置加1，现在想知道A最少需要加几次1，使得点B存在；
 
 **输入：**

 
 **输出：**
 
 **Examples**
 **input**
 
 
 **output**

 **题目解析：**
 假如B没有整数的要求，那么当n>=k的时候，则B肯定存在于O到A之间；n<k的时候，则A的位置不断加1，直到n=k；
 当增加B的位置为整数限制时，即使n>=k（比如说n=1,k=0），由于B的位置是0.5，此时只能将A的位置加1，使得A=2；
 考虑有哪些情况会出现B的位置为整数，我们可以发现是n为奇数k为偶数 和 n为偶数k为奇数两种情况，我们用 (n+k) % 2 可以区分；
 至于n<k的情况，我们移动A点，使得n=k，将点B放在原点即可。
 
 **思考🤔：**
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

lld calc(lld a) {
    lld x = 0, y = 9;
    while (a) {
        x = max(x, a%10);
        y = min(y, a%10);
        a /= 10;
    }
    return x*y;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        lld a, k;
        cin >> a >> k;
        if (a >= k) {
            cout << (a+k)%2 << endl;
        }
        else {
            cout << (k-a) << endl;
        }
    }   
    
    return 0;
}
