//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/largest-sum-of-averages/)
 **题目大意：**
 给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个相邻的非空子数组 。 分数由每个子数组内的平均值的总和构成。
 注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。
 返回我们所能得到的最大 分数 是多少。答案误差在 10-6 内被视为是正确的。

 示例 1:
 输入: nums = [9,1,2,3,9], k = 3
 输出: 20.00000
 解释:
 nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
 我们也可以把 nums 分成[9, 1], [2], [3, 9].
 这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
 
 示例 2:
 输入: nums = [1,2,3,4,5,6,7], k = 4
 输出: 20.50000
  

 提示:
 1 <= nums.length <= 100
 1 <= nums[i] <= 104
 1 <= k <= nums.length


 **题目解析：**
 题目的分数是由平均值计算，我们以[1,2,3,4]这4个数字的数组来看看分数的计算：
 1234
 分成[123],[4]=2+4=6
 [12],[34]=1.5+3.5=6
 [1],[234]=1+3=4
 容易知道越小的数字单独一组收益越低，越大的数字单独一组收益越高，并且理论最大值应该改1+2+3+4=10。
 基于此，我们容易知道可以用dp[i][j]，来表示前i个数字分为j组的最大分数。
 对于数字a[i]，有两种选择：并入前面的分组，或者新增分组；
 并入分组的情况，对于k∈[1, i - 1] dp[i][j]=max(dp[i][j], dp[k][j-1]+sum(k+1, i)/(i-k) )；
 新增分组的情况，dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i])；
 其中新增分组的情况，就是k=i-1的情况。
 状态转移复杂度O(N)，状态数O(N^2)，总的复杂度是O(N^3);
 
 
 
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
const int N = 110;

class Solution {
    double dp[N][N];
public:
    double largestSumOfAverages(vector<int>& nums, int m) {
        auto n = nums.size();
        vector<double> sum;
        sum.push_back(0);
        for (int i = 0; i < n; ++i) sum.push_back(sum.back() + nums[i]);
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = sum[i];
            dp[i][1] = sum[i] / i;
            for (int j = 2; j < i; ++j) {
                dp[i][j] = 0;
                for (int k = i - 1; k > 0; --k) {
                    // 对于k∈[1, i - 1] dp[i][j]=max(dp[i][j], dp[k][j-1]+sum(k+1, i)/(i-k) )；
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) / (i - k));
                }
                
                cout << i << " " << j << "  " << dp[i][j] << endl;
            }
        }
        
        return dp[n][m];
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {9,1,2,3,9};
    vector<int> nums2 = {1,2,3,4,5,6,7};
    
    cout << leetcode.largestSumOfAverages(nums1, 3) << endl;
    
    cout << leetcode.largestSumOfAverages(nums2, 4) << endl;
    
    return 0;
}
