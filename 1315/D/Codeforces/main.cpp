//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1315/problem/D)
 **题目大意：**
 有n个整数a[i]的数组，现在可以对数组的数字分别进行一个操作：
 令某个数a[i]=a[i]+1，但是代价是t[i]；
 现在希望数组中没有重复的数字，问最小的代价是多少？
 
 **输入：**
 第一行1个整数n，  (1≤𝑛≤200000).
 第二行n个整数𝑎[𝑖]  (1≤𝑎[𝑖]≤10^9).
 第二行n个整数𝑡[𝑖] (1≤𝑡[𝑖]≤10^5)；
 
 **输出：**
 一个整数m，代表最小的代价；
 
 **Examples**
 input
 5
 3 7 9 7 8
 5 2 5 7 5
  
 output
 6
 
 **题目解析：**
 先考小数据的情况，当有两个数字相同时，我们会把代价最大的留着，代价小的数字+1；
 当有3个数字相同时（假设都是x），我们我们会按照代价从大到小的分配x/x+1/x+2；
 同理，当有若干个数字相同时，同样可以按照代价从大到小排序。
 
 再回过来看题目的数据，我们从小到大来分析数据；
 如果某个数字只有1个，则直接跳过；
 如果某个数字出现2个以上，则最大代价的数字留着，其他的数字需要加一；
 
 考虑到当数字x到数字y之间，会存在某些区间也可以分配数字，那么我们同样需要按照代价从大到小去分配；
 
 每个数字只会分配一次，保持代价从大到小，可以使用优先队列，整体的复杂度是O(NLogN)，在题目可接受范围内。
 

 
 **思考🤔：**
 
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
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 200100, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (second != tmp.second) return second < tmp.second;
        else return first > tmp.first;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool const cmp(Node a, Node b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
  
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].first);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].second);
    }
    sort(node, node + n, cmp);
    priority_queue<Node> pq;
    lld pos = 0, lastValue = 0;
    lld ans = 0;
    while (pos < n) {
        lld val = node[pos].first;
        // 在处理每组，第一个数字之前，先把之前能填补的数字补上
        lld cnt = val - lastValue;
        while (cnt > 0 && !pq.empty()) {
            Node top = pq.top();
            pq.pop();
            ans += (lastValue - top.first) * top.second;
            
            ++lastValue;
            --cnt;
        }
               
        // 把这一组的数字加上
        while (pos < n && node[pos].first == val) {
            pq.push(node[pos]);
            ++pos;
        }
        
        lastValue = val;
    }

    lastValue = node[n - 1].first;
    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        ans += (lastValue - top.first) * top.second;
        ++lastValue;
    }
    
    cout << ans << endl;
    
    return 0;
}


/**

 6
 1     1     2   3   4   5
 10  10    1   1   1   1
>1     2     3  4   5     6
 
 */
