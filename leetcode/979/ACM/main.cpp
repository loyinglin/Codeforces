//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/distribute-coins-in-binary-tree/
 题目大意：
 给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。

 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。

 返回使每个结点上只有一枚硬币所需的移动次数。

  

 示例 1：



 输入：[3,0,0]
 输出：2
 解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。

 
 题目解析：
 遍历二叉树，方式采用后序遍历；
 对于点x，如果孩子节点数为负数，则从点x迁移欠下的点数过去；如果孩子节点为正数，则迁移多出来的部分到点x；
 这样遍历完之后，累计迁移的代价就是最小的移动次数。
 
 
 
 
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 特殊样例：

 
 
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 class Solution {
     int ans;
     void dfs(TreeNode *node) {
         if (node->left) {
             dfs(node->left);
             ans += abs(node->left->val - 1);
             node->val += node->left->val - 1;
         }
         if (node->right) {
             dfs(node->right);
             ans += abs(node->right->val - 1);
             node->val += node->right->val - 1;
         }
     }
 public:
     int distributeCoins(TreeNode* root) {
         ans = 0;
         dfs(root);
         return ans;
     }
 }leetcode;

int main(int argc, const char * argv[]) {
    TreeNode node1(5);
    TreeNode node2(0);
    TreeNode node3(0);
    TreeNode node4(0);
    TreeNode node5(0);
    TreeNode node6(6);
    node1.left = &node2;
    node2.left = &node3;
    node3.left = &node4;
    node4.right = &node5;

    cout << leetcode.distributeCoins(&node1) << endl;
    
    
    return 0;
}
