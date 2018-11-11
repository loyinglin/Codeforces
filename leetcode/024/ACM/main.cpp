//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/swap-nodes-in-pairs/description/
 题目大意：
 给出一个链表，要求每两个节点做一次节点交换，如果是奇数链表，最后一个节点不用交换；
 比如说给出1->2->3->4，要求结果是2->1->4->3；
 要求：
 1、常数的空间大小；
 2、不允许修改链表节点的值，只能修改其next指针；
 
 题目解析：
 假如是数组交换，那么就是a[1]=a[2]这样直接交换即可；
 如果允许值修改，同样可以用上面的方案，但这里要求交换节点；
 
 先看直接交换节点的情况：对于节点1和2，直接交换next指针，变成2，1，此时链表是2->1->3->4->NULL;
 接着重复上面的过程交换3，4，变成4，3，链表是4->3->NULL，但是此时链表并不是2134；
 注意看前面1、2交换后，此时1指向3；当3，4交换完之后，链表就是2-1>3->NULL！
 这是题目的第一个trick，解决方案有两种：
 1、从倒数开始交换；
 2、新增last指针，在每次交换后记录后一个节点，在下一次交换时修改值；比如说在1，2交换后last=1；在交换3，4后，让last->next=4即可；
 
 方案2实现较为简单，增加一个临时变量即可。
 
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = head;
        if (head && head->next) { // null trick
            ret = head->next;
        }
        ListNode *last = NULL;
        while (head && head->next) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            // update last
            if (last && last->next) { // null trick
                last->next = tmp;
            }
            last = head;
            
            head = head->next;
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
