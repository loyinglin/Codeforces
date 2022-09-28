//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1661/problem/A)
 **题目大意：**
 给出n个整数的数组a和b，现在可以执行任意次下面的操作：
 选择索引x，交换数组a和b中的元素a[x]和b[x]；
 
 现在想知道|𝑎1−𝑎2|+|𝑎2−𝑎3|+⋯+|𝑎𝑛−1−𝑎𝑛| + |𝑏1−𝑏2|+|𝑏2−𝑏3|+⋯+|𝑏𝑛−1−𝑏𝑛|  的最小值是多少；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤4000)
 每个样例3行，第一行整数 𝑛 (2≤𝑛≤25)
 第二行n个整数 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1e9)
 第三行n个整数 𝑏1,𝑏2,…,𝑏𝑛 (1≤𝑏𝑖≤1e9)
 
 **输出：**
 每个样例一行，输出最小值；
 
 
 **Examples**
 **input**
 3
 4
 3 3 10 10
 10 10 3 3
 5
 1 2 3 4 5
 6 7 8 9 10
 6
 72 101 108 108 111 44
 10 87 111 114 108 100
 **output**
 0
 8
 218
 
 **题目解析：**
 假设有数字a1和a2，b1和b2；
 在一个一维数轴上，a1和b1就是两个点，并且我们可以让a1<b1；
 然后 |a1-a2|+|b1-b2| 其实就是在数轴上还有两个点a2和b2，也可以让a2<b2；
 题目的要求，就是求（a1到a2距离+b1到b2距离） 和 （a1到b2距离+b1到a2的距离）哪个距离和更小；
 可以知道，还是前者的距离更小，因为后者中的a1到b2距离 或者 b1到a2的距离，总会有一个距离很大；
  
 也可以用简单的思维来看：小的和小的比，大的和大的的比。
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
    int a[N], b[N];

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
            for (int i = 0; i < n; ++i) {
                cin >> b[i];
                if (a[i] > b[i]) {
                    swap(a[i], b[i]);
                }
            }
            lld sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += abs(a[i] - a[i + 1]);
                sum += abs(b[i] - b[i + 1]);
            }
            cout << sum << endl;
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
