//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1761/problem/B)
 **题目大意：**
 有n个整数的数组，这些数字形成一个环，其中第1个和第n个相连；
 初始化的时候，没有任何两个相邻数字相同，现在小明可以执行一个操作：
 从数组中选择一个位置并移除该元素，剩下的元素继续形成一个环，如果有两个相邻元素的数字相同，则会随机消除其中一个数字，继续形成新的环；
 以数组[1,2,4,2,3,2]为例，假如移除数字4，则形成环[1,2,2,3,2]；由于[2,2]相邻数字相同，会随机消除一个数字，则形成环[1,2,3,2]；
 问，小明最多执行多少次操作。
 
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤100)
 每个样例第一行 整数 𝑛  (1≤𝑛≤100)
 第二行是整数𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛)
  
 **输出：**
 每个样例一行，输出小明最大的操作次数。
 
 
 **Examples**
 **input**
 3
 4
 1 2 3 2
 4
 1 2 1 2
 1
 1
 **output**
 4
 3
 1
 
 
 **题目解析：**
 题目咋一看会比较难处理，尤其是消除数字之后形成新的环，每次可以选择的数字比较多；
 那先简化下题目，将题目的给出数字抽象成1、2、3；（即使给出的是1、4、9，我们用1、2、3来替代也等价）
 当只有1个数字时，结果是1；
 有2个数字时，由于没有相邻元素相同，给出的数字必须是1、2、1、2、1、2，这样的形式，结果一定是n/2+1；
 有3个数字时，我们以3为准，比较容易找出1、2、3或者2、1、3或者3、2、1等的序列，比如说数字32121321，我们只要看着3去消除右边的数字，肯定不会产生新的相邻相同元素；并且我们要保证数组中遗留3个元素，最终肯定可以完整消除，结果是n；
 有4个数字时，类似3；
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            map<int, int> h;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                h[a[i]] = 1;
            }
            if (h.size() == 1) cout << 1 << endl;
            else if (h.size() > 2) cout << n << endl;
            else cout << n / 2 + 1 << endl;
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
