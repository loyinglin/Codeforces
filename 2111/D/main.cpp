//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2111/problem/D)
 **题目大意：**
一个新学期即将开始，有必要为第一天制定一个课程表。
学院里总共有n个小组和m间教室。
已知每个小组在第一天恰好有6节课，并且每个小组的第k节课都在同一时间进行。
每节课必须在一间教室进行，且同一时间，一间教室不能有多个小组的课程。

每间教室都有自己的编号（至少三位数字 ），除最后两位数字外，编号的所有数字表示该教室所在的楼层。
例如，教室479位于4楼，而教室31415位于314楼。
楼层之间可以通过楼梯上下；对于任意楼层x，既可以下到楼层x - 1，也可以上到楼层x + 1；
从一楼出发，只能上到二楼；从楼层10^7（最后一层 ）出发，只能下到楼层9999999。

学院院长办公室决定制定这样的课程表，使得学生在楼层之间的移动尽可能多，即所有小组在楼层之间移动的总次数要最大化。
当学生从一个楼层移动到另一个楼层时，他们走的是最短路径。

例如，如果有(n = 2)个小组，(m = 4)间教室([479, 290, 478, 293])，课程表可以安排如下：（从上到下分别是第1~6节课）
293 290
479 478
290 293
478 479
293 290
479 478
在这样的课程表中，小组每次都会在2楼和4楼之间移动，楼层间移动的总次数为20次。

帮助院长办公室制定合适的课程表！

输入
第一行包含一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
每个测试用例的第一行包含两个整数n和m (1 ≤ 𝑛 ≤ 𝑚 ≤ 1e5) ——— 小组数量和可用教室数量。
每个测试用例的第二行包含m个整数𝑎𝑖  (100 ≤ 𝑎𝑖 < 1e9) ）——— 可用教室的编号。
输入的额外约束：
- 所有教室的编号互不相同；
- 所有测试用例中m的总和不超过10^5。

输出
对于每个测试用例，输出n行，第i行应包含6个整数 —— 第i个小组6节课所在教室的编号。
在第k节课时，每间教室最多被一个小组使用。 
 
 **Examples**
 **input**
3
2 4
479 290 478 293
1 1
31415
6 10
479 385 290 293 384 383 297 478 291 382


**output**
290 478 293 479 293 479
293 479 290 478 290 478
31415 31415 31415 31415 31415 31415
479 290 479 290 479 290
290 479 290 479 290 479
293 478 293 478 293 478
297 385 297 385 297 385
478 293 478 293 478 293
291 384 291 384 291 384

290、291、293、297、382、383、384、385、478、479


 
**题目解析：**
先对题目数据做一个处理，由于题目只关注楼层间移动，那么我们可以把教室的编号去掉最后两位，变成一个数字；
假设只有一个小组，那么只需要找到最小和最大的教室编号，然后交替安排这两个教室的课程，就是最优解；
当有2个小组时，如果还是2个教室，那么依旧是最大和最小交替安排；
但是如果有3间教室？（我们用1、2、5）来表示，我们会发现，还是会使用最大和最小两个教室（1和5）；
不管有多少间教室，最大最小交替安排都是2个小组的最优解。

那么，我们可以采用这样的解法：
1、假如教室只有一间，那么就直接安排小组到这个教室；
2、假如教室有两间，那么就交替安排两个教室，给1个或者2个小组；
3、假如教室大于两间，那么拿出编号最最大最小的教室按照操作2进行分配，剩下的教室继续按照操作3或者2进行分配；
 
 
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
    static const int N = 101010;
    int a[N];
    int ans[N][6];
public:
    void solve() {
        int t;
        cin >> t;
        
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < m; ++i) {
                cin >> a[i];
            }
            sort(a, a + m);

            int indexLeft = 0, indexRight = m - 1;
            int indexLeftAns = 0, indexRightAns = n - 1;
            while (indexLeftAns <= indexRightAns)
            {
                int minRoom = a[indexLeft], maxRoom = a[indexRight];
                for (int i = 0; i < 6; ++i) {
                    ans[indexLeftAns][i] = minRoom;
                    ans[indexRightAns][i] = maxRoom;
                    swap(maxRoom, minRoom);
                }
                indexLeft++, indexRight--;
                indexLeftAns++, indexRightAns--;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    // cout << "test B" << endl;  
    freopen("data.in", "r", stdin);
    ac.solve();
    
    return 0;
}
 
