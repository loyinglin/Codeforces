//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1173/problem/A)
 **题目大意：**
 小明在某个社区进行评论，有x个人点赞同，y个人点反对，z个人可能会点赞同，也可以会点反对；
 如果赞同人数大于反对人数，则小明的评论旁边会显示"+"；
 如果反对人数大于赞同人数，则小明的评论旁边会显示"-"；
 如果反对人数等于赞同人数，则小明的评论旁边会显示"0"；
 问，小明这个评论旁边可能会显示什么？
 
 输入：
 一行，𝑥, 𝑦, 𝑧 (0≤𝑥,𝑦,𝑧≤100)
 
 输出：
 如果结果是确定的，则输出"+"、"-"、"0"；
 如果结果不确定，则输出"?";
 
 Examples
 input
 2 0 1
 output
 +
 input
 2 2 2
 output
 ?
 
 
 **题目解析：**
 dif=abs(x-y)；
 如果dif>z，则直接输出+/-；
 如果dif<z，则直接输出?；
 如果dif==z，则看z是否为0，不为0则输出?，为0则输出0；
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x, y, z;
    cin >> x >> y >> z;
    int dif = x > y ? x-y : y-x;
    if (dif > z) {
        cout << (x > y ? "+" : "-") << endl;
    }
    else if (dif < z) {
        cout << "?" << endl;
    }
    else {
        if (z == 0) {
            cout << 0 << endl;
        }
        else {
            cout << "?" << endl;
        }
    }
    
    return 0;
}
