//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1313/problem/C2)
 **题目大意：**
 建筑公司要建n栋楼（排成一行），第i栋的设计最大高度是m[i]；
 并且当地城市有规定：每栋楼不能在左右两边同时出现比它高的建筑；
 用数学的语言来描述，即是每栋楼的最终高度a[i]必须要小于等于m[i]；不能存在j和k，满足j<i<k并且a[j]>a[i]<a[k]；
 现在想知道建筑公司如何分配每栋楼的高度，使得最终所有楼的总高度最大？
 
 
 **输入：**
 第一行整数𝑛 (1≤𝑛≤500000)
 第二行整数𝑚1,𝑚2,…,𝑚𝑛 (1≤𝑚𝑖≤10^9)
 
 **输出：**
 n个整数a[i]，如果有多个分配组合，输出任何一个总高度最大的组合；
  
 **Examples**
 input
 5
 1 2 3 2 1
 output
 1 2 3 2 1
 
 
 **题目解析：**
 由前面可以知道，最终结果必然是由一段非严格递增的数字，加上一段非严格递减的数字；
 我们用dpLeft[i]来表示前i个数字，保持非严格递增的最大高度总和，那么有dpLeft[i]可以由dpLeft[1]到dpLeft[i-1]算出来；这个状态转移的复杂度是O（N）；
 以样例的数据来看，当我们在计算1、2、3这个三个数字的dpLeft[3]的时候，dpLeft[3]可以直接由dpLeft[2]来递推；
 从i-1开始，找到第一个比a[i]小的数字k，我们有dpLeft[i]=dpLeft[k]+(i - k) * a[i]；
 
 同理，我们用dpRight[i]来表示从i到n的数字，保持非严格递减的数字；同样可以得到dpRight[i] = dpRight[k]+(k-i)*a[i]；
 然后遍历1~n，ans=max(ans, dpLeft[i] + dpRight[n+1]);
 得到最大的结果。
 
  **思考🤔：**
 单调性是进阶必备。
 
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
const int N = 501000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool cmp(int a, int b) {
    return a > b;
}

lld a[N], dpLeft[N], dpRight[N], ans[N];
stack<int> vec; // pos

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    
    vec.push(0);
    for (int i = 1; i <= n; ++i) {
        while (!vec.empty()) {
            int pos = vec.top();
            if (a[i] <= a[pos]) {
                vec.pop();
            }
            else {
                break;
            }
        }
        dpLeft[i] = dpLeft[vec.top()] + (i - vec.top()) * a[i];
        vec.push(i);
//        cout << i << " left " << dpLeft[i] << endl;
    }
    
    while (!vec.empty()) {
        vec.pop();
    }
    vec.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (!vec.empty()) {
            int pos = vec.top();
            if (a[i] <= a[pos]) {
                vec.pop();
            }
            else {
                break;
            }
        }
        dpRight[i] = dpRight[vec.top()] + (vec.top() - i) * a[i];
        vec.push(i);
//        cout << i << " right " << dpRight[i] << endl;
    }
    
    lld sum = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (dpLeft[i] + dpRight[i + 1] > sum) {
            sum = dpLeft[i] + dpRight[i + 1];
            pos = i;
        }
    }
    
    
    ans[pos] = a[pos];
    lld tmp = pos - 1;
    while (tmp >= 1) {
        ans[tmp] = min(a[tmp], ans[tmp + 1]);
        --tmp;
    }
    ans[pos + 1] = a[pos + 1];
    tmp = pos + 2;
    while (tmp <= n) {
        ans[tmp] = min(a[tmp], ans[tmp  - 1]);
        ++tmp;
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
