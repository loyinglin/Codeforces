//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1818/problem/A)
 **题目大意：**
 有n个人参加投票，小明是第一个；
 投票一共k轮，每轮每个人会做出一个选择，分别用+和-表示，那么一共有三个结果：
 +的人数大于-的人数，那么-的人出局；
 -的人数大于+的人数，那么+的人出局；
 如果+和-的人数一样多，那么所有人出局；
 出局的人，不再参与后续投票。
 
 小明有特权，可以在第一轮投票之前淘汰掉若干个人，现在想知道，最终能有多少个人留到了最后；（小明一定保证自己会留到最后）
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例n+1行
 第一行，整数𝑛 和 𝑘 (1≤𝑛,𝑘≤100)
 接下来n行，每行有k个字符，表示每个人都投票结果。
 
  
 **输出：**
 输出留到最后的人数。
 
 
 **Examples**
 **input**
 5
 2 2
 ++
 +-
 1 3
 +-+
 4 1
 +
 -
 -
 +
 5 4
 ++++
 +--+
 ++-+
 +-++
 ++++
 4 2
 ++
 --
 --
 -+

 **output**
 1
 1
 2
 2
 1


 
 **题目解析：**
 由于题目不需要选择淘汰的顺序，并且小明一定会留在最后，那么和小明相同的投票结果的人会保留；
 
 
 
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
    char s[N], r[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            int ans = 1;
            cin >> s;
            for (int i = 1; i < n; ++i) {
                cin >> r;
                int tmp = 0;
                for (int j = 0; j < k; ++j) tmp += s[j] == r[j];
                ans += tmp == k;
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
 
