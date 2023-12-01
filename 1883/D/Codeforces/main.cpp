//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1883/problem/D)
 **题目大意：**
 有一个线段集合，初始状态是空的；现在有两个操作：
 1、往集合中增加线段[l, r]；
 2、移除集合中的一条线段[l, r]；
 
 问每次操作后，集合中是否存在未与其他线段先交的线段。
 
 **输入：**
 第一行，整数𝑞 表示𝑞个操作  (1≤𝑞≤105 )
 每个操作一行，可能有两种情况：
 情况1，+   𝑙  𝑟；(1≤𝑙≤𝑟≤1e9).
 情况2，− 𝑙 𝑟;；(1≤𝑙≤𝑟≤1e9).
 
 **输出：**
 每个操作一行，输出操作后数组是否存在满足要求线段；如果存在则输出YES，如果不存在则输出NO；
 
 **Examples**
 **input**
 12
 + 1 2
 + 3 4
 + 2 3
 + 2 2
 + 3 4
 - 3 4
 - 3 4
 - 1 2
 + 3 4
 - 2 2
 - 2 3
 - 3 4

 **output**
 NO
 YES
 YES
 YES
 YES
 YES
 NO
 NO
 YES
 NO
 NO
 NO



 **题目解析：**
 
 可以将集合进行预处理，先按照左区间从小到大，相同左区间起点的可以放在一个桶里，再按照右区间从小到大；
 这样对于某一条线段，要判断与其他所有线段的关系，可以通过当前桶和右桶的关系来判断相交；（假设我们所有线段都只考虑是否与右侧相交，如果某条线段都不能超过右边桶，那么更不可能与右边桶更右边的线段相交）
 
 接下来分情况讨论，对于add操作：
 情况1，当前是NO（表示已经有线段相交），那么add不影响；
 情况2，当前是YES（表示未有线段相交），那么add操作可能会形成新的交集，并且这个交集必然包括新的线段，那么只需判断这个线段是否与其他线段相交；=》直接遍历存量所有线段判断是否与新线段相交，复杂度是O(n)；经过预处理只需判断这个新加线段所在的桶，与右边第一个桶相交即可，复杂度为O（1）；
 
 对于remove操作：
 情况1，当前是NO（表示已经有线段相交），那么remove可能会导致交集消失，需要重新对集合进行遍历；复杂度为O（N）；
 情况2，当前是YES（表示未有线段相交），则remove操作无影响；
 
 
 remove的情况1是一个耗时较长点。理论上有可能会导致整体复杂度变为O(N^2)，超过了题目限制。
 
 
 
 
 
 
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            int ans = 0, cnt = 0;
            while (n--) {
                int tmp;
                cin >> tmp;
                if (tmp % k) ans = max(ans, tmp % k);
                else ans = k;
                while (tmp % 2 == 0) {
                    ++cnt;
                    tmp /= 2;
                }
            }
            if (k == 4) {
                if (cnt >= 2) cout << 0 << endl;
                else cout << min(k - ans, 2 - cnt) << endl;
            }
            else {
                cout << (k - ans) << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
