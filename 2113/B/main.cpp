//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2113/problem/B)
 B. 良好开端

屋顶是一个尺寸为w×h的矩形，其左下角在平面上的点(0, 0)处。你的团队需要用尺寸为a×b的相同屋面板完全覆盖这个屋顶，需满足以下条件：
- 屋面板不能旋转（即使旋转90度也不行）。
- 屋面板之间不能重叠（但边缘可以接触）。
- 屋面板可以延伸到矩形屋顶的边界之外。

你团队的一名新手已经以屋面板不重叠且每块都部分覆盖屋顶的方式，在屋顶上放置了两块这样的屋面板。
你的任务是判断，在不移除已放置的这两块屋面板的情况下，是否有可能完全铺满屋顶。

输入
每个测试包含多个测试用例。第一行包含测试用例的数量t（1 ≤ t ≤ 10⁴）。接下来是各测试用例的描述。
每个测试用例的第一行包含四个整数w、h、a、b（1 ≤ w, h, a, b ≤ 10⁹）——分别是屋顶的尺寸和屋面板的尺寸。
每个测试用例的第二行包含四个整数x₁、y₁、x₂、y₂（-a + 1 ≤ x₁, x₂ ≤ w - 1，-b + 1 ≤ y₁, y₂ ≤ h - 1）——已放置屋面板左下角的坐标。保证这些屋面板不重叠。

输出
对于每个测试用例，如果在不移除已放置的两块屋面板的情况下有可能完全铺满屋顶，输出“Yes”（不加引号）；否则输出“No”（不加引号）。
你可以用任意大小写输出答案。例如，字符串“yEs”、“yes”、“Yes”和“YES”都会被视为有效肯定回复。

示例
输入
7
6 5 2 3
-1 -2 5 4
4 4 2 2
0 0 3 1
10 9 3 2
0 0 4 3
10 9 3 2
0 0 6 3
5 5 2 2
-1 -1 4 -1
5 5 2 2
-1 -1 2 3
7 8 2 4
0 0 0 5


输出
Yes
No
No
Yes
No
Yes
No




 
**题目解析：**
先假设只有一个已存在木板的情况，由于题目要求允许木板延伸到边界之外，那么只需要从已存在木板按照边缘对齐的方式开始向外延伸，最终总是能铺满整个区域；
那有两个木板的情况呢？
先考虑两个木板横坐标相同，纵坐标有差别的情况，此时上下间距如果是木板高的整数倍，那么一定可以铺满；（如果不是整数倍，那么中间要么放不下，要么留下空隙）
再考虑两个木板纵坐标相同，横坐标有差别的情况，此时左右间距如果是木板宽的整数倍，那么一定可以铺满；（道理同上）
如果横纵坐标都不相同，那么上面两种情况都可以考虑，比如说顺着原来已有木板上下延伸，这样肯定可以铺出来两条线，接下来就看两条线中间是否能够铺满即可；
如果两条线中间的间距不是木板高的整数倍，那么一定无法铺满。
 
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
            int w, h, a, b;
            int x1, y1, x2, y2;
            cin >> w >> h >> a >> b;
            cin >> x1 >> y1 >> x2 >> y2;
            bool ans = 0;
            if (x1 == x2) {
                if (abs(y1 - y2) % b == 0) {
                    ans = 1;
                }
            }
            else if (y1 == y2) {
                if (abs(x1 - x2) % a == 0) {
                    ans = 1;
                }
            }
            else {
                if (abs(x1 - x2) % a == 0 || abs(y1 - y2) % b == 0) {
                    ans = 1;
                }
            }
            cout << (ans ? "Yes" : "No") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
