//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1821/problem/C)
 **题目大意：**
 给出一个小写字母组成的字符串s，现在可以对字符串进行多次操作：
 选择若干个不相邻的位置，移除这些位置上的字符，剩下的字符保持相对顺序组成新的字符串s；
 
 假如操作若干次后，剩下的字符串都由相同字符组成，最少需要多少次；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，字符串s；（长度不超过200,000）
 
  
 **输出：**
 每个样例一行，输出最少的次数。
 
 **Examples**
 **input**
 5
 abacaba
 codeforces
 oooooooo
 abcdef
 mewheniseearulhiiarul
 
 **output**
 1
 3
 0
 2
 4


 12345678
 
 **题目解析：**
 先简化题目，按照题目去掉若干个字符：
 去掉字符长度为2，需要2个操作；
 去掉字符长度为3，需要2个操作；
 去掉字符长度为4，需要3个操作；
 去掉字符长度为7，需要3个操作；
 去掉字符长度为8，需要4个操作；
 ...
 去除的规则比较简单，每次去除所有奇数位置，就可以最快去除；
  
 题目的要求，最后只剩一种字符，那么结果一共有26种组合。
 以字符a为例，遍历一遍字符串，那么就可以得到若干个由a分隔的区间，其中最长的区间假设是x，那么这个区间的移除代价就是最终的移除代价；
 同理得到26个字母的结果，取其最小得到结果。
 
 
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
    char s[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> s;
            int n = strlen(s);
            int ans = n;
            for (int i = 0; i < 26; ++i) {
                char c = 'a' + i;
                int len = 0, last = -1;
                for (int j = 0; j < n; ++j) {
                    if (s[j] == c) {
                        last = j;
                    }
                    else {
                        len = max(len, j - last);
                    }
                }
                if (len == 0) {
                    ans = 0;
                    break;
                }
                int tmp = 1;
                while ((1 << tmp) <= len) ++tmp;
                ans = min(ans, tmp);
            }
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
 
