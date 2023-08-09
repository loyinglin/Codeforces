//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1838/problem/C)
 **题目大意：**
 将1、2、3、、、、n x m个整数，填入到n x m的网格中；
 要求任何两个相邻的格子，格子上数字差的绝对值不是素数。
 现在求其中一个填充结果。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行，整数𝑛, m (4≤𝑛, m≤1000)
 
 
 **输出：**
 每个样例输出n行，每行m个整数；（题目保证有解）
 
 
 **Examples**
 **input**
 3
 4 4
 5 7
 6 4

 **output**
 16  7  1  9
 12  8  2  3
 13  4 10 11
 14  5  6 15

 29 23 17  9  5  6  2
 33 27 21 15 11  7  1
 32 31 25 19 20 16 10
 26 30 24 18 14  8  4
 35 34 28 22 13 12  3

  2  3  7 11
  8  9  1 10
 17 13  5  4
 18 14  6 12
 19 23 15 21
 20 24 16 22

 **题目解析：**
 当n/m偶数时，从左到右，从上到小填写即可。例如n=4：
 1      2       3       4
 5      6       7       8
 9      10     11    12
 13    14     15    16
 ...
 
 每个数字和左右相邻都是1，上下相邻是2的倍数。
 
 当n/m是奇数时，比如说k=2时，n=(2k + 1)=5；
 如果还是采用原来解决方案，1和6的差距就是n=5，此时两数之差是质数；
 1      2       3       4       5
 6      7       8       9       10
11      12     13     14     15
 ....
 但是知道，1和11的差是2 * n，不是质数；
 那么这个整数矩阵可以做一些简化，只考虑每行第一个整数：
 1
 n + 1
 2n + 1
 3n + 1
 4n + 1
 ...
 
 做一些调整
 1
 2n + 1
 4n + 1
 n + 1
 3n + 1
 ...
 
 这样上下整数的差就变成2n、2n、3n、2n，都是n的倍数，也即是都是合数。（注意，至少n>4才能用着这种方式）

 
 
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
    static const int N = 1010;
    int a[N][N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            if (n % 2 == 0) {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j)
                        a[i][j] = (j - 1) * n + i;
            }
            else {
                for (int i = 1; i <= (n + 1)/2; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        a[i][j] = (i - 1) * 2 * m + j;
                    }
                }
                
                for (int i = 1; i <= n/2; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        a[i + (n+1)/2][j] = (i - 1) * 2 * m + j + m;
                    }
                }
            }
            
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j){
                    cout << a[i][j] << " ";
                }
                cout << endl;
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
 
