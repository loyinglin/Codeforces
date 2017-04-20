//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/754/problem/D
 题目大意：
 小明有n张优惠券，每张优惠券可以覆盖id范围是(l[i], r[i])的商品，包括商品id为l[i]、r[i];
 现在小明想从中选出k张优惠券，并且让这k张优惠券共同覆盖的商品尽可能多；
 输出最多的商品数，还有选中的k张购物券。
 
 n and k (1 ≤ k ≤ n ≤ 3·1e5)
 l[i] and r[i] ( - 1e9 ≤ l[i] ≤ r[i] ≤ 1e9)
 
 
 Examples
 input
 4 2
 1 100
 40 70
 120 130
 125 180
 output
 31
 1 2
 解释：共同覆盖的区间是[40, 70]，总共有31种商品；
 input
 3 2
 1 12
 15 20
 25 30
 output
 0
 1 2
 解释：没有共同覆盖的区间，任选两张即可。
 
 
 题目解析：
 容易知道优惠券的选择是没有先后顺序，考虑对其按照区间进行排序。
 区间从小到大，右区间从小到大。
 排序后，
 对于一个区间(l[i], r[i])，如果之前某个区间的r[j] < l[i]; (j < i)
 那么就有l[i] > r[j] >= l[j]; 即是新的区间i是在区间j的右边；
 那么对于区间i+1,因为有l[i+1] >= l[i], 那么i+1 必然也是在区间j的右边；
 由此可以知道：
 
 ansVec的方式，tle；
 
 因为每次选择到答案，都会把queue里的数据导出来，这样的复杂度，每次是Nlog(N);
 
 优化方案：
 只记录最优解的区间，再输出答案的时候通过遍历区间，输出k个符合条件的区间即可。 
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int l, r, id;
    bool operator < (const Node &tmp) const
    {
        if (r != tmp.r) return r > tmp.r; // 优先队列默认是大顶堆，但是我们希望r小的在前面
        else return l < tmp.l; // 如果r相同，那么希望l大的在前面
    };
    Node(int first, int second, int id):l(first), r(second), id(id){};
    Node(){};
}a[N];

bool cmp(Node x, Node y) {
    if (x.l != y.l) {
        return x.l < y.l;
    }
    else {
        return x.r < y.r;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int k, n;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    priority_queue<Node> priQueue;
    int ans = 0;
    pair<int, int> seg;
    for (int i = 0; i < n; ++i) { // 有限队列里面有若干个值，r最小的在前面，假设是top.r，l最大的是l[i]，那么这些区间的公共区域是 l[i] 到 r
        while (!priQueue.empty()) {
            Node top = priQueue.top();
            if (top.r < a[i].l) {
                priQueue.pop();
                continue;
            }
            else {
                break;
            }
        }
        while (priQueue.size() >= k) {
            priQueue.pop();
        }
        
        if (priQueue.size() == k - 1) {
            int topR;
            if (priQueue.size() == 0) {
                topR = a[i].r;
            }
            else {
                topR = min(priQueue.top().r, a[i].r);
            }
            if (ans < topR - a[i].l + 1) {
                ans = topR - a[i].l + 1;
                seg = make_pair(a[i].l, topR);
            }
        }
        priQueue.push(a[i]);
    }
    
    if (ans == 0) {
        cout << 0 << endl;
        for (int i = 0; i < k; ++i) {
            printf("%d ", i + 1);
        }
    }
    else {
        cout << ans << endl;
        for (int i = 0; i < n && k; ++i) {
            if (a[i].l <= seg.first && a[i].r >= seg.second) {
                printf("%d ", a[i].id);
                --k;
            }
        }
        cout << endl;
    }
    
    return 0;
}
