//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1173/problem/C)
 **题目大意：**
 小明有 2 x n 张卡片，其中n张卡片序号是1、2、3、、、n，另外n张的卡片序号是0。
 现在这些卡片都随机打乱，分成2组卡片，从上到下分别为a[i]和b[i]。
 现在小明在玩一个游戏，卡片a组是手牌，卡片b组是目标卡组。
 每次小明可以从手牌中拿出一张卡片（可以是手牌中任意一张），放置在卡片b组的最下面，然后从卡片b组中的最上面拿掉一张卡片放入手牌。
 小明希望用这个操作，使得目标卡组从上到下分别为1、2、3、4、、、、n。
 问，最少需要多少次操作。
 
 输入：
 第一行，数字𝑛 (1≤𝑛≤2⋅105)
 第二行，n个数字表示a[i]，𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤𝑛)
 第三行，n个数字表示b[i]，𝑏1,𝑏2,…,𝑏𝑛 (0≤𝑏𝑖≤𝑛)
 
 输出：
 一个数字，最少的次数。
 
 Examples
 input
 3
 0 2 0
 3 0 1
 output
 2
 input
 3
 0 2 0
 1 0 3
 output
 4
 input
 11
 0 0 0 5 0 0 0 4 0 0 11
 9 2 6 0 8 1 7 0 3 0 10
 output
 18
 
 
 **题目解析：**
 小明手上的n张卡片a[n]，另外的n张卡片是b[n];
 最终的结果数组a全部是0，数组b=1,2,3...,n;
 
 先不考虑复杂度，可以把b中所有的非零数字先用0换取出来；
 然后按照顺序放入1~n个数字，可以用最多2*n次操作完成。
 
 简化这个思考逻辑，我们发现这个操作其实就是队列的操作。
 
 3
 0 2 0
 3 0 1
 那么这里的交换其实就是:
 [3,0,1,2,3] 原始是[3,0,1]，第一次操作后是[0,1,2]，第二次操作之后是[1,2,3]，满足要求；
 
 3
 0 2 0
 1 0 3
 [1,0,3,0,1,2,3] 是第二样例；
 
 总结前面的思路，就是不断拿0去交换b里面的数字，直到a里面的数字可以开始填1、2、3...；
 现在的问题是如何断定1开始填是可以的？
 
 容易知道如果从第x个位置开始填入有解，那么从第x+1个位置开始填也是有解。
 那么可以从[1, n]二分，最终得到一个有效的解。
 
 这里需要考虑一种特殊情况，就是填充的数字不是从1开始的。
 
 如果不想用二分呢？
 有解决方案！
 从左到右遍历数组b，对于每个位置都判断一次：
 当前的数字是x（x从1开始），如果x在手牌中，则使用x，然后获得该位置对应的卡片；（x+1）
 如果当前的数字x没有在手牌上，则可以在原来最开始的位置先插入0，延后1的插入位置，那么2、3、4、、等所有的位置都会延后；
 直到所有的数字插入完毕。
 
 因为此处用二分比较简单快捷，就先使用二分。
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
const int N = 201000, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N], b[N], v[N];

bool check(int n, int k) {
    memset(v, 0, sizeof(v));
    
    for (int i = 0; i < n; ++i) {
        v[a[i]] = 1;
    }
    for (int i = 0; i < k; ++i) {
        v[b[i]] = 1;
    }
    
    for (int index = 1; index <= n; ++index) {
        if (v[index]) {
            // ok
            if (index + k - 1 < n) {
                // recycle
                v[b[index + k - 1]] = 1;
            }
        }
        else {
            return false;
        }
    }
    return true;
}

bool other_check(int n) {
    int k = n - 1;
    while (b[k]) {
        if (b[k - 1] + 1 == b[k]) {
            --k;
        }
        else {
            return false;
        }
    }
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i) {
        v[a[i]] = 1;
    }
    
    for (int index = b[n - 1] + 1; index <= n; ++index) {
        if (v[index]) {
            // ok
            int t = index - b[n - 1] - 1;
            // recycle
            v[b[t]] = 1;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    int left = 0, right = n, ans1 = n; // [left, right]
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(n, mid)) {
            ans1 = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    ans1 += n;
    
    int ans2 = 2*n;
    if (other_check(n)) {
        ans2 = n - b[n - 1];
    }
    
    cout << min(ans1, ans2) << endl;
    
    return 0;
}
