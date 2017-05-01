//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/761/problem/D
 题目大意：
 假设有一个数组a，数组b，长度都为n，并且l ≤ a[i] ≤ r 和 l ≤ b[i] ≤ r;
 定义一个数组c,c[i] = b[i] - a[i]，并且数组c里面没有相同的元素；
 数组p 表示数组c中的大小关系,比如说 c=[250, 200, 300, 100, 50], 那么 p = [4, 3, 5, 2, 1];
 
 现在给出数组a和p，还有长度n，数组b的范围[l, r];
 求是否存在一个数组b，满足要求？
 如果有，输出数组b；
 如果没有，输出-1；
 
  n, l, r (1 ≤ n ≤ 1e5, 1 ≤ l ≤ r ≤ 1e9)
  (l ≤ a[i] ≤ r)
  (1 ≤ p[i] ≤ n)
 
 Examples
 input
 5 1 5
 1 1 1 1 1
 3 1 5 4 2
 output
 3 1 5 4 2
 
 input
 6 1 5
 1 1 1 1 1 1
 2 3 5 4 1 6
 output
 -1
 
 
 题目解析：
 根据题目定义，我们需要在[l, r]范围内，寻找一个数组b，满足c[i]=b[i] - a[i], c[i]各不相同，并且大小顺序满足数组p;
 容易知道，b[i] = a[i] + c[i];
 c[i]是不确定的，因为确定c[i]就相当于确定b[i];
 限制在于b[i]有范围，否则c[i]只需在[1, n]按顺序选择即可；
 
 那么我们能否先按照c=[1, n]，直接算出b[i]的范围，再对b[i]的值进行缩减？
 先对p排序，得到[1,2,3]的数组，和新的a[i];
 那么有b[i]=a[i]+i;
 可能会有 b[i]<l || b[i]>r 的情况出现。
 假设找到一个最小值bMin, 一个最大值bMax;
 现在需要保证最小值bMin>=l, 那么整个数组b，都应该+(l - bMin)的大小；
 （这里思考🤔，是否存在不统一加的更优解？bMin的值变大，导致其对应的c[j]变大， c[1~j]可以不变，c[j+1~n]的值会变大）
 
 故而采取，c[i]实时计算，如果b[i]<l ,那么直接令b[i]=l, 那么c= b[i] - a[i]，b[i]变大会导致c[i]，变大。
 只要保证之后b[i] <= r即可；
 
 
 
 
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

struct Node {
    int a, b, c, p, n;
}node[N];
int a[N];

bool cmp(Node x, Node y) {
    return x.p < y.p;
}
bool cnp(Node x, Node y) {
    return x.n < y.n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, l, r;
    
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].a;
        node[i].n = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].p;
    }
    sort(node + 1, node + 1 + n, cmp);
    node[1].b = l;
    node[1].c = l - node[1].a;
    for (int i = 2; i <= n; ++i) {
        node[i].c = node[i - 1].c + 1;
        node[i].b = node[i].c + node[i].a;
        if (node[i].b < l) {
            node[i].b = l;
            node[i].c = l - node[i].a;
        }
        if (node[i].b > r) {
            cout << -1 << endl;
            return 0;
        }
    }
    sort(node + 1, node + 1 + n, cnp);
    for (int i = 1; i <= n; ++i) {
        cout << node[i].b << " ";
    }
    return 0;
    return 0;
}
