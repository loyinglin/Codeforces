//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/E2)
 **题目大意：**
 有一种雪花结构，可以用这样的规则来描述：
 1、初始状态只有一个节点；
 2、往每一个边的数量小于k的节点，添加k条边以及对应的新节点；
 不断重复规则2达到2次以上，则能形成雪花结构， [如图](https://espresso.codeforces.com/fe824c2b4d492a130f08a011d1b7f63735543344.png)
 
 现在想知道，是否存在一个雪花结构的结点数为n；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行整数𝑛 (1≤𝑛≤1e18 ).
 
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
 找到规律后，由于n的数据非常大，那么无法直接枚举k来得到结果。
 
 对于重复3次及以上，1 + k + k^2  + k^3，k取10^6是极大值，可以直接枚举。
 
 重点放在重复2次的情况，此时结果表达式为 1 + k + k^2 ，由于平方可以有很多种可能，需要用数学分析；
 容易知道最终结果是k * (k + 1) + 1，那么减去1之后进行sqrt开平方，可以得到一个数字q。容易知道q的结果是在n和n+1之间的数字，因为平方后的数字是大于n^2，小于(n+1)^2。
 
 
 注意：
 1、样例最大的情况，会超过int64。
 2、样例很多大数据，特殊情况会超时，可以先提前打表；
 
 
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
        map<lld, lld> h;
        lld cur = 2;
        lld total = 1000000000000000000l;
        while (cur < 1000000) {
            lld pos = cur * cur * cur;
            lld tmp = 1 + cur + cur * cur + pos;
            while (tmp <= total) {
                h[tmp] = 1;
                if (total / pos >= cur) {
                    pos *= cur;
                    tmp += pos;
                }
                else break;
            }
            ++cur;
        }
        
        while (t--) {
            lld n;
            cin >> n;
            //1 + n + n*n
            lld ans = h.find(n) != h.end();
            if (!ans) {
                lld tmp = sqrt(n - 1);
                if (tmp >= 2 && (tmp * tmp + tmp + 1) == n) ans = 1;
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
 
