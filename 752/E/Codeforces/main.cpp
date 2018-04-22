//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/752/problem/E
 题目大意：
 给出n个数字a[i]，要分给k个人；
 数字a[i]可以平分，如果是奇数，那么会分成a[i]/2 和 a[i]/2 + 1;
 每个人只能分得一个数字，问所有人中最小的数字的最大值是多少？
 如果不够分，那么输出-1；
 
 n and k (1 ≤ n ≤ 1e6, 1 ≤ k ≤ 2·1e9)
 1 ≤ a[i] ≤ 1e7
 
 
 Examples
 input
 3 2
 5 9 3
 output
 5
 input
 2 3
 1 1
 output
 -1
 
 题目解析：
 分出k个数，保证最小值尽可能大；
 第一想法是二分答案，假设最后的结果是ans，对于数字x，while(x/2>=ans)，对数字x进行平分；
 假设num[x]表示数字x的数量，如果x/2>=ans，那么有num[x/2] += num[x], num[x - x/2] += num[x];
 最后再统计所有数字比ans大的数字数量，判断是否大于k；
 复杂度为二分复杂度log(1e7) * 枚举平分复杂度(1e7) =24*1e7=2.4e8的复杂度；
 因为题目给的时限为2s，勉强可以完成；
 
 思考：
 另一种更优雅的方案。
 以数字21为例，如果ans∈[11, 21]这一区间，>ans的数字只有一个；
 如果ans=10时，就能算两个数字；（因为21可以拆分为10+11）
 数字x，可以切分为数字较小的部分x/2和数字较大的部分(x-x/2)，我们用a[x]来表示数字x的个数，b[x]表示当x拆分时(x-x/2)的数量；
 当ans>(x-x/2)时，x的拆分没有额外收益；
 当ans<=x/2时，x的拆分相当于多出来一个数字a[x/2]；
 于是有：
 a[x/2] += a[x]+b[x];
 b[x-x/2] += a[x]+b[x];
 
 
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
const lld N = 10100000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N], b[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, k, total = 0;
    lld maxAns = 0;
    cin >> n >> k;
    for (lld i = 0; i < n; ++i) {
        lld t;
        cin >> t;
        ++a[t];
        maxAns = max(maxAns, t);
    }
    for (lld i = maxAns; i > 0; --i) {
        total += a[i];
        if (total >= k) {
            cout << i << endl;
            return 0;
        }
        else {
            a[i / 2] += a[i] + b[i]; // 数字i本身能分离出来一个i
            b[i - i / 2] += a[i] + b[i];  //
        }
//        cout << i << " a: " << a[i] <<  " b: " << b[i] << " sum: " << total << endl;
    }
    cout << -1 << endl;
    
    return 0;
}


/*
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
const lld N = 1010000, M = 10101000, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    lld first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != second) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(lld first, lld second):first(first), second(second){};
    Node(){};
}node[N];
lld a[N];
lld num[M];

inline lld find(lld x, lld mid) {
    lld ret = 0;
    if (x >= mid * 2) {
        ret = find(x / 2, mid) + find(x - x / 2, mid);
    }
    else {
        ret = x >= mid;
    }
    return ret;
}

lld findExt(lld n, lld mid) {
    lld ret = 0;
    memset(num, 0, sizeof(num));
    for (lld i = 0; i < n; ++i) {
        num[a[i]]++;
    }
    for (lld i = 1e7; i >= mid; --i) {
        if (i / 2 >= mid) {
            num[i / 2] += num[i];
            num[i - i / 2] += num[i];
        }
        else {
            ret += num[i];
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, k, total = 0;
    cin >> n >> k;
    for (lld i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        total += a[i];
    }
    if (total < k) {
        cout << -1 << endl;
    }
    else {
        lld l = 1, r = 1e7 + 1; // [l, r)
        lld ans = 1;
        while (l < r) {
            lld mid = (l + r) / 2;
            lld sum = findExt(n, mid);
            if (sum >= k) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}

*/
