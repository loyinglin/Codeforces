//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 H题。
 有n张卡片A，m张卡片B。卡片A的效果是再摸2张牌，卡片B的效果是造成a[i]点伤害；
 现在将n+m张牌混合随机打乱。
 抽一张牌，当出完抽的所有牌的时候，能造成>=P点伤害的概率。
 P (P<=1000), N and M (N+M<=20)
 样例
 3 1 2
 1 2
 
 1/3
 解释：三张牌，分别是"抽2张牌"、"造成1点伤害"、"造成2点伤害";
 只有第一张为卡片A的时候，才能造成3点伤害；其他两种可能因为无法抽后续卡牌，无法造成3点伤害；
 
 
 
 题目解析：
 d[j] 表示状态为j的合法数量；(j化为01010，1表示当前牌已经选了）
 d[j]，枚举i个伤害牌，放入j中，得到新状态jj
 d[jj] = d[jj] + d[j];
 
 状态j是否合法，取决于当前已选卡片A的数量与卡片B的数量，当A+1>=B的时候，有意义的；(A>=B 表示还能抽一张）
 
 
 
 
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
const lld N = 21, M = 3010100, mod = 1000000007ll;


int main(int argc, const char * argv[]) {
    int caseN, ca = 0;

    cin >> caseN;
    while (caseN--) {
        ++ca;
        
        
    }
    
}
