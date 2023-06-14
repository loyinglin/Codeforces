//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1820/problem/B)
 **题目大意：**
 给出一个0/1字符组成的字符串，现在按照以下规则进行排序：
 1、将字符串str作为矩阵第一行；
 2、将字符串str所有字符右移1位（最后一位字符会移动到最左边的位置），将这个字符当做下一行；
 重复以上规则，直到得到一个正方形矩阵。
 以“101”字符串为例：
 第一行是101；
 第二行是110；
 第三行是011；
 
 问得到的正方形矩阵中，由1组成的连续字符矩阵最大面积是多少。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤2⋅1e4 )
 每个样例1行，字符串𝑠 (1≤|𝑠|≤2⋅1e5),
 
  
 **输出：**
 每个样例一行，输出最大的面积，如果不存在则输出0；
 
 **Examples**
 **input**
 5
 0
 1
 101
 011110
 101010

 **output**
 0
 1
 2
 6
 1

 
 **题目解析：**
 由于字符串长度很大，暴力枚举计算的空间复杂度太高；
 分析题目给出的构造规则，我们发现0会形成一条斜线，将矩形分割开来；
 
 参考题目样例4，我们可以知道最终矩阵：
 0    0    1    1    1    1    0
 1    0    0    1    1    1    1
 1    1    0    0    1    1    1
 1    1    1    0    0    1    1
 1    1    1    1    0    0    1
 0    1    1    1    1    0    0
 存在一个长为4，等边三角形；
 
 同理，这样的字符串，一样在矩阵中存在长为4的等边三角形。
 1    1    1    1    0    0    0
 0    1    1    1    1    0    0
 0    0    1    1    1    1    0
 0    0    0    1    1    1    1
 1    0    0    0    1    1    1
 1    1    0    0    0    1    1
 
 
 极端的情况，连续的1拆分在两边
 1    1    0    0    0    1    1
 1    1    1    0    0    0    1
 1    1    1    1    0    0    0
 0    1    1    1    1    0    0
 0    0    1    1    1    1    0
 0    0    0    1    1    1    1
 1    0    0    0    1    1    1


 1     1    1    0    0    0    1
 1     1    1    1    0    0    0
 0     1    1    1    1    0    0
 0     0    1    1    1    1    0
 0     0    0    1    1    1    1
 1     0    0    0    1    1    1
 1     1    0    0    0    1    1
 
 可以得到一个规律，我们根据字符串中“连续”1的数量，就可以得到等边三角形的数量。
 这个连续1的计算方式，可以用下面的规则：
 将字符串1100011，复制一遍粘到末尾 1100011+1100011 = 11000111100011
 这样去计算一遍连续的最长字符串即可。
 
 注意：
 1、如果全为1，答案为n * n；
 2、如果全为0，答案为0；
 3、结果有可能超int32，需要用long long。
 
 
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
    static const int N = 401010;
    char s[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int n = strlen(s);
            for (int i = 1; i < n; ++i) {
                s[n + i - 1] = s[i - 1]; // 拼接
            }
            s[n * 2 - 1] = '0';
            int cur = 0, zero = 0, len = 0;
            for (int i = 0; i < 2 * n; ++i) {
                if (s[i] == '0') {
                    len = max(len, cur);
                    cur = 0;
                }
                else {
                    ++cur;
                }
            }
            for (int i = 0; i < n; ++i) zero |= (s[i] == '0');
            if (!zero) cout << n * 1LL * n << endl;
            else {
                if (len <= 2) cout << len << endl;
                else if (len % 2) cout << (len + 1) / 2LL * (len + 1) / 2 << endl;
                else cout << len / 2LL * (len + 2) / 2 << endl;
            }
            
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
