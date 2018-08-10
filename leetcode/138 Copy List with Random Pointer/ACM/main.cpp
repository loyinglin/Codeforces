//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/copy-list-with-random-pointer/
 题目大意：
 给出一个链表RandomListNode *next, *random;
 每个节点有int值，有两个指针，一个指向下一个节点，一个指向链表的任意节点；
 现在实现一个深度复制，复制节点的next、random、还有int值；
 
 
 
 题目解析：
 要求的是复制所有的值，其中的next、int是常规值，遍历一遍赋值即可；
 较为复杂的是random指针的复制，random指针有可能指向上一个节点，也可能指向下一个节点，在赋值的时候要保持对应的关系；
 这里可以用hash解决，我们把旧链表和新链表的节点一一对应，比如说oldList[i]=>newList[i]；
 那么如果random指针指向oldList[i]，相当于新链表指向newList[i]；
 
 
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


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *ret = NULL;
        RandomListNode *p = head;
        unordered_map<RandomListNode *, RandomListNode *> hashMap;
        while (p) {
            RandomListNode *node = new RandomListNode(p->label);
            hashMap[p] = node;
            if (ret) {
                ret->next = node;
            }
            ret = node;
            p = p->next;
        }
        p = head;
        ret = hashMap[head];
        while (p) {
            if (p->random) {
                ret->random = hashMap[p->random];
            }
            p = p->next;
            ret = ret->next;
        }
        return hashMap[head];;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
