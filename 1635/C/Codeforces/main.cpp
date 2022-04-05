//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1635/problem/C)
 **题目大意：**
 给出n个整数的数组a，现在可以选择数组中三个元素a[x],a[y],a[z]（其中x<y<z），令a[x]=a[y]-a[z]；
 现在可以执行不超过n次操作，要求数组变成非递减；
 
  **输入：**
 第一行样例数，(1≤𝑡≤10000)
 每个样例两行，第一行是 𝑛 (3≤𝑛≤2⋅1e5)
 第二行是n个整数𝑎1,𝑎2,…,𝑎𝑛  (−1e9≤𝑎𝑖≤1e9)
 
 **输出：**
 每个样例第一行输出操作次数k，如果无解则输出-1；
 有解的情况，接下来k行，每一行包括整数x,y,z，表示每次操作的数组元素序号；（没有要求最少操作次数）
 
 **Examples**
 **input**
 3
 5
 5 -4 2 -1 2
 3
 4 3 2
 3
 -3 -2 -1
 **output**
 2
 1 2 3
 3 4 5
 -1
 0
 **题目解析：**
 题目有一个很重要的条件，没有要求最少操作次数。
 那么对于数组中只有最后两个整数是有意义的，如果第n个元素>=0，那么必然有解：可以把前面的元素都替换成a[n-1]-a[n]；
 
 先判断下数组是不是本身符合要求；
 其他的情况根据a[n-1]和a[n] 的大小就可以判断。
 
 
 **思考🤔：**
 如果要求最小次数呢？
 
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
    static const int N = 200010;
    string str;
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
            
            if (a[n - 1] < a[n - 2]) {
                cout << -1 << endl;
            }
            else {
                int rightIndex = n - 3;
                while (rightIndex >= 0) {
                    if (a[rightIndex] > a[rightIndex + 1]) {
                        break;
                    }
                    --rightIndex;
                }
                if (rightIndex < 0) {
                    cout << 0 << endl;
                }
                else {
                    if (a[n - 1] >= 0) {
                        cout << rightIndex + 1 << endl;
                        for (int i = 0; i < rightIndex + 1; ++i) {
                            cout << i + 1 << " " << rightIndex + 2 << " " << n << endl;
                        }
                    }
                    else {
                        cout << -1 << endl;
                    }
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
