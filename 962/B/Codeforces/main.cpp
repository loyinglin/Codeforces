//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/962/problem/B)
 **题目大意：**
 
 **输入数据：**
 n (1 ≤ n ≤ 109)
 
 >**Examples**
 **input**
 1
 **output**
 Ehab
 **input**
 2
 **output**
 Mahmoud
 
 
 **题目解析：**
 n=1时，Mahmoud必输；
 n=2时，Mahmoud必胜；
 n=奇数时，因为Mahmoud只能取偶数，取完之后还是奇数，那么Ehab直接取n就可以；
 n=偶数时，因为Mahmoud只能取偶数，那么直接取n就必胜。
 
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
