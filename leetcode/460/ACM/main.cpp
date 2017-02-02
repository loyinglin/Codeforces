//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/lfu-cache/
 题目大意：
 实现最近最不经常使用算法。如果有相同的使用频率，保留最近使用的（put操作不算使用）。
 要求，get、put操作O（1）实现；
 
 ```
 LFUCache cache = new LFUCache(2);
 cache.put(1, 1);
 cache.put(2, 2);
 cache.get(1);       // returns 1
 cache.put(3, 3);    // evicts key 2
 cache.get(2);       // returns -1 (not found)
 cache.get(3);       // returns 3.
 cache.put(4, 4);    // evicts key 1.
 cache.get(1);       // returns -1 (not found)
 cache.get(3);       // returns 3
 cache.get(4);       // returns 4
 ```
 
 题目解析：
 put操作先考虑key是否存在：
 1、key存在，直接更新key值；
 2、key不存在， 如果cache没满，直接放入cache；
 如果当前cache已满，去掉最不经常使用的key，再把key放入cache；
 
 
 get操作考虑key是否存在：
 1、key存在，返回key对应的值，并+1最近使用频率；
 key不存在，返回-1；
 
 如果使用朴素实现，list来存(key, value)对，并且在需要更新时直接去掉list节点，重新查找插入位置；
 每次的操作复杂度都是O(N)，并不符合要求。
 
 优化思路：
 耗时在于查找key值和插入key值；
 因为每次
 
 
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
#include <list>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

class LFUCache {
public:
    int cap, curSize, minFreq; // cap是容量，curSize是当前大小，minFreq是最小的使用频率
    unordered_map<int, pair<int, int> > keyMap; // key = <value, freq>
    unordered_map<int, list<int>::iterator> iterMap; // 对应key的list迭代器，用于快速获得值
    unordered_map<int, list<int> > freqMap; // 使用频率是map
    LFUCache(int capacity) {
        cap = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyMap.count(key) == 0) {
            return -1;
        }
        freqMap[keyMap[key].second].erase(iterMap[key]);
        ++keyMap[key].second;
        freqMap[keyMap[key].second].push_back(key);
        iterMap[key] = --freqMap[keyMap[key].second].end();
        
        if (freqMap[minFreq].size() == 0) {
            ++minFreq;
        }
        return keyMap[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) {
            return ;
        }
        int storgeValue = get(key);
        if (storgeValue != -1) {
            keyMap[key].first = value;
            return ;
        }
        if (curSize >= cap) {
            keyMap.erase(freqMap[minFreq].front());
            iterMap.erase(freqMap[minFreq].front());
            freqMap[minFreq].pop_front();
            --curSize;
        }
        keyMap[key] = make_pair(value, 1);
        freqMap[1].push_back(key);
        iterMap[key] = --freqMap[1].end();
        minFreq = 1;
        ++curSize;
    }
}leetcode(3);


int main(int argc, const char * argv[]) {
    leetcode.put(1, 1);
    leetcode.put(2, 2);
    leetcode.put(3, 3);
    leetcode.put(1, 1);
    leetcode.put(4, 4);
    cout << leetcode.get(1) << endl;
    cout << leetcode.get(2) << endl;
    cout << leetcode.get(3) << endl;
    cout << leetcode.get(4) << endl;
    
    
    
    
    
    return 0;
}
