//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/binary-tree-cameras/
 题目大意：
 给定一个二叉树，我们在树的节点上安装摄像头。

 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

 计算监控树的所有节点所需的最小摄像头数量。

 
 题目解析：
 贪心，从叶子节点开始，尽可能往上去放摄像机；
 更具体的描述，每个点有3个状态，0表示初始状态，1表示放置了摄像机，2表示没有放置摄像机，但是在影响范围内；
 对于某一个点，假设其左孩子是left，右孩子是right；
 如果left和right中有一个为状态0，则该点必须放置摄像机，设置状态为1；（包括0+0, 0+1, 0+2, 1+0，2+0共5种状态）
 如果left和right中有一个点为状态1，则该点可以不用放置摄像机，设置为状态2；（包括1+1，1+2，2+1共3种状态）
 如果left和right都为状态2，则看如果看是否有父节点，如果没有父节点，则必须放置摄影机，设置状态为1；有父节点则设置状态为0，由父节点来设置摄影机；（包括状态2+2共1种状态）
 
 为了实现上述的判断，遍历方式必须采用后序遍历。
 
 
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
    void dfs(TreeNode *node, TreeNode *parent, int &sum) {
        if (node->left) {
            dfs(node->left, node, sum);
        }
        if (node->right) {
            dfs(node->right, node, sum);
        }
        if ((node->left && node->left->val == 0) || (node->right && node->right->val == 0)) {
            node->val = 1;
            ++sum;
        }
        else if ((node->left && node->left->val == 1) || (node->right && node->right->val == 1)) {
            node->val = 2;
        }
        else {
            if (parent) {
                node->val = 0;
            }
            else {
                node->val = 1;
                ++sum;
            }
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int ret = 0;
        dfs(root, NULL, ret);
        
        return ret;
    }
}leetcode;

int main(int argc, const char * argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    node1.left = &node2;
    node2.left = &node3;
    node3.left = &node4;
    node4.right = &node5;

    cout << leetcode.minCameraCover(&node1) << endl;
    
    
    return 0;
}
