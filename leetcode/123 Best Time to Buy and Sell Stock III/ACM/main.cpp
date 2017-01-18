//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 题目大意：
 给出n个数字的数组a，a[i]表示第i天股票的价格；
 现在要求进行最多两次买卖：
 1、不考虑购买数量，利润就是价格差，要求买卖后利润最大；
 2、手上不能同时持有两次股票；
 3、买卖次数最多为两次，可以为1次。
 
 举例：
 [1,2,3,4] 利润最大是2;（只有一个选择1买、2卖、3买、4卖）
 不能买1、2，在3、4卖。
 
 
 题目解析：
 题目要求交易两次，但是两次又不能重叠。
 那么可以枚举k，[1, k]为第一次交易，[k+1, n]为第二次交易，即可解决两次交易问题。
 问题简化成在[1, k]中交易一次，求出最值。
 [1, k] 同样可以简化为[1, t]区间买，[t+1, k]区间卖。
 但是，这样的时间复杂度是O(N^2)，因为需要枚举两次区间分隔。
 实际上，这里面有很多重复的操作，比如说枚举完k之后，在枚举k+1的时候，有[1, k]区间的运算是之前求过的。
 那么，考虑预处理，把这些结果存下来。
 
 leftMax[i] 表示从左边开始，前i个的交易的最优解；
 rightMax[i] 表示从右边开始，前i个的交易的最优解；
 这样只需要枚举k即可。
 时间、空间复杂度O(n)；
 
 
 其他解法：
 动态规划。
 因为状态数非常少，直接用4个状态来表示当前状态。
 // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
 
 
 ************************* 题解 ***********************/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};
*/

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


class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> leftMax(prices.size() + 2, 0), rightMax(prices.size() + 2, 0);
        int leftMin = prices[0];
        leftMax[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            leftMax[i] = max(leftMax[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        int right = prices.back();
        rightMax[prices.size() - 1] = 0;
        for (int i = (int)prices.size() - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], right - prices[i]);
            right = max(right, prices[i]);
        }
        int ret = 0;
        
        rightMax[prices.size()] = 0;
        for (int i = 0; i < prices.size(); ++i) {
            ret = max(ret, leftMax[i] + rightMax[i + 1]);
        }
        return ret;
    }
}leetcode;



int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3, 2, 4};
    cout << leetcode.maxProfit(nums1) << endl;
    return 0;
}
