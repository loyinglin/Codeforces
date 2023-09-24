//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1867/problem/A)
 **题目大意：**
 有n个整数的数组a，现在需要构造一个1到n的排列b；
 令𝑐𝑖 = 𝑎𝑖−𝑏𝑖，希望最终𝑐𝑖 出现尽可能多的不同整数。

 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤40000)
 每个样例两行
 第一行整数𝑛(1≤𝑛≤4⋅1e4)
 第二行整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤1e9)
 
 **输出：**
 每个样例一行，输出符合要求的1-n排列。
 
 **Examples**
 **input**
 3
 1
 100000
 2
 1 1
 3
 10 3 3

 **output**
 1
 2 1
 1 3 2




 **题目解析：**
 当n=1时，只有1个解；
 当n=2时，假如a1<a2,那么令c[1]=a1-2,c[2]=a2-1，由于a1<a2且2>1，那么c1必然<c2;
 当n=3时，同理我们可以把3、2、1依次与数组中较小值进行匹配，可以保证最终的值各不相同。
  
 
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
 
class Solution {
    static const int N = 201010;
    pair<int, int> a[N];
    int b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i].first;
                a[i].second = i;
            }
            sort(a, a + n);
            for (int i = 0; i < n; ++i) {
                b[a[i].second] = n - i;
            }
            for (int i = 0; i < n; ++i) cout << b[i] << " ";
            cout << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
