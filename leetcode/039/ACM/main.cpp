//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/combination-sum/description/
 题目大意：
 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

 candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

 
 
 题目解析：
 题目要找出所有组合，并且一个数字可以无限选，那么可以用这样的枚举方式：
 初始化状态，curTarget=target，记录剩下的数字和；
 对于数字a[0]，不断选择从curTarget减去a[0]，直到curTarget<=0截止；
 此时再恢复一个a[0]，curTarget+=a[0]，然后同样方式枚举a[1]、a[2]...
  
 DFS的方式，中间curTarget=0则表示出现一个解，当前栈数字就是答案。
 
 
 
 复杂度解析：
 
 
 
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
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        while (!ans.empty()) {
            ans.pop_back();
        }
        dfs(cur, candidates, 0, target);
        return ans;
    }
    
    void dfs(vector<int> &cur, vector<int>& candidates, int index, int left) {
        if (left == 0) {
            ans.push_back(cur);
            return ;
        }
        if (index >= candidates.size()) {
            return ;
        }
        if (left >= candidates[index]) {
            cur.push_back(candidates[index]);
            dfs(cur, candidates, index, left - candidates[index]);
            cur.pop_back();
        }
        dfs(cur, candidates, index + 1, left);
    }
    
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {5,7,8,4};
    
    leetcode.combinationSum(nums1, 20);
    
    return 0;
}
