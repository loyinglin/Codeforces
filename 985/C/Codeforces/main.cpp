//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Chess Placing
 [题目链接](http://codeforces.com/contest/985/problem/C)
 **题目大意：**
 有m个木板，每个木板有一个长度a[i]；
 k个木板可以组成一个木桶，根据木桶原理知道，最短的木板决定容量，我们用最短木板的长度来表示容量；
 现在需要用m个木板来组成n个木桶，已知m=n*k；
 现在要求任意桶之间的容量差不能超过l，问组成的n个桶的最大容量和是多少？
 
 
 
 **输入数据：**
 第一行 n, k and l (1 ≤ n, k ≤ 1e5, 1 ≤ n·k ≤ 1e5, 0 ≤ l ≤ 1e9).
 第二行 m个数字（m=n*k）a[i]，表示第i个木板的长度；
 
 输出：
 如果满足要求，n个桶的最大容量和；
 如果不满足要求，则输出0.
 
 
 >**Examples**
 **input**
 4 2 1
 2 2 1 2 3 2 2 3
 **output**
 7
 
 **题目解析：**
 如果没有要求，任意组成n个木桶，怎样才能使得容量和最大？
 思路：因为所有木板都要参与组成木桶，那么最短的那块木板所在的木桶必然受到这个影响；
 所以，我们可以把木板排序，然后从小到大的选择木板组成木桶，即可得到最大容量和。
 
 再考虑题目要求，容量差不能超过l；
 先对数组a[i]排序，从小到大；
 第一个桶容量只能是a[1]，剩下的桶必须选一块木板长度在(a[1], a[1]+l)之间；
 根据上面贪心的经验，我们可以在(a[1], a[1]+l)区间内中选择最大的一块木板，然后在区间外选择任意木板组成木桶；
 接着重复在(a[1], a[1]+l)区间内中选择最大的一块木板，接着在区间外选择任意木板组成木桶，如果区间外的木桶不够，则使用区间内的木桶，同样是大者优先；
 这样可以得到满足要求的n个木桶的最大容量和。
 
 对上面的思路进行整理：
 排序后的a[i]，如果(a[1], a[1]+l)存在n个木板，那么必然存在解；
 对于第i个木桶，假设其最短的木板是a[x]，优先考虑(a[x], a[1]+l)选择木板，但是要保证区间剩余木板数量>=(n-i)个木板。
 
 
 **思考🤔：**
 
 
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
const lld N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, k, l;
    cin >> n >> k >> l;
    
    lld m = 1LL * n * k;
    for (lld i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + m);
    
    lld sum = 0;
    for (lld i = 1; i <= m; ++i) {
        if (a[i] <= a[1] + l) {
            ++sum;
        }
        else {
            break;
        }
    }
    
    if (sum >= n) {
        lld curIndex = 0, curCount = 0;
        lld ans = 0;
        while (curCount < n) {
            ++curIndex;
            ++curCount;
            --sum; // curIndex对应的木板已经使用
            
            ans = ans + a[curIndex];
            
            if (sum > (n - curCount)) { // 剩余木板足够
                lld s = sum - (n - curCount);
                curIndex += min(s, k - 1);
                sum -= min(s, k - 1);
            }
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    
    return 0;
}
