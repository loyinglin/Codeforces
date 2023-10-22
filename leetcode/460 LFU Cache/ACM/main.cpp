//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/lfu-cache/
 题目大意：
 实现LRU(最近最少使用)算法。如果有相同的使用频率，保留最近使用的（put操作不算使用）。
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
 2、key不存在，返回-1；
 
 如果使用朴素实现，list来存(key, value)对，并且在需要更新时直接去掉list节点，重新查找插入位置；
 每次的操作复杂度都是O(N)，并不符合要求。
 
 优化思路：
 耗时在于查找key值和插入key值；
 
 unordered_map<int, pair<int, int> > keyMap; // key = <value, freq>
 unordered_map<int, list<int>::iterator> iterMap; // 对应key的list迭代器，用于快速获得值
 unordered_map<int, list<int> > freqMap; // 使用频率是map
 
 引入三个map，分别是keyMap、iterMap和freqMap；
 keyMap记录对应key的value和出现频率，这样可以O(1)得到对应key值的pair(值value，出现频率freq)；
 freqMap的索引是出现频率freq，value是链表，存储当前使用频率为freq的数字；（比如说put(1, 2)，put(3, 4)，两次put操作之后，key值1、3都出现了（初始出现频率=1），所以有freq=1的链表(3，4)，即使freqMap[1]=(3,4)；
 iterMap的索引是输入的key，这样可以O(1)得到对应key值的链表迭代器，方便的更新key值的出现频率；（比如说在put(1, 2)，put(3, 4)之后，又出现一次get(1)，此时key=1出现频率为2，所以应该挪到freqMap[2]=(1)这样，此时需要把freqMap[1]中链表的4移除，此时如果遍历会很慢，所以引入iterMap以快速访问）
 
 这样就解决了key值的查找、插入带来的更新问题；
 
 同时为了解决cache满了之后，需要快速定位到抛弃哪个key值的问题，我们引入整数minFreq；
 因为出现频率总是从1、2、3.。这样递增，每次淘汰的时候从出现频率为minFreq的链表中选择1个即可；
 ps：get操作也需要更新minFreq，比如说put(1, 2)后minFreq=1，如果再出现get（1）此时minFreq=2，因为唯一的key值1已经出现了两次；
 仔细看代码，minFreq的更新并没有while循环，留给你思考下为什么。
 
 
 
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
