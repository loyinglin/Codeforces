//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/762/problem/B
 题目大意：
 机房有三种电脑，一种只有USB接口，一种只有PS/2接口，一种是两种接口均有，数量分别为a、b、c；
 现在机房希望给电脑配上鼠标，鼠标有两种，一种只支持USB，一种只支持PS/2；
 鼠标有m个，每个仅能用于一台电脑，价格为val[i]；
 
 现在希望能支持尽可能多的电脑，如果有多个选择，选择总价格最低的。
 输出：最多能支持的电脑数量还有总价格；
 
 Example
 input
 2 1 1
 4
 5 USB
 6 PS/2
 3 PS/2
 7 PS/2
 output
 3 14
 
 
 s a, b and c (0 ≤ a, b, c ≤ 1e5)
 m (0 ≤ m ≤ 3·1e5)
 val[i] (1 ≤ val[i] ≤ 1e9)
 
 
 题目解析：
 对鼠标按价值排序，尽可能选即可。（贪心：优先选择a和b，如果没有再选c）
 
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
const int N = 301000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

pair<int, string> mouse[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> mouse[i].first >> mouse[i].second;
    }
    sort(mouse, mouse + m);
    
    int ansCount = 0;
    lld ansCost = 0;
    for (int i = 0; i < m; ++i) {
        if (mouse[i].second[0] == 'U') { //use
            if (a) {
                --a;
                ++ansCount;
                ansCost += mouse[i].first;
            }
            else if (c) {
                --c;
                ++ansCount;
                ansCost += mouse[i].first;
            }
        }
        else {
            if (b) {
                --b;
                ++ansCount;
                ansCost += mouse[i].first;
            }
            else if (c) {
                --c;
                ++ansCount;
                ansCost += mouse[i].first;
            }
        }
    }
    
    cout << ansCount << " " << ansCost << endl;
    
    return 0;
}
