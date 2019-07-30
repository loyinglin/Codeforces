//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1195/problem/A)
 **题目大意：**
 有n个学生，每个学生都有自己喜欢的饮料类型，用𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑘)表示，一共有k种饮料的类型。
 现在老师要采购饮料，饮料是两瓶装；
 所以老师打算采购(n/2)个单位，保证每个学生至少有一瓶。（n/2向上取整，如果5个人，老师会买3个单位）
 老师希望尽可能多的学生能喝到喜欢的饮料类型，问最多能有几个学生喝到？
 
 
 输入：
 第一行，𝑛 and 𝑘 (1≤𝑛,𝑘≤1000)
 接下来n行，分别表示 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑘)
 
 输出：
 能够喝到喜欢饮料的学生人数；
 
 Examples
 input
 5 3
 1
 3
 1
 1
 2
 output
 4
 
 **题目解析：**
 兴趣相同的，两两成对拿出来，凑成一个单位；(ans += 2)
 剩下的所有人(n - ans)，每个人的兴趣都不相同，任意两两凑对一个单位；(n-ans+1)/2
 
 
 
 
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


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k;
    cin >> n >> k;
    int a[1001] = {0}, ans = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ++a[t];
        if (a[t] % 2 == 0) {
            ans += 2;
        }
    }
    ans += (n - ans + 1) / 2;
    cout << ans << endl;
    
    return 0;
}
