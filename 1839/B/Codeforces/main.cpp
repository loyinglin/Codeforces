//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1839/problem/B)
 **题目大意：**
 有n个灯，编号分别为1到n，每个灯有两个参数a[i]和b[i]；
 初始状态，n个灯都是关闭的状态，接下来可以进行若干个操作：
 选择一个关闭状态的灯i，将其打开，得到分数b[i];
 在这个操作之后，假设亮着的灯有x盏，那么所有a[i] <= x的灯，都会坏掉；（不管是打开，还是关闭的状态）
 
 假设可以任意选择开灯的顺序，问最多能得到多少分。
 
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 接下来n行，每行有整数a𝑖 and b𝑖 (1≤a𝑖,b𝑖≤𝑛 )
   
 **输出：**
 对于每个样例，输出最大的得分数；
 
 **Examples**
 **input**
 4
 4
 2 2
 1 6
 1 10
 1 13
 5
 3 4
 3 1
 2 5
 3 2
 3 3
 6
 1 2
 3 4
 1 4
 3 4
 3 5
 2 3
 1
 1 1
 
 **output**
 15
 14
 20
 1

 
 
 **题目解析：**
 题目的意思比较难理解，“假设亮着的灯有x盏，那么所有a[i] <= x的灯，都会坏掉“的解释是：
 假设点亮1盏灯，那么a[i] <= 1的灯会坏掉；
 假设点亮2盏灯，那么a[i] <= 2的灯会坏掉；
 也就是说，a[i]越小，灯就越容易坏。
 
 那么可以知道，我们必然会先选择a[i] = 1的灯去打开，并且有且只有一盏a[i]=1的灯能够打开；
 同理a[i]=2的灯，最多能打开2盏；
a[i]=3的灯，最多能打开3盏；
 ...
 这样就可以知道，a[i]=x的灯，有x盏能打开。
 
 结果就是排序，先按照a[i]从小到大，再按b[i]从大到小即可。
 实现逻辑可以用map来降低复杂度。
  
 
 
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
    pair<int, int> g[N];
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
                cin >> g[i].first >> g[i].second;
            }
            sort(g, g + n, cmp);
            lld ans = 0;
            map<int, int> vis;
            for (int i = 0; i < n; ++i) {
                if (vis[g[i].first] < g[i].first) {
                    ++vis[g[i].first];
                    ans += g[i].second;
                }
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
 
