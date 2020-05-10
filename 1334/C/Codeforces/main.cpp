//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1334/problem/C)
 **题目大意：**
 小明在打游戏，有n只怪物围绕成一圈，第1只和第n只相邻；
 第i只怪物的血量为a[i]，小明每次可以攻击一只怪物，使得怪物的血量-1；
 当怪物的血量小于等于0的时候会死亡，并且产生爆炸，对第i+1个位置的怪物造成b[i]点伤害；（如果是第n只怪物爆炸，则是对第1只怪物造出伤害）
 现在想知道，小明最少攻击多少次，才能使得所有怪物都爆炸；
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 每个样例第一行， 整数𝑛 (2≤𝑛≤300000)
 接下来n行，每行两个整数𝑎𝑖 and 𝑏𝑖 (1≤𝑎𝑖,𝑏𝑖≤1012)
 
 
 **输出：**
 每个样例一行，小明的最少攻击次数。
 
 **Examples**
 input
 1
 3
 7 15
 2 14
 5 3
 ⁣output
 ⁣6
 
 
 **题目解析：**
 题目有两个点使得决策比较复杂：1、n个怪物绕成一个圈；2、怪物死亡之后，会产生爆炸；
 先不考虑怪物死亡后爆炸的问题，就是n只怪物的血量和；
 再考虑爆炸的情况，由于题目要求的是最终所有怪物都死亡，即所有怪物都会爆炸，那么可以直接减去爆炸影响的血量；
 
 接下来的问题是，找到n个怪物中，应该首先攻击哪一个，使得其最先爆炸；
 这个可以先统计一遍所有怪物减去被爆炸影响后的血量和，然后遍历每一个怪物，枚举这个怪物如果最先爆炸，最终的攻击次数。
 
 **思考🤔：**
 如果是双向爆炸呢？
 即位置i有多种可能爆炸顺序， i最先爆炸，i-1先爆炸然后i爆炸，i+1先爆炸然后i爆炸，i-1和i+1都爆炸然后i再爆炸；
 这样需要考虑复杂很多！
 
 
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
const int N = 300010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld a[N], val[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &a[i], &val[i]);
        }
        
        lld sum = max(0ll, a[0] - val[n - 1]);
        for (int i = 1; i < n; ++i) {
            sum = sum + max(0ll, a[i] - val[i - 1]);
        }
        
        lld ans = sum - max(0ll, a[0] - val[n - 1]) + a[0]; // 直接打死第0个
        for (int i = 1; i < n; ++i) {
            lld tmp = sum - max(0ll, a[i] - val[i - 1]) + a[i];
            ans = min(ans, tmp);
        }

        cout << ans << endl;
    }   
    
    return 0;
}


/**
 44
 4
 6 8
 9 3
 8 1
 9 7
  
 */
