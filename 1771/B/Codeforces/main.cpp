//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1771/problem/B)
 **题目大意：**
 给出1到n的n个整数的数组，现在需要从数组里面选择新的数组，但是已知有m对整数是不能共存：
 比如说整数2和4不能共存，则新的数组里面不能同时存在2和4，比如说整数数组[1,2,3,4,5]，其中[2,3]和[3,4]都是合法的，[2,3,4]是不合法的；
 现在想知道，能选出多少个子数组，里面不存在不合法的整数对。
 
  **输入：**
 第一行，整数𝑡 表示t个样例𝑡 (1≤𝑡≤2⋅1e4),
 每个样例第一行整数 𝑛  and 𝑚 (2≤𝑛≤1e5, 0≤𝑚≤1e5)
 接下来m行整数 𝑥𝑖  and 𝑦𝑖 (1≤𝑥𝑖,𝑦𝑖≤𝑛, 𝑥𝑖≠𝑦𝑖)，表示两个不能相互相处的整数。
  
 **输出：**
 每个样例一行，输出满足要求的组合数。
 
 
 **Examples**
 **input**
 2
 3 2
 1 3
 2 3
 4 2
 1 2
 2 3
 **output**
 4
 5
 样例解释：
 样例1，满足要求的有整数[1],[2],[3],[1,2]；
 样例2，满足要求的有整数[1],[2],[3],[4],[3,4]；
 
 
 
 **题目解析：**
 对于子数组[x, y]，我们可以枚举做区间x，再考虑y的取值；
 首先y要满足x <= y，考虑所有y的取值，只要包括一个不能相处整数对，那么后续的整数就不用考虑，比如说样例2：
 x=1，我们考虑y=1,2,3,4的情况，当我们发现整数1和2是不能相处的，那么2以及2后面的整数就不用考虑；
 也即是说，我们只需要向右遍历到第一个出现的最小不能相处整数对的右区间y，[x, x]到[x, y-1]的区间都是合法的；
 
 现在的问题变成了，对于选定整数x，如何快速得到右边区间最小的整数对；
 假设我们把所有不合法整数对都按照左区间归类，然后从右到左遍历整数数组。
 比如说遍历到整数i，那么对于所有做左区间≥i的整数对，都是在i的右边；
  
 
 
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
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        int tmp = 0;
        while (t--) {
            ++tmp;
            int n, m;
            map<int, vector<int> > mp;
            cin >> n >> m;
            while (m--) {
                int x, y;
                cin >> x >> y;
                if (x < y) {
                    mp[x].push_back(y);
                }
                else {
                    mp[y].push_back(x);
                }
            }
            lld sum = 0;
            int leftMin = n + 1;
            for (int i = n; i > 0; --i) {
                if (mp[i].size()) {
                    sort(mp[i].begin(), mp[i].end());
                    leftMin = min(leftMin, mp[i][0]);
                }
                sum += leftMin - i;
            }
            cout << sum << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
