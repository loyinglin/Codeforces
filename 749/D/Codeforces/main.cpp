//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/749/problem/D
 题目大意：
 给出n个竞标的过程，出价表；
 
 现在问题来了：
 q个询问，每个询问首先是k，表示假如k个人没来，输出此时的竞标结果；
 

 ai and bi (1 ≤ ai ≤ n, 1 ≤ bi ≤ 1e9, bi < bi + 1)
 n (1 ≤ n ≤ 200 000)
 q (1 ≤ q ≤ 200 000)
 询问总数(1 ≤ sum of all k ≤ 200 000)
 
 题目解析：
 题目比较拗口，重点在于某部分人不来的情况，如何快速求出竞标的结果。
 q的数量较大，能够接受的时间复杂度在O(logN);
 先看看题目给出的条件，bi < bi + 1 并且 ai ≠ ai + 1；
 那么，越后面出价的数字会越高，直接通过最后面可以知道最高价；
 看看询问会造成的影响：
 1、某些人不来，其竞标的价格无效，本来可能是他的最高价，会顺延下一个人；
 2、假设某个人出了最高价，但是因为某些人没来，导致他的次高价也是最高的，这时候会选择次高价；
 
 
 有多次修改和多次询问，考虑用线段树；
 
 
 结果是：
 每个人的竞标结果，按大小顺序放到自己的一个桶里；
 每个桶按照最高价作为权值进行排序；
 
 每次找到有效的、权值最高的桶，这个人会中标；
 接着找到次高的桶，在最高的桶里面选择一个比次高桶的权值更高的竞标作为低价；
 
 复杂度分析：
 把每个人的竞标结果分类，O(N);  N是竞标的数量
 每个桶排序，O(MlogM);        M是桶的数量
 
 对于每个询问，找到权值最高的桶，这里用遍历操作；
 找到权值最高的桶之后，继续找权值次高的桶，这里仍然用的遍历操作；
 这两个操作的复杂度取决于每个询问中，不来人的数量，因为询问总数为N，所以复杂度是O(N);
 在权值最高的桶里面找一个竞标，比次高桶的权值更高的，这里用二分查找，复杂度是O(logN)，次数可能会有O(N)次；
 
 总的复杂度是 O(NlogN);
 
 
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
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        if (value != tmp.value) return value > tmp.value;
        else return pos > tmp.pos;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
}node[N];
vector<int> bucket[N];
vector<Node> people(N);

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int pid, bid;
        scanf("%d%d", &pid, &bid);
        people[pid] = Node(bid, pid); // bigger bid
        bucket[pid].push_back(bid);
    }
    
    sort(people.begin(), people.begin() + n + 1);
//    cout << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << people[i].pos << " " << people[i].value << endl;
//    }
    cin >> q;
    while (q--) {
        int k;
        scanf("%d", &k);
        map<int, int> h;
        for (int i = 0; i < k; ++i) {
            int tmp;
            scanf("%d", &tmp);
            h[tmp] = 1;
        }
        int ok = 0;
        for (int i = 0; i < n; ++i) {
            if (people[i].pos == 0) {
                break;
            }
            if (h.find(people[i].pos) == h.end()) { // find top one
                int topId = people[i].pos;
                
                int secondId = 0;
                for (int j = i + 1; j < n; ++j) {
                    if (h.find(people[j].pos) == h.end()) { // find second top
                        secondId = people[j].pos;
                        break;
                    }
                }
                if (secondId == 0) { // not find second top
                    cout << topId << " " << bucket[topId].front() << endl;
                }
                else {
                    cout << topId << " " << *upper_bound(bucket[topId].begin(), bucket[topId].end(), bucket[secondId].back()) << endl;
                }
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "0 0" << endl;
        }
    }
    
    
    return 0;
}
