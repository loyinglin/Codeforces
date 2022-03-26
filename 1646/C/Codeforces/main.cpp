//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1646/problem/C)
 **题目大意：**
 一个整数是2的x次幂，或者是x的阶乘，那么这个数字是powerful的；
 现在给出一个整数n，希望由若干个powerful的整数相加来得到n，要求：
 1、没有相同的powerful整数；
 2、powerful整数尽可能少；
 
  **输入：**
 第一行样例数𝑡 (1≤𝑡≤100).
 接下来每个样例一行𝑛  (1≤𝑛≤1e12).
 
 **输出：**
 能相加得到n的最少powerful整数的数量，如果没有答案则输出-1；

 
 **Examples**
 **input**
 4
 7
 11
 240
 17179869184
 **output**
 2
 3
 4
 1
 
 **题目解析：**
 首先把powerful的整数枚举取出来：
 2的x次幂：1、2、4、8、16、32、64、128等；
 x的阶乘：1、2、6、24、120等；
 这两部分数字可以通过hash去重，得到1、2、4、8、16、24、32、64、120、128等；
 题目的要求就是从这些数字中选出最少的数字，来组成整数n；
 n个物品的选择来形成特定大小，这个是典型的动态规划问题，但是如果用背包的解法，会由于状态数过多而超时；
 
 仔细分析题目，2的x次幂这部分数字，其实已经可以足够组成任意数字；
 那么题目就变成了，要在阶乘中选择多少个数字来组成n，剩下的部分可以有2的x次幂来组成（并且这部分的最优解就是数字的二进制位数）；
 阶乘递增比较快，在15!的时候就超过了题目要求，再减去最开始的阶乘1和2，最终可以不超过2^13=8000左右种结果；
 枚举这些结果，结合剩下数字的二进制长度，来得到最优解；
 
 
 
 **思考🤔：**
 
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
    static const int N = 10010;
    string str;
    vector<lld> num;
    
    lld count(lld n) {
        lld ret = 0;
        while (n) {
            ret += n % 2;
            n /= 2;
        }
        return ret;
    }

public:
    void solve() {
        int t;
        cin >> t;
        
        lld tmp = 2;
        for (int i = 3; i < 15; ++i) {
            tmp *= i;
            num.push_back(tmp);
        }
        
        while (t--) {
            lld n;
            cin >> n;
            lld ans = n;
            for (int i = 0; i < (1 << num.size()); ++i) {
                lld sum = 0;
                lld index = 0;
                int tmp = i;
                while (tmp) {
                    if (tmp % 2) {
                        sum += num[index];
                    }
                    tmp /= 2;
                    ++index;
                }
                if (sum <= n) {
                    ans = min(ans, count(i) + count(n - sum));
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

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
