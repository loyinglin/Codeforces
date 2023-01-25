//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/two-city-scheduling/description/)
 **题目大意：**
 公司计划面试 2n 人。给你一个数组 costs ，其中 costs[i] = [aCosti, bCosti] 。第 i 人飞往 a 市的费用为 aCosti ，飞往 b 市的费用为 bCosti 。
 返回将每个人都飞到 a 、b 中某座城市的最低费用，要求每个城市都有 n 人抵达。

 示例 1：
 输入：costs = [[10,20],[30,200],[400,50],[30,20]]
 输出：110
 解释：
 第一个人去 a 市，费用为 10。
 第二个人去 a 市，费用为 30。
 第三个人去 b 市，费用为 50。
 第四个人去 b 市，费用为 20。

 最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
 
 提示：
 2 * n == costs.length
 2 <= costs.length <= 100
 costs.length 为偶数
 1 <= aCosti, bCosti <= 1000

 **题目解析：**
 如果不考虑复杂度，可以直接使用搜索的方式，每个人有2个选择，总共会有2^2n种选择，这个复杂度明显超过题目限制；
 注意到每个人有2个选择，那么用dp[i][j]来表示前i个人，有j个选择a城市的最小费用，对于第i个人：
 如果第i个人选择a城市，那么有dp[i][j]=dp[i-1][j-1] + aCost[i]；
 如果第i个人选择b城市，那么有dp[i][j]=dp[i-1][j] + bCost[i];
 
 总的复杂度是O(N^2)；
 
 **思考：**
 
 
 
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
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


struct Node {
    int first, second;
    Node(){}
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator < (const Node tmp) const {
        if (first != tmp.first) {
            return first > tmp.first;
        }
        else {
            return second > tmp.second;
        }
    }
};

typedef long long lld;
const int N = 50000;

class Solution {
    int dp[110][110];
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + costs[i-1][1]; // bCost[i]
            dp[i][i] = dp[i - 1][i - 1] + costs[i-1][0]; // aCost[i]
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1] + costs[i - 1][0], dp[i - 1][j] + costs[i - 1][1]);
            }
        }
        return dp[n][n/2];
    }
}ac;

int main(int argc, const char * argv[]) {
    vector<vector<int> > nums1 = {{10, 20},{30, 200},{400, 50},{30, 20}};
    vector<vector<int> > nums2 = {{1, 2},{3, 4},{7, 8},{11, 9},{20, 2},{1, 10}};
    ac.twoCitySchedCost(nums2);
    
    return 0;
}
