//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/last-stone-weight/)
 **题目大意：**
 有一堆石头，每块石头的重量都是正整数。

 每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

 如果 x == y，那么两块石头都会被完全粉碎；
 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

  
 示例：
 输入：[2,7,4,1,8,1]
 输出：1
 解释：
 先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
 再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
 接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
 最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
  

 提示：
 1 <= stones.length <= 30
 1 <= stones[i] <= 1000
 
 
 **题目解析：**
 模拟题目操作，用优先队列，每次取出头部两个元素进行操作，如果元素不相同则把石头差放回队列。
  
 
 
 
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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int i = 0; i < stones.size(); ++i) q.push(stones[i]);
        while (q.size() >= 2) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            if (first - second) q.push(first - second);
        }
        return q.empty() ? 0 : q.top();
    }
}ac;

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {83,20,17,43,52,78,68,45};
    vector<int > nums2 = {1,2,3,4};
    cout << ac.lastStoneWeight(nums1) << endl;
    
    return 0;
}
