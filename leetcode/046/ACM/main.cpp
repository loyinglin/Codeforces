//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/permutations/description/
 题目大意：
 
 
 题目解析：
 
 dfs，每个数字有和不取的选择；
 因为数字不相同，所以不会出现不一致的情况；（每一位至少存在不一样的数字）
 递归实现，更加简单；
 
 
 
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
