//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1674/problem/E)
 **题目大意：**
 小明在玩游戏，游戏中有n个怪兽站成一排，每个怪兽的血量为a[i];
 小明可以释放技能，每次技能可以伤害其中1个怪兽2点血，以及左边或者右边相邻1点血；
 比如说3个怪兽血量为[1,3,1]，则小明可以对中间怪兽释放两次技能，则可以把所有怪兽的血量清零；（怪兽血量为0仍然可以释放技能）
 现在只需要把其中2个怪兽的血量清理，问最少需要放几次技能；
 
  **输入：**
 第一行，整数n (2≤𝑛≤2⋅1e5)
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1e6）
  
 **输出：**
 最少需要的技能次数；
 
 
 **Examples**
 **input**
 5
 20 10 30 10 20
 **output**
 10

 
 **题目解析：**
 这个题目用dp来解决，dp[i][0]表示前i怪兽打死1个的最小次数，dp[i][1]表示前i个怪兽打死2个的最小次数；
 对于第i个怪物，有打死和不打死两种可能，不打死的话直接dp[i-1]转移，打死的话有多种可能：单独打死，和i-1一起打死，或者和i-2一起打死；
 根据上面两种情况，得到两个状态的转移方程，即可解决问题，复杂度O(N)；
 
 但是这个题目不需要动态规划，同样可以解决：
 打怪兽只有两种可能，分开打死和一起打死，分开打死取数组最小2个元素即可，一起打死有下面两种可能：
 1、两个怪兽是相邻的，可以假设血量为x和y（x<y），先只考虑对y放技能的情况，算出打死两个怪物的最少次数，然后考虑有多少个1/2的伤害可以替换为2/1；
 2、两个怪兽是不相邻的，那么必然是打击中间的怪兽，掉两边的血；当有一个怪物死亡后，就可以瞄准剩下的怪物；（解决血量为[1,10,3]这样的情况）
 复杂度同样为O(N)，并且不要考虑状态转移，实现更加简单；
 
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
    int a[N], dp[N][2];
    
    int check(int x, int y) {
        int maxItem = max(x, y);
        int minItem = min(x, y);
        int cnt = 0;
        if (minItem * 2 <= maxItem) {
            cnt = (maxItem + 1) / 2;
        }
        else {
            cnt = minItem - (minItem * 2 - maxItem) / 3;
        }
        return cnt;
    }

public:
    void solve() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0xfffffff;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, check(a[i], a[i - 1]));
            if (i >= 2) {
                ans = min(ans, min(a[i], a[i - 2]) + (a[i] + a[i - 2] - min(a[i], a[i - 2]) * 2 + 1) / 2);
            }
        }
        sort(a, a + n);
        ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
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
 */
