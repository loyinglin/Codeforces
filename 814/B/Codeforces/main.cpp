//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/814/problem/B
 题目大意：
 
 给出长度为n的两个整数数组a和b，数组a和数组b至少有一个数字不相同；
 现在需要构造出新的数组c，要求：
 1、数组c是1到n的一种排列；
 2、数组c和数组a有且仅有一个数字不同，数组c和数组b有且仅有一个数字不同；
 如果有多个解，可以任意输出一个。
 数据范围
  (2 ≤ n ≤ 1 000)
  (1 ≤ a[i] ≤ n)
  (1 ≤ b[i] ≤ n)
 
 Examples
 input
 5
 1 2 3 4 3
 1 2 5 4 5
 output
 1 2 5 4 3
 
 样例解释：
 输入
 第一个数字5，表示n=5；
 接下来两行，每行有5个整数。
 输出
 1, 2, 5, 4, 3 和 1, 2, 3, 4, 5 都是可行解。
 
 
 题目解析：
 根据题意可以知道，数组a的元素是在[1, n]之间，由于数组c的数字是由[1,n]中的数字不重复排列而来，且数组c会有一个数字和数字a不同，其他数字是一样的；
 那么数组a必然会存在两个相同的数字x，并且数组c与数组a不相同的数字就是x；（这里是题目意思的核心）
 那么可以直接把数组a的一个x修改为数字t，验证是否满足题意，如果不行再尝试另一个解。
 
 
 
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
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N], visA[N];
int b[N], visB[N];

int find(int c[], int n) {
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            return i;
        }
    }
    return 0;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<int> vec;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        visA[a[i]]++;
    }
    
    for (int j = 1; j <= n; ++j) {
        cin >> b[j];
        visB[b[j]]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (visA[a[i]] == 2) {
            vec.push_back(i);
        }
    }
   
    a[vec[0]] = find(visA, n);
    
    int diff = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) {
            ++diff;
        }
    }
    if (diff != 1) {
        a[vec[0]] = a[vec[1]];
        a[vec[1]] = find(visA, n);
    }
   
    
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
