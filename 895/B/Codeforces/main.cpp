//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/895/problem/B
 题目大意：
 如果数字x的二进制表示，是由k+1个连续的1 与 k个连续的0组成，那么数字x是beautiful Number；
 1(2) = 1(10);
 110(2) = 6(10);
 
 给出数字n，求数字n最大的约数，并且这个约数是beautiful Number.
  (1 ≤ n ≤ 105)
 
 
 题目解析：
 可以直接遍历<=n的所有数字，先判断约数，再判断是否为beautiful Number；
 为了代码更简单，先枚举出来所有的beautiful Number，再从中选择一个最大且是n的约数的beautiful Number。
 
 
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
    int k = 1;
    a[0] = 1;
    do {
        int sum = (pow(2, k + 1) - 1) * pow(2, k);
        if (sum > N) {
            break;
        }
        else {
            a[k++] = sum;
        }
    } while (true);
    
//    for (int i = 0; i < k; ++i) {
//        cout << i << " " << a[i] << endl;
//    }
    
    
    int n;
    cin >> n;
    for (int i = k - 1; i >= 0; --i) {
        if (n % a[i] == 0) {
            cout << a[i] << endl;
            break;
        }
    }

    
    return 0;
}
