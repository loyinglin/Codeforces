//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1684/problem/C)
 **题目大意：**
 给出n x m的矩阵a，a[i][j]是一个整数；
 现在需要选择任意两列进行交换，现在想知道是否存在一种交换方式，满足：
 交换之后，每一行的元素，从左到右都是非递减的；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤100)
 每个样例第一行是整数𝑛 and 𝑚 (1≤𝑛,𝑚≤2⋅1e5)
 接下来会有n行m列的整数 𝑎[𝑖,𝑗] (1≤𝑎[𝑖,𝑗]≤1e9)；
  
 **输出：**
 每个样例一行，输出满足的交换位置；（可以交换相同位置）
 如果无解则输出-1；
 
 **Examples**
 **input**
 5
 2 3
 1 2 3
 1 1 1
 2 2
 4 1
 2 3
 2 2
 2 1
 1 1
 2 3
 6 2 1
 5 4 3
 2 1
 1
 2
 
 **output**
 1 1
 -1
 1 2
 1 3
 1 1
 
 **题目解析：**
 先考虑一维的情况，给出一个数组，交换任意两个数字，然后将数组变成非递减；
 由于每次只能选择交换相同位置或者两个位置，也就是说要么影响2个数字，要么不影响，那么可以先计算一遍最长非递减的子序列得到长度k；
 根据k和n的区别，如果n-k>2，那么就是必然无解；
 但是由于k可以等于n、n-1、这几种情况是比较难以决策如何选择出来两个位置；
 考虑到只有一次交换（2个位置），那么假如将数组直接排序，是不是也可以通过这个来对比得到这个位置？
 假如排序之后，将有序数组和原数组对比，得到若干个不匹配的位置，如果不同数大于2则无解，如果不同数为2则就是交换的两个位置，如果不同数为0则不需要交换；（这里不存在不同数位1的情况）
 
 基于上面一维的分析，我们可以推导到二维数组的情况。
 当我们从上到下去遍历每一行元素时，当我们第一次找到存在2个位置不同的时候，我们就将这位置作为最终的交换位置；
 将整个矩阵相应列进行交换，最后判断结果是否符合要求。
 
 注意：如果某一行完全匹配（不同数为0），此时应该先忽略，去找不同位置为2的行；
 
 
 
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
    vector<int> a[N];
    vector<int> b[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < n; ++i) {
                a[i].clear();
                b[i].clear();
                for (int j = 0; j < m; ++j) {
                    int x;
                    scanf("%d", &x);
                    a[i].push_back(x);
                    b[i].push_back(x);
                }
            }
            vector<int> diff;
            bool ans = true;
            for (int i = 0; i < n; ++i) {
                sort(a[i].begin(), a[i].end());
                if (!diff.size()) {
                    for (int j = 0; j < m; ++j) {
                        if (a[i][j] != b[i][j]) {
                            diff.push_back(j);
                        }
                    }
                }
            }
            if (diff.size() > 2) {
                ans = false;
            }
            else if (!diff.size()){
                diff.push_back(0);
                diff.push_back(0);
            }
            else {
                for (int i = 0; i < n; ++i) {
                    int x = diff[0], y = diff[1];
                    int tmp = b[i][x];
                    b[i][x] = b[i][y];
                    b[i][y] = tmp;
                    for (int j = 0; j < m; ++j) {
                        if (a[i][j] != b[i][j]) {
                            ans = false;
                        }
                    }
                }
                
            }
            
            if (ans) {
                cout << diff[0] + 1 << " " << diff[1] + 1 << endl;
            }
            else {
                cout << (-1) << endl;
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

/**
 */
