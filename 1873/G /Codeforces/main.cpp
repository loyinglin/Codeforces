//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1873/problem/G)
 **题目大意：**
 给出一个字符串s，现在可以进行以下操作：
 1、将某个子串AB，替换成子串BC；
 2、将某个子串BA，替换成子串CB；
 
 现在想知道，最多可以对字符串进行多少次操作。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，字符串𝑠 ，只有字符A和B (1≤|𝑠|≤2⋅1e5)
  
 **输出：**
 每个样例一行，输出可以最多可以执行的操作数。
 
 **Examples**
 **input**
 8
 ABBA
 ABA
 BAABA
 ABB
 AAAAAAB
 BABA
 B
 AAA

 **output**
 2
 1
 3
 1
 6
 2
 0
 0



 **题目解析：**
 假设原来字符串是xxxAByyy，进行一次操作1之后，会变成xxxBCyyy；
 容易知道，字符C会成为阻断，yyy无法与C形成搭配，但是xxxB仍然可能会产生操作1，比如说AAAB这样的字符串就可以连续执行操作1；
 同理，BAAA可以连续执行操作2；
 
 那么将连续的A聚合起来，题目的要求，就变成如何分配B给连续A，使得最终的结果最大；
 对于 ABABABA的这样字符，那么从中选择一个最小的A即可。
 但是对于BABA、ABBA这样的字符呢？
 
 为了方便计算，我们可以用字符B来分割原字符串。
 如果遇到ABBA这样的字符，我们假设在BB中间插入一个A(0)的字符，那么整个算法就完善起来：
 整个字符串都可以抽象成这样的的字符组合：Ax B Ax B Ax ..... （Ax表示有连续x个字符A）
 比如说BAABA就可以表示为 [A0,B,A2,B,A1]，容易知道最终A0是最小，那么结果就是0+2+1-0=3；
 
  
 
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
    string s;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int n = s.length();
            int cur = 0;
            vector<int> vec;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'B') {
                    vec.push_back(cur);
                    cur = 0;
                }
                else {
                    ++cur;
                }
            }
            if (cur != 0 || s[n - 1] == 'B') {
                vec.push_back(cur);
            }
            sort(vec.begin(), vec.end());
            int ans = 0;
            for (int i = 0; i < vec.size(); ++i) {
                ans += vec[i];
            }
            ans -= vec[0];
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
