//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/merge-two-sorted-lists)
 **题目大意：**
 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
 示例：
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4

 
 **题目解析：**
 遍历两个链表，每次从链表中选择一个较小大数字的节点出来，直接两个链表为空；
 注意：需要考虑两个链表，部分为空或者全部为空的情况；

 
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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL, *cur = NULL;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (!cur) {
                    cur = ret = l1;
                }
                else {
                    cur->next = l1;
                }
                cur = l1;
                l1 = l1->next;
            }
            else {
                if (!cur) {
                    cur = ret = l2;
                }
                else {
                    cur->next = l2;
                }
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1) {
            if (cur) {
                cur->next = l1;
            }
            else {
                ret = cur = l1;
            }
        }
        else {
            if (cur) {
                cur->next = l2;
            }
            else {
                ret = cur = l2;
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
