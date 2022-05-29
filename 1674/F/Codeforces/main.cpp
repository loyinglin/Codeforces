//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1674/problem/F)
 **题目大意：**
 给出一个n x m的矩阵，由'.'和'*'组成；
 现在想把矩阵内的星号全部调整到前面，比如说：
 .*.
 .**
 .**
 调整为
 **.
 **.
 *..
 先填充第1列，然后再填充第2列，以此类推，填充顺序为从上到下；
 每次移动可以选择一个'*'移动到任意为'.'的位置；
 
 现在有q次操作，每次会输入2个位置x和y，会把对应位置的元素修改为另外一个符号；
 现在想知道每次操作之后，最少需要的移动次数；（每次操作的结果保留在矩阵中）
 
 
  **输入：**
 第一行，整数 𝑛, 𝑚 and 𝑞 (1≤𝑛,𝑚≤1000;1≤𝑞≤2⋅1e5)
 接下q行，每行2个整数 𝑥𝑖 and 𝑦𝑖 (1≤𝑥𝑖≤𝑛;1≤𝑦𝑖≤𝑚)
  
 **输出：**
 输出q行，每行是操作后的最少移动次数；
 
 
 **Examples**
 **input**
 4 4 8
 ..**
 .*..
 *...
 ...*
 1 3
 2 3
 3 1
 2 3
 3 4
 4 3
 2 3
 2 2
 **output**
 3
 4
 4
 3
 4
 5
 5
 5

 
 **题目解析：**
 按照题目的要求，假设矩阵中有sum个星号，容易知道最终排成的元素会集中在j=(sum-1)/n列和i=(sum-1)%m行中；
 并且我们得到一个快速计算移动次数的方法，假如前j列，前i行中一共有ans个星号，那么最少移动次数就是sum-ans；
 
 容易知道q次操作中，每次操作之后影响str[x][y]这个位置，并且会导致sum变化，从而导致ans变化；
 但是由于每次操作只能修改1个字符，我们只需判断下sum变化之前，最后一个位置是否为星号，就可以快速计算得到ans；
 这样每次操作之后，计算sum和ans的复杂度只需要O(1)；
 
 注意，每次操作之后，有两种可能会影响ans：
 1、操作的字符就在最终排列的结果里面；
 2、影响sum之后，sum关联到的对应的最后一个位置；
 
 
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
    vector<string> str;
    
  
public:
    void solve() {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i < n; ++i) {
            string tmp;
            cin >> tmp;
            str.push_back(tmp);
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (str[i][j] == '*') {
                    ++sum;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j * n + i < sum) {
                    if (str[i][j] == '*') {
                        ++ans;
                    }
                }
                else {
                    break;
                }
            }
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            if (str[x][y] == '*') {
                str[x][y] = '.';
                if (y * n + x < sum) {
                    --ans;
                }
                int j = (sum - 1) / n, i = (sum -  1) % n;
                if ((i != x || j != y) && str[i][j] == '*') {
                    --ans;
                }
                --sum;
            }
            else {
                str[x][y] = '*';
                ++sum;
                if (y * n + x < sum) {
                    ++ans;
                }
                int j = (sum - 1) / n, i = (sum -  1) % n;
                if ((i != x || j != y) && str[i][j] == '*') {
                    ++ans;
                }
            }
//            for (int i = 0; i < n; ++i) {
//                cout << str[i] << endl;
//            }
            cout << sum - ans << endl;
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
 4 4 111
 ..**
 .*..
 *...
 ...*
 */
