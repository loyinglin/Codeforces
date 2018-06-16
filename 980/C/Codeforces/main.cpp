//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/980/problem/C)
 **题目大意：**
 小明正在上图像算法课程，老师要求他实现一个图像滤镜算法，其处理过程可以这么描述：
 给出n个数字p[i]，[0, 255]范围，表示颜色；
 把范围[0, 255]划分多个区间比如说[0, 4], [5, 9], [10, 14]....要求区间的大小不超过k；
 然后对数据进行处理，区间[0, 4]内的数字都可以用0表示，同理[5, 9]=5；
 要求处理之后所有的数字形成的字典序最小。
 
 输入：
 第一行 n，k ( 1 ≤ n ≤ 1e5 , 1 ≤ k ≤ 256 )
 第二行 p 1 , p 2 , … , p n ( 0 ≤ p i ≤ 255 )
 
 **输入数据：**
 
 **Examples**
 **input**
 3
 2 14 3 4
 **output**
 0 12 3 3
 
 样例解释
 color 2 属于 group [0, 2] = 0
 color 14 = group [12, 14] = 12
 color 3,4 = group [3, 5] = 3
 所以最终数字是0，12，3，3
 
 
 **题目解析：**
 所有的数字形成的字典序最小，相当于前面的数字越小越好。
 那么在考虑第i个数字的时候，可以不管i+1之后的数据，尽可能满足第i个数字最小。
 由此，我们可以得到一个贪心策略：
 默认[0, 255]都不分配区间，对第i个数字，其颜色值p[i]，我们从p[i]-1开始往前找还没分配的区间，这时会有两种情况：
 1、都没有分配，那么我们可以把(p[i] - k + 1, p[i])分配成一个区间；
 2、找到一个已经分配的区间（x, y），那么看这个区间的长度是否能达到（x, p[i]），如果可以则把区间放大成(x, p[i]);
 如果长度不够，那么则从(y + 1, p[i]）分配一个区间；
 这样可以得到一个最小字典序。
 
 **思考🤔：**
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int color[1000];

int checkLen(int x) {
    int sum = 1;
    for (int i = x - 1; i >= 0; --i) {
        if (color[i] == color[x]) {
            ++sum;
        }
        else {
            break;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, k;
    cin >> n >> k;
    
    int cnt = 1;
    for (int index = 0; index < n; ++index) {
        int x;
        cin >> x;
        
        if (!color[x]) {
            int cur, ok = 0;
            for (cur = x - 1; cur >= 0 && cur + k > x; --cur) {
                if (color[cur]) {
                    int len = checkLen(cur);
                    if (len + (x - cur) <= k) {
                        ok = color[cur];
                    }
                    break;
                }
            }
            
            if (ok) {
                while (cur <= x) {
                    color[cur++] = ok;
                };
            }
            else {
                while (cur < x) {
                    ++cur;
                    color[cur] = cnt;
                }
                cnt++;
            }
        }
        
        cout << x - checkLen(x) + 1 << " ";
        
    }
    
    
    
    return 0;
}
