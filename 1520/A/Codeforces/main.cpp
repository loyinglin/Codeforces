//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1520/problem/A)
 **题目大意：**
 给出一个字符串（由26个大写字母组成），询问这个字符串中，是否相同的字母都连在一起。
 
 **输入：**
 第一行整数t，表示有t个样例（1≤𝑡≤1000）
 每个样例两行，第一行是整数n，表示字符串长度 (1≤𝑛≤50)
 第二行是字符串
 **输出：**
 如果满足要求，则输出YES；
 如果不满足要求，则输出NO；
 
 **Examples**
 **input**
 5
 3
 ABA
 11
 DDBBCCCBBEZ
 7
 FFGZZZY
 1
 Z
 2
 AB
 
 **output**
 NO
 NO
 YES
 YES
 YES
 
 
 **题目解析：**
 用一个数组记录已经出现的字符串，从左到右枚举字符串；
 对于第i个字符，如果和第i-1个字符不相同，则判断是否出现过：
 已出现过则不满足要求；
 未出现则标识该字符已出现；
 
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

class Solution {
    static const int N = 100010;
public:
    int n, m;
    string str;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            cin >> str;
            int a[256] = {0}, ok = 1;
            a[str[0]] = 1;
            for (int i = 1; i < n; ++i) {
                if (str[i] == str[i-1]) {
                    continue;;
                }
                else {
                    if (a[str[i]]) {
                        ok = 0;
                    }
                    else {
                        a[str[i]] = 1;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
