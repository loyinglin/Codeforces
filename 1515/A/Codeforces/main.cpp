//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1515/problem/A)
 **题目大意：**
 给出n个整数和整数x，问能否找到一个顺序：
 按照这个顺序累加数字，中间不会出现数字和等于x；
 已知n个整数互不相同。
 
 **输入：**
 第一行，整数 𝑡 表示样例数(1≤𝑡≤1000)
 每个样例有2行，第一行 整数  𝑛 and 𝑥 (1≤𝑛≤100; 1≤𝑥≤1e4)
 第二行 n个整数𝑤𝑖  (1≤𝑤𝑖≤100)
 **输出：**
 如果无解，直接输出NO；
 如果有解，则输出YES，接下来一行输出n个整数，从左到右为累加顺序；
 
 **Examples**
 **input**
 3
 3 2
 3 2 1
 5 3
 1 2 3 4 8
 1 5
 5
 **output**
 YES
 3 2 1
 YES
 8 1 2 3 4
 NO

 
 
 **题目解析：**
 如果最终结果等于x，那么不管如何调整，最终会有x出现，无解；
 如果最终结果不等于x，那么就一定构造出来合理的顺序：
 比如说[1, i]的和等于x，由于a[i]!=a[i+1]，那么将i和i+1的数字进行调换即可。
 
 那么只需要从左到右遍历数组，不断累加中间的数字和sum；
 假如sum==x，则判断数字是否用完，否则将后面的数字与当前任意一个位置交换，由于整数各不相同，交换之后必然sum!=x；
 如果后面没有数字了，则无解。
 
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
    static const int N = 100010;
public:
    int n, x;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> x;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            int ok = 1, sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += a[i];
                if (sum == x) {
                    if (i == n - 1) {
                        ok = 0;
                    }
                    else {
                        swap(a[i], a[i + 1]);
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "NO" << endl;
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
