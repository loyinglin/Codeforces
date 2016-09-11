//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/710/problem/F
 题目大意：m个操作。
 操作1，把一个字符串s放入集合D，每次插入不同；
 操作2，把一个字符串s从集合D删除，保证有值；
 操作3，询问一个字符串x在集合中子串的数量。
  m (1 ≤ m ≤ 3·10e5)
 
 题目解析：
 题目有一个很重要的性质：每次插入不同。
 于是可以插入建一个自动机，删除建一个自动机，相减即可。
  
 
 查找函数再引入一个dp值，如果访问一次，就记录当前值。这样每个点就只访问一次
 build函数，dp值=-1 比较关键
 这里的字典树要引入一个flag来标志是否真的有孩子。（build之后，及时字典树没有孩子，ch指针也会指向fail指针）死循环了几次
 插入和更新，在引入一个flag，有更新之后再重新build
 
 
 如果题目数据更强：
 再引入logN的优化，建logN个自动机，分别存放1、2、4、8等个自动机。
 
 
 
 
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

const int N = 612345;
struct tim{
    int word;
    tim *ch[26], *fail;
    bool flag[26]; // 标志这个点是不是真正有值
    int dp;
}node[N];
char s[N], str[N];
int cnt;
tim *addHead;
tim *rmHead;

tim* need(int t){
    memset(node + t, 0, sizeof(tim));
    return &node[t];
}
void tree_insert(tim* head, char s[]){				//字典树建树
    tim *p = head;
    for(int i = 0; s[i]; i++){
        int id = s[i] - 'a';
        if(!p->flag[id]) {
            p->ch[id] = need(++cnt);
            p->flag[id] = 1;
        }
        p = p->ch[id];
    }
    p->word++;
}

void build(tim* head){
    queue<tim*> q;
    q.push(head);
    while(!q.empty()){
        tim *p = q.front();
        p->dp = -1; //build之后，dp值失效
        q.pop();
        for(int i = 0; i < 26; i++){
            tim *fail = (p == head) ? head : p->fail->ch[i];    //如果为头指针，则失败时指向自己
            if(!p->flag[i]) p->ch[i] = fail;  //很方便的一点
            else{
                p->ch[i]->fail = fail;
                q.push(p->ch[i]);
            }
        }
    }
}
int look(tim* head, char str[]){
    int sum = 0;
    tim *p = head;
    for(int i = 0; str[i]; i++){
        int id = str[i] - 'a';
        p = p->ch[id];
        tim* tp = p;
        int tmpSum = 0;
        while(tp != head) {
            if (tp->dp == -1) { //没有访问过
                tmpSum += tp->word;
                tp = tp->fail;
            }
            else {
                tmpSum += tp->dp;
                break;
            }
        }
        p->dp = tmpSum;
        sum += tmpSum;
    }
    return sum;
}
int main(){
//    freopen("input.txt", "w", stdout);
//    cout << 3 << endl;
//    cout << "1 " << endl;
//    for (int i = 0; i < 100000; ++i) {
//        cout << "a";
//    }
//    cout << endl;
//    cout << "3 ";
//    for (int i = 0; i < 200000; ++i) {
//        cout << "a";
//    }
//    cout << endl;
//    cout << "3 aaaa" << endl;
//    return 0;
//    freopen("input.txt", "r", stdin);
    int n, flag = 1, rmFlag = 1;
    cin >> n;
    cnt = 0;
    addHead = need(cnt);
    rmHead = need(++cnt);
    while(n--){
        int op;
        scanf("%d", &op);
        scanf("%s", s);
        if (op == 1) {
            tree_insert(addHead, s);
            flag = 1;
        }
        else if (op == 2) {
            tree_insert(rmHead, s);
            rmFlag = 1;
        }
        else {
            if (flag || rmFlag) {
                for (int i = 0; i <= cnt; ++i) {
                    node[i].fail = NULL;
                }
                build(addHead);
                build(rmHead);
                flag = rmFlag = 0;
            }

            cout << look(addHead, s) - look(rmHead, s) << endl;
        }
     
    }
}
