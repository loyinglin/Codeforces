//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/add-two-numbers-ii/?tab=Description
 题目大意：
 给俩个链表，节点由0~9的数字组成，分别表示两个数字；
 求出两个数字的和，以链表的形式返回。
 
 
 例如
 Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 
 7243 + 564 =7807
 
 Output: 7 -> 8 -> 0 -> 7
 
 
 题目解析：
 题目的意思很明显，就是把两个数字加起来，需要考虑进位的情况。
 因为是单向的链表，遍历后很难回溯，所以先把数字存到vec中。
 并且为了处理方便，vec的最低位存在vec的起始部分。
 于是从0开始遍历两个vec即可，注意考虑最后进位的情况。
 
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




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL;
        vector<int> vec1, vec2;
        sum(l1, vec1);
        sum(l2, vec2);
        int n = vec1.size(), m = vec2.size(), flag = 0;
        for (int i = 0; i < n || i < m; ++i) {
            int x = 0, y = 0;
            if (i < n) {
                x = vec1[i];
            }
            if (i < m) {
                y = vec2[i];
            }
            int s = x + y + flag;
            if (s > 9) {
                s -= 10;
                flag = 1;
            }
            else {
                flag = 0;
            }
            ListNode *tmp = new ListNode(s);
            tmp->next = ret;
            ret = tmp;
        }
        if (flag) {
            ListNode *tmp = new ListNode(1);
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
    
    void sum(ListNode* list, vector<int> &vec) {
        if (list->next) {
            sum(list->next, vec);
        }
        vec.push_back(list->val);
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
