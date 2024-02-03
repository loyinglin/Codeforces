//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1916/problem/C)
 **题目大意：**
 有n个整数的数组a，现在有Alice和Bob两个人玩游戏，Alice先手。
 游戏规则如下：
 1、数组中只有一个元素时结束游戏，当前数字为最终结果；
 2、每次可以选择数组2个整数，移除对应整数；然后将整数相加再除以2，向下取整，再乘以2，最终将数字重新加回去数组；（比如说[1,3]=4, [2,3]=4)
 
 Alice的目标是让结果尽可能大，Bob的目标是让结果尽可能小。
 现在想知道，当只有数组前k个数字参与游戏时（𝑘=1,2,…,𝑛），最终的游戏结果是什么。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，整数𝑛(1≤𝑛≤1e5)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e9)
  
 **输出：**
 每个样例一行，共n个整数；第k个数字，表示只有前k个数字参与游戏时，最终的结果。
 
 **Examples**
 **input**
 4
 1
 31
 6
 6 3 7 2 5 4
 3
 3 10 11
 5
 7 13 11 19 1

 
 **output**
 31
 6 8 16 18 22 26
 3 12 24
 7 20 30 48 50


 **题目解析：**
 先不考虑k的取值情况，只看整个数组都参与游戏。
 数组中的数字，我们可以分为奇数和偶数，已知偶数+偶数、奇数+奇数的操作只会合并数字，不会有任何变化。只有奇偶数相加，此时最终结果会-1。
 这样， 我们假设有x个奇数；
 先手每次优先消耗2个奇数，产出1个偶数；
 后手每次优先消耗1个奇数+1个偶数，产出1个偶数；（偶数必然存在，因为先手会产出偶数）
 这样我们就可以得到一个策略：
 n=1，ans=sum（用sum来表示前n项和）
 n=2，ans=sum
 n=3=2+1，ans=sum-1
 n=4=2+1 +1, ans=sum-2
 n=5=2+1 +2, ans=sum-1
 n=6=2+1 + 2+1, ans=sum-2
 n=7=2+1 + 2+1 +1, ans=sum-3
 ...
 依次类推，我们知道3个奇数是一个循环，最终ans= sum - (n + 2) / 3 + ((n + 1) % 3 == 0)
 
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
            vector<lld> ans;
            lld sum = 0, cnt = 0;;
            for (int i = 0; i < n; ++i) {
                int k;
                cin >> k;
                sum += k;
                if (k % 2) ++cnt;
                if (i == 0) ans.push_back(sum);
                else {
                    ans.push_back(sum - (cnt + 2) / 3 + ((cnt + 1) % 3 == 0));
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << " ";
            }
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
 
