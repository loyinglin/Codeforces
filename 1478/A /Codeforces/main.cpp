//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1478/problem/A)
 **题目大意：**
 有n个球，序号分别是1、2、3、、、、n，每个球上面有一个数字a[1]、a[2]、a[3]、、、a[n]，这组数字是不递减的，即是 a[i]≤𝑎[i]+1， 1≤i<𝑛；
 现在需要给n个球染色，需要满足：
 1、每个球只有一个颜色；
 2、将某个颜色的球挑选出来，按照序号从小到大放好，上面的数字是严格递增；
 
 问，最少需要几个颜色。
 
 **输入：**
 𝑡 (1≤𝑡≤100)
 𝑛 (1≤𝑛≤100)
 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛)
 
 **输出：**

 
 **Examples**
 **input**
 5
 6
 1 1 1 2 3 4
 5
 1 1 2 2 3
 4
 2 2 2 2
 3
 1 2 3
 1
 1
 
 **output**
 3
 2
 4
 1
 1
 
 **题目解析：**
 由于本身数字就是不递减，要满足严格递增，只需要关注数字相同的部分；
 相同数字的最大连续长度，就是需要的颜色数量。
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

lld calc(lld a) {
    lld x = 0, y = 9;
    while (a) {
        x = max(x, a%10);
        y = min(y, a%10);
        a /= 10;
    }
    return x*y;
}

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1, cur = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i > 0) {
                if (a[i] == a[i - 1]) {
                    ++cur;
                    ans = max(ans, cur);
                }
                else {
                    cur = 1;
                }
            }
        }
        cout << ans << endl;
    }   
    
    return 0;
}
