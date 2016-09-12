//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/708/problem/B
 题目大意：一个由字符'0'和字符'1'组成的字符串，给出所有长度为2的子序列（不是子串）中，a00, a01, a10, a11的数量。构造一个字符串满足条件条件。如果没有就输出”Impossible“。
 数字范围为 10e9。
 
 输入：1 2 2 1
 输出：0110
 
 input
 1 2 3 4
 output
 Impossible
 
 
 
 题目解析：
 假设构建出来的字符串长度是n，所有长度为2的子序列有1+2+3...+(n-1)=(n-1)*n/2，那么sum必须满足这个条件；
 同理，对00和11，可以求出i（字符串中0的个数）和 j（字符串中1的个数），要满足i+j=n；
 接下来构建01和10，容易知道a[01]+a[10]的总数是不变的，那么
当我们构建一个01的时候，就少构建一个10，总和会满足a[01] + a[10]，
 故而我们只需构建满足a[01]的字符串，那么a[10]也会满足。
 
 对于a[01]，我们用贪心来构建。
 假设把所有的1放在最右边，那么此时的最大值是i*j。
 容易知道，我们只需把 a[01]/i 个1放在最右边即可；
 如果 a[01] % i 不为零，可以在a[01]%i个0后面放一个1，剩下的1全部放最前面即可；
 
 
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
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];

vector<lld> g;

int main(int argc, const char * argv[]) {
    // insert code here...
    lld a, b, c, d;
    cin >> a >> b >> c >> d;
    lld sum = a + b + c + d;
    if (sum == 0) {
        cout << "0" << endl;
        return 0;
    }
    //    if (sum == 1) {
    //        if (a == 1) {
    //            puts("00");
    //        }
    //        if (b == 1) {
    //            puts("01");
    //        }
    //        if (c == 1) {
    //            puts("10");
    //        }
    //        if (d == 1) {
    //            puts("11");
    //        }
    //        return 0;
    //    }
    bool flag = 1;
    lld i = 0, j, n = 1; //i表示0的数量 j表示1的数量
    while (n * (n - 1) / 2 < sum) {
        ++n;
    }
    if (sum != n * (n - 1) / 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    while (i * (i - 1) / 2 < a) {
        ++i;
    }
    
    if (i * (i - 1) / 2 != a) {
        cout << "Impossible" << endl;
        return 0;
    }
    if ((i == 0) && (b != 0 || c != 0)) {
        i = 1;
    }
    j = n - i;
    if (j * (j - 1) / 2 != d) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    // 从01开始枚举，每个1，最多有i个01
    lld x = 0, y = 0; // 前面是y个1，接着输出0，第x个0后输出1，再接着输出0，其余1在最后
    if (i == 0 || j == 0) {
        x = 0;
        y = 0;
    }
    else {
        x = b % i;
        y = j - (b / i);
        if (x != 0) {
            if (y > 0) {
                --y;
            }
        }
    }
    
    for (int z = 0; z < y; ++z) {
        putchar('1');
    }
    
    for (int z = 0; z < x; ++z) {
        putchar('0');
    }
    if (x != 0) {
        j--;
        putchar('1');
    }
    for (int z = (int)x; z < i; ++z) {
        putchar('0');
    }
    for (int z = 0; z < j - y; ++z) {
        putchar('1');
    }
    puts("");
    
    return 0;
}
