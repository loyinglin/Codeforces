//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1883/problem/C)
 **题目大意：**
 有n个整数的数组a，再给出整数k；
 现在可以进行任意次以下操作：
 选择某个数组元素，将该元素+1；
 
 现在要求数组最终的乘积，能够整除数字k，问最少需要操作多少次；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，𝑛  and 𝑘  (2≤𝑛≤1e5 , 2≤𝑘≤5 )
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤10).
  
 **输出：**
 每个样例一行，输出最小的操作次数。
 
 **Examples**
 **input**
 15
 2 5
 7 3
 3 3
 7 4 1
 5 2
 9 7 7 3 9
 5 5
 5 4 1 2 3
 7 4
 9 5 1 5 9 5 1
 3 4
 6 3 6
 3 4
 6 1 5
 3 4
 1 5 9
 4 4
 1 4 1 1
 3 4
 3 5 3
 4 5
 8 9 9 3
 2 5
 1 6
 2 5
 10 10
 4 5
 1 6 1 1
 2 5
 7 7
 **output**
 2
 2
 1
 0
 2
 0
 1
 2
 0
 1
 1
 4
 0
 4
 3



 **题目解析：**
 第一反应，是将k进行因数分解，然后将数字分配到对应因数，还要考虑一个数字对应多个因数的情况（比如说a1=25，可以对应到两个因数5）；
 这样题目整体处理会比较麻烦。
 考虑到k的数据范围很小，因数情况也只有4=2x2的可能，可以不使用这种方法来处理。
 
 假如k=2时，如果数组a存在偶数，则ans=0，否则ans=1；
 假如k=3时，判断每个数组元素与3的余数即可，如果有能整除，则ans=0，否则为ans=3-最大余数；
 假如k=4时，按照2的因数来算，比如说4就算2个，如果数组中存在2个，那么ans=0；如果数组中存在1个，那么ans=1（因为必然还有一个奇数，这个奇数可以+1得到偶数）；如果数组中存在0个，那么ans=2（因为有两个数字，必定是2个奇数）；（同时也可以按照k=3的做法，计算下如果累加每个数字的情况，取较小者）
 假如k=5时，可以按照k=3的做法来；
 
 
 
 
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
            int n, k;
            cin >> n >> k;
            int ans = 0, cnt = 0;
            while (n--) {
                int tmp;
                cin >> tmp;
                if (tmp % k) ans = max(ans, tmp % k);
                else ans = k;
                while (tmp % 2 == 0) {
                    ++cnt;
                    tmp /= 2;
                }
            }
            if (k == 4) {
                if (cnt >= 2) cout << 0 << endl;
                else cout << min(k - ans, 2 - cnt) << endl;
            }
            else {
                cout << (k - ans) << endl;
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
 
