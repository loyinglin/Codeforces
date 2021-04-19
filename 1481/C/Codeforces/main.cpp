//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1481/problem/C)
 **题目大意：**
 给出n个栅栏，每个栅栏有一个初始颜色a[i]，现在想把n个栅栏的颜色染成b[i]；
 已知会有m个工人携带燃料c[j]先后过来，每个工人都必须对一个栅栏进行染色，并且工人染色的顺序会按照到达顺序（无法修改先后）；
 
 如果最终n个栅栏都可以染成目标颜色，则输出YES，然后输出m个数字，分别表示m个工人先后对m个栅栏进行的染色；
 如果最终无法都染成目标颜色，则输出NO；

 **输入：**
 **输出：**

 
 **Examples**
 **input**
 
 
 **output**
 
 
 **题目解析：**
 先找出数组a和数组b的差别，首先这些差别的颜色必须是数组c的子集，这样才有足够的颜色。
 但是他们还有一个要求是工人的达到顺序，所以如果存在最后某些颜色无法使用，则仍然会导致最终颜色一致。
 
 那么可以采用这样一种策略：如果最后一个工人的颜色是在数组b的第y个位置出现，那么前面所有不需要的颜色，都可以先放在位置y，等到最后一个工人把颜色刷成正确颜色；
 如果最后一个工人的颜色和数组b没有相似的，那么这个工人必然会导致最终的颜色不一致，此时无解。
 
 这里有一个小trick，在确定最后一个工人对应的位置y时，要优先选择a[y]!=b[y]的位置，避免浪费。
 
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

class Solution {
    static const int N = 100010;
public:
    int n, m;
    int a[N], b[N], c[N], ans[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n >> m;
            map<int, vector<int>> cnt;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            for (int i = 0; i < n; ++i) {
                cin >> b[i];
            }
            for (int i = 0; i < m; ++i) {
                cin >> c[i];
                ans[i] = -1;
                cnt[c[i]].push_back(i);
            }
            int y = -1;
            for (int i = 0; i < n; ++i) {
                if (b[i] == c[m - 1] && b[i] != a[i]) { // no waste
                    y = i;
                    break;
                }
            }
            for (int i = 0; i < n && y == -1; ++i) {
                if (b[i] == c[m - 1]) { // useless color
                    y = i;
                    break;
                }
            }
            
            bool ok = 1;
            if (y == -1) {
                ok = 0;
            }
            else {
                for (int i = 0; i < n; ++i) {
                    if (a[i] != b[i]) { // search color
                        if (cnt[b[i]].size() > 0) {
                            ans[cnt[b[i]].back()] = i;
                            cnt[b[i]].pop_back();
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                for (int i = 0; i < m; ++i) {
                    if (ans[i] < 0) {
                        ans[i] = y;
                    }
                }
                cout << "YES" << endl;
                for (int i = 0; i < m; ++i) {
                    cout << ans[i] + 1 << " ";
                }
                cout << endl;
            }
            else {
                cout << "NO" << endl;
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

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
