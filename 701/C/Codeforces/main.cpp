//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/701/problem/C
    题目大意：N个字符串，找到最短的区间，包含所有字符串出现过的字符，输出区间长度。
    题目解析：
 假设[1, right] 包含了所有的字符，其中：[left, right]这个区间就包含了所有的字符，那么[1, left]可以舍弃；
 
 
************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000


int flag[N];
int c[N];
char str[N];


int main(int argc, const char * argv[]) {
    // insert code here...
   
    int n, sum = 0;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        if (!flag[str[i]]) {
            flag[str[i]] = 1;
            ++sum;
        }
    }
    
    int left = 0, k = 0;
    int ret = n;
    for (int i = 0; i < n; ++i) {
        if (!c[str[i]]) {
            ++k;
        }
        ++c[str[i]];
        
        if (k == sum) { //[left, i]区间，存在答案
            while (c[str[left]] > 1) {
                --c[str[left]];
                ++left;
            }
            ret = min(ret, i - left + 1);
        }
        
    }
    
    cout << ret << endl;
    
    
    return 0;
}
