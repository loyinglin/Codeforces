//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/dungeon-game/
 题目大意：
 n*m的网格，求从左上角到右下角，路径上的最大数字和；
 
 题目解析：
 典型的动态规划，注意如果和是整数，return 0.
 
 收获一枚WA。
 需要保证路径上，体力值一直不小于1。
 
 有个简单的思路，二分。
 然后N*N的遍历所有能到达的点，看是否能到达右下角；时间复杂度是O(N * M * logK) K为数字和，N、M为行列数量；
 
 在原来的基础上，在位置(i,j) 上有两个信息，能到达i、j时的最小体力值，到达时的最大力体值；这部分用dp维护不太方便。
 
 
 后记：
 后来发现，就动态规划也是可行的，倒着来即可。
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
#include<unordered_set>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 1000, inf = 0x3ffffff;
class Solution {
public:
    int dp[N][N];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int left = 1, right = inf, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canPass(dungeon, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    bool canPass(vector<vector<int>>& dungeon, int health) {
        for (int i = 0; i < dungeon.size(); ++i) {
            for (int j = 0; j < dungeon[i].size(); ++j) {
                dp[i][j] = -inf;
            }
        }
        dp[0][0] = dungeon[0][0] + health;
        if (dp[0][0] <= 0) {
            return false;
        }
        for (int i = 0; i < dungeon.size(); ++i) {
            for (int j = 0; j < dungeon[i].size(); ++j) {
                if (i > 0 && dp[i - 1][j] + dungeon[i][j] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + dungeon[i][j]);
                }
                if (j > 0 && dp[i][j - 1] + dungeon[i][j] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + dungeon[i][j]);
                }
            }
        }
        int ret = dp[dungeon.size() - 1][dungeon[0].size() - 1];
        return ret > 0;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<vector<int>> nums1 = {{-3, 5}};
    cout << leetcode.calculateMinimumHP(nums1) << endl;
    
    return 0;
}
