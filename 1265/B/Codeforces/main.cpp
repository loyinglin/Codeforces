//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1265/problem/b)
 **题目大意：**
 给出1~n的n个整数组成的数组，每个数字都只有一个；
 我们把数字i称为beautiful，如果能够在数组中找到一段连续的数字，这个区间内的数字是1到i；
 比如说对于数组[4,5,1,3,2,6]，我们能找到：
 [1], [1,3,2], [4,5,1,3,2],[4,5,1,3,2,6] 这四个区间，所以数字1、3、5、6是beautiful，数字2、4不是beautiful；
 
 现在给出一个1~n组成的数组，问数组中有哪些数字是beautiful；
  
 输入：
 第一行 𝑡  (1≤𝑡≤1000) 表示接下来有t个样例
 每个样例的第一行是𝑛  (1≤𝑛≤2⋅10^5），表示数组的长度；
 接下来一行是n个整数；
 
 
 输出：
 每一个样例输出一行长度为n的字符串，每个字符都是01组成，第i个字符为1表示第i个数字是beautiful；
 
 input
 3
 6
 4 5 1 3 2 6
 5
 5 3 1 2 4
 4
 1 4 3 2
 
 output
 101011
 11111
 1001
 
 
 **题目解析：**
 
 看到题目的第一想法是从小到大排序，然后从1开始枚举数字；
 对于某个数字x，如果左边数字比x小，则合并到集合x；
 如果右边的数字比x小，则合并到集合x；
 这样不断枚举，不断合并，通过集合的元素和x是否相同，就可以判断是否存在解。（对应下面解法A）
 
 
 更优解：
 对于数字k是否有解，其实是看[1, k]这个区间内，所有数字的左边界和右边界的距离，是否刚好等于数字k；
 比如说k=3，[1,2,3]三个数字的左边界是3（对应1的位置），右边界是5（对应2的位置），距离是 (5-3+1)=3，所以k=3有解；
 比如说k=4,  [1,2,3,4]四个数字的左边界是1（对应4的位置），右边界是5（对应2的位置），距离是 (5-1+1)=5≠k，所以k=4无解。（对应下面解法B）
 
 
 
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
const int N = 1010010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


class SolutionA {
    int a[N];
    int fat[N];
    int cnt[N];
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    
    int find(int x) {
        if (fat[x] == x) {
            return x;
        }
        int ret = find(fat[x]);
        if (ret != fat[x]) {
            fat[x] = ret;
            cnt[ret] += cnt[x];
            cnt[x] = 0;
        }
        
        return fat[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx > fy) {
            fat[fx] = fy;
            cnt[fy] += cnt[fx];
            cnt[fx] = 0;
        }
        else {
            fat[fy] = fx;
            cnt[fx] += cnt[fy];
            cnt[fy] = 0;
        }
        find(x);
        find(y);
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            scanf("%d", &n);
            
            for (int i = 0; i < n; ++i) {
                scanf("%d", &a[i]);
            }
            
            while (!q.empty()) {
                q.pop();
            }
            
            memset(fat, 0, sizeof(fat));
            memset(cnt, 0, sizeof(cnt));
            
            for (int i = 0; i < n; ++i) {
                q.push(make_pair(a[i], i));
            }
            
            while (!q.empty()) {
                pair<int, int> tmp = q.top();
                tmp = q.top();
                q.pop();
                
                fat[tmp.first] = tmp.first;
                cnt[tmp.first] = 1;
                
                int l = tmp.second - 1;
                if (l >= 0 && a[l] < tmp.first) {
                    merge(a[l], tmp.first);
                }
                int r = tmp.second + 1;
                if (r < n && a[r] < tmp.first) {
                    merge(a[r], tmp.first);
                }
                
                if (cnt[find(tmp.first)] == tmp.first) {
                    putchar('1');
                }
                else {
                    putchar('0');
                }
            }
            puts("");
        }
    }
}ac;


class SolutionB {
    int a[N];
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            scanf("%d", &n);
            
            for (int i = 0; i < n; ++i) {
                int x;
                scanf("%d", &x);
                a[x-1] = i;
            }
            
            int left = n, right = 0;
            for (int i = 0; i < n; ++i) {
                left = min(left, a[i]);
                right = max(right, a[i]);
                if (right - left == i) {
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
            cout << endl;
        }
    }
}ac_fast;

int main(int argc, const char * argv[]) {
    ac_fast.solve();
    
    return 0;
}

/**
 3
 6
 4 5 1 3 2 6
 5
 5 3 1 2 4
 4
 1 4 3 2
 output
 101011
 11111
 1001
 
 */
