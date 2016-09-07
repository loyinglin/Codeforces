//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 题目解析：
 
 max：即代码中 val 变量，它表示该状态能够接受的最长的字符串长度。
 min：表示该状态能够接受的最短的字符串长度。实际上等于该状态的 par 指针指向的结点的 val + 1。
 max-min+1：表示该状态能够接受的不同的字符串数。
 right：即 end-set 的个数，表示这个状态在字符串中出现了多少次，该状态能够表示的所有字符串均出现过 right 次。
 par：par 指向了一个能够表示当前状态表示的所有字符串的最长公共后缀的结点。所有的状态的 par 指针构成了一个 parent 树，恰好是字符串的逆序的后缀树。
 parent 树的拓扑序：序列中第i个状态的子结点必定在它之后，父结点必定在它之前。
 
 
 SAM 的状态要多维护两个信息：lcs，当多个串的最长公共子串的最后一个字符落在该状态上的长度；nlcs，当前串的最长公共子串的最后一个字符落在该状态上的长度。
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

struct Node{
    Node *ch[26], *f;
    int ml, maxRight;
    bool vis;
};
char s[10][N];
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
        pool[t].maxRight = 0;
        return &pool[t];
    }
    Node* need(int t, Node* p) {
        need(t);
        pool[t] = *p;
        return pool + t;
    }
    void add(int c, int loc){
        Node *p = last, *np = need(++tot);
        np->ml = loc;
        np->maxRight = loc;
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
                newNode->maxRight = p->ml + 1;
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
        for(int i = 0; i < n; ++i) add(str[i] - 'a', i + 1);
        topsSort();
        for (int i = n; i > 0; --i) {
            for (int j = 0; j < g[i].size(); ++j) {
                Node *p = pool + g[i][j];
                if (p->f) {
                    p->f->maxRight = max(p->f->maxRight, p->maxRight);
                }
            }
        }
    }
    void topsSort() {
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i <= tot; ++i) {
            g[pool[i].ml].push_back(i);
        }
    }
    
    void output(int loc, int len) {
        int tmp = len;
        cout << "len:" << tmp << " ";
        while (tmp) {
            --tmp;
            putchar(str[loc - 1 + tmp]);
        }
        cout << endl;
    }
}sam;

int ans[N];

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
    
    scanf("%s", sam.str);
    sam.build();
    
    Node *p = sam.head;
    int len = 0;
    p->vis = 1;
    for (int i = sam.n; i > 0; --i) {
        int id = sam.str[i - 1] - 'a';
        if (p->ch[id]) {
            p = p->ch[id];
            ++len;
        }
        else {
            while (p) {
                if (p && p->ch[id]) {
                    len = p->ml + 1;
                    p = p->ch[id];
                    break;
                }
                p = p->f;
            }
            if (!p) {
                len = 0;
                p = sam.head;
            }
        }
        if (len + i > p->maxRight) {
            if (i <= p->maxRight) {
                if (!p->vis) {
                    sam.output(i, p->maxRight - i + 1);
                    p->vis = 1;
                }
            }
            Node* tmp = p->f;
            while (tmp && !tmp->vis && tmp->maxRight >= i && tmp->maxRight < i + tmp->ml) {
                tmp->vis = 1;
                sam.output(i, tmp->maxRight - i + 1);
                tmp = tmp->f;
            }
        }
    }
    return 0;
}


