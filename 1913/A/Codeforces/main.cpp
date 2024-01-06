//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1913/problem/A)
 **题目大意：**
 给出一个整数，问该整数能否切分为两个数字a和b，满足：
 1、a和b都不包括前导零，是一个正常的数字；
 2、a和b都大于0；
 3、b > a；
 
 如果可以，则输出数字a和b；如果不可以则输出-1；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，单个整数 (数字长度为2~8)
  
 **输出：**
 每个样例一行，如果可以，则输出数字a和b；如果不可以则输出-1；
 
 **Examples**
 **input**
 5
 20002001
 391125
 200200
 2001000
 12



 **output**
 2000 2001
 39 1125
 -1
 200 1000
 1 2



 **题目解析：**
 按照题目的要求，a要尽可能小，b要尽可能大。
 由于题目给出的数字本身就合法，那么将第一个数字开始分为a，往后找到第一个非零的数字就分给b，这样b一定是最大的。
 从字符串上切分好a和b，接下来就是转成数字。
 这里为了便于计算，从字符串a右边开始往左边枚举每一个位置上的数字，就可以得到数字a。（数字b同理，也可以字符串切割后，用sscanf取巧）
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            string str;
            cin >> str;
            int k = 1, n = str.length();
            while (k < n) {
                if (str[k] != '0') break;
                ++k;
            }
            if (k >= n) {
                cout << -1 << endl;
                continue;;
            }
            int x = 0, y = 0;
            int tmp = k - 1, val = 1;
            while (tmp >= 0) {
                x += val * (str[tmp] - '0');
                --tmp;
                val *= 10;
            }
            tmp = n - 1, val = 1;
            while (tmp >= k) {
                y += val * (str[tmp] - '0');
                --tmp;
                val *= 10;
            }
            if (x < y) cout << x << " " << y << endl;
            else  cout << -1 << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
