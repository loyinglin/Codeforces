//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/940/problem/B)
 **题目大意：**
 给出四个整数n，k，A，B;
 现在需要把数字n变成数字1，每次有两个操作：
 1、n=n-1, 代价为A；
 2、n=n/k，代价为B；（要求是n能被k整除）
 求最小代价。
 
 **输入数据：**
 四行整数，分别表示 n、k、A、B (1 ≤ n,k,A,B ≤ 2·1e9)
 
 >**Examples**
 **input**
 9
 2
 3
 1
 **output**
 6

 样例解释：
 Subtract 1 from x (9 → 8) paying 3 coins.
 Divide x by 2 (8 → 4) paying 1 coin.
 Divide x by 2 (4 → 2) paying 1 coin.
 Divide x by 2 (2 → 1) paying 1 coin.
 
 **题目解析：**
 直接的做法，每次判断操作的代价，选择最小的代价进行操作，直到数字变为1。
 但是因为n的数字较大，如果出现极端的情况，可能会进行n-1次操作1，这样使得复杂度过高。
 
 换一种思路，操作2只能发生在n%k==0的情况，那么只需判读数字n变成n/k*k的操作代价是否划算。
 假设t=n/k*k，那么如果数字t进行操作2都不划算，那么往后所有的操作2都是不划算的。
 
  **思考🤔：**
 代码很简洁。
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
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


int main(int argc, const char * argv[]) {
    lld n, k, a, b;
    cin >> n >> k >> a >> b;
    lld ans = (n - 1) * a;
    while (n > 1) {
        lld t = n / k * k;
        if ((t - t / k) * a <= b) {
            break;
        }
        else {
            n = t / k;
            ans = ans - (t - t / k) * a + b;
        }
    }
    cout << ans << endl;
    return 0;
}
