//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/lru-cache/
 题目大意：
 实现一个最近最少使用的缓存算法，要求：
 get(key) - 返回缓存中key对应的值，如果没有存在缓存，返回-1；
 set(key, value) - 设置缓存中的key对应的value；
 缓存有固定大小。
 
 
 题目解析：
 缓存需要维护两个信息，
 1是key和value的对应；
 2是value的有效时间；
 时间是从小到大，每次会把一个大的值插入（新值），同时可能删掉旧值；（命中）
 那么维护一个value的有效时间，优先队列；
 
 这种做法，单次操作的时间复杂度是O(LogN)，和题目要求的O(1)有较大的差距；
 
 O(1)表示存储的数据结构只能用数组或者hash加链表的方式。
 数组的读取是O(1)，但是增删是O(N)的操作；
 hash+链表的方式较为符合题目的要求，可以实现大致O(1)的查找，也可以实现O(1)的增删操作；
 基于此数据结构，我们可以延伸出以下的解法：
 1、使用双向链表存储每个key和value；
 2、每次get、set已有节点时，把节点放到链表的最前面；
 3、每次set的时候如果size已经达到限制，则去掉尾部节点，然后在头部增加节点；
 
 接下来的问题是如何实现O(1)的读取，O(1)的大小判断，以及O(1)的链表移动；
 O(1)的读取，我们引入unordered_map，然后每次根据key去获取当前节点；（unordered_map 比 map 更快）
 O(1)的增删操作，我们通过list.splice函数实现；（因为是双向链表，O(1)的增删并不难实现）
 O(1)的大小判断，list获取size是O(N)的复杂度，所以我们引入一个变量curSize来记录当前节点数量；
 
 
 
 
 
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
#include <unordered_map>
#include<algorithm>
#include <list>
using namespace std;
#define LYTEST  1



typedef long long lld;
class LRUCache{
public:
    int cap, curSize;
    unordered_map<int, list<pair<int, int> >::iterator> keyMap;
    list<pair<int, int> > freqList;
    LRUCache(int capacity) {
        cap = capacity;
        curSize = 0;
    }
    
    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }
        else {
            auto iter = keyMap[key];
            freqList.splice(freqList.begin(), freqList, iter);
            return iter->second;
        }
    }
    
    void set(int key, int value) {
        if (keyMap.find(key) != keyMap.end()) {
            auto iter = keyMap[key];
            iter->second = value;
            freqList.splice(freqList.begin(), freqList, iter);
        }
        else {
            if (curSize >= cap) {
                auto last = freqList.back().first;
                keyMap.erase(last);
                freqList.pop_back();
                --curSize;
            }
            ++curSize;
            freqList.emplace_front(key, value);
            keyMap[key] = freqList.begin();
        }
    }
}lc(2);


int main(int argc, const char * argv[]) {
    
    lc.set(2, 1);
    lc.set(1, 1);
    cout << lc.get(2) << endl;
    lc.set(3, 3);
    cout << lc.get(2) << endl;
    cout << lc.get(1) << endl;
    lc.set(4, 4);
    cout << lc.get(1) << endl;
    cout << lc.get(2) << endl;
    cout << lc.get(3) << endl;
    cout << lc.get(4) << endl;
    
    
    return 0;
}
