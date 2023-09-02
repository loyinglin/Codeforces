//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1847/problem/C)
 **题目大意：**
 给出n个整数数组a，现在可以进行操作：
 选择数组中某个位置k，将a[k]以及之后的数字进行异或操作，将生成的数字放在第k+1位（原来位置k后面的数字被移除）；
 
 现在可以进行任意次上述操作，想知道在这个操作过程中，生成的数字最大为多少。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例两行
 第一行整数𝑛 (1≤𝑛≤1e5).
 第二行整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤2^8)
 
 **输出：**
 每个样例一行，输出最大的生成数字。
 
 **Examples**
 **input**
 3
 4
 0 2 5 1
 3
 1 2 3
 5
 8 2 4 12 1


 **output**
 7
 3
 14




 **题目解析：**
 n=1时，只有一个值a[1];
 n=2时，除了a[1~2]，新增是a[1]&a[2];
 n=3时，除了a[1~3]，新增是a[3]&a[2]（选择2和3合并），a[1]&a[2]（先选择位置3生成a[4]=a[3]，这样抵消a[3]，再选择位置1生成a[1]&a[2]&a[3]&a[4]=a[1]&a[2])，a[1]&a[2]&a[3]（选择位置1）;
 从末尾开始分析可以得知，每个末尾的数字有两种选择，要么加入前面的合成，要么复制一次然后被抵消；
 
 题目给出的a[i]的范围很小，可以由此来降低复杂度，我们用dp[i][j]表示第i个整数往后，拼出结果数字为j的可能性，dp[i][j]=1表示有解，dp[i][j]=0表示无解；
 这样从最后面往前dp就可以得到所有可能出现数字。
 
   
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
    static const int N = 202010;
    static const int M = 260;
    static const int inf = 0x7fffffff;
    int a[N];
    int dp[N][M];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            for (int i = 0; i < n+1; ++i)
            for (int j = 0; j < M; ++j) dp[i][j] = 0;
            int ans = 0;
            for (int i = n - 1; i >= 0; --i) {
                dp[i+1][0] = 1;
                for (int j = 0; j < M; ++j) {
                    if (dp[i + 1][j]) {
                        dp[i][j ^ a[i]] = 1;
                        ans = max(ans, j ^ a[i]);
                    }
                }
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
 
