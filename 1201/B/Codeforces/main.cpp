//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1201/problem/B)
 **题目大意：**
 有n个数字，有一个操作：选择两个数字a[i]和a[j]（i ≠ j)，使得a[i]=a[i]-1，a[j]=a[j]-1;（两个数字-1）
 现在想知道，能否执行若干个操作，使得所有的数字变为0.
 
 
 输入：
 第一行，整数𝑛 (2≤𝑛≤10e5)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10e9)
 
 输出：
 如果可以，输出YES；
 如果不可以，输出NO；
 
 Examples
 input
 4
 1 1 2 2
 output
 YES
 input
 6
 1 2 3 4 5 6
 output
 NO
 
 **题目解析：**
 这里的核心逻辑是如何分配这些数字。
 先从小范围数据来分析，假如n=2，那么没得选只能a[0]，a[1]操作；
 假如n=3，我们先把数组从小到大排序，有a[0]<a[1]<a[2]；
 容易知道，如果a[0]+a[1]<a[2]的话，是无解的；
 同时如果a[0]+a[1]+a[2]=sum，sum%2==1的话，也是无解的；
 在其他情况下，有a[0]+a[1]>=a[2]，并且(a[0]+a[1]-a[2])%2==0；
 那么，可以对a[0],a[1]进行操作，则相当于(a[0]+a[1]) -= 2，最终可以得到a[0]+a[1]=a[2]；
 
 当n=4的时候，同样先排序，得到a[0]<a[1]<a[2]<a[3]；
 为了复用上面的思考过程，我们可以把a[0],a[1]合并成一个数字来看，这个数字除了可以和其他数字进行-1操作，也可以自己和自己进行-1的操作；
 再重复上面的思考过程，最终发现只有两种情况无解：
 1、sum%2==1，和为奇数无解；
 2、a[n-1]*2>sum，最大数超过和的一半，无解；
 其他的情况，都可以用上面类似的方法得到一个解。
 
 
 
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
const int N = 201234, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    lld sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = sum + a[i];
    }
    sort(a, a + n);
    if (sum % 2 || 2 * a[n - 1] > sum) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
    
    return 0;
}
