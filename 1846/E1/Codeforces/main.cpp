//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/E1)
 **题目大意：**
 有一种雪花结构，可以用这样的规则来描述：
 1、初始状态只有一个节点；
 2、往每一个边的数量小于k的节点，添加k条边以及对应的新节点；
 不断重复规则2达到2次以上，则能形成雪花结构， [如图](https://espresso.codeforces.com/fe824c2b4d492a130f08a011d1b7f63735543344.png)
 
 现在想知道，是否存在一个雪花结构的结点数为n；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行整数𝑛 (1≤𝑛≤1e6 ).
 
 **输出：**
 每个样例，如果无解直接输出NO；
 如果有解，则先输出YES；
 
 **Examples**
 **input**
 9
 1
 2
 3
 6
 13
 15
 255
 10101
 1000000

 **output**
 NO
 NO
 NO
 NO
 YES
 YES
 YES
 YES
 NO



 **题目解析：**
 按照题目的要求，一个雪花的结构可以用 1 + k + k*k + ....来描述；
 找到规律，那么可以枚举k，从小到大，再枚举雪花结构重复次数。
  
 
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
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            //1 + n + n*n
            lld ans = 0, cur = 2;
            while (!ans && cur < 1000) {
                lld tmp = 1 + cur + cur * cur, pos = cur * cur * cur;
                while (tmp + pos <= n) {
                    tmp += pos;
                    pos *= cur;
                }
                if (tmp == n) ans = 1;
                ++cur;
            }
            cout << (ans ? "YES" : "NO") << endl;
            
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
