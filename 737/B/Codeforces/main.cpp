//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/737/problem/B
 题目大意：
 n个cell排成一行，b个连续的cell可以放下一艘ship，总共有a艘ship；
 ships可以相邻，但是不能多个ship覆盖同个cell；
 现在朝这n个cell打枪，目前已经打了k枪，但是没有打中一艘船；
 现在询问，还需要打多少枪，保证至少能打中一艘船。
  n, a, b, k (1 ≤ n ≤ 2·105, 1 ≤ a, b ≤ n, 0 ≤ k ≤ n - 1)
 Examples
 input
 5 1 2 1
 00100
 output
 2
 4 2
 input
 13 3 2 3
 1000000010001
 output
 2
 7 11
 
 解释：0101字符串中，1表示已经往当前位置打枪，保证只有k个1；
 
 题目解析：
 贪心。
 从左到右，只要出现连续的b个空的cell，就打一枪，假设总共打了m枪；
 最后因为有a艘船，答案就是m-a+1;（假设有3个位置，2艘船，那么只要打两枪即可）
 
 
 
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
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            ++sum;
        }
        else {
            sum = 0;
        }
        if (sum == b) {
            sum = 0;
            ++cnt;
            if (cnt >= a) {
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
