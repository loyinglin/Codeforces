//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1277/problem/A)
 **题目大意：**
 给出正整数n，求整数1到整数n之中，有多少整数是由单一的字符组成，比如说1 , 77, 777, 44 和 999999 就是符合要求的整数。
 整数1到18中，只有 1, 2, 3, 4, 5, 6, 7, 8, 9 和 11符合要求。
 
 输入：
 第一行整数𝑡，表示有t个样例  (1≤𝑡≤1e4)
 每个样例一行，𝑛  (1≤𝑛≤1e9)
 
 输出：
 每个样例一行，输出1到n之间有多少个数字符合要求。

 
 input
 6
 18
 1
 9
 100500
 33
 1000000000
 
 output
 10
 1
 9
 45
 12
 81
 
 **题目解析：**
 纯暴力枚举，则是从1、2、3开始算，把每个数字拆解成字符串数组，然后判断数字是否相同的；
 但是由于n=1e9，数据量较大，容易在字符串转化的过程中超时。
 
 换一种思路，只枚举符合要求的部分，比如说先考虑1位数、再考虑2位数、然后是3位数，知道数字比n大。
 
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

char a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while (t--) {
        cin >> a;
        int n = strlen(a);
        
        int ans = (n - 1) * 9 + (a[0] - '0');
        int ok = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[0]) {
                ok = 0;
                break;
            }
            else if (a[i] > a[0]) {
                ok = 1;
                break;
            }
        }
        if (!ok) {
            --ans;
        }
        
        cout << ans << endl;
    }
           
    
    return 0;
}


/**
 
 */
