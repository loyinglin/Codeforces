//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：http://poj.org/problem?id=2104
 题目大意：给出一个长度为n的数列，m次询问区间内的第k大数
 题目解析：
 首先看只有一个区间的做法：
 要求区间[l, r]的第k大数，我们可以用二分的方式来解决；
 对于二分出来的值mid，我们把区间[l, r]的值分成两种（大于mid和小于mid），当大于mid的值=k-1的时候，就是第k大的值。
 （容易知道这个具有二分性质）
 
 
 
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
const int N = 1010000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node{
    Node *ch[26], *f;
    int ml, num, flag;
};
int mark;
char str[N];
vector<int> g[N];
struct SAM {
    Node pool[N * 2], *last, *head;
    char str[N];
    int tot, n, maxLen;
    SAM() {
        reset();
    }
    
    void reset() {
        tot = 0;
        maxLen = 0;
        n = 0;
        last = head = NULL;
    }
    
    Node* need(int t){
        memset(pool + t, 0, sizeof(pool[t]));
        
        return &pool[t];
    }
    Node* need(int t, Node* p) {
        need(t);
        pool[t] = *p;
        pool[t].num = 0;
        return pool + t;
    }
    void add(int c, int loc){
        Node *p = last, *np = need(++tot);
        np->ml = loc;
        np->num = 1;
        while (p && !p->ch[c]) {
            p->ch[c]=np;
            p = p->f;
        }
        last = np;
        if(!p) {
            np->f = head;
        }
        else
            if(p->ch[c]->ml == p->ml + 1) {
                np->f = p->ch[c];
            }
            else{
                Node *q = p->ch[c], *newNode = need(++tot, q);
                newNode->ml = p->ml + 1;
                q->f = np->f = newNode;
                while (p && p->ch[c] == q) {
                    p->ch[c] = newNode;
                    p = p->f;
                }
            }
    }
    
    void build() {
        last = head = need(++tot);
        n = (int)strlen(str);
        for (int i = 0; i < n; ++i) add(str[i] - 'a', i + 1);
        topsSort();
        for (int i = n; i > 0; --i) {
            for (int j = 0; j < g[i].size(); ++j) {
                Node *p = pool + g[i][j];
                if (p->f) {
                    p->f->num += p->num;
                }
            }
        }
    }
    void look(char s[]) {
        Node *p = head;
        int m = (int)strlen(s);
        int len = 0;
        int ans = 0;
        for (int i = 0; i < m * 2 - 1; ++i) {
            int id;
            if (i < m) {
                id = s[i] - 'a';
            }
            else {
                id = s[i - m] - 'a';
            }
            
            if (p->ch[id]) {
                p = p->ch[id];
                ++len;
            }
            else {
                while (p) {
                    if (p->ch[id]) {
                        len = p->ml + 1;
                        p = p->ch[id];
                        break;
                    }
                    p = p->f;
                }
                if (!p) {
                    p = head;
                    len = 0;
                }
            }
            while (p->f && p->f->ml >= m) {
                p = p->f;
                len = p->ml;
            }
            
            if (len >= m && p->flag != mark) {
                p->flag = mark;
                ans += p->num;
            }
        }
        
        printf("%d\n", ans);
    }
    void topsSort() {
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i <= tot; ++i) {
            g[pool[i].ml].push_back(i);
        }
    }
}sam;



int main(int argc, const char * argv[]) {
    // insert code here...
    //    freopen("input.txt", "w", stdout);
    //    for (int i = 0; i < 250000; ++i) {
    //        putchar(arc4random_uniform(26) + 'a');
    //    }
    //    cout << endl;
    //    for (int i = 0; i < 250000; ++i) {
    //        putchar(arc4random_uniform(26) + 'a');
    //    }
    //    return 0;
    //    freopen("input.txt", "r", stdin);
    mark = 1;
    int cnt = 0;
    scanf("%s", sam.str);
    sam.build();
    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%s", str);
        sam.look(str);
        ++mark;
    }
    
    return 0;
}

