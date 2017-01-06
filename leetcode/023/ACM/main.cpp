//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/merge-k-sorted-lists/
 题目大意：
 Merge k Sorted Lists
 给出k个有序的链表，把k个链表合并一个有序链表
 
 题目解析：
 轮询，每次从链表中取出最小的一个值；
 复杂度O（N*M）N是所有节点的数量和，M是链表数量；
 
 收获一枚TLE;
 增加一个优先队列的优化，每次取出一个值的时候，把上一个值添加到优先队列里；
 复杂度O(N*LogM)。
 
 
 在priority_queue中结构体指针的比较函数卡顿了很久，不需要引用。
 其实除了struct的方式，还可以用
 bool operator < (Node *a,Node *b){
 return a->weight < b->weight;
 }
 直接写在外面。
 
 
 
 这个题还有另外的一种思路：
 每次只合并两个链表；（这样就不用每次轮询判断M条链）
 然后用归并，这样也能极快的合并完k条链。
 
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


typedef long long lld;
const int N = 50000, inf = 0x3ffffff;


struct cmp {
    bool operator () (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL, *cur = NULL;
        priority_queue<ListNode*, vector<ListNode *>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            if (top->next) {
                q.push(top->next);
            }
            if (cur) {
                cur->next = top;
                cur = cur->next;
            }
            else {
                ret = cur = top;
                cur->next = NULL;
            }
        }
        
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    node1->next = node2;
    node2->next = node3;
    vector<ListNode *> vt = {node1};
    leetcode.mergeKLists(vt);
    
    return 0;
}
