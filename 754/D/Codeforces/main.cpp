//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/754/problem/D
 题目大意：
 小明去商场购物，有若干个商品排成一行。
 小明有n张优惠券，每张优惠券可以覆盖id范围是(l[i], r[i])的商品，包括第l[i]、r[i]个商品;
 现在小明想从中选出k张优惠券，并且让这k张优惠券共同覆盖的商品尽可能多；
 输出最多的商品数，还有选中的k张购物券。
 
 输入数据
 第一行两个整数，n and k (1 ≤ k ≤ n ≤ 3·1e5)
 接下来n行，每行两个整数 l[i] and r[i] ( - 1e9 ≤ l[i] ≤ r[i] ≤ 1e9)
 输出数据
 第一行是最多覆盖的商品数；
 第二行是k个整数，表示选中的k张购物券；
 
 
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
 样例解释： 共同覆盖的区间是[40, 70]，总共有31种商品；
 input
 3 2
 1 12
 15 20
 25 30
 output
 0
 1 2
 样例解释：没有共同覆盖的区间，任选两张即可。
 
 
 题目解析：
 容易知道优惠券的选择是没有先后顺序，可以对其进行排序。
 先保证左区间从小到大，再考虑右区间从小到大。
 
 对于购物券i覆盖的区间(l[i], r[i])，如果之前某个购物券（我们用j来表示），其覆盖区间的r[j] < l[i]; (j < i)
 那么就有l[i] > r[j] >= l[j]; 即是购物券i的覆盖区间是在购物券j覆盖区间的右边；
 并且对于购物券i+1覆盖区间，因为有l[i+1] >= l[i], 那么购物券 i+1的覆盖区间必然也是在购物券j的覆盖区间右边；
 
 由此，我们可以维护一个优先队列：里面有若干个值，r最小的在前面，如果r相同则让大的在前面；
 由于前面我们已经按照左区间从小到大排序，那么对于第i张优惠券，l[i]就是最大的left，再拿优先队列里面的top.r，就是最小右区间；
 l[i]和top.r形成的区间，就是优先队列里面的所有区间的公共覆盖区间，再判断下优先队列里面的区间是否大于k。
 
 注意题目还要求输出k个优惠券，如果求解过程去记住这个值，很容易超时；
 可以只记录最长的公共覆盖区间ans，输出答案的时候通过遍历所有优惠券，如果该优惠券的覆盖区间超过输出ans，则直接输出。
 
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
    for (int i = 0; i < n; ++i) {
        // 优先队列里面有若干个值，r最小的在前面，假设是top.r，l最大的是l[i]，那么这些区间的公共区域是 l[i] 到 r
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
