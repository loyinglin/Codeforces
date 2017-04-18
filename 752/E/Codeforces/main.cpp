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
 二分答案ans，每个数字尽可能分，保证每个大于ans，最后判断是否足够分。
 枚举的过程，首先尝试的方法是对每个数字进行拆分，在保证>=ans，直到不能拆，这的复杂度logM * n * n;
 最初是以 `find(x){ find(x/2)+find(x-x/2)}`这样的方式，进行判断，在ans较小的时候，其实是O(N)的复杂度；
 因为没有考虑到这一点，导致TLE了三次；
 解决方案是：
 考虑到每个数字的范围只有1e7；
 从最大开始枚举，如果大于ans*2，那么进行拆分；
 直到数字=ans，这时可以得到>=ans的数字数量。
 ```
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
 ```
 
 
 ************************* 题解 ***********************/
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
const lld N = 10100000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N], b[N];

lld main(lld argc, const char * argv[]) {
    // insert code here...
    
    lld n, k, total = 0;
    lld maxAns = 0;
    cin >> n >> k;
    for (lld i = 0; i < n; ++i) {
        lld t;
        scanf("%d", &t);
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
            a[i / 2] += a[i] + b[i]; // 数字i本身能分离出来一个i，
            b[i - i / 2] += a[i] + b[i];  //
        }
        cout << i << " a: " << a[i] <<  " b: " << b[i] << " sum: " << total << endl;
    }
    cout << -1 << endl;
    
    return 0;
}
*/


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

