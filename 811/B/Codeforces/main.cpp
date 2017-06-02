//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/818/problem/B
 题目大意：给出一个1~n的排列，有m个询问，每个询问包括 l, r, x。 (l <= x <= r)
 [l, r]区间内的数字会进行一次从小到大的排序，然后得到一个新的1到n的排列，问第x个数字是否等于原来的第x个数字；
 每次询问之后，数组会变回初始的排列顺序；
 
  n, m (1 ≤ n, m ≤ 1e4)
  l[i], r[i], x[i] (1 ≤ l[i] ≤ x[i] ≤ r[i] ≤ n)
 
 Examples
 input
 5 5
 5 4 3 2 1
 1 5 3
 1 3 1
 2 4 3
 4 4 4
 2 5 3
 output
 Yes
 No
 Yes
 Yes
 
 NoNote
 Explanation of first test case:
 [1, 2, 3, 4, 5] — permutation after sorting, 3-rd element hasn’t changed, so answer is "Yes".
 [3, 4, 5, 2, 1] — permutation after sorting, 1-st element has changed, so answer is "No".
 [5, 2, 3, 4, 1] — permutation after sorting, 3-rd element hasn’t changed, so answer is "Yes".
 [5, 4, 3, 2, 1] — permutation after sorting, 4-th element hasn’t changed, so answer is "Yes".
 [5, 1, 2, 3, 4] — permutation after sorting, 3-rd element has changed, so answer is "No".
 
 
 题目解析：
 题目给出的是1~n的排列，那么有个性质1--没有重复的数字；
 m个询问是独立的，没有相互影响；
 对于询问l, r, x，直接对[l, r]排序的复杂度是O(NlogN)，m个询问的复杂度会到N^2LogN，题目是无法接受的；
 
 因为要询问的是第x个数字是否改变，利用性质1，那么只需统计比a[x]小的区间数字有多少个，即可知道a[x]具体的位置坐标，再和原来的数字进行判断即可。
 统计的方法是遍历区间[l, r]，复杂度为O(N)，m个询问的复杂度为N^2，可以接受。
 
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
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        int id = 0;
        for (int i = l - 1; i < r; ++i) {
            if (a[i] < a[x - 1]) {
                ++id;
            }
        }
        if (id == x - l) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        
    }
    
    return 0;
}
