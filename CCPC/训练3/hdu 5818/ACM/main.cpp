//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：给出两个栈A、B，n个操作
 三种操作：
 push A/B x (将x放入A/B)
 pop A/B (A/B出栈)
 merge A B (将A、B栈的元素按照入栈时间顺序放入A中)或merge B A，
 要求 每次pop时，输出pop的值。
 
 
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
