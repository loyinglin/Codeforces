//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/permutations/description/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china)
 题目大意：
 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 示例 1：
 输入：nums = [1,2,3]
 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 示例 2：
 输入：nums = [0,1]
 输出：[[0,1],[1,0]]
 示例 3：
 输入：nums = [1]
 输出：[[1]]

 提示：
 1 <= nums.length <= 6
 -10 <= nums[i] <= 10
 nums 中的所有整数 互不相同


 题目解析：
 只要完成1到n的全排列，那么输出的时候把1到n换成数组元素nums[1]到nums[n]就可以得到全排列；
 全排列的做法：
 深度优先遍历（DFS），1、2、3、、、n，每个数字有取和不取的选择；
 因为数字不相同，所以不会出现不一致的情况；（每一位至少存在不一样的数字）
 用递归更容易实现。 
 
 
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
public:
    int vis[N];
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        memset(vis, 0,  sizeof(int) * nums.size());
        vector<int> tmp;
        look(ans, nums, tmp, 0);
        return ans;
    }
    
    void look(vector<vector<int> > &ans, vector<int> &num, vector<int> &tmp, int count) {
        if (count == num.size()) {
            ans.push_back(tmp);
            return ;
        }
        int id;
        for (id = 0; id < num.size(); ++id) {
            if (!vis[id]) {
                vis[id] = 1;
                tmp.push_back(num[id]);
                look(ans, num, tmp, count + 1);
                tmp.pop_back();
                vis[id] = 0;
            }
        }
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {5,7,8,4};
    
    leetcode.permute(nums1);
    
    return 0;
}
