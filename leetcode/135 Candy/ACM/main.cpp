//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/candy/
 题目大意：
 n个人排成一行，每个人有一个rating的数值。
 现在给所有人分配糖果，要求：
 1、每个人至少有一个；
 2、rating比身边人高的分配到更多的糖果。
 问最少需要多少糖果。
 
 题目解析：
 假设所有人rating一致，那么需要n个糖果；
 如果有一人rating更高，那么需要n+1；
 如果有2人rating更高，则看两个人是否相邻，需要n+2或n+3个糖果；
 以此，可以得出一种分配方案：
 从最小的rating值开始分配，每次观看旁边的人是否有糖果：
 如果身边人有糖果，则分配max(左边, 右边) + 1；
 如果身边人没有糖果，则分配1；
 时间复杂度为O(NLogN)，排序耗时。
 
 收获一枚TLE；
 那么对算法进行优化。
 根据分配糖果的条件2，我们知道在一个单调递增中：（单调递减可以逆着看，就是单调递增）
 分配的结果是1、2、3、4、5这样的序列；
 那么，一个数组可以分成多个单调递增的序列；
 然后反着遍历，找到单调递减的序列；
 剩下的部分可以全部填1。
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 
 
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




class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = max(ans[i], ans[i - 1] + 1);
            }
        }
        for (int i = (int)ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }
        for (int i = 0; i < ratings.size(); ++i) {
            ret += ans[i];
        }
        return ret;
    }
}leetcode;
/*
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


class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        vector<int> ans(ratings.size() + 2, 0);
        priority_queue<Node> q;
        for (int i = 0; i < ratings.size(); ++i) {
            q.push(Node(ratings[i], i + 1));
        }
        while (!q.empty()) {
            Node top = q.top();
            q.pop();
            int id = top.second - 1;
            ans[id] = 1;
            if (id > 0 && ratings[id] > ratings[id - 1]) {
                ans[id] = max(ans[id], ans[id - 1] + 1);
            }
            if (id + 1 < ratings.size() && ratings[id] > ratings[id + 1]) {
                ans[id] = max(ans[id], ans[id + 1] + 1);
            }
//            cout << top.second << " " << ans[id] << endl;
            ret += ans[id];
        }
        return ret;
    }
}leetcode;
*/

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3, 3, 3, 1};
    vector<int> nums2 = {0};
    cout << leetcode.candy(nums2);
    return 0;
}
