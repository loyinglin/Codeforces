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
 J题有两个想法;
 想法1，每个点存两个指针，comNext一个指向离自己下一个节点，stackNext指向同栈的下一个节点，pop遍历时需要路径压缩；
 想法2，两个优先队列，存入<时间，value>的值，合并时选择小的队列合并到大的队列；
 
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


struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return pos < tmp.pos;
    };
    Node(int x, int y):value(x), pos(y){};
    Node(){};
};
lld a[N];
char op[11], s1[11], s2[11];

int main(int argc, const char * argv[]) {
    int ca = 0, n;
    while (scanf("%d", &n) && n) {
        ++ca;
        printf("Case #%d:\n", ca);
        priority_queue<Node> queue[2];
        int indexA = 0, indexB = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%s", op);
            if (op[1] == 'u') {
                scanf("%s", s1);
                int k;
                scanf("%d", &k);
                int index;
                if (s1[0] == 'A') {
                    index = indexA;
                }
                else {
                    index = indexB;
                }
                queue[index].push(Node(k, i));
            }
            if (op[1] == 'o') {
                scanf("%s", s1);
                int index;
                if (s1[0] == 'A') {
                    index = indexA;
                }
                else {
                    index = indexB;
                }
                printf("%d\n", queue[index].top().value);
                queue[index].pop();
            }
            if (op[1] == 'e') {
                scanf("%s%s", s1, s2);
                int source;
                if (queue[0].size() >= queue[1].size()) {
                    source = 0;
                }
                else {
                    source = 1;
                }
                if (s1[0] == 'A') {
                    indexA = source;
                    indexB = 1 - source;
                }
                else {
                    indexB = source;
                    indexA = 1 - source;
                }
                
                while (queue[1-source].size()) {
                    queue[source].push(queue[1-source].top());
                    queue[1-source].pop();
                }
            }
        }
    }
    
}
