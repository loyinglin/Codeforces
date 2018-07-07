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
 
 输入：
 第一行 s a, b and c (0 ≤ a, b, c ≤ 1e5)
 第二行 m (0 ≤ m ≤ 3·1e5)
 接下来m行 每行 val[i] 和 鼠标支持类型 (1 ≤ val[i] ≤ 1e9)
 输出：
 最多能支持的电脑数量还有总价格；
 
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
 
 
 
 
 题目解析：
 要求首先是支持的电脑数量最多，其次再是价格最低。
 电脑与电脑之间的差别：电脑类型A（USB接口）和电脑类型B（PS/2接口）兼容性比电脑类型C（两种接口都支持）差，那么应该优先支持类型A、B；
 鼠标与鼠标之间的差别：同类型的鼠标，价格低者应该优先使用，这样总价格会更低；
 综合这两者的差异，可以得到一个贪心的策略：
 对鼠标按价格排序，从价格小的开始选；在配电脑的时候，优先选择类型A/B，如果没有再选择类型C。
 
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
