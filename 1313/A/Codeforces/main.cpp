//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1313/problem/A)
 **题目大意：**
 餐馆有三种食物，数量分别是a、b、c个；
 餐馆给客人提供就餐的特点：
 1、每个人至少吃到一种食物；
 2、每个人，每种食物最多吃1个；
 3、每个人要吃不同组合的食物；
 
 问，最多能给几个人提供就餐服务？
 
 **输入：**
  第一行，整数𝑡，表示样例个数 (1≤𝑡≤500)
  接下来t行，每行有整数𝑎 , 𝑏 and 𝑐 (0≤𝑎,𝑏,𝑐≤10)
 **输出：**
  
 **Examples**
 
 
 **题目解析：**
 每种食物，单独分给1个人，肯定是最优的，可以优先分配；（100，010，001）
 食物两两组合的时候，优先考虑量最大的一种；（011，101，110）
 如果还有剩下，则分配所有的食物；（111）
 
 
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
int a[N];

bool cmp(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (a[i]) {
                --a[i];
                ++cnt;
            }
        }
        sort(a, a+3, cmp);
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (a[i] && a[j]) {
                    --a[i];
                    --a[j];
                    ++cnt;
                }
            }
        }
        if (a[0]&&a[1]&&a[2]) {
            ++cnt;
        }
        
        cout << cnt << endl;
        
    }
    
    
    return 0;
}
