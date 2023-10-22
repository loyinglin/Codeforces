//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1867/problem/C)
 **题目大意：**
 有一个整数数组s，长度为n；一个数组的MEX值，就是该数组没有出现过的非负整数的最小值，比如说 MEX({0,1,2,4}) = 3 .
 现在Alice和Bob两个人在玩游戏，Alice先手。游戏规则如下：
 Alice可以添加一个整数𝑥(0≤𝑥≤1e9)到数组中，要求该整数在数组中没有；
 Bob可以移除一个整数y，y必须要小于最近一次Alice添加的整数x，并且该数字在数组存在；
 Alice的目标是尽可能让数组最终的MEX值更大，Bob的目标是让最终的MEX值尽可能小。
 
 现在让你扮演Alice，使得最终MEX尽可能大。
 

 **输入：**
 第一行，整数𝑡 表示t次游戏 (1≤𝑡≤100000)
 每个样例有多行：
 第一行整数𝑛(1≤𝑛≤1e5)
 第二行整数数组s (0≤𝑠1<𝑠2<…<𝑠𝑛≤1e9)
 接下来有多行，每行一个整数y：
 如果y>=0，表示Bob从数组中移除该数字；
 y=-1，表示该次游戏结束；
 
 **输出：**
 每个样例若干行，每行一个整数x，表示要添加的整数；
 
 **Examples**
 **input**
 3
 5
 1 2 3 5 7

 7

 5

 -1

 3
 0 1 2

 0

 -1

 3
 5 7 57

 -1
 **output**
 8

 57

 0

 3

 0

 0

 样例解释：
 样例一的整个操作过程 {1,2,3,5,7 } → {1,2,3,5,7,8 } → {1,2,3,5,8 } → {1,2,3,5,8,57 } → {1,2,3,8,57 } → {0,1,2,3,8,57 }. 最终游戏结束 MEX(𝑆)=4



 **题目解析：**
 题目看起来复杂，其实分析下Alice和Bob的策略，会发现逻辑比较简单：
 Alice想要MEX值尽可能大，那么必须从小开始填充未出现的字符；
 Bob想要MEX值尽可能小，那么必须从小开始移除出现的字符；
 
 那么为了让题目交互起来更加简单：
 先手采用这样的策略，先填充一个数字。
 后手移除任何数字，都选择添加该数字。
 
 
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
    static const int N = 101010;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            map<int, int> h;
            for (int i = 0;i < n; ++i) {
                int tmp;
                cin >> tmp;
                h[tmp] = 1;
            }
            int first = -1, second = -1;
            for (int i = 0; i < n + 10; ++i) {
                if (h.find(i) != h.end()) continue;;
                if (first == -1) {
                    first = i;
                }
                else if (second == -1) {
                    second = i;
                    break;
                }
            }
            cout << first << endl;;
            while (true) {
                int p;
                cin >> p;
                if (p == -1) break;
                cout << p << endl;
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
 
