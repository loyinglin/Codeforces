//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1201/problem/A)
 **题目大意：**
 n个学生参加测试，一共有m道题，每道题的答案可能是(A, B, C, D , E)中的一个；
 m道题分别有𝑎1,𝑎2,…,𝑎𝑚，m个分数；
 现在已知道n个学生对m道题目的选择，假如题目的正确答案可以任意选择，想知道所有学生最大的分数总和是多少？
 
 
 输入：
 第一行𝑛 and 𝑚 (1≤𝑛,𝑚≤1000)
 接下来n行，每行有m个字符，每个字符是 (A, B, C, D or E)表示选择的答案；
 接下来一行，有m个整数，𝑎1,𝑎2,…,𝑎𝑚  (1≤𝑎𝑖≤1000)
 
 
 输出：
 最大的分数。
 
 Examples
 input
 2 4
 ABCD
 ABCE
 1 2 3 4
 output
 16
 样例解释：答案是ABCD时，分数最大，最大值是16
 input
 3 3
 ABC
 BCD
 CDE
 5 4 12
 output
 21
 
 
 **题目解析：**
 每道题是相对独立的，可以分来开看；
 对于每一道题，选择答案人数最多的结果，乘以分数即可得到这道题的最大分数；
 累加每一道题得到 最大分数和。
 
 
 
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
    int n, m;
    cin >> n >> m;
    
    string str[1001];
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    int a[1001], ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        int v[5] = {0}, cnt = 0;
        for (int j = 0; j < n; ++j) {
            v[str[j][i] - 'A']++;
            cnt = max(cnt, v[str[j][i] - 'A']);
        }
        ans += cnt * a[i];
    }
    
    cout << ans << endl;
    
    return 0;
}
