//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1783/problem/C)
 **题目大意：**
 小明和n个人参加比赛，已知n个人的序号分别为1、2、3、、、n；
 当n个人中的两个人（序号i和j）内部比赛时，假如i < j,则序号j的选手获胜；（即n个人比赛，序号大者获胜）；
 当小明与n个人中的一个比赛时，对于选手i，小明需要花费a[i]时间进行准备，如果有充足时间准备则能胜出，否则会落败；
 已知小明一共有m的时间进行比赛，同一时间只能准备一个选手；
 最终名次就是胜场较多人数的+1，比如说胜场比小明多的人数一共有5人，那么小明就是第6名；（其他胜场和小明一样多的人，并列第6名）
 问小明最的获胜名次最好是多少。（越低越好）
 
 **输入：**
 第一行，整数𝑡 表示t个样例   𝑡(1≤𝑡≤1e4)
 每个样例2行，第一行整数 𝑛 and 𝑚 (1≤𝑛≤5⋅1e5)
 第二行n个整数𝑎1,𝑎2,…,𝑎𝑛(0≤𝑎𝑖≤1000)
  
  
 **输出：**
 每个样例1行，输出小明最好的名次。
  
 
 **Examples**
 **input**
 5
 4 401
 100 100 200 1
 3 2
 1 2 3
 5 0
 1 1 1 1 1
 4 0
 0 1 1 1
 4 4
 1 2 2 1


 **output**
 1
 2
 6
 4
 1

 
 **题目解析：**
 如果时间比较充裕，那么足够准备所有人的比赛；
 当时间不够时，通常的选择是优先准备耗时较少的选手；但是在这个题目中，会产生额外的影响：
 如果我们没有针对某个选手准备，则该选手都胜场会+1，从而影响到自己的名次。
 所以决策是否针对某个选手准备时候，要考虑当前的因素。
 
 由此，我们产生一个简单的策略：
 先将准备时间从小到大排序，然后我们从耗费时间小的开始准备，直到某个选手的准备时间不够；
 此时我们先不要花时间准备，而是用剩下的时间，将所有能够准备的选手筛出，选择一个胜场数量等于小明胜场+1的选手进行准备；（如果不选他，他就会排在小明前面，选了他则并列）剩下的胜场数相同、胜场数少于小明的，并不会因为小明的选择而影响名次；
 然后接下来的选手，由于我们无法准备，所有的选手胜场+1；
 至此，我们得到一个解，胜场x，以及每个选手的胜场，得到最终的名次。
 
 
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

bool lycmp(pair<int, int> x, pair<int, int> y) {
    if (x.first != y.first) return x.first < y.first;
    else return x.second > y.second;
}
 
class Solution {
    static const int N = 601000;
    pair<int, int> a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < n; ++i) {
                cin >> a[i].first;
                a[i].second = i;
            }
            sort(a, a + n, lycmp);
            if (a[0].first > m) {
                cout << n + 1 << endl;
                continue;;
            }
            int index = -1, win = 0;
            while (index < n) {
                if (a[index + 1].first <= m) {
                    m -= a[index + 1].first;
                    ++win;
                    ++index;
                }
                else {
                    break;
                }
            }
            
//            for (int i = 0; i < n; ++i) {
//                cout << a[i].first << " " << a[i].second << endl;
//            }
//            cout << "index " << index << endl;
            for (int i = index; i < n; ++i) {
                if (a[index].first + m >= a[i].first && a[i].second == win) {
                    a[i].second -= 1;
                    break;
                }
            }
            int ans = 1;
            for (int i = 0; i < n; ++i) {
                if (i < index && a[i].second > win) ++ans;
                else if (i >= index && a[i].second >= win) ++ans;
            }
//            cout<< "ans ";
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
 
