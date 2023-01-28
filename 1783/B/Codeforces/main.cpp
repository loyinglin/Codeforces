//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1783/problem/B)
 **题目大意：**
 给出整数n，构造一个n x n的整数矩阵，要求：
 1、数字是由1、2、3到n^2的整数组成；
 2、相邻整数的绝对值差，能形成尽可能多的数字。
 
 **输入：**
 第一行，整数𝑡 表示t个样例  𝑡(1≤𝑡≤49)
 每个样例1行，整数𝑛(2≤𝑛≤50)
  
  
 **输出：**
 每个样例n行，每行n个整数；
  
 
 **Examples**
 **input**
 2
 2
 3

 **output**
 1 3
 4 2
 1 3 4
 9 2 7
 5 8 6

 样例解释：
 对于n=2，矩阵中相邻整数的差有： |1−3|=2 , |1−4|=3 , |3−2|=1 和 |4−2|=2，一共有3个整数（1、2、3）；
 

 
 **题目解析：**
 有题目的要求1可以知道，矩阵中差的绝对值，最大值为n^2 - 1，最小值为1，那么不同数最多可能有：1、2、3、、、n^2-1；
 那么如何构造一个最大值？首先1放在左上角的位置，然后1的下面和右面放n^2和 n^2-1，这样就构造了两个较大的数字；
 同理接下来就可以放再较小的整数。
 以整数n=4为例
 1 0 0 0
 0 0 0 0
 0 0 0 0
 0 0 0 0
 接着
 1  15  0   0
 16 0   0   0
 0   0   0   0
 0   0   0   0
 然后是
 1  15  4   0
 16 3   0   0
 2   0   0   0
 0   0   0   0
 最终就是大小交替的效果。
 1  15  4   11
 16 3   12  7
 2  13   6   9
 14  5   10  8
 
 
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
    static const int N = 101;
    int a[N][N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int x = 1, y = n * n;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    for (int j = 0; i - j >= 0; ++j) { // a[i][0]
                        a[i - j][j] = x++;
                    }
                }
                else {
                    for (int j = 0; i - j >= 0; ++j) { // a[i][0]
                        a[i - j][j] = y--;
                    }
                }
            }
            for (int j = 1; j < n; ++j) {
                if ((n + j - 1) % 2 == 0) {
                    for (int i = n - 1; i - j >= 0; --i) { // a[n - i][j]
                        a[i][j + n - 1 - i] = x++;
                    }
                }
                else {
                    for (int i = n - 1; i - j >= 0; --i) { // a[n - i][j]
                        a[i][j + n - 1 - i] = y--;
                    }
                }
            }
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) cout << a[i][j] << " ";
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
 
