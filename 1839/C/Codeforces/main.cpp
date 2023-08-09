//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1839/problem/C)
 **题目大意：**
 有整数数组，初始为空数组，接下来执行n次操作：
 第i次操作，可以选择整数数组b中的0到i-1，其中一个位置p；在位置p后面增加一个整数0，然后对这个位置p之前的数组b元素执行revert操作（原来0，则会变成1；原来1，则会变成0）
 
 现在知道最终操作完的整数数组结果，我们用数组a表示；
 求这n次操作中，每一次操作组成的整数素组；
 
 比如说，已知最终整数数组为[0, 1, 0]；
 那么我们第1次可以选择0，得到[0];
 第2次可以选择1，得到[1，0]；
 第2次可以选择0，得到[0，1，0]；
 这样操作结果组成的整数数组就是[0, 1, 0]；
 
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 第二行，每行有整数a𝑖  (1≤a𝑖≤𝑛 )
   
 **输出：**
 对于每个样例，如果无解，输出NO；
 如果有解，先输出YES；
 接下来一行，输出n个整数，表示n次操作的结果；（第i个元素表示第i次操作）
 
 **Examples**
 **input**
 4
 5
 1 1 0 0 0
 1
 1
 3
 0 1 1
 6
 1 0 0 1 1 0

 
 **output**
 YES
 0 0 2 1 3
 NO
 NO
 YES
 0 1 0 2 4 2
 

 **题目解析：**
 根据题目的限制，第i次的选择区间是[0, i-1]，那么：
 第1次，选择区间是[0, 0];
 第2次，选择区间是[0, 1];
 第3次，选择区间是[0, 2];
 第4次，选择区间是[0, 3];
 ...
 可以发现，不管如何选择，数组的最后一个元素必然是0，如果为1就无解；
 插入整数是0，假设插入的是第0位，那么就是添加元素0；
 对于都是0的数组，假设插入的是第x位，那么就是前面x个整数变成1；
 接下来就比较简单，对于数组[1, 1, 0]，可以用[2, 0, 0]操作结果来表示；
 对于整数[0, 1，1, 0]，可以拆分为[0] + [1，1，0】，那就可以用[0，2，0，0]的操作来表示；
  
 总结来说，就是关注1的部分，将相邻的1合并在一起；假设有x个1在一起，那么就在某个时机选择位置x来生成x个连续的1。
 
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
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            if (a[n - 1]) cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                int pos = 0;
                while (pos < n) {
                    if (!a[pos]) ++pos;
                    int cnt = 0;
                    int tmp = pos;
                    while (a[pos] == 1) {
                        a[pos] = 0;
                        ++pos;
                        ++cnt;
                    }
                    a[tmp] = cnt;
                }
                for (int i = n - 1; i >= 0; --i) cout << a[i] << " ";
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
 
