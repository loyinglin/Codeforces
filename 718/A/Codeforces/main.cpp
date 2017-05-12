//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/718/problem/A
 题目大意：
 输入一个长度为n的字符串表示一个浮点数；
 每次可以对浮点部分进行一次四舍五入，10.45 => 10.5；
 最多可以进行t次。
 输出最大的数。
 
 Examples
 input
 6 2
 10.245
 output
 10.3
 
 样例解释：10.245第一次四舍五入变成10.25，再次四舍五入变成10.3；
 
 
 题目解析：
 首先可以确定，如果小数第一位x[1]>=5，那么直接进位即可；
 x[1] < 4, 肯定不会进位，因为即使后面进位上来最多x[1]+1=4，达不到进位的条件；
 x[1] == 4的情况，如果x[1 + 1] >= 5，则可能发生x[1+1]进位后导致x[1]进位；
 
 那么对于第i位：
 x[i]>=5的时候，第i位之后的数字无意义；
 x[i]==4的时候，有可能从后面传递过来；
 x[i]<4的时候，进位停止；
 
 最后在考虑一种特殊情况：进位导致进位的情况，比如说99.9949进位2次，会变成100.00。
 就是完整的过程。
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


char a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, t;
    cin >> n >> t;
    cin >> a;
    int ok = 0, last = n - 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '.') {
            ok = 1;
        }
        else {
            if (ok) {
                if (a[i] >= '5') {
                    for (int j = i; a[j] != '.'; --j) {
                        if (t && a[j] >= '5') {
                            --t;
                            if (a[j - 1] != '.') {
                                a[j - 1]++;
                                a[j] = '\0';
                                last = j;
                            }
                            else {
                                a[j - 2]++;
                                a[j - 1] = '\0';
                                last = j - 1;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    
    if (last) {
        for (int i = last - 1; i > 0; --i) {
            if (a[i] > '9') {
                a[i - 1]++;
                a[i] = '0';
            }
        }
    }
    if (a[0] == '9' + 1) {
        cout << '1';
        a[0] = '0';
    }
    cout << a << endl;
    
    
    
    return 0;
}
