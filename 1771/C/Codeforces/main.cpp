//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1771/problem/C)
 **题目大意：**
 给出n个整数，询问是否存在两个整数，最大公约数不是1；
 如果存在则输出YES，如果不存在则输出NO；
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e5)；
 每个样例第一行整数  𝑛 (2≤𝑛≤1e5).
 接下来n个整数  𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9).
  
 **输出：**
 每个样例一行，输出是否满足要求。
 
 
 **Examples**
 **input**
 2
 3
 32 48 7
 3
 14 5 9
 **output**
 YES
 NO
 
 **题目解析：**
 先不考虑复杂度，最直接的做法，就是求出每个整数的因子，复杂度是O(M)，M是整数的大小的根，10^9需要遍历1w+次；
 然后用map管理每个整数的因子，遍历每一个整数求是否有相同的因子，整体复杂度在O(NM)左右，map的复杂度可以暂时忽略；
 总的复杂度会到达10^5 * 10^5 = 10^10量级，时间上是不允许的。
 
 分析这个里面的优化空间，每个整数的因子最终都可以拆分为若干素数，这样就可以大幅度减少因子数量；
 先预处理1-sqrt(10^9)的素数，再用这个素数去筛选n个整数，这样速度会更加快。
 
 trick：这个如果遇到两个相同数字，就会出现异常。
 另外在拆解的时候，一定要拆解数字到x = a * b * c这样的形式。
 
 
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
        int m = sqrt(1e9) + 1;
        vector<int> vec;
        
        for (int i = 2; i<= sqrt(m); ++i) {
            if (!a[i]) {
                int tmp = i;
                while (tmp <= m) {
                    tmp += i;
                    a[tmp] = 1;
                }
            }
        }
        for (int i = 2; i <= m; ++i) {
            if (!a[i]) {
                vec.push_back(i);
//                cout << i << " ";
            }
        }
        
        int t;
        cin >> t;
        while (t--) {
            int n;
            map<int, int> mp;
            cin >> n;
            bool ok = 0;
            for (int i = 0; i < n; ++i) {
                int k;
                cin >> k;
                vector<int> tmp;
                for (int j = 0; j < vec.size(); ++j) {
                    if (k % vec[j] == 0) {
                        tmp.push_back(vec[j]);
                        while (k % vec[j] == 0) k /= vec[j];
                    }
                }
                if (k != 1) {
                    tmp.push_back(k);
                }
                
                for (int j = 0; j < tmp.size(); ++j) {
                    if (mp[tmp[j]]) ok = 1;
                    mp[tmp[j]] = 1;
                }
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
