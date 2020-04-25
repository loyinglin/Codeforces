//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1315/problem/B)
 **题目大意：**
 小明放学回家，要经过若干个公交车站；每个地方都有公共交通工具可以到达，如果是公交车，我们用A来表示；如果是地铁，我们用B来表示；
 公交车的费用是a，之后连续的公交车站都可以免费到达；
 地铁的费用是b，之后连续的地铁站都可以免费到达；
 以AABBBAB为例，如果从第一个站开始，通过公共交通到达最后一个站，小明需要买三次票：
 公交车1次，可以经过AA；
 地铁1次，可以经过BBB；
 公交车1次，可以经过A；（A下车之后就到达目的地B了，不需要买票）
 
 现在小明身上之后p块钱，可能钱不够所有的交通费用，需要走路到某个站开始乘坐公共交通工具，小明想知道最少要走到哪一站？（从左到右）
 
 **输入：**
 第一行 整数𝑡 (1≤𝑡≤10^4)
 接下来t个样例，每个样例两行
 第一行3个整数  𝑎,𝑏,𝑝 (1≤𝑎,𝑏,𝑝≤10^5)
 第二行n个字符
 
 **输出：**
 每个样例一行，每行一个整数k，表示最少要步行到第k个站。
 
 **Examples**
 input
 5
 2 2 1
 BB
 1 1 1
 AB
 3 2 8
 AABBBBAABB
 5 3 4
 BBBBB
 2 1 1
 ABABAB
 
 
 output
 2
 1
 3
 1
 6
 
 **题目解析：**
 用逆推的方式，从最后一个站开始往前考虑。
 从倒数第二个开始，假设小明当前持有的票是cur，根据cur=A或者cur=B，可以知道当前他是否需要买票；
 然后倒着遍历，直到钱不够，得到正确答案。

 >考察的是实现的巧妙程度和边界处理。
 
 
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
const int N = 100100, M = 3010100, inf = 0x7fffffff;
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

char s[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int a, b, p;
        
        cin >> a >> b >> p;
        cin >> s;
        
        char cur = 0;
        int pos = (int)strlen(s) - 2;
        while (pos >= 0) {
            if (cur == s[pos]) {
                --pos;
                continue;
            }
            else {
                int cost = s[pos] == 'A' ? a : b;
                if (p >= cost) {
                    p -= cost;
                    cur = s[pos];
                    --pos;
                    continue;
                }
                else {
                    break;
                }
            }
        }
        cout << pos + 2 << endl;
    }
    
    return 0;
}


/**
 5
 2 2 1
 BB
 1 1 1
 AB
 3 2 8
 AABBBBAABB
 5 3 4
 BBBBB
 2 1 1
 ABABAB
 
 */
