//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/all-oone-data-structure/
 题目大意：
 实现一个数据结构，要求：
 1、Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
 2、Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
 3、GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
 4、GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
 
 要求所有的数据结构的时间复杂度是O(1);
 
 题目解析：
 在不考虑复杂度的前提下，朴素做法是遍历，O(N);
 简单的优化，用map来维护优先队列，操作1、2先获取key值，更新完重新插入；操作3、4直接拿队列top；每个操作的复杂度是O(LogN);
 
 题目要求是O(1)，那么必然不能使用树类型的结构，应该利用题目特性，配合hash以及贪心来实现。
 
 假设有一个key-hash表，来存key的对应值。
 操作1、先看keyHash里面是否有key，有则+1，无则插入；
 操作2、先看keyHash里面是否有key，有则-1，无则Nothing；
 
 为了维护最值，引入链表list，里面所有的元素是从小到大；每个元素是一个桶，桶里放着值相同的key；
 操作3、直接获取list头元素的值；
 操作4、直接获取list尾元素的值；
 
 同时，操作1、2在操作的过程中，需要把当前key值从list对应的桶里移除，放到上一个或者下一个桶里，或者丢弃。
 为了实现O(1)获取key所在位置，可以用iter-hash来维护key所对应元素的迭代器。
 
 
 RE代码。代码略复杂， 对stl的迭代不太熟悉。
 
 复杂度解析：
 
 
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
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


class AllOne {
public:
    list<list<pair<string, int>> > bucketList;
    unordered_map<string, list<pair<string, int>>::iterator> iterHash;
    unordered_map<string, list<list<pair<string, int>>>::iterator> bucketHash;
    unordered_map<int, int> bucketCount;
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (iterHash.find(key) == iterHash.end()) { // 新的key
            if (bucketList.empty()) { // 没有任何桶，新建一个桶放到列表
                list<pair<string, int>> bucket;
                bucket.push_back(make_pair(key, 1));
                bucketList.push_back(bucket);
                iterHash[key] = bucket.begin();
                bucketHash[key] = bucketList.begin();
            }
            else {
                if (bucketList.begin()->begin()->second == 1) {// 第一个桶的元素为1，直接放入桶中
                    bucketList.begin()->push_front(make_pair(key, 1));
                    iterHash[key] = bucketList.begin()->begin();
                    bucketHash[key] = bucketList.begin();
                }
                else { // 第一个桶不为1，新 建一个桶1
                    list<pair<string, int> > bucket;
                    bucket.push_back(make_pair(key, 1));
                    bucketList.push_back(bucket);
                    iterHash[key] = bucket.begin();
                    bucketHash[key] = bucketList.begin();
                }
            }
            ++bucketCount[1];
        }
        else {
            pair<string, int> value = *iterHash[key];
            ++value.second;
            list<list<pair<string, int>>>::iterator iter = bucketHash[key];
            list<list<pair<string, int>>>::iterator tmpIter = iter;
            iter->erase(iterHash[key]); // 从原来的桶移除
            ++iter;
            if (iter == bucketList.end()) { //没有新的list来接受
                list<pair<string, int>> bucket;
                bucket.push_back(value);
                bucketList.push_back(bucket);
                iterHash[key] = bucket.begin();
                bucketHash[key] = --bucketList.end();
            }
            else {
                iter->push_front(value);
                iterHash[key] = iter->begin();
                bucketHash[key] = iter;
            }
            
            ++bucketCount[value.second];
            // 删除空的桶
            if (--bucketCount[value.second-1] == 0) {
                bucketList.erase(tmpIter);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (iterHash.find(key) == iterHash.end()) {
            return ;
        }
        else {
            pair<string, int> value = *iterHash[key];
            --value.second;
            list<list<pair<string, int>>>::iterator iter = bucketHash[key];
            list<list<pair<string, int>>>::iterator tmpIter = iter;
            iter->erase(iterHash[key]);
            if (value.second == 0) {
                iterHash.erase(key);
            }
            if (iter == bucketList.begin()) {
                list<pair<string, int>> bucket;
                bucket.push_back(value);
                bucketList.push_front(bucket);
                iterHash[key] = bucket.begin();
                bucketHash[key] = bucketList.begin();
            }
            else {
                --iter;
                iter->push_front(value);
                iterHash[key] = iter->begin();
                bucketHash[key] = iter;
            }
            
            ++bucketCount[value.second];
            // 删除空的桶
            if (--bucketCount[value.second - 1] == 0) {
                bucketList.erase(tmpIter);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        string ret;
        if (!bucketList.empty()) {
            ret = bucketList.back().back().first;
        }
        return ret;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        string ret;
        if (!bucketList.empty()) {
            ret = bucketList.front().front().first;
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    leetcode.inc(string("hello"));
    leetcode.inc(string("hello"));
    leetcode.inc(string("leet"));
    leetcode.inc(string("code"));
    cout << leetcode.getMaxKey() << endl;
    cout << leetcode.getMinKey() << endl;
    
    
    
    return 0;
}
