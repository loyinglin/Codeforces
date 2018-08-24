//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/3sum/description/
 题目大意：
 给出一个数组nums，数组包括n个整数（可能有重复）；
 现在需要从数组中选择三个数a、b、c，使得a+b+c=0；
 输出所有可能性的组合；（重复的只输出一次）
 
 
 题目解析：
 题目的难点不在于满足a+b+c=0，而是在于去重；
 因为题目数据包括重复，先排序，得到有序的数组；
 接着对于每个数字nums[i]，从(i+1, n)区间选出两个数字x，y使得nums[i]+x+y=0；
 容易知道，随着x的增大，y会不断变小；那么从i+1开始向右选择x，从n开始向左选择y，可以在O(N)的复杂度内遍历完所有组合；
 
 
 优化思路：
 
 
 复杂度解析：
 时间复杂度
 
 空间复杂度
 
 代码量
 
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
#include <list>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  ret;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int i = 0;
        while (i < n) {
            int x = i + 1;
            int y = n - 1;
            while (x < y) {
                int sum = nums[i] + nums[x] + nums[y];
                if (sum == 0) {
                    vector<int> tmp = {nums[i], nums[x], nums[y]};
                    ret.push_back(tmp);
                    while (x < n) {
                        ++x;
                        if (tmp[1] != nums[x]) {
                            break;
                        }
                    }
                }
                else if (sum < 0) {
                    ++x;
                }
                else { // sum > 0
                    --y;
                }
            }
            
            while (i < n) {
                ++i;
                
                if (nums[i] != nums[i - 1]) break;
            }
        }
        
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    
    vector<int> test = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = leetcode.threeSum(test);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
