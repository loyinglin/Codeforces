//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2113/problem/C)
 C. 斯米洛与《我的世界》（Smilo and Minecraft）

男孩斯米洛正在玩《我的世界》！为了准备与末影龙的战斗，他需要大量的金苹果，而这需要很多金子。因此，斯米洛前往矿井。
矿井是一个尺寸为n×m的矩形网格，每个单元格可能是金矿石、石头或空单元格。斯米洛可以在任意空单元格引爆炸药。
当炸药在坐标为(x, y)的空单元格爆炸时，以(x, y)为中心、边长为2k + 1的正方形内的所有单元格都会变成空的。
如果金矿石严格位于这个正方形内部（不在边界上），它会消失。
然而，如果金矿石位于这个正方形的边界上，斯米洛会收集到那些金子。
炸药只能在矿井内部引爆，但爆炸形成的正方形可能会延伸到矿井边界之外。
确定斯米洛能收集到的最大金子数量。

输入
每个测试包含多个测试用例。第一行包含测试用例的数量t（1 ≤ t ≤ 10⁴）。接下来是各测试用例的描述。
每个测试用例的第一行包含三个整数n、m、k（1 ≤ n, m, k ≤ 500）——分别表示行数、列数和爆炸参数k。
接下来的n行，每行包含m个字符，字符为'.'、'#'或'g'，其中'.'表示空单元格，'#'表示石头，'g'表示金子。保证至少有一个单元格是空的。
保证所有测试用例的n·m之和不超过2.5·10⁵。

输出
对于每个测试用例，输出一个整数——能获得的最大金子数量。

示例
输入
3
2 3 1
#.#
g.g
2 3 2
#.#
g.g
3 4 2
.gg.
g..#
g##.


输出
2
0
4

 
**题目解析：**
注意题目限制，爆炸的次数并没有任意限制，并且爆炸区域是可以超出边界；
并且由于爆炸之后，会把爆炸区域内的所有东西都清空，包括之前已经有的东西，也就是会制造新的空格子。
那么，选择哪个空格子开始爆炸，以及爆炸的先后顺序都会影响最终答案。
先从k=1的情况开始考虑，此时爆炸区域和收获区域相同，那么随便找一个空格子放置炸弹，然后不断沿着爆炸边缘的空格子继续爆炸，直到没有空格子；
由于题目限制，至少存在一个空格子，那么结果就是所有金子数量。
再考虑k=2的情况，当我们选择某个位置(x, y)开始爆炸之后，我们只需要沿着(x+1, y)和（x, y+1）的位置继续放炸弹，这样总是能炸完整个区域；
并且除了最初格子之外的金子我们都能收获。
那么k=2就是找到一个空格子，以该格子为爆炸中心，所损失的金子数最少的，那么最终收获的格子就会尽可能多。
题目就变成了：寻找一个空格子为中心，爆炸距离为(k-1)范围内的金子数量最少的区域。

遍历整个区域，找到空格子，一共有O(N²）的复杂度；
每个格子的计算成本，也是需要遍历矩形，单次复杂度是O(N²）；
那么总的复杂度就是O(N^4），整体复杂度会比较高。

遍历的复杂度比较容易优化，我们可以先计算好每个空格子到左上角（0，0）的金子数量sum[i][j]，那么在计算金子数量时，可以用公式：
sum[i+k-1][y+k-1] - sum[x-k][y] - sum[x][y-k] + sum[x-k][y-k]；
这样计算的复杂度可以控制在O(1)，那么总体复杂度是O(N^2）；

 
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
    static const int N = 501;
    char s[N][N];
    int sum[N][N];

public:
    void solve() {
        int t;
        cin >> t;
        
        while (t--) {
            int n, m, k;
            cin >> n >> m >> k;
            for (int i = 0; i < n; ++i) cin >> s[i];
            int all = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    sum[i][j] = (s[i][j] == 'g') + (i ? sum[i-1][j] : 0) + (j ? sum[i][j-1] : 0) - (i && j ? sum[i-1][j-1] : 0);
                    all += (s[i][j] == 'g');
                }
            }
            int ans = 500 * 500;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (s[i][j] == '.') {
                        int x = i + k - 1, y = j + k - 1;
                        x = min(n - 1, x);
                        y = min(m - 1, y);
                        int tmp = sum[x][y] - (i >= k ? sum[i - k][y] : 0) - (j >= k ? sum[x][j - k] : 0) + (i >= k && j >= k ? sum[i - k][j - k] : 0);
                        ans = min(ans, tmp);
                    }
                }
            }
            cout << all - ans << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
