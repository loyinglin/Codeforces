//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 题目大意：给出一个链表，删除链表的倒数第n个节点，然后返回链表的头指针。
 Example:
 给出链表 1->2->3->4->5, and n = 2.
 操作后的链表 1->2->3->5.
 
 题目解析：
 这里可以分解两个子问题：
 1、找到链表倒数第n个点；
 2、在链表中删除一个节点；
 
 问题1可以先遍历指针得到节点个数sum，这样可以得到删除的节点为正数的第sum-n+1个节点；
 问题2是标准问题，注意next指针的特殊处理；
 
 这里有个trick，如果删除的节点是第一个节点，此时应该返回head->next的节点；
 其他情况，类似 1->3->x->4->6，这样的链表，删除中间x点，只需要找到x的上一个节点，使得其next等于x的下一个节点即可。
 
 
 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        int count = 1;
        while (tmp->next) {
            tmp = tmp->next;
            ++count;
        }
        int x = count - n + 1;
        
        ListNode *ret = head;
        if (x == 1) {
            ret = head -> next;
        }
        else {
            tmp = head;
            while (x > 2) {
                --x;
                tmp = tmp->next;
            }
            if (tmp->next) {
                tmp->next = tmp->next->next;
            }
            else {
                tmp->next = NULL;
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
