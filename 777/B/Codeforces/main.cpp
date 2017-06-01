//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/777/problem/B
 题目大意：
 小明和小红各有n张卡片，每张卡片的数字是0~9；
 现在小明和小红进行比赛，每次出一张卡片，每张卡片只能用一次，数字小的输；
 现在问：
 小红最少会输几次？还有小红最多能赢多少次？
 
 n (1 ≤ n ≤ 1000)
 
 Examples
 input
 3
 123
 321
 output
 0
 2
 样例解释：
 最少输的出牌顺序是小明vs小红 ： 123vs123；
 最多赢的出牌顺序是小明vs小红 ： 123vs231;
 
 
 题目解析：
 分情况讨论，先看最少输的情况：
 如果希望小红尽可能少输，那么应该让小红每个数字尽可能找大于等于小明的数字进行匹配；
 于是可以采取这种的策略：
 对于每个数字，尽可能找与之最近的数字；

 
 最多赢的情况：
 如果希望小红尽可能多赢，那么应该让小红每个数字尽可能大于小明的数字进行匹配即可。
 
 
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
const int N = 1010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

char a[N], b[N];
int vis[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    cin >> a >> b;
    int ansMin = 0;
    for (int i = 0; i < n; ++i) {
        int id = -1, dif = 100;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && b[i] >= a[j]) {
                if (b[i] - a[j] < dif) {
                    id = j;
                    dif = b[i] - a[j];
                }
            }
        }
        if (id != -1) {
            vis[id] = 1;
            ++ansMin;
        }
    }
    int ansMax = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        int id = -1, dif = 100;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && b[i] > a[j]) {
                if (b[i] - a[j] < dif) {
                    id = j;
                    dif = b[i] - a[j];
                }
            }
        }
        if (id != -1) {
            vis[id] = 1;
            ++ansMax;
        }
    }
    cout << n - ansMin << " " << ansMax << endl;
    
    
    return 0;
}
