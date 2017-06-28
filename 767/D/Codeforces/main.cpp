//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/767/problem/D
 题目大意：
 小红很喜欢喝牛奶，每天最多能喝k瓶牛奶；
 小红有n瓶牛奶，每瓶牛奶都有一个有效时间f[i]，表示需要在f[i]天内喝完；
 同时商店里有m瓶牛奶，每瓶牛奶的有效时间是g[[i];
 小红很讨厌浪费，所以她希望能全部喝完自己的牛奶；
 同时小红很喜欢牛奶，她希望尽可能喝更多的牛奶；
 
 n, m, k (1 ≤ n, m ≤ 1e6, 1 ≤ k ≤ n + m)
 
 Examples
 input
 3 6 2
 1 0 1
 2 0 2 0 0 2
 output
 3
 1 2 3
 input
 3 1 2
 0 0 0
 1
 output
 -1
 input
 2 1 2
 0 1
 0
 output
 1
 1
 
 
 
 题目解析：
 可以知道，小红必须是先满足喝完自己的牛奶，再尽可能去喝商店里的牛奶；
 那么小红的策略应该是每天尽可能喝有效时间最短的牛奶，如果有效期为当天的牛奶全部喝完了还不满k瓶，那么会喝自己剩下和商店里的；
 考虑一个简单的做法：
 把小红所有的牛奶排序，按照有效时间从小到大遍历每瓶牛奶，可以容易判断小红自己的牛奶是否能全部喝完；
 
 再来考虑商店里的牛奶：假如小红能喝完i+1瓶牛奶，那么必然能喝完i瓶牛奶，具有单调性；
 二分mid，表示小红能喝完mid瓶商店里的牛奶；
 再使用贪心策略，从商店里选择mid瓶有效时间最长的牛奶，混入小红必须喝完的列表，然后排序；
 
 总得复杂度O(logM*N*LogN)；
 
 
 没想到tle了，因为N=10^6，加上logM和logN，复杂度要加2^20 * 2 = 400，大概有4 * 10^8的复杂度较高；
 
 这里有一个优化的方案，在二分完mid之后，不与小红已有的牛奶混合排序；
 用two pointers 的方法进行判断。
 
 
  
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
const int N = 2010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;

    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first > tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}f[N], g[N];

int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    lld n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i].first);
        f[i].second = i;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &g[i].first);
        g[i].second = i;
    }
    sort(f + 1, f + 1 + n);
    sort(g + 1, g + 1 + m);
    
    int left = 0, right = m + 1, ans = -1;
    while (left < right) {
        int mid = (left + right) / 2;
        int ok = 1;
        int sum = 0, x = n, y = mid;
        while (x > 0 || y > 0) {
            ++sum;
            int day = 0;
            if (x == 0) { // left y
                day = g[y].first;
                --y;
            }
            else if (y == 0) {
                day = f[x].first;
                --x;
            }
            else {
                if (f[x].first < g[y].first) {
                    day = f[x].first;
                    --x;
                }
                else {
                    day = g[y].first;
                    --y;
                }
            }
            if (sum > (day + 1) * k) {
                ok = 0;
                break;
            }
        }
        
        if (ok) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    cout << ans << endl;
    for (int i = 1; i <= ans; ++i) {
        printf("%d ", g[i].second);
    }
    
    
    return 0;
}

/*
 4 4 2
 20000 20000 201 201
 1 2 3 45
 
 */
