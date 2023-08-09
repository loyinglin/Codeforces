//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1841/problem/B)
 **题目大意：**
 某个数组被定义为beautiful，只要满足：
 将数组前面连续的一段（长度可以是0）切下来，拼接到数组最后面，数组最终是非递减的，那么数组是beautiful。
 
 现在有一个数组，初始化状态为空；
 依次给出n个整数，如果某个整数添加到数组末尾后数组是beautiful，那么该整数必须添加到数组末尾，否则放弃；
 问最终由有哪些数字会添加到数组中。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，整数𝑛 (1≤𝑛≤2e5)
 第二行，n个整数𝑎1,𝑎2,…𝑎𝑛 (0≤𝑎𝑖≤1e9 )
 
 
 **输出：**
 每个样例一行，由01组成长度为n的字符串；第i个字符为1表示第i个字符会被添加到数组，为0则表示不会；
 
 **Examples**
 **input**
 3
 9
 3 7 7 9 2 4 6 3 4
 5
 1 1 1 1 1
 5
 3 2 1 2 3


 **output**
 111110010
 11111
 11011


 **题目解析：**
 按照题目的要求，在过程中并没有决策的空间，那么关键点就是如何快速得到这个结果。
 
 1、当a[i+1] >= a[i]，继续保持；
 2、当a[i+1] < a[i]，首次出现就要进行分割，a[i+1]要放在数组末尾，如果a[1] >= a[i]，那么a[i]可行；
 接下来要满足，所有数字大于等于a[i]并且小于等于a[1]；
 
 这里犯了一次低级错误 cur = a[i]写成了cur = ans[i]；
 导致出现几次Wrong Answer，后面名字要有差异。
 
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
    int a[N], ans[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            bool rev = 0;
            int cur = 0;
            memset(ans, 0, sizeof(ans));
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (i == 0) {
                    ans[i] = 1;
                    cur = a[i];
                }
                else {
                    if (rev) {
                        if (a[i] >= cur && a[i] <= a[0]) {
                            cur = a[i];
                            ans[i] = 1;
                        }
                    }
                    else {
                        //  0 4 15 18 4 10 12 8 13 8 15 0 14 12 10 12 10 14 13
                        if (a[i] >= cur) {
                            ans[i] = 1;
                            cur = a[i];
                        }
                        else if (i == 1 || a[0] >= a[i]){
                            cur = a[i];
                            rev = 1;
                            ans[i] = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i) putchar('0' + ans[i]);
            puts("");
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
