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
 题目可以分解为两个子问题：
 1、找到整数a、b、c，使得a+b+c=0；
 2、重复的a、b、c只输出一次；
 
 子问题1同样可以分解为两个问题：1、找到两个整数a、b，判断c=-a-b的数字是否存在；
 那么可以用两个for循环确定a、b，再用一个for循环判断c=-a-b是否存在；
 复杂度较高，但是可以解决，考虑子问题2；
 子问题2可以通过缓存已经存在的解，每次进行遍历匹配解决；
 至此，我们有一个不太优化的解决方案。
 
 优化思路：
 a、b、c重复因为有a+b+c=0的条件，只要a、b相同，则c必然相同；
 那么可以先对数组nums排序，得到有序的数组；
 接着对于每个数字nums[i]，从[i+1, n]区间选出两个数字x和y(x<y)，使得nums[i]+x+y=0；（a=nums[i], b=x, c=y）
 可以知道，随着x的增大，y会不断变小；那么从i+1开始向右选择x，从n开始向左选择y，可以在O(N)的复杂度内遍历完所有组合；
 当枚举完a=nums[i]的可能后，令a=nums[k]，k>i并且nums[k]!=nums[i]，这样也可以在O(N)的复杂度内遍历完a的所有可能；
 总的时间复杂度是O(N^2)；
 
 
 
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
