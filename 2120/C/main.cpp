//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2120/problem/C)
C. 神圣之树（Divine Tree）
Harshith 通过在一棵神圣之树下训练，在竞技编程中获得了顿悟。
神圣之树是一棵有n个节点的有根树*，节点编号从1到n。
节点u的“神圣度”，记为d(u)，定义为从根到节点u的唯一简单路径上的最小节点编号。
Aryan 作为一名求知若渴的竞技程序员，请求 Harshith 传授知识。
Harshith 同意的条件是，Aryan 要给定两个正整数n和m，并且他必须构造一棵有n个节点的神圣之树，使得这棵树的总神圣度为m。
如果不存在这样的树，Aryan 必须报告这是不可能的。
由于极度渴望知识，Aryan 向你求助来完成这项任务。作为他的好朋友，帮他解决这个问题吧。
（树是没有环的连通图。有根树是指其中一个顶点是特殊的，被称为根的树）

输入
每个测试包含多个测试用例。第一行包含测试用例的数量t（1 ≤ t ≤ 10⁴）。
接下来是各测试用例的描述。
每个测试用例的第一行包含两个整数n和m（1 ≤ n ≤ 10⁶，1 ≤ m ≤ 10¹²）。
保证所有测试用例中n的总和不超过10⁶。

输出
对于每个测试用例，在一行中输出一个整数k —— 树的根。
然后是n - 1行，每行描述树的一条边 —— 一对正整数uᵢ, vᵢ（1 ≤ uᵢ, vᵢ ≤ n，uᵢ ≠ vᵢ），表示第i条边连接顶点uᵢ和vᵢ。
边和边的顶点可以按任意顺序输出。如果有多个解决方案，输出任意一个即可。
如果没有解决方案，输出“-1”。

示例 
输入 
2
1 2
4 6

输出 
-1
3
3 1
1 2
2 4

 
**题目解析：**
假设只有一个节点，那么d(1) = 1，m = 1；
假设只有两个节点，只有一种结构，那么d(1) = 1, d(2) = 1，m = 2；
假设只有两个节点，那么有两种结构，串行（A-B-C，三点一线）和并行（A-B和A-C，A是根节点)；
如果根节点是1，此时结果最小，对于任何节点i都有d(i)=1，结果m = n；
如果根节点是3，结构是3-2-1或者3-2、3-1，此时结果最大，d(1）=1, d(2) = 2, d(3) = 3，m = 1 + 2 + 3 = 6；

分析到此，我们可以知道，有n个节点的树，我们可以选择根为1，此时最终的m最小，并且是n；
而全部并行（全部直连根节点），且根节点为n的情况下，最终的m最大，并且结果是1+2+3+...+n=n*(n+1)/2；
所以m有解取值范围是[n, n*(n+1)/2)]；

下面来分析如何构造一个合适的树。
我们从m值最大的情况，也就是根节点为n，其他节点全部直连根节点的情况开始。
当根节点为k的情况下，某个节点i直连根节点，那么d(i) = i；
我们把节点i的父节点改为1，那么会d(i)=1，此时总的m会减少（i-1）；
如果把所有节点都改为父节点是1，那么总共会减少（1+2+3+...+n-1）=n*(n-1)/2；
我们从n-1节点开始往节点1开始枚举，只要剩余m值大于当前节点，就把当前节点父亲节点分配到节点1，我们最多可以覆盖[n+n-1， n*(n+1)/2]的m值；

对于(n, n+n-1）这个区间，我们可以用根节点为2的情况，同样类似上面的方式来处理。

至于n的情况，我们就用根节点为1即可。



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
    static const int N = 1100100;
    lld ans[N];
public:
    void solve() {
        lld t;
        cin >> t;

        while (t--) {
            lld n, m;
            cin >> n >> m;
            if (m < n || m > n * (n + 1) / 2) {
                cout << -1 << endl;
                continue;;
            }
            lld root;
            if (n == m) {
                root = 1;
                for (int i = 1; i <= n; ++i) {
                    ans [i] = 1;
                }
            }
            else if (m < 2 * (n - 1) + 1) {
                root = 2;
                for (int i = 1; i <= n; ++i) {
                    ans [i] = 2; // root node
                }
                lld k = 2 * (n - 1) + 1;
                for (int i = n; i > 2; --i) {
                    if (k > m) {
                        ans[i] = 1;
                        k -= 1;
                    }
                }
            }
            else  {
                root = n;
                for (int i = 1; i <= n; ++i) {
                    ans [i] = n; // root node
                }
                lld k = n * (n + 1) / 2 - m;
                for (int i = n - 1; i > 1; --i) {
                    if (k >= (i - 1)) {
                        ans[i] = 1;
                        k -= i - 1;
                    }
                }
           }  
           cout << root << endl;
            for (int i = 1; i <= n; ++i) {
                if (ans[i] != i) cout << ans[i] << " " << i << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
