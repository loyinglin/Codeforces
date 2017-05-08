//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/766/problem/B
 题目大意：
 给出n个线段，每个线段长度为a[i];
 从中选出3个线段，组成一个三角形；
 如果可以，输出YES；
 如果不可以，输出NO；
  
 n (3 ≤ n ≤ 1e5)
 a1, a2, ..., an (1 ≤ ai ≤ 1e9)
 
 >Examples
 input
 5
 1 5 3 2 4
 output
 YES
 input
 3
 4 1 2
 output
 NO
 
 
 题目解析：
 这个题的题意很清晰， 我们知道三角形的性质是：两边之和大于第三边；
 暴力的做法是：枚举两条边，再遍历每一条边，通过上面的性质，判断是否为三角形；
 但是因为n较大，暴力枚举不可行；
 
 假设三条边分别是a,b,c，并且a<=b<=c，那么只需满足 a+b>c的条件即可；
 那么先对数组a排序，然后枚举两条边，假设是a[i]和a[j]，且(i < j)
 容易知道，对于第三条边，必然是a[j+1]；（证：如果存在k>j+1，且a[i]+a[j]>a[k],那么必然有a[i]+a[j]>a[j+1]);
 同理，我们知道j必然等于i+1；
 这样我们可以知道，只需枚举i，就能知道另外两条边；
 复杂度降到O(N); 
 
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
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
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0, last = 2;
    for (int i = 0; i + 2 < n; ++i) {
        int sum = a[i] + a[i + 1];
        if (sum > a[i + 2]) {
            ans = 1;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
