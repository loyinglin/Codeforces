//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1778/problem/A)
 **题目大意：**
 有n个整数的数组a，数组元素由1和-1组成；
 现在可以对数组中的元素进行操作（最后一个元素无法操作），将这个元素与右边元素进行符号反转；
 比如说数组[1, -1, -1]，如果我们选择[1, -1]进行符号反转，则得到[-1, 1, -1]；如果我们选择[-1, -1]进行符号反转，则可以得到[1, 1, 1]；
 这个操作必须执行一次，问操作完数组最大的和是多少。（a1+a2+a3...+an)
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤500)
 每个样例2行，第一行整数𝑛 (2≤𝑛≤10e5）
 第二行n个整数 𝑎1,𝑎2,…,𝑎𝑛 (𝑎𝑖=1 or 𝑎𝑖=−1)
 
  
 **输出：**
 每个样例一行，输出可能的最大数组和；
 
 **Examples**
 **input**
 4
 5
 -1 1 1 -1 -1
 5
 1 1 -1 -1 -1
 2
 1 1
 4
 1 -1 -1 1

 **output**
 3
 3
 -2
 4


 
 **题目解析：**
 直接累加数组的整数，得到整数和sum；
 接着遍历数组：
 如果能找到两个-1相邻，则直接反转着两个整数，sum=sum+4；
 如果能有一个-1，则sum=sum;
 如果都是1，则sum=sum - 4;
 
 
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
            int sum = 0, done = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                sum += a[i];
            }
            for (int i = 1; i < n && !done; ++i) {
                if (a[i] + a[i - 1] == -2) {
                    sum += 4;
                    done = 1;
                }
            }
            for (int i = 0; i < n && !done; ++i) {
                if (a[i] == -1) {
                    done = 1;
                }
            }
            if (!done) {
                sum -= 4;
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
 
