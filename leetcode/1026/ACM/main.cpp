//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/)
 **题目大意：**
 给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
 （如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

 示例 1：
 输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
 输出：7
 解释：
 我们有大量的节点与其祖先的差值，其中一些如下：
 |8 - 3| = 5
 |3 - 7| = 4
 |8 - 1| = 7
 |10 - 13| = 3
 在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
 
 提示：
 树中的节点数在 2 到 5000 之间。
 0 <= Node.val <= 1e5
 
 **题目解析：**
 根据题目的要求，要找到两个有父子关系的节点，然后另他们之间的差尽可能大；
 首先简化题目要求，假设不是一棵树，而是一条直线上的若干个节点，我们要如何找到任意两个节点，使其绝对差尽可能大？
 最直接的做法，我们可以枚举任意两个节点，这样的复杂度是O(N^2)；
 但是这样效率太低，我们可以从左到右遍历，记录最小值和最大值，最终用最大值减去最小值就可以得到最大的差值，这样的复杂度是O(N)；
 同理，当问题由一条线变成一棵树时，我们同样只要遍历整个树，在过程中不断更新当前节点到根节点这一条线中的最大值和最小值，这样就能快速得到最大的差值；

 
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
const int N = 50000;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int ans;
    void dfs(int maxVal, int minVal, TreeNode* curNode) {
        maxVal = max(maxVal, curNode->val);
        minVal = min(minVal, curNode->val);
        ans = max(ans, maxVal - minVal);
        if (curNode->left) dfs(maxVal, minVal, curNode->left);
        if (curNode->right) dfs(maxVal, minVal, curNode->right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        dfs(root->val, root->val, root);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
