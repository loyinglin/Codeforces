//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/binary-tree-maximum-path-sum/
 题目大意：
 给出一颗二叉树，每个节点有权值；
 求出权值和最大的路径，输出路径的权值和。
 
 例如，给出这样一棵树：
 
  1
 / \
2   3
 
 输出6。
 
 题目解析：
 对于一个节点x，假设两个儿子为left[x]、right[x]，父亲节点为fat[x];
 那么对于x，包含x的路径可能是
 单独一个点x；
 left + x;
 right + x;
 fat + x;
 left + x + right;
 left + x + fat;
 right + x + fat;
 
 为了实现方便，可以对left、right、fat、0、0排序，取前两个和x合并即可；
 提示： 
 left + x   = left + x + 0;
 right + x  = right + x + 0;
    x       = 0 + x + 0;
 时间复杂度O(N)，空间复杂度O(N);
 
 其他解法：
 都需要遍历树，而遍历树的复杂度不会低于O(N);
 
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
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        dfs(root, 0);
        return ans;
    }
    
    int dfs(TreeNode *node, int fat) {
        int ret = 0;
        int a[5] = {0}, curFat = 0, x = node->val;
        a[0] = fat;
        if (node->val + fat >= 0) {
            curFat = fat + x;
        }
        if (node->left) {
            a[1] = dfs(node->left, curFat);
        }
        if (node->right) {
            a[2] = dfs(node->right, curFat);
        }
        ret = max(ret, a[1] + x);
        ret = max(ret, a[2] + x);
        sort(a, a + 5);
        ans = max(ans, a[3] + a[4] + node->val);
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
