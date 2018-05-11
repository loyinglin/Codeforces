//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/962/problem/B)
 **题目大意：**
 有n个位置，还有a个班级1的学生，b个班级2的学生；
 n个位置排成一行，由一行长度为n的字符串表示，`*`表示已经有人，`.`表示可以坐人；
 现在不希望班级1和班级2的学生坐在相邻的位置，问最多能安排多少个人坐下。
 
 **输入数据：**
 n , a and b ( 1 ≤ n ≤ 2 ⋅ 10 5 , 0 ≤ a , b ≤ 2 ⋅ 10 5 , a + b > 0 )
 
 >**Examples**
 **input**
 5 1 1
 *...*
 **output**
 2
 **input**
 6 2 3
 *...*.
 **output**
 4
 
 
 **题目解析：**
 一个简单的策略：对于有空位的，优先选择人数较少的班级；
 其次，如果上一个位置坐了班级1的学生，则这个位置做班级2；
 
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
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

char str[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, a, b;
    cin >> n >> a >> b;
    cin >> str;
    
    int last = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '.') {
            if (last == -1) {
                if (a < b) {
                    --b;
                    last = 1;
                }
                else {
                    --a;
                    last = 0;
                }
                ++ans;
            }
            else {
                if (last == 0) {
                    if (b) {
                        --b;
                        ++ans;
                        last = 1;
                    }
                    else {
                        last = -1;
                    }
                }
                else {
                    if (a) {
                        --a;
                        ++ans;
                        last = 0;
                    }
                    else {
                        last = -1;
                    }
                }
            }
        }
        else {
            last = -1;
        }
        if (!a && !b) {
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}
