//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1201/problem/D)
 **题目大意：**
 有一个n x m的网格，小明站在位置(1,1)；
 现在小明每次可以选择移动一步：向上、向左、向右，但是不能向下，也不能超过网格；
 网格中，只有某些特定的列可以往上走，这些列有q个（𝑏1,𝑏2,…,𝑏𝑞）
 某些格子放着宝藏，这些格子有k个，分别是𝑟𝑖,𝑐𝑖, (1≤𝑟𝑖≤𝑛, 1≤𝑐𝑖≤𝑚)
 
 现在想知道，小明拿到所有的宝物，最少需要多少步；
 
 输入：
 第一行， 𝑛, 𝑚, 𝑘 and 𝑞 (2≤𝑛,𝑚,𝑘,𝑞≤2⋅1e5, 𝑞≤𝑚)
 接下来k行，每行2个整数 𝑟𝑖,𝑐𝑖, (1≤𝑟𝑖≤𝑛, 1≤𝑐𝑖≤𝑚)
 最后一行有q个整数，𝑏1,𝑏2,…,𝑏𝑞  (1≤𝑏𝑖≤𝑚)
 
 
 输出：
 最少移动步数。
 
 Examples
 input
 3 3 3 2
 1 1
 2 1
 3 1
 2 3
 output
 6
 input
 3 5 3 2
 1 2
 2 3
 3 1
 1 5
 output
 8
 input
 3 6 3 2
 1 6
 2 2
 3 4
 1 6
 output
 15
 
 
 **题目解析：**
 理清题目的要求和限制之后，我们可以知道：
 1、我们要拿到所有的宝藏，就需要把每一层宝物都拿完才能选择上一层；
 2、选择从哪一列上去是一个决策点；
 3、假如在第i行时，初始位置是在第x列，计划选择第y列上去，则这一层的遍历最优解已经决定；
 
 接下来简化这些问题，先看某一层的遍历宝藏问题，从贪心的角度来看，我们只有两个选择：
 1、先走到最左边的宝藏，再走到最右边的宝藏；
 2、先走到最右边的宝藏，再走到最左边的宝藏；
 那么以这两个状态为节点，我们有dp[i][0]，dp[i][1]表示第i行，站在最左边和最右边的最小步数；
 同时，我们需要把这一层的宝藏拿完，于是有dp[i][2],dp[i][3]表示第i行拿完宝藏后，站在最左边和最右边的最小步数；
 
 容易知道，转移过程有两个：
 a.dp[i][0]，dp[i][1]可以由dp[i-1][2],dp[i-1][3]转移过来；（表示拿完宝藏上来）
 b.dp[i][2],dp[i][3]可以由dp[i][0]，dp[i][1]转移过来；（表示拿完这一层的宝藏）
 
 情况b很简单，直接计算距离就可以得到转移方程；
 情况a比较复杂，有两个转移初始点，同时有m个选择上来的地点，如果每个都遍历一遍，转移的时间代价太高；
 为了简化这个过程，可以选出起点左右最近的两个点、终点左右最近的两个点，这样复杂度就从O(M)降为O(1)；
 这个查找过程，可以用二分来解决。
 
 
 
 注意事项:
 错误1：第一行为空的情况，插入字符0；
 错误2：某一行为空的情况，累计lastRow；
 错误3：dp[i-1]改为lastRow;
 错误4：long long；
 错误5：binary search 的时候，传入的n，应该是q；
 错误6：初始化错误，写成int的最大值，应该是longlong最大值；
 
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
const lld N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<lld> a[N];
lld dp[N][4];
lld b[N];

pair<lld, lld> binarySearch(lld val[], lld n, lld k) {
    pair<lld, lld> pos;
    lld left = 0, right = n; // [left, right) 左开右闭
    pos.first = left;
    while (left < right) {
        lld mid = (left + right) / 2;
        if (val[mid] == k) {
            pos.first = mid;
            break;
        }
        else if (val[mid] < k) {
            pos.first = mid;
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    left = 0, right = n, pos.second = n - 1;
    while (left < right) {
        lld mid = (left + right) / 2;
        if (val[mid] == k) {
            pos.second = mid;
            break;
        }
        else if (val[mid] < k) {
            left = mid + 1;
        }
        else {
            pos.second = mid;
            right = mid;
        }
    }
    return make_pair(val[pos.first], val[pos.second]);
}

lld cost(lld src, pair<lld, lld> pass, lld dest) {
    return min(abs(src - pass.first) + abs(pass.first - dest), abs(src - pass.second) + abs(pass.second - dest));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    lld n, m, k, q;
    cin >> n >> m >> k >> q;
    lld maxRow = 0;
    for (lld i = 0; i < k; ++i) {
        lld x, y;
        cin >> x >> y;
        --x;--y;
        a[x].push_back(y);
        maxRow = max(maxRow, x);
    }
    for (lld i = 0; i < q; ++i) {
        cin >> b[i];
        --b[i];
    }
    sort(b, b + q);
    if (a[0].size() == 0) {
        a[0].push_back(0); // 避免第一层没有宝藏的情况
    }
    for (lld i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    
    dp[0][0] = a[0].front();
    dp[0][1] = a[0].back();
    dp[0][2] = dp[0][1] + abs(a[0].back() - a[0].front());
    dp[0][3] = dp[0][0] + abs(a[0].back() - a[0].front());
    lld lastRow = 0;
    for (lld i = 1; i < n; ++i) {
        if (a[i].size()) {
            // dp[i][0]最左边，可以从下一层的dp[i-1][2]最左边，dp[i-1][3]最右边转移过来
            pair<lld, lld> posLeft = binarySearch(b, q, a[lastRow].front());
            pair<lld, lld> posRight = binarySearch(b, q, a[lastRow].back());
            
            dp[i][0] = llinf; // init
            // 从下一层的最左边上来
            dp[i][0] = min(dp[i][0], dp[lastRow][2] + (i-lastRow) + cost(a[lastRow].front(), posLeft, a[i].front()));
            // 从下一层的最右边上来
            dp[i][0] = min(dp[i][0], dp[lastRow][3] + (i-lastRow) + cost(a[lastRow].back(), posRight, a[i].front()));
            
            dp[i][1] = llinf; // init
            // 从下一层的最左边上来
            dp[i][1] = min(dp[i][1], dp[lastRow][2] + (i-lastRow) + cost(a[lastRow].front(), posLeft, a[i].back()));
            // 从下一层的最右边上来
            dp[i][1] = min(dp[i][1], dp[lastRow][3] + (i-lastRow) + cost(a[lastRow].back(), posRight, a[i].back()));
            
            dp[i][2] = dp[i][1] + abs(a[i].front() - a[i].back());
            dp[i][3] = dp[i][0] + abs(a[i].front() - a[i].back());
            lastRow = i;
        }
    }

    
    cout << min(dp[maxRow][2], dp[maxRow][3]) << endl;
    
    return 0;
}


/*
 10 10 10 1
 1 1
 2 1
 3 1
 4 1
 5 1
 6 1
 7 1
 8 1
 9 1
 10 1
 10
 
 
 
 4 4 2 1
 2 2
 4 2
 3
 
 
 123456 1000000000 3 1
 2 1
 55555 1
 100000 1
 1000000000
 
 
 5 5 3 1
 2 1
 4 1
 5 1
 5
 */
