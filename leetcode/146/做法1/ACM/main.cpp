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
 
 
 网上其他的做法：
 使用双向list每次set或get一个元素时都把这个元素放到list的头部；
 list.splice 函数
 替换时，直接用尾部；
 
 unordered_map 比 map 更快；
 
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



typedef long long lld;
const int N = 50000;
class LRUCache{
public:
    map<int, int> cache; // 键值对
    map<int, int> Hash; // key和有效时间
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > queue;
    int op[N], n, index, ids;
    LRUCache(int capacity) {
        n = capacity;
        index = 0;
        ids = 0;
    }
    
    int get(int key) {
        ++ids;
        if (Hash[key] == 0) {
            return -1;
        }
        else {
            Hash[key] = ids;
            queue.push(make_pair(ids, key));
            return cache[key];
        }
    }
    
    void set(int key, int value) {
        ++ids;
        cache[key] = value;
        if (Hash[key]) { // 以前有值
            Hash[key] = ids;
            queue.push(make_pair(ids, key));
        }
        else {
            ++index;
            Hash[key] = ids;
            queue.push(make_pair(ids, key));
            if (index > n) {
                int oldKey = 0;
                while (!queue.empty()) {
                    pair<int, int>  top = queue.top();
                    queue.pop();
                    if (Hash[top.second] == top.first) {
                        oldKey = top.second;
                        break;
                    }
                }
                cache[oldKey] = -1;
                Hash[oldKey] = 0;
            }
            
        }
    }
}lc(2);


int main(int argc, const char * argv[]) {
    
    lc.set(1, 1);
    lc.set(2, 2);
    lc.set(3, 3);
    cout << lc.get(3) << endl;
    cout << lc.get(2) << endl;
    cout << lc.get(1) << endl;
    lc.set(4, 4);
    cout << lc.get(1) << endl;
    cout << lc.get(2) << endl;
    cout << lc.get(3) << endl;
    cout << lc.get(4) << endl;
    
    
    return 0;
}
