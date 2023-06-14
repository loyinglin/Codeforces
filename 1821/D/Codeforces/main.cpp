//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1821/problem/D)
 **题目大意：**
 有一排格子排成一行，编号从左到右分别为0、1、2、3；
 小明站在第0个格子，每次小明有三个选择可以进行操作：
 1、移动到下一个格子：从格子x移动到格子x+1；
 2、按下shift按钮；
 3、松开shift按钮，小明在按下shift按钮期间经过的格子会被染色；
 
 现在只有若干个区间[x, y]允许染色，区间外的格子不允许染色；
 现在想要染色k个格子，问最少需要操作多少次；
 
 
 1e18
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行：
 第一行，整数 𝑛 和 𝑘 (1≤𝑛≤2⋅1e5; 1≤𝑘≤1e9)
 第二行，整数 𝑙1,𝑙2,…,𝑙𝑛，表示n个区间的起点  (1≤𝑙1<𝑙2<⋯<𝑙𝑛≤1e9)
 第三行，整数 𝑟1,𝑟2,…,𝑟𝑛  ，表示n个区间的终点 (1≤𝑟𝑖≤109; 𝑙𝑖≤𝑟𝑖<𝑙𝑖+1−1)
 n个区间没有重合；
 
  
 **输出：**
 每个样例一行，输出最少的操作次数，如果无解则输出-1；
 
 **Examples**
 **input**
 4
 2 3
 1 3
 1 4
 4 20
 10 13 16 19
 11 14 17 20
 2 3
 1 3
 1 10
 2 4
 99 999999999
 100 1000000000

 
 **output**
 8
 -1
 7
 1000000004

 
 **题目解析：**
 简单策略，小明从左到右，只要经过允许的区间就染色，直到k个格子；
 考虑到要最小操作次数，那么同一个区间的染色操作要合并，那么策略可以进行优化：
 对于每一个区间，先考虑区间是否小于需要染色数量，是的话则直接染色整个区间；
 如果当前区间足够剩余染色数量，则选择需要染色的x个格子即可。
 但是这种策略少考虑了一种情况：
 以题目样例3为例，假设一种情况是1011111111，其实先选择前面的1，则会花费3的代价（两次shift+1次移动），总的花费是8；如果不选择前面1，而是选择后面位置3开始的1，则只需要花费的代价是7；
 为什么会出现这种情况？
 因为前面会有2次选中操作，但是后面则只需要1次选中操作，减少了1次选中操作（即是2次shift），虽然多花费了1次move操作，但是总的花费还是减少了1；
 所以在这种情况下，简单的策略在以下这种情况：
 101010....011111....0110..101010....1111111... 都会难以处理，因为在决策是否要染色时，还可能受到后续方块的影响。
 
 为了简化思考过程，可以我们把移动和选择拆分来看，先假设小明从0开始移动到第i个可以染色区间，小明经过的区间可以分为三类：
 1、长度为1区间；
 2、第1个到第i-1个区间中，长度大于1的区间；
 3、第i个区间；（为什么第i个单独列出来，是因为第i个允许仅染色部分）
 
 移动的代价分为两部分，首先是移动到第i个区间起始位置，另外一个是在第i个区间移动的距离；
 选择的代价，首先是长度大于>1的区间，然后是第i个区间，接着是长度为1的区间；
  
 
 k=10
 10101010101010101010111011111111111111
 19+2*10=39
 20+4+7+4=35
 
 
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
    int a[N], b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) cin >> b[i];
            lld sum = 0, oneCnt = 0;
            lld ans = 0xffffffffffff;
            for (int i = 0; i < n; ++i) {
                lld len = b[i] - a[i] + 1;
                if ((sum + len) >= k && k >= (sum - oneCnt)) {
                    if (sum - oneCnt + len >= k) {
                        ans = min(ans, a[i] - 1 + (i - oneCnt + 1) * 2 + (k - (sum - oneCnt)));
                    }
                    else {
                        ans = min(ans, a[i] - 1 + (i - oneCnt + 1) * 2 + len + 2 * (k - (sum - oneCnt + len)));
                    }
                }
                if (len == 1) ++oneCnt;
                sum += len;
            }
            if (ans == 0xffffffffffff) cout << "-1" << endl;
            else cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
