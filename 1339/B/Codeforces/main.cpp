//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1339/problem/B)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，四个整数𝑎 , 𝑏, 𝑐, 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤10^9）
 
 **输出：**
 每个样例一行，三个s整数𝑥, 𝑦, 𝑧；
 
 **Examples**
 **input**
 4
 1 3 5 7
 1 5 5 7
 100000 200000 300000 400000
 1 1 977539810 977539810
 **output**
 3 4 5
 5 5 5
 182690 214748 300999
 1 977539810 977539810
 
 
 **题目解析：**
 假设n个数字散落在一维数轴上，那么任意两个数字的绝对值之差，就是两个数字在数轴之间的间距；
 题目的问题转化为，求一个排列，使得相邻两个数字的间距越来越大；
 假设从小到大排序完之后，数组是a[N]；容易知道，所有数字中间距的是a[n]-a[1]，那么可以将这个数字放到最右边；
 同理，第二大的数字要么是a[1]和a[n-1]，要么是a[2]和a[n]，我们任取其中一种，假设是a[1]和a[n-1]；
 同理，第三大的数字就是a[2]和a[n-1]；
 同理，第四大的数字就是a[3]和a[n-1]；
 如此交替选择，会使得间距越来越小，得到了一种满足题意的解法；
 
 **思考🤔：**
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
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

int a[N];
int ans[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >>a[i];
        sort(a, a + n);
        int l = 0, r = n - 1, k = n - 1;
        while (l <= r) {
            ans[k--] = a[r--];
            if (l <= r) {
                ans[k--] = a[l++];
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }   
    
    return 0;
}
