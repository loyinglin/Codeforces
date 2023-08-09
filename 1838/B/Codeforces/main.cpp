//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1838/problem/B)
 **题目大意：**
 给出n个整数的排列，现在可以选择排列中的2个位置，交换位置上的元素。
 要求，交换之后所有子数组形成的排列尽可能的少。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，整数𝑛 (3≤𝑛≤2e5)
 第二行，n个整数𝑎1,𝑎2,…𝑎𝑛
 
 
 **输出：**
 每个样例一行，输出交换的两个整数的位置；
 如果有多个答案，可以输出其中一个；（两个位置可以是相同的）
 
 **Examples**
 **input**
 8
 3
 1 2 3
 3
 1 3 2
 5
 1 3 2 5 4
 6
 4 5 6 1 2 3
 9
 8 7 6 3 2 1 4 5 9
 10
 7 10 5 1 9 8 3 2 6 4
 10
 8 5 10 9 2 1 3 4 6 7
 10
 2 3 5 7 10 1 8 6 4 9


 **output**
 2 3
 1 1
 5 2
 1 4
 9 5
 8 8
 6 10
 5 4



 **题目解析：**
 对于排列来说，最终的整数就是1，因为所有的排列都要从1开始；
 其次就是整数2，因为排列除了1，第二位是2；
 根据题目的要求，如果想要无法组成排列，那么最大数n也很重要，因为一旦1和2被n隔开，那么就无法形成排列（除非整个数组一起参与排列）；
 那么我们用 x,y,z来表示1,2,n这三个整数的位置。
 容易知道，只要我们形成x<z<y或者y<z<x这样的位置顺序，那么所有子数组只有2个排列（1和n）；
 只考虑x,y,z三个位置，我们知道交换一个位置，必然可以把z交换到中间去。
 
 为了简单实现，我们将x,y,z三个整数排序，然后将z与排序中间的位置交换即可。
 
 
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
            int x, y, z;
            for (int i = 1; i <= n; ++i)  {
                cin >> a[i];
                if (a[i] == 1) x = i;
                if (a[i] == 2) y = i;
                if (a[i] == n) z = i;
            }
            int tmp[] = {x, y, z};
            sort(tmp, tmp + 3);
            cout << tmp[1] << " " << z << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
