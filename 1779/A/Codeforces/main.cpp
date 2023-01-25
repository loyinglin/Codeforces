//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1779/problem/A)
 **题目大意：**
 有n个格子排成一行，每个格子有一个灯，灯有两个方向：L和R，分别表示朝左和朝右；
 当一个灯朝左时，它能照亮其左边的格子；（不包括灯所在格子）
 当一个灯朝右时，它能照亮其右边的格子；（不包括灯所在格子）
 现在允许选择某个格子，交换该格子和右边格子的灯，灯的朝向不变；（不能选择最右边的格子）
 现在想知道，是否能够让每个格子都能被灯照亮；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡 (1≤𝑡≤10000)
 每个样例2行，第一行整数 𝑛 (2≤𝑛≤100000)
 第二行n个字符'L' 和 'R'
  
 **输出：**
 每个样例一行，如果无解输出-1，如果不需要交换输出0，如果需要交换则输出交换第x个格子；（1  <= x < n）
  
 
 **Examples**
 **input**
 6
 2
 LL
 2
 LR
 2
 RL
 2
 RR
 7
 LLRLLLR
 7
 RRLRRRL
 **output**
 -1
 1
 0
 -1
 3
 6
 
 **题目解析：**
 样例给了一个比较关键的数据，当字符串出现RL，题目就必然存在解；
 基于此我们继续分析，当字符串只有L或者只有R时，必然无解；
 当字符串存在L和R时，必然有解：因为总是能找到L和R相交的位置，如果是R和L，则无需交换；如果是L和R，则进行交换；
 
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
            string str;
            cin >> str;
            int index = -1;
            for (int i = 0; i + 1 < n; ++i) {
                if (str[i] != str[i + 1]) {
                    index = str[i] == 'R' ? 0 : (i + 1);
                    break;
                }
            }
            cout << index << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
