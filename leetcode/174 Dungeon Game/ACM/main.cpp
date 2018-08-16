//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/dungeon-game/
 题目大意：
 n*m的网格，每个网格有一个数字，要从左上角到右下角（只能向右或者向左）；
 起始点是左上角，并且初始状态有个体力值，每次经过网格时体力值会发生该网格上数字的变化：
 如果是数字是x，那么体力值Hnew = Hold + x;
 问最少需要多少体力值，才能保证从左上角到右下角，体力值不小于1；
 
 题目解析：
 题目的意思可以理解为：求左上到右下的路径数字和最大；
 这是一个经典的动态规划，注意点1：如果和是正整数，那么体力值为1即可。
 
 但是，一个hard题目是否这么简单呢？
 这种做法忽略了一种情况：题目要求保证路径上，体力值一直不小于1。
 即使求出来的路径和是正整数，路上仍旧可能出现负数的情况。
 
 对题目进行思考，发现体力值符合线性特征：
 如果体力值H可行，那么体力值H+1必然也可以。
 
 于是改用二分，对每个二分的体力值我们判断其是否通过。
 
 canPass的思路就是：在n*m的网格中，遍历所有能到达的点，看是否能到达右下角；
 时间复杂度是O(N * M * logK) K为数字最大值，N、M为行列数量。
 
 
 **思考：**
 这里，其实还是可以用动态规划来解决，核心就是：逆序。
 假设到达右下角的体力值是1，在此基础上从右下往左上dp，保持状态转移过程中体力值不小于1即可。
 
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
