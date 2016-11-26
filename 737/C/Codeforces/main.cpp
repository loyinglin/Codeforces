//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/737/problem/C
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
const int N = 201001;

char str[N];
vector<int> ansv;

int main(int argc, const char * argv
         []) {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    cin >> str;
    int left = n - a * b;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            ++sum;
        }
        else {
            sum = 0;
        }
        if (sum == b) {
            sum = 0;
            if ((i + 1) % b <= left) {
                ansv.push_back(i + 1);
            }
        }
    }
    
    cout << ansv.size() << endl;
    for (int i = 0; i < ansv.size(); ++i) {
        cout << ansv[i] << " ";
    }
    cout << endl;

    
    return 0;
}
