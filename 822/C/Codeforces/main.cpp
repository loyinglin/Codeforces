//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/822/problem/C
 题目大意：
 小明有n张优惠券，每张的有效时间是(l[i], r[i])，代价是cost[i]，表示从 l[i]天开始，r[i]天结束，长度是(r[i] - l[i] + 1)；
 现在需要从n张优惠券中，选出2张优惠券，要求两张优惠券没有重叠的日期，并且两张优惠券的长度刚好是x；
 问，最少的代价合是多少。
 
 Examples
 input
 4 5
 1 3 4
 1 2 5
 5 6 1
 1 2 4
 output
 5
 样例解释：
 输入第一行是n和x；   n and x (2 ≤ n, x ≤ 2·105)
 接下来是n行，分别是l[i], r[i], cost[i]，表示优惠券的有效时间和代价；  (1 ≤ l[i] ≤ r[i] ≤ 2e5, 1 ≤ cost[i] ≤ 1e9)
 输出是最小的代价；
 
 
 题目解析：
 先考虑简单的方法，直接for/for 枚举两个优惠券的组合，可以求出最小代价；
 但这样的复杂度是O(N^2)，需要进行优化；
 考虑到对于优惠券i，能和它组合的只有长度为(x - (r[i] - l[i] + 1))的优惠券；
 长度的范围只有2e5，可以考虑用一个数组t来存长度为len的优惠券最小代价，这样在枚举优惠券i的时候，可以迅速得到与它配对的优惠券；
 但是，题目还有另外一个限制：两个优惠券不能相交。
 可以考虑，按l[i]从小到大，再按r[i]从小到大排序，这样可以保证l[i]的单调；
 同时在更新l[i]的时候，需要把1到i-1的合法优惠券更新到数组t里面，因为在i合法，在i+1也是合法的；
 
 把1到i-1的合法优惠券更新到数组t，这里有两种做法：
 1、新建一个数组s，把1到i-1中的右节点（假设是r[k])，放到vector(r[k])中；
 2、把1到i-1中的右节点（假设是r[k])，放到优先队列（最小堆）中，每次取出最小的更新；
 
 这里选择做法2，实现更为清晰。
 
 wa了很多次之后，发现一个trick，优惠券的长度会比x更长！
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    lld first, second, cost;
    
    bool operator < (const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    lld len() {
        return second - first + 1;
    }
    Node(lld first, lld second):first(first), second(second){};
    Node(){};
}node[N];

lld s[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &node[i].first, &node[i].second, &node[i].cost);
    }
    sort(node, node + n);
   
    priority_queue<Node> queue;
    
    lld ans = llinf;
    for (int i = 0; i < n; ++i) {
        while (!queue.empty()) {
            lld topRight = -queue.top().first;
            if (topRight < node[i].first) {
                lld index = queue.top().second;
                lld len = node[index].len();
                if(!s[len]) {
                    s[len] = node[index].cost;
                }
                else {
                    s[len] = min(s[len], node[index].cost);
                }
                queue.pop();
            }
            else {
                break;
            }
        }
        if (node[i].len() < x && s[x - node[i].len()] > 0) {
            ans = min(ans, node[i].cost + s[x - node[i].len()]);
        }
        
        queue.push(Node(-node[i].second, i));
    }
    if (ans == llinf) {
        ans = -1;
    }
    cout << ans << endl;
    
    
    return 0;
}

/**
 
 5 4
 1 2 521
 2 3 1521
 3 4 1151
 4 5 1151
 5 6 1153
 
 
 
 **/
