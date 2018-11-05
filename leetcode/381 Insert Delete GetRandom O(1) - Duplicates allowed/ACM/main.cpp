//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
 题目大意：
 实现一个数据结构，包括以下三个方法：
 1、insert(val): 插入一个数字；
 2、remove(val): 移除一个数字；
 3、getRandom: O(1)随机返回一个数字；
 
 Example
 插入数字1；
 collection.insert(1);
 插入数字1：
 collection.insert(1);
 插入数字2
 collection.insert(2);
 随机返回数字，要求 2/3可能返回1， 1/3可能返回2；
 collection.getRandom();

 
 题目解析：
 插入和移除数字不麻烦，考虑如何在O(1)时间返回一个数字。
 容易知道，放在数组里面可以，然后随机返回一个位置可以实现。
 增加可以在数组最末端增加；
 删除数组中间某个数字时，可以把最末端的数字放到删除的位置上；
 
 现在的问题是，如何快速找到数组中该删除的某个位置；
 考虑用hash来实现。
 数组就是vector<pair<int, int> >; first存val，second存出现次数；
 再用一个哈希map，unordered_map<int, vector<int>> 里面存对应数字出现的位置；
 
 
 复杂度解析：
 时间复杂度
 
 空间复杂度
 
 代码量
 
 
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


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = hashMap.find(val) == hashMap.end();
        hashMap[val].push_back(randVec.size());
        randVec.push_back(make_pair(val, hashMap[val].size() - 1));
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool ret = hashMap.find(val) != hashMap.end();
        if (ret) {
            auto last = randVec.back();
            hashMap[last.first][last.second] = hashMap[val].back();
            randVec[hashMap[val].back()] = last;
            hashMap[val].pop_back();
            if (hashMap[val].empty()) {
                hashMap.erase(val);
            }
            randVec.pop_back();
        }
        return ret;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return randVec[rand() % randVec.size()].first;
    }
    
private:
    unordered_map<int, vector<int>> hashMap;
    vector<pair<int, int>> randVec;
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
