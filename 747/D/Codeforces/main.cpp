//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/747/problem/D
 题目大意：
 小明要过冬，冬天持续n天，每天有一个天气温度，用a[i]表示；
 小明有两件衣服，分别是summer和winter的，每天只能选择穿一件衣服；
 summer只能在温度>=0的时候穿，winter的衣服可以在任何温度穿；
 summer的衣服不容易坏，但是winter的衣服只能穿k天；
 每天早上，小明可以选择换一次衣服，一开始的时候小明是穿summer 的衣服；
 问最少需要换多少次衣服，小明才能过冬？如果不能，就输出-1.
 
 
 题目解析：
 询问的是最小的改变次数，先考虑动态规划。
 需要记录的状态有当前已改变的次数，每次的抉择是换或者不换；
 但是因为最大的改变次数可能为n，状态数过多，动态规划不可取。
 
 从另外一个角度来思考，能不能过冬，取决于零度以下的天数。
 那么先假设所有的冬天都穿winter的衣服，这样可以得到能否过冬。
 此时穿衣的规则是遇到零度以下就穿winter，遇到零度及以上就穿summer，如果今天穿衣服和昨天不一样，那么改变次数加一；
 这样得到最多的改变次数，但是保证能过冬天（如果winter的衣服够穿）
 剩下的天数，再尽可能分配到winter与winter之间，减少改变次数。
 
 
 n = 8，k = 4
 0 0 -1 0 0 -1 0 0
 
 分别第3、4、6、7天换衣服，winter的衣服用了2天，可以过冬。
 剩下的2天可以分配到[1, 2], [4, 5], [7, 8]这三个区间，得到的最小的改变次数分别是4，2，3次。
 可以看得出来，把天数分配前第一个winter前面是没有意义的，分配给最后一个winter只能减少一次，分配给winter之间的能减少两次。
 
 于是算法就变成：
 1、统计winter的数量，以及winter之间天数，再统计最后一个winter到最后天数；
 2、减去winter的天数，剩下的衣服耐久度，从间隔最小开始分配给winter之间的天数，每分配减少2次；最后看剩下的天数够不够最后一个winter到末尾的天数，够的话再减一。
 
 代码实现：
 为了方便实现，在前面和最后加0。
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int pos, days;
    
    bool operator<(const Node &tmp) const
    {
        if (tmp.days != days) return days > tmp.days;
        else return pos > tmp.pos;
    };
    Node(int x, int y):pos(x), days(y){};
    Node(){};
}node[N];

int a[N];


int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i] < 0; // a[i] = 1 表示winter
    }
    vector<int> vec;
    int cnt = 1, winter = 0, ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] != a[i - 1]) { //
            if (a[i - 1]) {
                winter += cnt;
            }
            else {
                vec.push_back(cnt);
            }
            cnt = 1;
            ++ans;
        }
        else {
            ++cnt;
        }
    }
    if (cnt > 1) {
        vec.push_back(cnt - 1);
    }
    else {
        vec.push_back(0);
    }
    
    if (winter == 0) {
        cout << 0 << endl;
    }
    else if (winter > k) {
        cout << -1 << endl;
    }
    else {
        sort(vec.begin() + 1, vec.end() - 1); // 最后一个排除
        k -= winter;
        for (int i = 1; i + 1 < vec.size(); ++i) {
            if (vec[i] <= k) {
                k -= vec[i];
                ans -= 2;
            }
        }
        if (vec.back() <= k) {
            ans -= 1;
        }
        cout << ans << endl;
    }
    
    
    
    return 0;
}
