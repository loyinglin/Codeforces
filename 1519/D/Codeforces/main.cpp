//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1519/problem/D)
 **题目大意：**
 给出n个整数的数组a和b，数组a和数组b的乘积和等于a[0]*b[1]+a[2]*b[2]+...+a[n]*b[n]；
 可以选择一个区间[x, y]（x<=y)，调转数组a区间[x, y]内整数的顺序，比如说数字1,2,3则调转为3,2,1；
 求调转之后，数组a和数组b的最大乘积和。
 
 **输入：**
 第一行是整数n，表示数组长度 (1≤𝑛≤5000)
 第二行是n个整数a[1]、a[2]、a[3]... a[n]; (1<=a[i] <= 1e7）；
 第二行是n个整数b[1]、b[2]、b[3]... b[n];(1<=b[i] <= 1e7）；
 
 **输出：**
 调转一次区间之后，数组a和数组b的最大乘积和。
 
 **Examples**
 **input**
 5
 2 3 2 1 3
 1 3 2 4 2
 
 **output**
 29

 样例解释：
 调转区间[4,5]，a=[2,3,2,3,1]，那么数组a和b的成绩和= 2⋅1+3⋅3+2⋅2+3⋅4+1⋅2=29
 
 **题目解析：**
 先不考虑复杂度，一个直接的做法便是枚举区间，然后计算数字相乘和；
 这样的复杂度是O（N^3）；
 
 做一些简单的优化：
 将求和的过程拆成三部分，假设revert的区间是[x, y]，那么[1, x)和(y, n]部分是可以预处理的；（前i个数字相乘和、后i个数字相乘和）
 问题在于，revert的区间[x, y]如何快速计算？
 尝试从[x, y]去推导[x, y+1]和[x-1, y]的数字相乘和，发现都需要O（N）的时间去计算；
 后面发现从[x, y]去推导[x-1, y+1]就简单了很多。
 
 那么这个题目可以用O（N^2）的空间，来减少O（N）的时间复杂度，使得时间、空间复杂度都控制在O（N^2），在题目可接受范围内。
 
 注意：
 题目的核心在于计算revert(i, j)区间数字相乘和，由于推导的时候每次区间都会+2大小，所以需要推导区间[i, i]和[i, i+1]两次。
 
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
    static const int N =5001;
public:
    int n;
    lld a[N], b[N];
    lld sumLeft[N], sumRight[N], sumRevert[N][N];
public:
    void solve() {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sumLeft[0] = a[0] * b[0];
        for (int i = 1; i < n; ++i) {
            sumLeft[i] = sumLeft[i - 1] + a[i] * b[i];
        }
        sumRight[n - 1] = a[n - 1] * b[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sumRight[i] = sumRight[i + 1] + a[i] * b[i];
        }
        for (int i = 0; i < n; ++i) {
            // 推导[i, i]=>[i-1, i+1]
            int left, right;
            sumRevert[i][i] = a[i] * b[i];
            left = i - 1, right = i + 1;
            while (left >= 0 && right < n) {
                sumRevert[left][right] = sumRevert[left + 1][right - 1] + a[left] * b[right] + b[left] * a[right];
                --left;
                ++right;
            }
            left = i, right = i + 1;
            if (right < n) {
                sumRevert[left][right] = a[left] * b[right] + b[left] * a[right];
                while(true) {
                    --left;
                    ++right;
                    if (left < 0 || right >= n) {
                        break;
                    }
                    sumRevert[left][right] = sumRevert[left + 1][right - 1] + a[left] * b[right] + b[left] * a[right];
                }
            }
        }
        lld ans = sumLeft[n - 1];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // revert的区间为[i, j]
                lld tmp = 0;
                if (i > 0) {
                    tmp += sumLeft[i - 1];
                }
                if (j + 1 < n) {
                    tmp += sumRight[j + 1];
                }
                tmp += sumRevert[i][j];
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 Input
 5
 2 3 2 1 3
 1 3 2 4 2
 
 2 9 8 2 6
 
 Output
 29
 Input
 2
 13 37
 2 4
 Output
 174
 Input
 6
 1 8 7 6 3 6
 5 9 6 8 8 6
 Output
 235

 
 */
