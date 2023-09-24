//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1869/problem/A)
 **题目大意：**
 给出一个整数的数组，长度为n；
 现在可以进行以下的操作：
 选择长度不小于2的区间[l, r]，将区间内的整数依次进行异或操作，然后将得到的整数替换区间所有的数字；
 
 比如说数组[1,5,4,1,4,7]，当我们选择区间[1,5,4]进行异或操作，得到结果是4，然后替换原来的区间内所有数字得到：
 [1,5,4,1,4,7]→[4,4,4,1,4,7]
 
 问，如何找到一个操作，使得数组所有元素都为0；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤500)
 每个样例两行
 第一行整数𝑛(2≤𝑛≤100)
 第二行整数𝑎1,𝑎2,…,𝑎𝑛(0≤𝑎𝑖≤100)
 
 **输出：**
 每个样例第一行输出操作次数m，接下来m行，每行2个整数表示操作区间；（m不能大于8）
 
 **Examples**
 **input**
 3
 1
 100000
 2
 1 1
 3
 10 3 3

 **output**
 1
 2 1
 1 3 2




 **题目解析：**
 当n=偶数时，令l=1，r=n，我们可以得到一个元素相同的数组；再重复一次这样的操作，由于偶数个一样的数字进行异或，结果就全部是0；
 当n=奇数时，类似偶数的做法，我们可以先对偶数长度的区间[1, n-1]进行上述操作，使得区间归零；再对区间[2, n]进行相同操作即可；
   
 
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
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            if (n % 2) {
                printf("4\n%d %d\n%d %d\n", 1, n - 1, 1, n - 1);
                printf("%d %d\n%d %d\n", 2, n, 2, n);
            }
            else {
                printf("%d\n%d %d\n%d %d\n", 2, 1, n, 1, n);
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
 
