//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1634/problem/C)
 **题目大意：**
 有n*k个整数1、2、3、4、、、n*k，现在需要将这些整数分成n行，并且对于每一行都满足：
 任意选择区间[l, r]，区间的平均数是整数；
 问，是否存在这样的分配方式；
 
  **输入：**
 第一行，整数𝑡 表示t个样例  (1≤𝑡≤500)
 每个样例一行，整数𝑛 and 𝑘 (1≤𝑛,𝑘≤500)
 
 **输出：**
 每个样例，如果无解则输出NO；
 如果有解则输出YES，接下来n行分别输出k个数字；
 
 
 **Examples**
 **input**
 4
 1 1
 2 2
 3 3
 3 1
 
 **output**
 YES
 1
 YES
 1 3
 2 4
 NO
 YES
 1
 2
 3


 **题目解析：**
 按照题目的要求，对于n行数字，每行数字的任意区间的平均数都是整数；
 当区间长度为2时，（a[i][j] + a[i][j+1]）/ 2能够整除，那么必须是两个奇数或者两个偶数；
 由此我们知道，当k>1的时候，肯定每一行数字都是奇数，或者都是偶数；（n=1或者k=1结果较为简单，这里不做讨论）
 
 那么可以推断出， 如果n*k是奇数，那么最终肯定会出现奇数个数字，无法满足要求；
 当n*k是偶数时，如果n是奇数，则k是偶数，那么在平均分配奇偶数的时候，必然会在第(n+1)/2行出现奇偶数混杂的情况，无法满足要求；
 如果n是偶数，那么就可以按照1、3、5、7、、这样分配所有奇数，2、4、6、8这样分配所有偶数；
 任意区间的平均数，都是中间两个数的平均值；
 

 
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
    char str[N];
    int dp[N];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            if (k == 1) {
                cout << "YES" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << i + 1 << endl;
                }
            }
            else if (n % 2) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                for (int i = 0; i < n / 2; ++i) {
                    int tmp = i * k * 2 + 1;
                    for (int j = 0; j < k; ++j) {
                        cout << tmp + j * 2 << " ";
                    }
                    cout << endl;
                    for (int j = 0; j < k; ++j) {
                        cout << tmp + 1 + j * 2 << " ";
                    }
                    cout << endl;
                }
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

/**
 */
