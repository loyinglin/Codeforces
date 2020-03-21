//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1189/problem/B)
 **题目大意：**
 给出n个数字，用n个数字拼成一个环，要求每个数字比相邻数字之和要小。
 
 
 输入：
 第一行，𝑛 (3≤𝑛≤10^5)
 第二行，n个数字 𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤10^9)
 
 输出：
 如果无解输出"NO"；
 如果有解则输出"YES"，接下来一行输出n个数字，第1个和第n个认为是相连的。
 
 Examples
 input
 3
 2 4 3
 output
 YES
 4 2 3
 input
 5
 1 2 3 4 4
 output
 YES
 4 4 2 1 3
 input
 3
 13 8 5
 output
 NO
 
 **题目解析：**
 当某个数字很大的时候，比任意两个数字的和都大时，无解；
 从题目的条件来看，数字越大则越难分配，数字越小则容易分配，数字最小的数肯定可以满足题目要求。
 
 因为题目的数字是无序的，可以先对数字进行一个排序。（假如是从大到小）
 我们先拿出一个最大的数字a[0]，将a[1]和a[2]分配到a[0]的两侧：
    a[0]
    /  \
 a[1]  a[2]
 如果a[0]>=a[1]+a[2]，则无解。
 因为a[1]<a[0]，所以a[1]肯定满足条件。
 
 按照上面的思路，可以每次拿出两个数字，填充到两侧。
 最后将两侧的数据串联起来，则形成一个环。
 
 只要满足a[0]<a[1]+a[2]，则整个环都会满足题目的要求。
 
 实现的过程，可以用deque（双端队列来模拟这个过程）
 
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

deque<int> q;
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        bool isBack = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (isBack) {
                q.push_back(a[i]);
            }
            else {
                q.push_front(a[i]);
            }
            isBack = !isBack;
        }
        for (int i = 0; i < n; ++i) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
    
    
    return 0;
}
