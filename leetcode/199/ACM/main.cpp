//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/binary-tree-right-side-view/
 题目大意：给出一颗二叉树，找出每个深度最右边的节点。
 
 题目解析：
 右边优先的深度遍历，保证每次是最右边；
遍历的时候加入深度这一个变量，判断当前深度是否存在节点即可。 
 
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
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 1001000, M = 3010100, inf = 0x7fffffff;

char str[N * 2];
int Right[5];

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root) {
            dfs(root, ret, 0);
        }
        return ret;
    }
    
    void dfs(TreeNode* root, vector<int> &ret, int dep) {
        if (ret.size() <= dep) {
            ret.push_back(root->val);
        }
        if (root->right) {
            dfs(root->right, ret, dep + 1);
        }
        if (root->left) {
            dfs(root->left, ret, dep + 1);
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...

    
    return 0;
}
