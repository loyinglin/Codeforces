//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/849/problem/C
 题目大意：
 有一个字符数组，长度为n；（全部是小写字母）
 现在有一个操作：从数组中取出两个元素s和t，把字符s和t进行合并，得到新的字符串str，然后把str放入数组；
 每次操作的代价是，对于所有字母x∈{a,b,c...z}，字母x在两边s出现的次数的乘积的和；
 比如说：aab+aab, 代价就是(2*2) + (1*1) = 5；
 
 现在给出数字k，要求构造一个字符集合s，将s合并为一个字符串的最小代价刚好是k；
 
 输入数据：
 第一行，整数k (0 ≤ k ≤ 100 000)
 
 Examples
 input
 12
 output
 abababab
 样例解释：
 对于字符集合 {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'}，其中一个最小代价的方案是：
 {"ab", "a", "b", "a", "b", "a", "b"}，代价是0；
 {"aba", "b", "a", "b", "a", "b"}, 代价是1;
 {"abab", "a", "b", "a", "b"}, 代价是1;
 {"abab", "ab", "a", "b"}, 代价是0;
 {"abab", "aba", "b"}, 代价是1;
 {"abab", "abab"}, 代价是1;
 {"abababab"}, 代价是8；
 总得的最小代价是12；
 
 
 
 
 题目解析：
 对于代价的计算，我们看简单的例子：
 aaaa的两种合并方式，
 1、先(a,a)=aa, (a,a)=aa, 再(aa,aa)=aaaa；
 2、先(a,a)=aa, 在(aa,a)=aaa, 再(aaa,a)=aaaa;
 
 这两种的代价分别是1+1+4=6;
 1+2+3=6;
 容易知道，对于(aa,aa)的操作方式，我们可以看成是(aa,a) + (aa,a)，然后根据定义，我们可以知道(aa,a)+(a,a)=(aaa,a)；
 其实合并方式1 和 合并方式2 是等价的；
 
 再由定义，我们知道不同字母的代价计算是独立的；
 
 对于一个字符集合s，其合并的最小代价∑x∈{a,b,c...z}, sum+=1+2+3+...+count(x-1);
 
 这样可以得到一个快速的构造方案：
 先尽可能填a，从1、2、3.... 直到不能再填，接着重复b的数量。
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<int> g[N];
set<int> may[N]; // 没有和父类gcd的
char a[N];
int vis[N];
int ans[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "a" << endl;
        return 0;
    }
    
    int cur = 0;
    while (cur < 26 && n != 0) {
        for (int i = 1; i <= n; ++i) {
            ans[cur] = i + 1;
            n -= i;
        }
        ++cur;
    }
    
    
    for (int i = 0; i < cur; ++i) {
        while (ans[i]) {
            --ans[i];
            putchar('a' + i);
        }
    }
    
    
    
    return 0;
}

/**
 
 8
 48828 34632 22542 29094 11505 34476 46722 25545
 
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 8
 
 
 8
 192 96 48 24 12 6 2 2
 
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 8
 
 
 
 3
 12 11 11
 
 1 2
 2 3
 
 **/
