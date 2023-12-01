//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1890/problem/B)
 **题目大意：**
 有两个0、1组成的字符串s和t，长度分别为n和m；
 如果字符串a满足
 对所有的 all 𝑖=1,2,…,𝑘−1 ，有 𝑎𝑖≠𝑎𝑖+1，则可以认为字符串a是good；
 
 现在允许在字符串s中任意位置插入若干次字符串t，问最终能否生成一个good的字符串；
 
  
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例3行
 第1行整数𝑛 and 𝑚 (1≤𝑛,𝑚≤50 )
 第2、3行分别是字符串s和t
  
 **输出：**
 每个样例一行，如果可以生成good字符串，则输出YES；否则输出NO；
 
 **Examples**
 **input**
 5
 1 1
 1
 0
 3 3
 111
 010
 3 2
 111
 00
 6 7
 101100
 1010101
 10 2
 1001001000
 10


 **output**
 Yes
 Yes
 No
 No
 No


 **题目解析：**
 按照题目要求，good字符串就是字符0和1交替的字符串，比如说10101或者0101；
 那么字符串中如果存在00或者11，就表示不满足要求；
 
 由于题目可以插入字符串t，那么首先对字符串t做同样的检查，要求不含有00和11；
 字符串t要插入到字符串s中，且只会插入到00和11，那么必然字符串首尾必然相同，要么都是0、要么都是1；
 
 字符串s如果仅存在00或者11，那么可以考虑插入符合要求的字符串t；
 00只会插入首尾都是1的good字符串t；
 11只会插入首尾都是0的good字符串t；
 
 
 
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            string s, t;
            cin >> s >> t;
            int flag[2] = {0};
            for (int i = 1; i < n; ++i) {
                if (s[i] == s[i - 1]) flag[s[i] - '0'] = 1;
            }
            int ans = 0;
            if (flag[0] + flag[1] == 0) ans = 1;
            else if (flag[0] + flag[1] == 2) ans = 0;
            else {
                int sec[2] = {0};
                for (int i = 1; i < m; ++i) if (t[i] == t[i - 1]) sec[t[i] - '0'] = 1;
                if (sec[0] + sec[1] == 0 && t[0] == t[m - 1] && (flag[t[0] - '0']== 0)) {
                    // 不含00和11，并且头尾相同，并且互补
                    ans = 1;
                }
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
 

/**
 
 
 0101
 1
 
 110
 
 111
 0
 
 
 2000
 1 1
 0
 0
 1 1
 0
 1
 1 1
 1
 0
 1 1
 1
 1
 1 2
 0
 00
 1 2
 0
 10
 1 2
 0
 01
 1 2
 0
 11
 1 2
 1
 00
 1 2
 1
 10
 1 2
 1
 01
 1 2
 1
 11
 2 1
 00
 0
 2 1
 00
 1
 2 1
 10
 0
 2 1
 10
 1
 2 1
 01
 0
 2 1
 01
 1
 2 1
 11
 0
 2 1
 11
 1
 2 2
 00
 00
 2 2
 00
 10
 2 2
 00
 01
 2 2
 00
 11
 2 2
 10
 00
 2 2
 10
 10
 2 2
 10
 01
 2 2
 10
 11
 2 2
 01
 00
 2 2
 01
 10
 2 2
 01
 01
 2 2
 01
 11
 2 2
 11
 00
 2 2
 11
 10
 2 2
 11
 01
 2 2
 11
 11
 3 1
 000
 0
 3 1
 000
 1
 3 1
 100
 0
 3 1
 100
 1
 */
