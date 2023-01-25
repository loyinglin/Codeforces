//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1679/problem/C)
 **题目大意：**
 有一个n x n的国际象棋棋盘，现在有3个操作：
 操作1，往棋盘（x，y）上面放一个车，车可以攻击同一行或者同一列；
 操作2，移除棋盘（x，y）上面的车；
 操作3，询问区域(𝑥1,𝑦1)到(𝑥2,𝑦2)内所有位置，是否都可以被车攻击到；
 现在有q个操作，想知道每次操作3 之后的结果；
 
  **输入：**
 第一行，整数 𝑛 and 𝑞 (1≤𝑛,𝑞≤2⋅1e5)
 接下来q行，每行第一个数字是t，表示操作1、2、3；
 如果t=1或者2，则接下来输入数字x和y； (1 ≤ 𝑥,𝑦 ≤ 𝑛)
 如果t=3，则接下来输入数字x1、y1、x2和y2； (1 ≤ 𝑥1 ≤ 𝑥2 ≤ 𝑛, 1 ≤ 𝑦1 ≤ 𝑦2 ≤ 𝑛)
  
 **输出：**
 每个操作3一行，输出YES或者NO；
 
 
 **Examples**
 **input**
 8 10
 1 2 4
 3 6 2 7 2
 1 3 2
 3 6 2 7 2
 1 4 3
 3 2 6 4 8
 2 4 3
 3 2 6 4 8
 1 4 8
 3 2 6 4 8
 
 **output**
 No
 Yes
 Yes
 No
 Yes
 
 **题目解析：**
 我们用row[N]和column[N]来表示行和列，那么添加(x, y)就可以拆分为row[x]和column[y]的变动；
 操作1和操作2比较简单，直接操作数组即可；
 操作3，朴素的想法是遍历所有行、列，看看是否满足，所有行或者所有列都被车覆盖；这样的复杂度复杂度是O(N)；
 分析这个遍历过程，当我们想知道row[x1]到row[x2]这个区间，是否全部为1，其实可以转化为前n项和之差：只要sum[x2] - sum[x1] = x2 - x1，就满足条件；
 于是问题转化为，如何快速维护sum[i]？（row前i个元素的和）
 这里偷个懒，用树状数组来支持。（就不展开介绍怎么用树状数组了，可以自己百度，有非常详细介绍）
 
 
 
 
 
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

class TreeArray {
    static const int N = 201001;
    int tree[N];
    
    int low_bit(int x)
    {
        return x&-x;
    }
    public:
    void tree_add(int x,int v, int n)
    {
        while(x<=n)
        {
            tree[x] += v;
            x+=low_bit(x);
        }
    }
    int tree_sum(int x)
    {
        int sum=0;
        while(x)
        {
            sum += tree[x];
            x-=low_bit(x);
        }
        return sum;
    }
};

class Solution {
    static const int N = 201001;
    TreeArray rowArr, columnArr;
    int rowCnt[N], columnCnt[N];

public:
    void solve() {
        int n, q;
        cin >> n >> q;
        while (q--) {
            int k;
            cin >> k;
            
            if (k == 1) {
                int x, y;
                scanf("%d%d", &x, &y);
                int add = 1;
                rowCnt[x] += add;
                if (rowCnt[x] == 1) {
                    rowArr.tree_add(x, add, n);
                }
                columnCnt[y] += add;
                if (columnCnt[y] == 1) {
                    columnArr.tree_add(y, add, n);
                }
            }
            else if (k == 2) {
                int x, y;
                scanf("%d%d", &x, &y);
                int add = -1;
                rowCnt[x] += add;
                if (rowCnt[x] == 0) {
                    rowArr.tree_add(x, add, n);
                }
                columnCnt[y] += add;
                if (columnCnt[y] == 0) {
                    columnArr.tree_add(y, add, n);
                }
            }
            else {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                int rowSum = rowArr.tree_sum(x2) - rowArr.tree_sum(x1 - 1);
                int columnSum = columnArr.tree_sum(y2) - columnArr.tree_sum(y1 - 1);
                if (rowSum == (x2 - x1 + 1) || columnSum == (y2 - y1 + 1)) {
                    cout << "Yes" << endl;
                }
                else {
                    cout << "No" << endl;
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

/**
 3 100
 1 1 1
 1 3 3
 3 2 2 2 2
 
 3 1 2 3 2
 
 3 1 2 1 3
 
 */
