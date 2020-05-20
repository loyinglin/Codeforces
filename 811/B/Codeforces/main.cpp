//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/811/problem/B)
 **题目大意：**
 给出一个整数1~n的排列。
 接下来有m个询问，每个询问包括 l, r, x。 (l <= x <= r)
 [l, r]区间内的数字会进行一次从小到大的排序，然后得到一个新的1到n的排列，问第x个数字是否等于原来的第x个数字；
 每次询问之后，数组会变回初始的排列顺序；
 
 **输入数据**
 第一行，整数n, m (1 ≤ n, m ≤ 1e4)
 第二行，n个整数的排列
 接下来m行，每行有3个整数 l, r, x (1 ≤ l ≤ x ≤ r ≤ n)
 
 **输出数据**
 共m行，如果等于则输出Yes，如果不等于则输出No；
 
 **Examples**
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
 样例解释：
 样例第一行，按照给出区间，重新排序后的数组是[1, 2, 3, 4, 5]，第3个元素是3，输出Yes；
 样例第二行，按照给出区间，重新排序后的数组是[3, 4, 5, 2, 1]，第1个元素不是1，输出No；
  
 **题目解析：**
 题目给出的是1~n的排列，那么有个性质1--没有重复的数字；
 m个询问是独立的，没有相互影响；
 对于询问l, r, x，直接对[l, r]排序的复杂度是O(NlogN)，m个询问的复杂度会到NMLogN，复杂度较高；
 
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
