//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1823/problem/A)
 **题目大意：**
 有一个数组a，仅有整数1和-1组成，我们定义数组a的乘积为：
 对于 1≤𝑖<𝑗≤𝑛, 𝑎[𝑖]⋅𝑎[𝑗]=1的数量。
 
 现在给出数组长度n和乘积k，问是否可以构造一个满足要求的数组a；
 
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤20000)
 每个样例1行， n和𝑘，表示数组长度和乘积k （2≤𝑛≤100 ; 0≤𝑘≤(𝑛−1)*𝑛/2）
 
  
 **输出：**
 如果有解，则输出YES，然后第二行输出n个整数；
 如果无解，则输出NO；
 
 **Examples**
 **input**
 7
 2 0
 2 1
 3 1
 3 2
 3 3
 5 4
 5 5

 **output**
 YES
 1 -1
 YES
 1 1
 YES
 1 -1 1
 NO
 YES
 1 1 1
 YES
 -1 1 -1 1 1
 NO

 
 **题目解析：**
 题目给出的数据范围比较小，可以直接枚举；
 遍历数组存在0个、1个、2个、、、到n个1的情况，剩下用-1填充；
 然后再遍历整个数组，两两计算a[i]*a[j] = 1的数量；
 如果满足要求则输出；
 
 
 
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
            int n, k;
            cin >> n >> k;
            int ans = 0;
            for (int i = 0; i <= n; ++i) //第i个开始都是1，前面都是-1
            {
                int sum = 0;
                for (int x = 0; x < n; ++x) {
                    for (int y = x + 1; y < n; ++y) {
                        if ((x < i && y < i) || (x >= i && y >= i)) {
                            ++sum;
                        }
                    }
                }
                if (sum == k) {
                    ans = 1;
                    int tmp = 0;
                    cout << "YES" << endl;
                    while (tmp < i) {
                        cout << "-1" << " ";
                        ++tmp;
                    }
                    while (tmp < n) {
                        cout << "1" << " ";
                        ++tmp;
                    }
                    cout << endl;
                    break;
                }
            }
            if (!ans) cout << "NO" << endl;
            
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
