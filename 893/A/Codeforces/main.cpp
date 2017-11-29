//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/893/problem/A
 题目大意：
 有三个人A,B,C玩剪刀石头布的游戏，但是每次只能两个人参与，于是他们三个人制定规则：
 1、A和B先玩，C旁观；
 2、游戏的胜者和旁观者继续游戏，败者旁观；
 游戏按照这样的规则，重复继续。
 他们把每次的胜负写在纸上，总共有n行；(1<=n<=100)
 每行有一个数字a[i]; (1<=a[i]<=3，a[i]=1表示A胜，a[i]=2表示B胜，a[i]=3表示C胜）
 现在根据这个胜负记录，判断游戏过程中是否存在错误记录的情况；（比如第一行是3 表示C胜，但是C没有参与游戏）
 如果是正常的记录，输出YES;
 如果是错误的记录，输出NO；
 
 
 
 题目解析：
 题目的逻辑非常清晰，记录每场游戏的参与者和胜者，按照规则判断是否存在不合理情况。
 
 这里有一个优雅的实现，只记录旁观者，对于每一次胜利者，判断 是否为旁观者；
 至于如何快速求出每次游戏的败者，我们记录的旁观者加入是t,每次输入的胜利者是x，那么有每次的败者s=6-t-x; （因为有x+t+s=6）
 
 
 
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
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    bool ok = true;
    int emptyOne = 3;
    while (n--) {
        int winner;
        cin >> winner;
        if (winner == emptyOne) {
            ok = false;
        }
        else {
            emptyOne = 6 - emptyOne - winner;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    
    return 0;
}
