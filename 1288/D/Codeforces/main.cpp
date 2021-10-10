//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1288/problem/D)
 **题目大意：**
 有n个数组，每个数组有m个元素；
 对于两个数组可以进行一次合并，新的数组每个index的数字等于原来两个数组对应index 的较大值，比如：
 5 0 3 1 2
 1 8 9 1 3
=5 8 9 1 3
 现在从n个数组中选出2个数组，合并之后得到数组b，并且要求数组b的最小值，要尽可能的大；
 
 输入：
 第一行 𝑛 and 𝑚 (1≤𝑛≤3⋅1e5, 1≤𝑚≤8)
 接下来n行，每行有m个整数a[i][j]，(0≤𝑎[i][j]≤10^9)
 
 输出：
 一行，两个整数x，y，表示第x行和第y行；（x可以等于y）

 Example
 input
 6 5
 5 0 3 1 2
 1 8 9 1 3
 1 2 3 4 5
 9 1 0 3 7
 2 3 0 6 3
 6 4 1 7 0
 output
 1 5
 
 
 **题目解析：**
 题目的答案具有线性特征：假如最小值x满足要求，那么最小值x+1也满足。
 我们对最小值进行二分，先得到mid；
 每一行，大于mid的数字可以表示为1，小于mid的数字可以表示为0；
 那么数据可以转换为01矩阵：
 0 1 1 0 1
 0 1 1 1 1
 1 1 0 1 1
 ....
 由于m的取值较小，这里最多只有256个数字的可能性；
 for循环遍历也只需要256^2的复杂度，小于生成这个01矩阵的复杂度，那么check(mid)的代价仍是O(nm)；
 
 那么再乘以二分次数，总体复杂度就是O(logK N M )；
 
 
 
 
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
const int N = 301010, M = 256, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

class SolutionA {
    int a[N][8];
    int n, m;
    
    bool check(int mid, pair<int, int> &ans) {
        int index[M];
        for (int i = 0; i < M; ++i) {
            index[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                t <<= 1;
                if (a[i][j] >= mid) {
                    t++;
                }
            }
            index[t] = i;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = i; j < M; ++j) {
                if (index[i] == -1 || index[j] == -1) {
                    continue;
                }
                
                int k = i | j;
                if (k == ((1 << m) - 1)) {
                    ans.first = index[i];
                    ans.second = index[j];
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    void solve() {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        
        int l = 0, r = 1e9;
        pair<int, int> ans_index;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, ans_index)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        cout << ans_index.first + 1 << " " << ans_index.second + 1 << endl;
        
    }
    
}binary_ans;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    binary_ans.solve();
           
    
    return 0;
}


/**
 6 4
 3 0 0 3
 0 3 3 1
 0 1 1 1
 1 1 0 1
 2 2 2 2
 1 1 1 1
 */
