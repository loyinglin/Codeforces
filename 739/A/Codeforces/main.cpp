//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/739/problem/A
 题目大意：
 mex()定义：mex(arr)是 数组arr的最小且不属于S的整数，比如说 mex([0,1])=2；
 现在需要构造一个长度为n的数组，元素为非负整数；
 给出的m个区间(l[i], r[i])，所有的mex([l[i], r[i])的最小值最大；
 n and m (1 ≤ n, m ≤ 10^5)。
 
 要求：
 先输出f(i)最小值的最大值，再输出n个元素；
 输出的值在0~1e9之间，如果有多个答案输出，输出任意一个；
 
 Examples
 input
 5 3
 1 3
 2 5
 4 5
 output
 2
 1 0 2 1 0
 样例解释：在[1,0,2,1,0]中，mex(1, 3)=3, mex(2, 5)=3, mex(4, 5)=2，最小值是2。
 
 
 题目解析：
 题目要求是所有mex(l, r)中的最小值 最大，我们知道对于mex(l, r)， r-l+1是最大的值。
 那么是否存在一种可能，使得r-l+1一定是可以的？
 
 有的，如下：
 0、1、2、3、0、1、2、3... 这种构造，只要len>=4，必然是5。
 
 同样，我们找到长度最小的(l, r)，得到len=(r-l+1)，按照上诉的方法构造，必然能得满足条件。
 
 
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
const int N = 101001;

int a[N];


int main(int argc, const char * argv
         []) {
    int n, m;
    cin >> n >> m;
    int len = n, idx = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (r - l < len) {
            len = r - l;
            idx = l;
        }
    }
    int p = 0;
    for (int i = idx; i <= n; ++i) {
        a[i] = p;
        if (p < len) {
            ++p;
        }
        else {
            p = 0;
        }
    }
    p = len;
    for (int i = idx - 1; i >= 1; --i) {
        a[i] = p;
        if (p > 0) {
            --p;
        }
        else {
            p = len;
        }
    }
    cout << len + 1 << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
