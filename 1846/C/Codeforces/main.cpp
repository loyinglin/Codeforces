//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/C)
 **题目大意：**
 有n个人参加竞赛，竞赛有m个题目，每个题目需要耗费t[i][j]的时间；
 小明是参赛者1号，竞赛总时长为h；
 排名规则：
 解答题目数多者优先，如果题目相同则耗时少则优先，耗时为每个题目解答时比赛已经进行的时间；
 
 问，最终小明的排名是多少，假设每个参赛者都会用最优解去处理。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例第一行整数𝑛,𝑚,ℎ(1≤𝑛⋅𝑚≤2⋅1e5,1≤ℎ≤1e6)
 接下来n行，每行有m个整数，表示𝑡𝑖,𝑗 (1≤𝑡𝑖,𝑗≤1e6 )
 
 **输出：**
 每个样例一行，输出小明最终的排名。
 
 **Examples**
 **input**
 5
 3 4 2
 1 4 5
 1 5 1
 3
 4 6 6
 1 2 3 4
 2 1 200000
 1 200000
 2 4 3
 9 11


 **output**
 11
 2.5
 34.5
 199999.9999975
 11.333333



 **题目解析：**
 模拟题，首先理解每个选手的最优解，必然是优先做耗时少的题目，再做耗时多题目；
 那么对每个选手的题目耗时进行排序，从时间最小开始做题，直到时间消耗完毕或者题目做完；
 
 接下来对n个人的成绩进行排序，这里可以用sort+pair+自定义排序来实现。
 最后遍历结果，找到小明题数和耗时所在名次即可。

  
 
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
    static const lld N = 201010;
    vector<lld> a[N];
    pair<lld, lld> result[N];
    
    static bool cmp(pair<lld, lld> x, pair<lld, lld> y) {
        if (x.first != y.first) return x.first > y.first;
        else return x.second < y.second;
    }
    
public:
    void solve() {
        lld t;
        cin >> t;
        while (t--) {
            lld n, m, h;
            cin >> n >> m >> h;
            for (lld i = 0; i < n; ++i) {
                a[i].clear();
                for (lld j = 0; j < m; ++j) {
                    lld tmp;
                    cin >> tmp;
                    a[i].push_back(tmp);
                }
                sort(a[i].begin(), a[i].end());
            }
            for (lld i = 0; i < n; ++i) {
                lld tmp = 0, cnt = 0, time = 0;
                for (lld j = 0; j < m; ++j) {
                    if (tmp + a[i][j] <= h) {
                        tmp += a[i][j];
                        ++cnt;
                        time += tmp;
                    }
                }
                result[i] = make_pair(cnt, time);
            }
            pair<lld, lld> ans = result[0];
            lld out = 0;
            sort(result, result + n, cmp);
            for (lld i = 0; i < n; ++i) {
                if (result[i].first == ans.first && result[i].second == ans.second) {
                    out = i;
                    cout << out + 1 << endl;
                    break;
                }
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
 
