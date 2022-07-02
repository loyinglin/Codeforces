//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1691/problem/C)
 **题目大意：**
 给出一个长度为n的二进制字符串s，现在定义一个函数f(s)为数字中的所有两两相邻数字组成的十进制数字之和，比如说：
 𝑠=1011 时，可以得到10、01、11，那么𝑓(𝑠)=10+01+11=22；
 
 现在最多可以执行k次操作，每次操作可以交换一次相邻数字，问f(s)最小值是多少；
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡  (1≤𝑡≤1e5)
 每个样例俩行，第一行 整数  𝑛 and 𝑘 (2≤𝑛≤1e5, 0≤𝑘≤1e9)
 第二行长度为n的字符串s；
  
 **输出：**
 每个样例一行，输出最小的f(s)；
 
 
 **Examples**
 **input**
 3
 4 0
 1010
 7 1
 0010100
 5 2
 00110
 **output**
 21
 22
 12
 
 **题目解析：**
 根据f(s)的定义，我们知道大部分数字都会被使用两次，一次是在十位数，一次是在个位数；第一个数字只会用在十位数，最后一个数字只会用在个位数；
 那么如果想要令f(s)尽可能小，就是要将数字尽可能放在头尾两边；
 
 考虑数字1可能会在出现在多个位置，我们用left和right来表示数字1最左边和最右边的位置；（最右边不包括第n个位置）
 假如剩余的交换次数，足够right位置的1交换到最右边，则交换；
 假如剩余的交换次数，足够left位置的1交换到最左边，则交换；
 
 然后再遍历整个数组，按照规则计算得到f(s)即可。
 
 
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
    string s;

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            cin >> s;
            int left = n, right = 0, sum = 0;
            int ans = 0;
            for (int i = 0; i < (n - 1); ++i) {
                if (s[i] == '1') {
                    ++sum;
                    left = min(left, i);
                    right = i;
                }
            }
            if (sum > 0 && s[n - 1] == '0') {
                if (k >= n - 1 - right) {
                    --sum;
                    k -= n - 1 - right;
                    s[right] = '0';
                    s[n - 1] = '1';
                }
            }
            if (sum > 0 && k > 0 && s[0] == '0') {
                if (k >= left) {
                    --sum;
                    k -= left;
                    s[left] = '0';
                    s[0] = '1';
                }
                
            }
            for (int i = 0; i < n - 1; ++i) {
                ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
            }
//            cout << "TEST " << s << endl;
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
 
 
 112
 5
 1 1 1 1 1
 6
 1 1 2 2 3 3
 
 6
 1 2 2 2 3 4
 
 6
 1 1 2 2 2 3
 
 
 
 */
