//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1337/problem/B)
 **题目大意：**
 小明在打游戏，遇到了一条恶龙；
 恶龙血量为x，小明可以释放两个技能：
 技能1：使龙的血量变为x/2+10，x/2为向下取整；
 技能2：使龙的血量减10；
 当龙的血量小于等于零时，小明会赢得胜利；
 
 小明最多可以释放n个技能1和m个技能2，现在想知道，小明是否能否打败恶龙；
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，整数𝑥 , 𝑛, 𝑚 (1≤𝑥≤10^5, 0≤𝑛,𝑚≤30)
 
 **输出：**
 每个样例一行，如果小明可以打败恶龙，输出YES；如果无法打败，则输出NO；
 
 **Examples**
 input
 7
 100 3 4
 189 3 4
 64 2 3
 63 2 3
 30 27 7
 10 9 1
 69117 21 2
 output
 YES
 NO
 NO
 YES
 YES
 YES
 YES
 
 
 **题目解析：**
 题目只考虑是否能打败，而不是最优解，可以直接将技能1释放完，只要技能1不会使恶龙血量增加；
 然后再全部放完技能2，看最终血量是否小于等于0即可；
 
 **思考🤔：**
 贪心！
 
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

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int x, n, m;
        cin >>x >> n >> m;
        while (n && (x / 2 + 10 < x)) {
            --n;
            x = x / 2  +10;
        }
        if (x <= m * 10) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }   
    
    return 0;
}
