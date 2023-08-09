//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1834/problem/A)
 **题目大意：**
 有长度为n的整数数组a，数组元素都由-1和1组成；
 现在每次可以选择一个数组位置，翻转位置上元素（-1变成1，1变成-1）；
 假如想要实现下面的要求，最少需要多少次操作：
 `𝑎1+𝑎2+…+𝑎𝑛≥0`
 `𝑎1⋅𝑎2⋅…⋅𝑎𝑛=1`
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤500)
 每个样例2行，
 第一行，整数n (1≤n≤ 100)
 第二行，n个整数；

 
 
 **输出：**
 每个样例一行，输出最小操作次数。
 
 **Examples**
 **input**
 7
 4
 -1 -1 1 -1
 5
 -1 -1 -1 1 1
 4
 -1 1 -1 1
 3
 -1 -1 -1
 5
 1 1 1 1 1
 1
 -1
 2
 -1 -1

 **output**
 1
 1
 0
 3
 0
 1
 2


 **题目解析：**
 我们用x来表示1的数量，y表示-1的数量；
 当x<y时，需要将一部分-1变成1，这个数量是ans=(y - x + 1) / 2；（因为每次变化，都会让x和y的值差2，所以最终要除以2）
 当y=y-ans后，假如y%2为1，证明最终结果还是为负数，此时需要再去掉一个-1，故而++ans；
 
 
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
            int n;
            cin >> n;
            int a = 0, b = 0;
            while (n--) {
                int tmp;
                cin >> tmp;
                if (tmp == 1) ++a;
                else ++b;
            }
            int ans = 0;
            if (a < b) {
                ans = (b - a + 1) / 2;
                a += ans;
                b -= ans;
            }
            if (b % 2) {
                ++ans;
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
 
