//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解*********************
 [题目链接](https://leetcode.com/problems/add-two-numbers/description/)
 **题目大意：**
 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807

 **题目解析：**
 经典面试题。
 用链表加法，注意进位的考虑，以及边界情况。

 ```
 
 ```
 
 **思考：**
 
 
 
************************ 题解**********************/
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


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* node1, ListNode* node2) {
        if (!node1) {
            return node2;
        }
        if (!node2) {
            return node1;
        }
        ListNode *cur = NULL, *head = NULL;
        int addition = 0;
        while (node1 || node2) {
            int sum = addition;
            addition = 0;
            if (node1) {
                sum += node1->val;
                node1 = node1->next;
            }
            if (node2) {
                sum += node2->val;
                node2 = node2->next;
            }
            if (sum >= 10) {
                ++addition;
                sum -= 10;
            }
            if (!cur) {
                cur = new ListNode(sum);
                head = cur;
                cur->next = NULL;
            }
            else {
                cur->next = new ListNode(sum);
                cur = cur->next;
                cur->next = NULL;
            }
        }
        if (addition) {
            cur->next = new ListNode(addition);
            cur = cur->next;
            cur->next = NULL;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
