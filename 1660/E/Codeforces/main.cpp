//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/E)
 **题目大意：**
 给出一个n x n的矩阵，矩阵由数字0和1组成；
 现在可以对矩阵进行下列操作：
 1、将数组的每一行向上移动；
 2、将数组的每一行向下移动；
 2、将数组的每一列向左移动；
 2、将数组的每一列向右移动；
 这个操作是没有代价的，可以进行任意次；
 然后还可以对矩阵中任何一个数字进行异或（XOR）操作，这个操作的代价是1；
 
 现在想要把整个矩阵变成单元矩阵，问最小的代价是多少；
 （单元矩阵是一个对角线为非零元素，其它元素为零的方形矩阵）
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1e4)
 每个样例两行，第一行是整数𝑛  (1≤𝑛≤2000)
 接下来是n x n的01矩阵；
 
 **输出：**
 每个样例一行，输出最小的代价。

 
 **Examples**
 **input**
 4

 3
 010
 011
 100

 5
 00010
 00001
 10000
 01000
 00100

 2
 10
 10

 4
 1111
 1011
 1111
 1111
 **output**
 1
 0
 2
 11
 
 **题目解析：**
 题目的要求是构造单元矩阵的代价最小，那么需要尽可能利用无代价的4个位移操作；
 以简单的3阶矩阵来分析，对于矩阵
 010
 001
 010
 我们可以拼接4个矩阵，得到
 010 010
 001 001
 010 010
 ----------
 010 010
 001 001
 010 010

 以左移一列为例，结果就是图中左上角的2-4列，如下：
 0 100
 0 010
 0 100
 
 按照这个思路，其实就是在4个n x n矩阵拼出来的大矩阵中，找到一个n x n子矩阵，并且斜对角线的1尽可能多；
 那么就直接从每一行的第一列开始向右下角遍历，保持长度为n的斜对角线，存在尽可能多的1；
 但是直接拼接4个矩阵去模拟，整体实现复杂度比较高；对于第i行第j列的元素a[i][j]，右下角其实就是a[i+1][j+1]，其中：
 j是从1到n，因为每行的遍历都是从最左开始；
 i可能会存在大于n的情况，此时可以对n取模，保证数组不越界；
 
 假设对角线上最多的1数量为maxSize，矩阵中所有1的数量是totalSize；
 那么答案就是ans=(total - maxSize) + (n - maxSize) 
 
 
 
 
 **思考🤔：**

 
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
    static const int N = 3010;
    char a[N][N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            
            for (int i = 1; i <= n; ++i) {
                cin >> (a[i] + 1);
            }
            
            int total = 0, maxSize = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    total += ('1' == a[i][j]);
                }
                // 从a[i][1]开始，向右下角遍历
                int tmpSize = 0;
                for (int k = 0; k < n; ++k) {
                    int x = (i - 1 + k) % n + 1;
                    int y = 1 + k;
//                    cout << x << " " << y << endl;
                    if (a[x][y] == '1') {
                        ++tmpSize;
                    }
                }
                maxSize = max(maxSize, tmpSize);
            }
            cout << (total - maxSize) + (n - maxSize) << endl;
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
 */
