//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/741/problem/A
 题目大意：
 输入n个数字a[i]，设定一个操作x=a[x];
 找到一个最小的k，要求：
 执行k次，x=a[x]之后，x的最终值是y；
 如果对y也执行k次，y=a[y]，y的最终值是x；
 
 举例：
 3
 2 3 1
 k = 3
 （2->3->1->2, 3->1->2->3)
 
 2
 2 1
 k = 1
 （1->2，2->1)
 
 
 题目解析：
 因为n个数，每个数只有一个出去的选择；
 那么对于a[i]，可以连一条边i->a[i]，表示选择；
 题目要求就是从i出去的边，能最后指向自己；
 
 那么按照边遍历，如果n个数字能划分成若干个圈即可；
 每个圈按照各自的k求出最小公倍数；（因为可以x、y互换，所以如果k%2==0，要除以2）
 
 
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

int a[N], used[N];

//最大公约数
int gcd(int m,int n){
    int t;
    if(m<n){t = n;n = m;m = t;}
    if(n == 0)
        return m;
    else
        return gcd(n,m % n);
}

//最小公倍数
int lcm(int a,int b){
    return a/gcd(a,b) * b;
}



int main(int argc, const char * argv
         []) {
    lld n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            int t = i, k = 0;
            while (!used[t]) {
                used[t] = 1;
                ++k;
                t = a[t];
            }
            if (t != i) {
                ans = -1;
                break;
            }
            if (k % 2 == 0) {
                k /= 2;
            }
            ans = lcm(ans, k);
        }
    }
    
    cout << ans << endl;
    return 0;
}
