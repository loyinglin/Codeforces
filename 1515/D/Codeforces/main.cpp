//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1515/problem/D)
 **题目大意：**
 商店里有n只袜子，每只袜子的颜色是c[i]；（这只袜子可能是左脚，也可能是右脚）
 现在可以执行若干次操作，每次操作从下面3个选项中选择：
 1、将某只袜子染色成任意颜色；
 2、将一只左袜子改造成右袜子；
 3、将一只右袜子改造成左袜子；
 
 现在想知道最少执行多次操作，才能拼出n/2双袜子（一双袜子是左脚+右脚，并且颜色相同）；
 
 **输入：**
 第一行整数 𝑡 ，表示样例数 (1≤𝑡≤1000)
 每个样例两行，第一行整数𝑛, 𝑙, and 𝑟 (2≤𝑛≤2⋅1e5; 𝑛 是偶数;  0≤𝑙,𝑟≤𝑛;  𝑙+𝑟=𝑛)
 第二行是n个整数𝑐𝑖 (1≤𝑐𝑖≤𝑛)，前l个是左脚，后r个是右脚；
 **输出：**
 每个样例一行，输出最少的操作次数。
 
 **Examples**
 **input**
 4
 6 3 3
 1 2 3 2 2 2
 6 2 4
 1 1 2 2 2 2
 6 5 1
 6 5 4 3 2 1
 4 0 4
 4 4 4 3
 **output**
 2
 3
 5
 3

 
 **题目解析：**
 先将左右袜子颜色一样的挑出来；
 接着将相同颜色的left/right 组成一对，每对的代价是1；（将多的那一组，分给少的那一组）
 
 假设剩下x只left，y只right，并且x和y没有相同的颜色，则剩下有两个花费：
 1、花费abs(x-y)/2的差额，将left和right数量对齐；
 2、花费（x+y)/2的费用，将一半的颜色和另外一半对齐；
 
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
    static const int N = 200010;
public:
    int n, l, r;
    int a[N];
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> l >> r;
            map<int, int> hashLeft, hashRight;
            int ans = 0, cntLeft = 0, cntRight = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (i < l) {
                    ++hashLeft[a[i]];
                    ++cntLeft;
                }
                else {
                    if (hashLeft[a[i]]) {
                        --hashLeft[a[i]];
                        --cntLeft;
                    }
                    else {
                        ++hashRight[a[i]];
                        ++cntRight;
                    }
                }
            }
            if (cntLeft > cntRight + 1) {
                for (map<int, int>::iterator it = hashLeft.begin(); it != hashLeft.end(); ++it) {
                    while (it->second >= 2 && cntLeft > cntRight + 1) {
                        cntLeft -= 2;
                        ++ans;
                        it->second -= 2;
                    }
                }
            }
            else if (cntRight > cntLeft + 1) {
                for (map<int, int>::iterator it = hashRight.begin(); it != hashRight.end(); ++it) {
                    while (it->second >= 2 && cntRight > cntLeft + 1) {
                        cntRight -= 2;
                        ++ans;
                        it->second -= 2;
                    }
                }
            }
            ans += max(cntLeft, cntRight);
            
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
 4
 6 3 3
 1 2 3 2 2 2
 6 2 4
 1 1 2 2 2 2
 6 5 1
 6 5 4 3 2 1
 4 0 4
 4 4 4 3
 
 output
 2
 3
 5
 3
 
 */
