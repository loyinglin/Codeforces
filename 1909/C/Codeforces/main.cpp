//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1909/problem/C)
 **题目大意：**
 有n个整数区间[𝑙1,𝑟1],[𝑙2,𝑟2],…,[𝑙𝑛,𝑟𝑛]，每个区间有一个系数 𝑐𝑖，每个区间的重量为𝑐𝑖⋅(𝑟𝑖−𝑙𝑖).
 现在可以进行下列操作：
 1、任意调换n个整数区间，左区间l的数字；
 2、任意调换n个整数区间，右区间r的数字；
 3、任意调换n个整数区间，系数c的数字；
 要求调换完，每个区间 [𝑙𝑖, 𝑟𝑖] 都满足 𝑙𝑖 < 𝑟𝑖;
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例有4行
 第一行，整数 𝑛 (1≤𝑛≤2e5)
 第二行，整数 𝑙1,𝑙2,…,𝑙𝑛(1≤𝑙𝑖≤2⋅1e5)
 第三行，整数 𝑟1,𝑟2,…,𝑟𝑛 (𝑙𝑖<𝑟𝑖≤2⋅1e5)
 第四行，整数𝑐1,𝑐2,…,𝑐𝑛   (1≤𝑐𝑖≤1e7 )
 
 题目保证，{𝑙1,𝑙2,…,𝑙𝑛,𝑟1,𝑟2,…,𝑟𝑛}数字各不相同。
  
 **输出：**
 每个样例一行，输出调整后，所有区间的最小重量和。
 
 **Examples**
 **input**
 2
 2
 8 3
 12 23
 100 100
 4
 20 1 2 5
 30 4 3 10
 2 3 2 3


 **output**
 2400
 42

 **题目解析：**
 题目允许对l、r、c进行任意调换，那么可以先对l、r、c进行从小到大排序，便于分析问题。
 接下来做数据分析，先考虑n=2的情况
 a1  a2
 b1 b2
 c1 c2
 正常情况下 (b1-a1)*c1 + (b2 - a2)*c2
 先考虑c1和c2的情况，假设b1-a1和b2-a2相等，那么调换c1和c2对于结果没有影响。
 假设b1-a1<b2-a2呢？ 这次c1<c2就会导致更小的结果，应该把更大的数字放在前面。
 
 延伸分析，假设有若干个区间长度，那么可以将区间长度从小到大排序，接着把c越大的匹配到越前面的结果。
 
 接下来，就是怎么匹配出来若干个区间长度，并且保证结果符合要求。
 首先还是从2个区间开始分析
 a1  a2
 b1 b2
 我们知道最终两个区间的和，不管如何交换，必然是 (b1 - a1) + (b2 - a2)。
 那在这种情况下，我们让其中一个区间尽可能小，另外一个区间必然会增大。
 
 沿着这个贪心思路，我们只需要每次让右区间，去匹配到尽可能接近的左区间。
 有一个简单实现方案，对于每一个左区间（从大到小开始），我们从大到小去遍历右区间，找出来一个最近的节点。
 但是这样的复杂度是O(N x N)；
 
 我们可以引入优先队列来简化操作，在选择右区间的时候，big队列表示前面选择过的节点队列，从大到小排列，这样就可以直接从big队列中找到之前遍历过的最大值；
 backup表示还没有被选择过的节点，从小到大排列，这样当big队列最大值都无法满足要求，就需要从backup中取数字。
 这样整体的复杂度就可以降低到NlogN的级别。


 
 5
 50 100 150 200 300
 201 250 301 400 300
 100 1 1 1 1
 
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
 
class Solution {
    static const int N = 201010;
    priority_queue<int> big;
    priority_queue<int, vector<int>, greater<int> > backup;
    int a[N], b[N], c[N], diff[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) cin >> b[i];
            for (int i = 0; i < n; ++i) cin >> c[i];
            sort(a, a + n);
            sort(c, c + n);
            for (int i = 0; i < n; ++i) backup.push(b[i]);
            for (int i = n - 1; i >= 0; --i) {
                int cur = 0;
                if (!big.empty()) {
                    cur = big.top();
                }
                if (cur < a[i]) { // 当前big堆里不满足
                    while (cur < a[i]) {
                        cur = backup.top();
                        big.push(cur);
                        backup.pop();
                    }
                    big.pop();
                }
                else {
                    big.pop();
                    while (big.size() && big.top() > a[i]) {
                        backup.push(cur);
                        cur = big.top();
                        big.pop();
                    }
                }
                diff[i] = cur - a[i];
//                cout << "match: " << cur << " " << a[i] << endl;
            }
            sort(diff, diff + n);
            lld ans = 0;
            for (int i = 0; i < n; ++i) ans += diff[i] * 1LL * c[n - 1 - i];
            cout << ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
