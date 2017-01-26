//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/jump-game-ii/
 题目大意：
 给出一个数组，数组上的值表示能前进的距离；
 现在从pos=0的位置向右出发，问最少需要走几步才能到达终点。
 
 Example
 输入 A = [2,3,1,1,4]
 返回 2
 因为可以从pos=0走到pos=1，然后直接到达pos=4；
 
 
 题目解析：
 第一反应就是bfs，但是bfs需要每次判断距离[i+1, i+k]内的点是否访问，导致时间复杂度是O(N^2);
 这个题也可以用动态规划：
 dp[i]表示到达i的最短步数；
 那么状态方程可以写成dp[i+k]=min(dp[i+k], dp[i] + 1); k∈[1, nums(i)]
 这样对于每个i都需要去更新后面nums[i]状态，故而复杂度也是O(N^2);
 对状态转移方程稍作修改：
 dp[i] = min(dp[i], dp[k] + 1); k+num[k] >= i 且 k < i
 这样可以建一个dp[i]的优先队列，先按照步数排序，再按能到达的距离排序；
 每次从队列的顶端拿出步数最小的dp值，判断pos的有效区间是否覆盖当前位置i；
 如果不覆盖，那么对i+1必然也不覆盖，可以丢弃；
 如果覆盖，则直接dp[i]=dp[k]+1，并把(dp[i],i+nums[i])放入优先队列；
 复杂度是O(NlogN)。
 
 提交后，非常遗憾的收获TLE...
 
 仔细观察dp[i]的性质，可以得出一个结论：
 
 
 
 
 
 其他解法：
 
 
 
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
    int step, pos;
    Node() {
        step = pos = 0;
    }
    Node(int s, int p) {
        step = s;
        pos = p;
    }
    
    bool operator<(const Node &tmp) const
    {
        if (step != tmp.step) {
            return step > tmp.step;
        }
        else {
            return pos < tmp.pos;
        }
    };
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        vector<int> step(nums.size(), 0);
        queue<Node> q;
        q.push(Node(0, nums[0]));
        int maxRight = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            while (q.front().pos < i) {
                q.pop();
            }
            ret = q.front().step + 1;
            if (i + nums[i] > maxRight) {
                maxRight = i + nums[i];
                q.push(Node(ret, i + nums[i]));
            }
        }
        return ret;
    }
}lc;

/*
struct Node {
    int step, pos;
    Node() {
        step = pos = 0;
    }
    Node(int s, int p) {
        step = s;
        pos = p;
    }
    
    bool operator<(const Node &tmp) const
    {
        if (step != tmp.step) {
            return step > tmp.step;
        }
        else {
            return pos > tmp.pos;
        }
    };
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        vector<int> step(nums.size(), 0);
        priority_queue<Node> q;
        q.push(Node(0, nums[0]));
        for (int i = 1; i < nums.size(); ++i) {
            while (q.top().pos < i) {
                q.pop();
            }
            ret = q.top().step + 1;
            q.push(Node(ret, i + nums[i]));
        }
        return ret;
    }
}lc;
*/

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,1,2,3,3};
    vector<int> nums2 = {2};
    lc.jump(nums1);
    
    return 0;
}
