//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1678/problem/A)
 **题目大意：**
 给出n个整数的数组，现在可以对数据进行多次操作；
 每次操作可以选择两个元素a[i]或者a[j]，如果a[i]和a[j]相同，则可以把其中一个元素改为0，如果不相同则可以令较大值改为较小值；（i != j）
 现在想知道，最少需要多少次操作，才能将整个数组变为0；
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤1000)
 每个样例俩行，第一行 整数 𝑛 (2≤𝑛≤100)
 第二行n个整数  𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤100)
  
 **输出：**
 每个样例一行，最少的操作次数；
 
 
 **Examples**
 **input**
 3
 3
 1 2 3
 3
 1 2 2
 3
 1 2 0
 **output**
 4
 3
 2
 
 **题目解析：**
 由于题目的要求是将元素变成0，假如数组中存在元素0，那么每次操作可以把1个非零整数变成0，答案就是非0数量；
 如果没有0，则看是否有元素相同，有的话只需增加1次操作，产生1个0之后，就可以重复上面的过程；
 如果没有相同元素，那么就再增加1次操作，产生2个数值相同的元素，再重复上面的过程；
  
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
            sort(a, a + n);
            int same = 0;
            for (int i = 1; i < n; ++i) {
                if (a[i] == a[i - 1]) {
                    same = 1;
                }
            }
            int zero = 0;
            for (int i = 0; i < n; ++i) {
                zero += (a[i] == 0);
            }
            int ans;
            if (zero > 0) {
                ans = n - zero;
            }
            else if (same > 0) {
                ans = n;
            }
            else {
                ans = n + 1;
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

/**
 */
