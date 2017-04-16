//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/712/problem/B
 题目大意：输入一个字符串s，由 'L', 'R', 'U', or 'D'组成，分别表示点P在原点的向左、右、上、下前进一步。
 修改字符串的序列，每次操作能修改一个字符为其他字符（L/R/U/D），问点P按照字符串s移动后能回到原点的最小操作次数；
 如果可以，输出做小操作次数；
 如果不能，则输出-1；
 
 Examples
 input
 RRU
 output
 -1
 input
 UDUR
 output
 1

 
 题目解析：
 先考虑不能情况。
 如果字符串的长度为奇数，那么必然不能回到原点。
 如果字符串的长度为偶数，那么必然有解。（最多把所有的字符串变成UDUD）
 然后分开考虑，L 和 R 相对， U 和 D 相对。
 求出在x方向和y方向的需要修改的字符数量。
 容易知道我们可以把需要修改的数量加起来，然后除以2可以得到修改的次数。（两个方向的需要修改数量，必然为偶数）
 
 
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
const int M = 110010, N = 3, inf = 0x7fffffff;
const lld MOD = 1000000007LL;

int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    cin >> str;
    if (str.size() % 2) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    int x = 0, y = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'L') {
            --x;
        }
        if (str[i] == 'R') {
            ++x;
        }
        if (str[i] == 'U') {
            ++y;
        }
        if (str[i] == 'D') {
            --y;
        }
    }
    
    ans = (abs(x) + abs(y)) / 2;
    
    cout << ans << endl;
    
    return 0;
}
