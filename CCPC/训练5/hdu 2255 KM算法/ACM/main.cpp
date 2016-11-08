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
 
 
 ************************* 题解 ***********************/
#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


struct Node {
    int word;
    Node *ch[26], *fail;
};
struct Trie {
    static const int N = 1001000, inf = 10000000; // 注意点的大小
    char s[N], str[N];
    struct Node node[N];
    int cnt;
    Node *head;
    Node* need(int t){
        memset(node + t, 0, sizeof(Node)); // 注意大小写！！
        return &node[t];
    }
    
    void reset() {
        cnt = 0;
        head = need(cnt);
    }
    
    void insert(char s[]){				//字典树建树
        Node *p = head;
        for(int i = 0; s[i]; i++){
            int id = s[i] - 'a';
            if(!p->ch[id]) p->ch[id] = need(++cnt);
            p = p->ch[id];
        }
        p->word++;
    }
    void build(){
        queue<Node*> q;
        q.push(head);
        while(!q.empty()){
            Node *p = q.front();
            q.pop();
            for(int i = 0; i < 26; i++){
                Node *fail = (p == head) ? head : p->fail->ch[i];    //如果为头指针，则失败时指向自己
                if(!p->ch[i]) p->ch[i] = fail;  //很方便的一点
                else{
                    p->ch[i]->fail = fail;
                    q.push(p->ch[i]);
                }
            }
        }
    }
    int look(char str[]){
        int sum = 0;
        Node *p = head;
        for(int i = 0; str[i]; i++){
            int id = str[i] - 'a';
            p = p->ch[id];
            Node* tp = p;
            while(tp != head)
                if(tp->word > 0)
                    sum += tp->word, tp->word = 0;
                else
                    tp = tp->fail;
        }
        return sum;
    }
    

}acm;


int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int n;
        cin >> n;
        acm.reset();
        while(n--) scanf("%s", acm.s), acm.insert(acm.s);
        acm.build();
        scanf("%s", acm.s);
        cout << acm.look(acm.s) << endl;
    }
}

